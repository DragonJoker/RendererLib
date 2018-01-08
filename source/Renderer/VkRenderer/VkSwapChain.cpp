#include "VkSwapChain.hpp"

#include "VkBackBuffer.hpp"
#include "VkCommandBuffer.hpp"
#include "VkCommandPool.hpp"
#include "VkDevice.hpp"
#include "VkFrameBuffer.hpp"
#include "VkImageMemoryBarrier.hpp"
#include "VkMemoryStorage.hpp"
#include "VkPhysicalDevice.hpp"
#include "VkQueue.hpp"
#include "VkRenderPass.hpp"
#include "VkSemaphore.hpp"
#include "VkTexture.hpp"

namespace vk_renderer
{
	SwapChain::SwapChain( Device const & device
		, utils::IVec2 const & size )
		: renderer::SwapChain{ device, size }
		, m_device{ device }
		, m_surface{ device.getPresentSurface() }
		, m_dimensions{ size }
	{
		m_surfaceCapabilities = m_device.getSurfaceCapabilities();

		// On choisit le format de la surface.
		doSelectFormat( m_device.getPhysicalDevice() );

		// On cr�e la swap chain.
		doCreateSwapChain();

		// Puis les tampons d'images.
		doCreateBackBuffers();

		m_renderingResources.resize( 3 );

		for ( auto & resource : m_renderingResources )
		{
			resource = std::make_unique< RenderingResources >( device );
		}
	}

	SwapChain::~SwapChain()
	{
		m_backBuffers.clear();
		DestroySwapchainKHR( m_device, m_swapChain, nullptr );
	}

	void SwapChain::reset( utils::IVec2 const & size )
	{
		m_dimensions = size;
		doResetSwapChain();
	}

	renderer::FrameBufferPtrArray SwapChain::createFrameBuffers( renderer::RenderPass const & renderPass )const
	{
		renderer::FrameBufferPtrArray result;
		result.resize( m_backBuffers.size() );

		for ( size_t i = 0u; i < result.size(); ++i )
		{
			result[i] = static_cast< RenderPass const & >( renderPass ).createFrameBuffer( m_dimensions
				, { m_backBuffers[i]->getTexture() } );
		}

		return result;
	}

	renderer::CommandBufferPtrArray SwapChain::createCommandBuffers()const
	{
		renderer::CommandBufferPtrArray result;
		result.resize( m_backBuffers.size() );

		for ( auto & commandBuffer : result )
		{
			commandBuffer = std::make_unique< CommandBuffer >( m_device
				, static_cast< CommandPool const & >( m_device.getGraphicsCommandPool() )
				, true );
		}

		return result;
	}

	void SwapChain::preRenderCommands( uint32_t index
		, renderer::CommandBuffer const & commandBuffer )const
	{
		commandBuffer.memoryBarrier( renderer::PipelineStageFlag::eColourAttachmentOutput
			, renderer::PipelineStageFlag::eColourAttachmentOutput
			, m_backBuffers[index]->getTexture().makeColourAttachment() );
	}

	void SwapChain::postRenderCommands( uint32_t index
		, renderer::CommandBuffer const & commandBuffer )const
	{
		commandBuffer.memoryBarrier( renderer::PipelineStageFlag::eColourAttachmentOutput
			, renderer::PipelineStageFlag::eBottomOfPipe
			, m_backBuffers[index]->getTexture().makePresentSource() );
	}

	renderer::RenderingResources * SwapChain::getResources()
	{
		auto & resources = *m_renderingResources[m_resourceIndex];
		m_resourceIndex = ( m_resourceIndex + 1 ) % m_renderingResources.size();

		if ( resources.waitRecord( renderer::FenceTimeout ) )
		{
			uint32_t backBuffer{ 0u };
			auto res = AcquireNextImageKHR( m_device
				, m_swapChain
				, std::numeric_limits< uint64_t >::max()
				, static_cast< Semaphore const & >( resources.getImageAvailableSemaphore() )
				, VK_NULL_HANDLE
				, &backBuffer );
			checkError( res );

			if ( doCheckNeedReset( res, true, "Swap chain image acquisition" ) )
			{
				resources.setBackBuffer( backBuffer );
				return &resources;
			}

			return nullptr;
		}

		std::cerr << "Can't render: " << getLastError() << std::endl;
		return nullptr;
	}

	void SwapChain::present( renderer::RenderingResources & resources )
	{
		auto res = static_cast< Queue const & >( m_device.getPresentQueue() ).presentBackBuffer( { *this }
			, { resources.getBackBuffer() }
			, { static_cast< Semaphore const & >( resources.getRenderingFinishedSemaphore() ) } );
		checkError( res );
		doCheckNeedReset( res, false, "Image presentation" );
		resources.setBackBuffer( ~0u );
	}

	uint32_t SwapChain::doGetImageCount()
	{
		uint32_t desiredNumberOfSwapChainImages{ m_surfaceCapabilities.minImageCount + 1 };

		if ( ( m_surfaceCapabilities.maxImageCount > 0 ) &&
			( desiredNumberOfSwapChainImages > m_surfaceCapabilities.maxImageCount ) )
		{
			// L'application doit s'initialiser avec moins d'images que voulu.
			desiredNumberOfSwapChainImages = m_surfaceCapabilities.maxImageCount;
		}

		return desiredNumberOfSwapChainImages;
	}


	void SwapChain::doSelectFormat( VkPhysicalDevice gpu )
	{
		// On r�cup�re la liste de VkFormat support�s par la surface.
		uint32_t formatCount{ 0u };
		auto res = GetPhysicalDeviceSurfaceFormatsKHR( gpu
			, m_surface
			, &formatCount
			, nullptr );

		if ( !checkError( res ) )
		{
			throw std::runtime_error{ "Surface formats enumeration failed: " + getLastError() };
		}

		std::vector< VkSurfaceFormatKHR > surfFormats{ formatCount };
		res = GetPhysicalDeviceSurfaceFormatsKHR( gpu, m_surface
			, &formatCount
			, surfFormats.data() );

		if ( !checkError( res ) )
		{
			throw std::runtime_error{ "Surface formats enumeration failed: " + getLastError() };
		}

		// Si la liste de formats ne contient qu'une entr�e VK_FORMAT_UNDEFINED,
		// la surface n'a pas de format pr�f�r�. Sinon, au moins un format support�
		// sera renvoy�.
		if ( formatCount == 1u && surfFormats[0].format == VK_FORMAT_UNDEFINED )
		{
			m_format = utils::PixelFormat::eB8G8R8A8;
		}
		else
		{
			assert( formatCount >= 1u );
			m_format = convert( surfFormats[0].format );
		}

		m_colorSpace = surfFormats[0].colorSpace;
	}

	VkPresentModeKHR SwapChain::doSelectPresentMode()
	{
		// On r�cup�re la liste de VkPresentModeKHR support�s par la surface.
		uint32_t presentModeCount{};
		auto res = GetPhysicalDeviceSurfacePresentModesKHR( m_device.getPhysicalDevice()
			, m_surface
			, &presentModeCount
			, nullptr );

		if ( !checkError( res ) )
		{
			throw std::runtime_error{ "Surface present modes enumeration failed: " + getLastError() };
		}

		std::vector< VkPresentModeKHR > presentModes{ presentModeCount };
		res = GetPhysicalDeviceSurfacePresentModesKHR( m_device.getPhysicalDevice()
			, m_surface
			, &presentModeCount
			, presentModes.data() );

		if ( !checkError( res ) )
		{
			throw std::runtime_error{ "Surface present modes enumeration failed: " + getLastError() };
		}

		// Si le mode bo�te aux lettres est disponible, on utilise celui-l�, car c'est celui avec le
		// minimum de latence dans tearing.
		// Sinon, on essaye le mode IMMEDIATE, qui est normalement disponible, et est le plus rapide
		// (bien qu'il y ait du tearing). Sinon on utilise le mode FIFO qui est toujours disponible.
		VkPresentModeKHR swapchainPresentMode{ VK_PRESENT_MODE_FIFO_KHR };

		for ( auto mode : presentModes )
		{
			if ( mode == VK_PRESENT_MODE_MAILBOX_KHR )
			{
				swapchainPresentMode = VK_PRESENT_MODE_MAILBOX_KHR;
				break;
			}

			if ( ( swapchainPresentMode != VK_PRESENT_MODE_MAILBOX_KHR ) &&
				( mode == VK_PRESENT_MODE_IMMEDIATE_KHR ) )
			{
				swapchainPresentMode = VK_PRESENT_MODE_IMMEDIATE_KHR;
			}
		}

		return swapchainPresentMode;
	}

	void SwapChain::doCreateSwapChain()
	{
		VkExtent2D swapChainExtent{};

		// width et height valent soient tous les deux -1 ou tous les deux autre chose que -1.
		if ( m_surfaceCapabilities.currentExtent.width == uint32_t( -1 ) )
		{
			// Si les dimensions de la surface sont ind�finies, elles sont initialis�es
			// aux dimensions des images requises.
			swapChainExtent.width = m_dimensions.x;
			swapChainExtent.height = m_dimensions.y;
		}
		else
		{
			// Si les dimensions de la surface sont d�finies, alors les dimensions de la swap chain
			// doivent correspondre.
			swapChainExtent = m_surfaceCapabilities.currentExtent;
		}

		// Parfois, les images doivent �tre transform�es avant d'�tre pr�sent�es (lorsque l'orientation
		// du p�riph�rique est diff�rente de l'orientation par d�faut, par exemple).
		// Si la transformation sp�cifi�e est diff�rente de la transformation par d�faut, le moteur de 
		// pr�sentation va transformer l'image lors de la pr�sentation. Cette op�ration peut avoir un
		// impact sur les performances sur certaines plateformes.
		// Ici, nous ne voulons aucune transformation, donc si la transformation identit� est support�e,
		// nous l'utilisons, sinon nous utiliserons la m�me transformation que la transformation courante.
		VkSurfaceTransformFlagBitsKHR preTransform{};

		if ( m_surfaceCapabilities.supportedTransforms & VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR )
		{
			preTransform = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
		}
		else
		{
			preTransform = m_surfaceCapabilities.currentTransform;
		}

		VkSwapchainKHR oldSwapChain{ VK_NULL_HANDLE };

		VkSwapchainCreateInfoKHR createInfo
		{
			VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR,
			nullptr,
			0,                                                                        // flags
			m_surface,                                                                // surface
			doGetImageCount(),                                                        // minImageCount
			convert( m_format ),                                                      // imageFormat
			m_colorSpace,                                                             // imageColorSpace
			swapChainExtent,                                                          // imageExtent
			1,                                                                        // imageArrayLayers
			VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,                                      // imageUsage
			VK_SHARING_MODE_EXCLUSIVE,                                                // imageSharingMode
			0,                                                                        // queueFamilyIndexCount
			nullptr,                                                                  // pQueueFamilyIndices
			preTransform,                                                             // preTransform
			VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR,                                        // compositeAlpha
			doSelectPresentMode(),                                                    // presentMode
			true,                                                                     // clipped
			oldSwapChain,                                                             // oldSwapchain
		};
		DEBUG_DUMP( createInfo );
		auto res = CreateSwapchainKHR( m_device
			, &createInfo
			, nullptr
			, &m_swapChain );

		if ( !checkError( res ) )
		{
			throw std::runtime_error{ "Swap chain creation failed: " + getLastError() };
		}

		// On supprime la pr�c�dente swap chain au cas o� il y en avait une.
		if ( oldSwapChain != VK_NULL_HANDLE )
		{
			DestroySwapchainKHR( m_device
				, oldSwapChain
				, nullptr );
		}
	}

	void SwapChain::doCreateBackBuffers()
	{
		// On r�cup�re les images de la swapchain.
		uint32_t imageCount{ 0u };
		auto res = GetSwapchainImagesKHR( m_device
			, m_swapChain
			, &imageCount
			, nullptr );

		if ( !checkError( res ) || ( imageCount == 0 ) )
		{
			throw std::runtime_error{ "Swap chain images count retrieval failed: " + getLastError() };
		}

		std::vector< VkImage > swapChainImages( imageCount );
		res = GetSwapchainImagesKHR( m_device
			, m_swapChain
			, &imageCount
			, &swapChainImages[0] );

		if ( !checkError( res ) )
		{
			throw std::runtime_error{ "Swap chain images retrieval failed: " + getLastError() };
		}

		// Et on cr�e des BackBuffers � partir de ces images.
		m_backBuffers.reserve( imageCount );
		uint32_t index{ 0u };

		for ( auto image : swapChainImages )
		{
			m_backBuffers.emplace_back( std::make_unique< BackBuffer >( m_device
				, *this
				, index++
				, m_format
				, m_dimensions
				, Texture{ m_device
					, m_format
					, m_dimensions
					, image } ) );
		}
	}

	bool SwapChain::doCheckNeedReset( VkResult errCode
		, bool acquisition
		, char const * const action )
	{
		bool result{ false };

		switch ( errCode )
		{
		case VK_SUCCESS:
			result = true;
			break;

		case VK_ERROR_OUT_OF_DATE_KHR:
			if ( !acquisition )
			{
				doResetSwapChain();
			}
			else
			{
				result = true;
			}
			break;

		case VK_SUBOPTIMAL_KHR:
			doResetSwapChain();
			break;

		default:
			std::cerr << action << " failed: " << getLastError() << std::endl;
			break;
		}

		return result;
	}

	void SwapChain::doResetSwapChain()
	{
		m_device.waitIdle();
		auto colour = m_clearColour;
		m_backBuffers.clear();
		DestroySwapchainKHR( m_device, m_swapChain, nullptr );
		m_renderingResources.clear();
		m_surfaceCapabilities = m_device.getSurfaceCapabilities();
		// On choisit le format de la surface.
		doSelectFormat( m_device.getPhysicalDevice() );
		// On cr�e la swap chain.
		doCreateSwapChain();
		// Puis les tampons d'images.
		doCreateBackBuffers();

		m_renderingResources.resize( 3 );

		for ( auto & resource : m_renderingResources )
		{
			resource = std::make_unique< RenderingResources >( m_device );
		}

		onReset();
	}
}