#include "RenderPanel.hpp"

#include "Application.hpp"
#include "MainFrame.hpp"

#include <Buffer/PushConstantsBuffer.hpp>
#include <Buffer/StagingBuffer.hpp>
#include <Buffer/UniformBuffer.hpp>
#include <Buffer/VertexBuffer.hpp>
#include <Command/Queue.hpp>
#include <Core/BackBuffer.hpp>
#include <Core/Connection.hpp>
#include <Core/Device.hpp>
#include <Core/Renderer.hpp>
#include <Core/SwapChain.hpp>
#include <Descriptor/DescriptorSet.hpp>
#include <Descriptor/DescriptorSetLayout.hpp>
#include <Descriptor/DescriptorSetLayoutBinding.hpp>
#include <Descriptor/DescriptorSetPool.hpp>
#include <Image/Texture.hpp>
#include <Image/TextureView.hpp>
#include <Miscellaneous/PushConstantRange.hpp>
#include <Miscellaneous/QueryPool.hpp>
#include <Pipeline/DepthStencilState.hpp>
#include <Pipeline/InputAssemblyState.hpp>
#include <Pipeline/MultisampleState.hpp>
#include <Pipeline/Scissor.hpp>
#include <Pipeline/VertexLayout.hpp>
#include <Pipeline/Viewport.hpp>
#include <RenderPass/FrameBuffer.hpp>
#include <RenderPass/RenderPass.hpp>
#include <RenderPass/RenderSubpass.hpp>
#include <RenderPass/RenderSubpassState.hpp>
#include <Shader/ShaderProgram.hpp>
#include <Sync/ImageMemoryBarrier.hpp>

#include <Utils/Transform.hpp>

#include <FileUtils.hpp>

#include <chrono>

namespace vkapp
{
	namespace
	{
		enum class Ids
		{
			RenderTimer = 42
		}	Ids;

		static int const TimerTimeMs = 20;
		static renderer::PixelFormat const DepthFormat = renderer::PixelFormat::eD32F;

		renderer::PushConstantArray doGetVariables()
		{
			renderer::PushConstantArray result;
			result.push_back( { 3u, 0u, renderer::AttributeFormat::eVec4f } );
			return result;
		}
	}

	RenderPanel::RenderPanel( wxWindow * parent
		, wxSize const & size
		, renderer::Renderer const & renderer )
		: wxPanel{ parent, wxID_ANY, wxDefaultPosition, size }
		, m_timer{ new wxTimer{ this, int( Ids::RenderTimer ) } }
		, m_offscreenVertexData
		{
			// Front
			{ { -1.0, -1.0, +1.0, 1.0 }, { 0.0, 0.0 } },
			{ { -1.0, +1.0, +1.0, 1.0 }, { 0.0, 1.0 } },
			{ { +1.0, -1.0, +1.0, 1.0 }, { 1.0, 0.0 } },
			{ { +1.0, +1.0, +1.0, 1.0 }, { 1.0, 1.0 } },
			// Top
			{ { -1.0, +1.0, +1.0, 1.0 }, { 0.0, 0.0 } },
			{ { -1.0, +1.0, -1.0, 1.0 }, { 0.0, 1.0 } },
			{ { +1.0, +1.0, +1.0, 1.0 }, { 1.0, 0.0 } },
			{ { +1.0, +1.0, -1.0, 1.0 }, { 1.0, 1.0 } },
			// Back
			{ { -1.0, +1.0, -1.0, 1.0 }, { 1.0, 1.0 } },
			{ { -1.0, -1.0, -1.0, 1.0 }, { 1.0, 0.0 } },
			{ { +1.0, +1.0, -1.0, 1.0 }, { 0.0, 1.0 } },
			{ { +1.0, -1.0, -1.0, 1.0 }, { 0.0, 0.0 } },
			// Bottom
			{ { -1.0, -1.0, -1.0, 1.0 }, { 1.0, 1.0 } },
			{ { -1.0, -1.0, +1.0, 1.0 }, { 1.0, 0.0 } },
			{ { +1.0, -1.0, -1.0, 1.0 }, { 0.0, 1.0 } },
			{ { +1.0, -1.0, +1.0, 1.0 }, { 0.0, 0.0 } },
			// Right
			{ { +1.0, -1.0, +1.0, 1.0 }, { 0.0, 0.0 } },
			{ { +1.0, +1.0, +1.0, 1.0 }, { 0.0, 1.0 } },
			{ { +1.0, -1.0, -1.0, 1.0 }, { 1.0, 0.0 } },
			{ { +1.0, +1.0, -1.0, 1.0 }, { 1.0, 1.0 } },
			// Left
			{ { -1.0, -1.0, -1.0, 1.0 }, { 0.0, 0.0 } },
			{ { -1.0, +1.0, -1.0, 1.0 }, { 0.0, 1.0 } },
			{ { -1.0, -1.0, +1.0, 1.0 }, { 1.0, 0.0 } },
			{ { -1.0, +1.0, +1.0, 1.0 }, { 1.0, 1.0 } },
		}
		, m_offscreenIndexData
		{
			// Front
			0, 1, 2, 2, 1, 3,
			// Top
			4, 5, 6, 6, 5, 7,
			// Back
			8, 9, 10, 10, 9, 11,
			// Bottom
			12, 13, 14, 14, 13, 15,
			// Right
			16, 17, 18, 18, 17, 19,
			// Left
			20, 21, 22, 22, 21, 23,
		}
		, m_mainVertexData
		{
			{ { -1.0, -1.0, 0.0, 1.0 }, { 0.0, 0.0 } },
			{ { -1.0, +1.0, 0.0, 1.0 }, { 0.0, 1.0 } },
			{ { +1.0, -1.0, 0.0, 1.0 }, { 1.0, 0.0 } },
			{ { +1.0, +1.0, 0.0, 1.0 }, { 1.0, 1.0 } },
		}
		, m_objectPcb{ renderer::ShaderStageFlag::eFragment, doGetVariables() }
	{
		*m_objectPcb.getData() = renderer::RgbaColour{ 0.5, 0.5, 1.0, 1.0 };
		try
		{
			doCreateDevice( renderer );
			std::cout << "Logical device created." << std::endl;
			doCreateSwapChain();
			std::cout << "Swap chain created." << std::endl;
			doCreateStagingBuffer();
			std::cout << "Staging buffer created." << std::endl;
			doCreateTexture();
			std::cout << "Truck texture created." << std::endl;
			doCreateUniformBuffer();
			std::cout << "Uniform buffer created." << std::endl;
			doCreateOffscreenDescriptorSet();
			std::cout << "Offscreen descriptor set created." << std::endl;
			doCreateOffscreenRenderPass();
			std::cout << "Offscreen render pass created." << std::endl;
			doCreateFrameBuffer();
			std::cout << "Frame buffer created." << std::endl;
			doCreateOffscreenVertexBuffer();
			std::cout << "Offscreen vertex buffer created." << std::endl;
			doCreateOffscreenPipeline();
			std::cout << "Offscreen pipeline created." << std::endl;
			doPrepareOffscreenFrame();
			doCreateMainDescriptorSet();
			std::cout << "Main descriptor set created." << std::endl;
			doCreateMainRenderPass();
			std::cout << "Main render pass created." << std::endl;
			doCreateMainVertexBuffer();
			std::cout << "Main vertex buffer created." << std::endl;
			doCreateMainPipeline();
			std::cout << "Main pipeline created." << std::endl;
			doPrepareMainFrames();
		}
		catch ( std::exception & )
		{
			doCleanup();
			throw;
		}

		m_timer->Start( TimerTimeMs );

		Connect( int( Ids::RenderTimer )
			, wxEVT_TIMER
			, wxTimerEventHandler( RenderPanel::onTimer )
			, nullptr
			, this );
		Connect( wxID_ANY
			, wxEVT_SIZE
			, wxSizeEventHandler( RenderPanel::onSize )
			, nullptr
			, this );
	}

	RenderPanel::~RenderPanel()
	{
		doCleanup();
	}

	void RenderPanel::doCleanup()
	{
		delete m_timer;

		if ( m_device )
		{
			m_device->waitIdle();

			m_updateCommandBuffer.reset();
			m_commandBuffer.reset();
			m_commandBuffers.clear();
			m_frameBuffers.clear();
			m_sampler.reset();
			m_view.reset();
			m_texture.reset();
			m_stagingBuffer.reset();

			m_matrixUbo.reset();
			m_objectUbo.reset();
			m_mainDescriptorSet.reset();
			m_mainDescriptorPool.reset();
			m_mainDescriptorLayout.reset();
			m_mainPipeline.reset();
			m_mainPipelineLayout.reset();
			m_mainVertexBuffer.reset();
			m_mainRenderPass.reset();

			m_queryPool.reset();
			m_offscreenDescriptorSet.reset();
			m_offscreenDescriptorPool.reset();
			m_offscreenDescriptorLayout.reset();
			m_offscreenPipelines.red.reset();
			m_offscreenPipelines.green.reset();
			m_offscreenPipelineLayout.reset();
			m_offscreenIndexBuffer.reset();
			m_offscreenVertexBuffer.reset();
			m_offscreenRenderPass.reset();

			m_frameBuffer.reset();
			m_renderTargetDepthView.reset();
			m_renderTargetDepth.reset();
			m_renderTargetColourView.reset();
			m_renderTargetColour.reset();

			m_swapChain.reset();
			m_device->disable();
			m_device.reset();
		}
	}

	void RenderPanel::doUpdateProjection()
	{
		auto size = m_swapChain->getDimensions();
#if 0
		float halfWidth = static_cast< float >( size.x ) * 0.5f;
		float halfHeight = static_cast< float >( size.y ) * 0.5f;
		float wRatio = 1.0f;
		float hRatio = 1.0f;

		if ( halfHeight > halfWidth )
		{
			hRatio = halfHeight / halfWidth;
		}
		else
		{
			wRatio = halfWidth / halfHeight;
		}

		m_matrixUbo->getData( 0u ) = m_device->ortho( -2.0f * wRatio
			, 2.0f * wRatio
			, -2.0f * hRatio
			, 2.0f * hRatio
			, 0.0f
			, 10.0f );
#else
		auto width = float( size.x );
		auto height = float( size.y );
		m_matrixUbo->getData( 0u ) = m_device->perspective( utils::toRadians( 90.0_degrees )
			, width / height
			, 0.01f
			, 100.0f );
#endif
		m_stagingBuffer->uploadUniformData( *m_updateCommandBuffer
			, m_matrixUbo->getDatas()
			, *m_matrixUbo
			, renderer::PipelineStageFlag::eVertexShader );
	}

	void RenderPanel::doCreateDevice( renderer::Renderer const & renderer )
	{
		m_device = renderer.createDevice( common::makeConnection( this, renderer ) );
		m_device->enable();
	}

	void RenderPanel::doCreateSwapChain()
	{
		wxSize size{ GetClientSize() };
		m_swapChain = m_device->createSwapChain( { size.x, size.y } );
		m_swapChain->setClearColour( { 1.0f, 0.8f, 0.4f, 0.0f } );
		m_swapChainReset = m_swapChain->onReset.connect( [this]()
		{
			doCreateFrameBuffer();
			doPrepareOffscreenFrame();
			doCreateMainDescriptorSet();
			doPrepareMainFrames();
		} );
		m_updateCommandBuffer = m_device->getGraphicsCommandPool().createCommandBuffer();
	}

	void RenderPanel::doCreateTexture()
	{
		std::string shadersFolder = common::getPath( common::getExecutableDirectory() ) / "share" / "Assets";
		auto image = common::loadImage( shadersFolder / "texture.png" );
		m_texture = m_device->createTexture(
			{
				renderer::TextureType::e2D,
				image.format,
				{ image.size[0], image.size[1], 1u },
				1u,
				1u,
				renderer::SampleCountFlag::e1,
				renderer::ImageTiling::eOptimal,
				renderer::ImageUsageFlag::eTransferDst | renderer::ImageUsageFlag::eSampled
			}
			, renderer::MemoryPropertyFlag::eDeviceLocal );
		m_view = m_texture->createView( m_texture->getType()
			, image.format );
		m_sampler = m_device->createSampler( renderer::WrapMode::eClampToEdge
			, renderer::WrapMode::eClampToEdge
			, renderer::WrapMode::eClampToEdge
			, renderer::Filter::eLinear
			, renderer::Filter::eLinear );
		m_stagingBuffer->uploadTextureData( m_swapChain->getDefaultResources().getCommandBuffer()
			, image.data
			, *m_view );
	}

	void RenderPanel::doCreateUniformBuffer()
	{
		m_matrixUbo = std::make_unique< renderer::UniformBuffer< renderer::Mat4 > >( *m_device
			, 1u
			, renderer::BufferTarget::eTransferDst
			, renderer::MemoryPropertyFlag::eDeviceLocal );
		m_objectUbo = std::make_unique< renderer::UniformBuffer< renderer::Mat4 > >( *m_device
			, 2u
			, renderer::BufferTarget::eTransferDst
			, renderer::MemoryPropertyFlag::eDeviceLocal );
	}

	void RenderPanel::doCreateStagingBuffer()
	{
		m_stagingBuffer = std::make_unique< renderer::StagingBuffer >( *m_device
			, 0u
			, 10000000u );
	}

	void RenderPanel::doCreateOffscreenDescriptorSet()
	{
		std::vector< renderer::DescriptorSetLayoutBinding > bindings
		{
			renderer::DescriptorSetLayoutBinding{ 0u, renderer::DescriptorType::eCombinedImageSampler, renderer::ShaderStageFlag::eFragment },
			renderer::DescriptorSetLayoutBinding{ 1u, renderer::DescriptorType::eUniformBuffer, renderer::ShaderStageFlag::eVertex },
			renderer::DescriptorSetLayoutBinding{ 2u, renderer::DescriptorType::eUniformBufferDynamic, renderer::ShaderStageFlag::eVertex },
		};
		m_offscreenDescriptorLayout = m_device->createDescriptorSetLayout( std::move( bindings ) );
		m_offscreenDescriptorPool = m_offscreenDescriptorLayout->createPool( 2u );

		m_offscreenDescriptorSet = m_offscreenDescriptorPool->createDescriptorSet();
		m_offscreenDescriptorSet->createBinding( m_offscreenDescriptorLayout->getBinding( 0u )
			, *m_view
			, *m_sampler );
		m_offscreenDescriptorSet->createBinding( m_offscreenDescriptorLayout->getBinding( 1u )
			, *m_matrixUbo
			, 0u
			, 1u );
		m_offscreenDescriptorSet->createDynamicBinding( m_offscreenDescriptorLayout->getBinding( 2u )
			, *m_objectUbo
			, 0u
			, 1u );
		m_offscreenDescriptorSet->update();
	}

	void RenderPanel::doCreateOffscreenRenderPass()
	{
		renderer::RenderPassAttachmentArray attaches
		{
			{
				0u,
				renderer::PixelFormat::eR8G8B8A8,
				renderer::SampleCountFlag::e1,
				renderer::AttachmentLoadOp::eClear,
				renderer::AttachmentStoreOp::eStore,
				renderer::AttachmentLoadOp::eDontCare,
				renderer::AttachmentStoreOp::eDontCare,
				renderer::ImageLayout::eUndefined,
				renderer::ImageLayout::eShaderReadOnlyOptimal,
			},
			{
				1u,
				DepthFormat,
				renderer::SampleCountFlag::e1,
				renderer::AttachmentLoadOp::eClear,
				renderer::AttachmentStoreOp::eStore,
				renderer::AttachmentLoadOp::eDontCare,
				renderer::AttachmentStoreOp::eDontCare,
				renderer::ImageLayout::eUndefined,
				renderer::ImageLayout::eDepthStencilAttachmentOptimal,
			}
		};
		renderer::RenderSubpassAttachmentArray subAttaches
		{
			{ 0u, renderer::ImageLayout::eColourAttachmentOptimal }
		};
		renderer::RenderSubpassPtrArray subpasses;
		subpasses.emplace_back( m_device->createRenderSubpass( renderer::PipelineBindPoint::eGraphics
			, renderer::RenderSubpassState{ renderer::PipelineStageFlag::eColourAttachmentOutput
				, renderer::AccessFlag::eColourAttachmentWrite }
			, subAttaches
			, { 1u, renderer::ImageLayout::eDepthStencilAttachmentOptimal } ) );
		m_offscreenRenderPass = m_device->createRenderPass( attaches
			, std::move( subpasses )
			, renderer::RenderSubpassState{ renderer::PipelineStageFlag::eColourAttachmentOutput
				, renderer::AccessFlag::eColourAttachmentWrite }
			, renderer::RenderSubpassState{ renderer::PipelineStageFlag::eColourAttachmentOutput
				, renderer::AccessFlag::eShaderRead } );
	}

	void RenderPanel::doCreateFrameBuffer()
	{
		auto size = GetClientSize();
		m_renderTargetColour = m_device->createTexture(
			{
				renderer::TextureType::e2D,
				renderer::PixelFormat::eR8G8B8A8,
				{ uint32_t( size.GetWidth() ), uint32_t( size.GetHeight() ), 1u },
				1u,
				1u,
				renderer::SampleCountFlag::e1,
				renderer::ImageTiling::eOptimal,
				renderer::ImageUsageFlag::eColourAttachment | renderer::ImageUsageFlag::eSampled
			}
			, renderer::MemoryPropertyFlag::eDeviceLocal );
		m_renderTargetColourView = m_renderTargetColour->createView( m_renderTargetColour->getType()
			, m_renderTargetColour->getFormat() );
		
		m_renderTargetDepth = m_device->createTexture(
			{
				renderer::TextureType::e2D,
				DepthFormat,
				{ uint32_t( size.GetWidth() ), uint32_t( size.GetHeight() ), 1u },
				1u,
				1u,
				renderer::SampleCountFlag::e1,
				renderer::ImageTiling::eOptimal,
				renderer::ImageUsageFlag::eDepthStencilAttachment
			}
			, renderer::MemoryPropertyFlag::eDeviceLocal );
		m_renderTargetDepthView = m_renderTargetDepth->createView( m_renderTargetDepth->getType()
			, m_renderTargetDepth->getFormat() );
		renderer::FrameBufferAttachmentArray attaches;
		attaches.emplace_back( *( m_offscreenRenderPass->begin() + 0u ), *m_renderTargetColourView );
		attaches.emplace_back( *( m_offscreenRenderPass->begin() + 1u ), *m_renderTargetDepthView );
		m_frameBuffer = m_offscreenRenderPass->createFrameBuffer( { size.GetWidth(), size.GetHeight() }
			, std::move( attaches ) );
	}

	void RenderPanel::doCreateOffscreenVertexBuffer()
	{
		m_offscreenVertexLayout = renderer::makeLayout< TexturedVertexData >( 0 );
		m_offscreenVertexLayout->createAttribute< renderer::Vec4 >( 0u
			, uint32_t( offsetof( TexturedVertexData, position ) ) );
		m_offscreenVertexLayout->createAttribute< renderer::Vec2 >( 1u
			, uint32_t( offsetof( TexturedVertexData, uv ) ) );

		m_offscreenVertexBuffer = renderer::makeVertexBuffer< TexturedVertexData >( *m_device
			, uint32_t( m_offscreenVertexData.size() )
			, renderer::BufferTarget::eTransferDst
			, renderer::MemoryPropertyFlag::eDeviceLocal );
		m_stagingBuffer->uploadVertexData( m_swapChain->getDefaultResources().getCommandBuffer()
			, m_offscreenVertexData
			, *m_offscreenVertexBuffer
			, renderer::PipelineStageFlag::eVertexInput );

		m_offscreenIndexBuffer = renderer::makeBuffer< uint16_t >( *m_device
			, uint32_t( m_offscreenIndexData.size() )

			, renderer::BufferTarget::eTransferDst
			, renderer::MemoryPropertyFlag::eDeviceLocal );
		m_stagingBuffer->uploadBufferData( m_swapChain->getDefaultResources().getCommandBuffer()
			, m_offscreenIndexData
			, *m_offscreenIndexBuffer );
	}

	void RenderPanel::doCreateOffscreenPipeline()
	{
		renderer::PushConstantRange range{ renderer::ShaderStageFlag::eFragment, 0u, m_objectPcb.getSize() };
		m_offscreenPipelineLayout = m_device->createPipelineLayout( renderer::DescriptorSetLayoutCRefArray{ { *m_offscreenDescriptorLayout } }
			, renderer::PushConstantRangeCRefArray{ { range } } );
		wxSize size{ GetClientSize() };
		std::string shadersFolder = common::getPath( common::getExecutableDirectory() ) / "share" / AppName / "Shaders";

		if ( !wxFileExists( shadersFolder / "offscreen.vert.spv" )
			|| !wxFileExists( shadersFolder / "offscreen.frag.spv" ) )
		{
			throw std::runtime_error{ "Shader files are missing" };
		}

		if ( !m_device->getPhysicalDevice().isSPIRVSupported() )
		{
			throw std::runtime_error{ "SPIR-V support is needed for this test." };
		}

		std::vector< renderer::ShaderStageState > shaderStages;

		shaderStages.emplace_back( m_device->createShaderModule( renderer::ShaderStageFlag::eVertex ) );
		shaderStages.emplace_back( m_device->createShaderModule( renderer::ShaderStageFlag::eFragment )
			, renderer::makeSpecialisationInfo( { { 0u, 0u, renderer::AttributeFormat::eInt } }, int( 0 ) ) );
		shaderStages[0].getModule().loadShader( common::dumpBinaryFile( shadersFolder / "offscreen.vert.spv" ) );
		shaderStages[1].getModule().loadShader( common::dumpBinaryFile( shadersFolder / "offscreen.frag.spv" ) );
		renderer::GraphicsPipelineCreateInfo createInfoRed
		{
			std::move( shaderStages ),
			*m_offscreenRenderPass,
			renderer::VertexInputState::create( *m_offscreenVertexLayout ),
			renderer::InputAssemblyState{ renderer::PrimitiveTopology::eTriangleList },
			renderer::RasterisationState{ 1.0f, 0, false, false, renderer::PolygonMode::eFill, renderer::CullModeFlag::eNone },
			renderer::MultisampleState{},
			renderer::ColourBlendState::createDefault(),
			renderer::DepthStencilState{},
		};
		m_offscreenPipelines.red = m_offscreenPipelineLayout->createPipeline( std::move( createInfoRed ) );

		shaderStages.emplace_back( m_device->createShaderModule( renderer::ShaderStageFlag::eVertex ) );
		shaderStages.emplace_back( m_device->createShaderModule( renderer::ShaderStageFlag::eFragment )
			, renderer::makeSpecialisationInfo( { { 0u, 0u, renderer::AttributeFormat::eInt } }, int( 1 ) ) );
		shaderStages[0].getModule().loadShader( common::dumpBinaryFile( shadersFolder / "offscreen.vert.spv" ) );
		shaderStages[1].getModule().loadShader( common::dumpBinaryFile( shadersFolder / "offscreen.frag.spv" ) );
		renderer::GraphicsPipelineCreateInfo createInfoGreen
		{
			std::move( shaderStages ),
			*m_offscreenRenderPass,
			renderer::VertexInputState::create( *m_offscreenVertexLayout ),
			renderer::InputAssemblyState{ renderer::PrimitiveTopology::eTriangleList },
			renderer::RasterisationState{ 1.0f, 0, false, false, renderer::PolygonMode::eFill, renderer::CullModeFlag::eNone },
			renderer::MultisampleState{},
			renderer::ColourBlendState::createDefault(),
			renderer::DepthStencilState{},
		};
		m_offscreenPipelines.green = m_offscreenPipelineLayout->createPipeline( std::move( createInfoGreen ) );
	}

	void RenderPanel::doCreateMainDescriptorSet()
	{
		std::vector< renderer::DescriptorSetLayoutBinding > bindings
		{
			renderer::DescriptorSetLayoutBinding{ 0u, renderer::DescriptorType::eCombinedImageSampler, renderer::ShaderStageFlag::eFragment },
		};
		m_mainDescriptorLayout = m_device->createDescriptorSetLayout( std::move( bindings ) );
		m_mainDescriptorPool = m_mainDescriptorLayout->createPool( 1u );
		m_mainDescriptorSet = m_mainDescriptorPool->createDescriptorSet();
		m_mainDescriptorSet->createBinding( m_mainDescriptorLayout->getBinding( 0u )
			, *m_renderTargetColourView
			, *m_sampler );
		m_mainDescriptorSet->update();
	}

	void RenderPanel::doCreateMainRenderPass()
	{
		renderer::RenderPassAttachmentArray attaches
		{
			{
				0u,
				m_swapChain->getFormat(),
				renderer::SampleCountFlag::e1,
				renderer::AttachmentLoadOp::eClear,
				renderer::AttachmentStoreOp::eStore,
				renderer::AttachmentLoadOp::eDontCare,
				renderer::AttachmentStoreOp::eDontCare,
				renderer::ImageLayout::eUndefined,
				renderer::ImageLayout::ePresentSrc,
			}
		};
		renderer::RenderSubpassAttachmentArray subAttaches
		{
			{ 0u, renderer::ImageLayout::eColourAttachmentOptimal }
		};
		renderer::RenderSubpassPtrArray subpasses;
		subpasses.emplace_back( m_device->createRenderSubpass( renderer::PipelineBindPoint::eGraphics
			, renderer::RenderSubpassState{ renderer::PipelineStageFlag::eColourAttachmentOutput
				, renderer::AccessFlag::eColourAttachmentWrite }
			, subAttaches ) );
		m_mainRenderPass = m_device->createRenderPass( attaches
			, std::move( subpasses )
			, renderer::RenderSubpassState{ renderer::PipelineStageFlag::eBottomOfPipe
				, renderer::AccessFlag::eMemoryRead }
			, renderer::RenderSubpassState{ renderer::PipelineStageFlag::eBottomOfPipe
				, renderer::AccessFlag::eMemoryRead } );
	}

	void RenderPanel::doPrepareOffscreenFrame()
	{
		doUpdateProjection();
		m_queryPool = m_device->createQueryPool( renderer::QueryType::eTimestamp
			, 2u
			, 0u );
		m_commandBuffer = m_device->getGraphicsCommandPool().createCommandBuffer();
		wxSize size{ GetClientSize() };
		auto & commandBuffer = *m_commandBuffer;
		auto & frameBuffer = *m_frameBuffer;

		if ( commandBuffer.begin( renderer::CommandBufferUsageFlag::eSimultaneousUse ) )
		{
			auto dimensions = m_swapChain->getDimensions();
			commandBuffer.resetQueryPool( *m_queryPool
				, 0u
				, 2u );
			commandBuffer.beginRenderPass( *m_offscreenRenderPass
				, frameBuffer
				, { renderer::ClearValue{ m_swapChain->getClearColour() }, renderer::ClearValue{ renderer::DepthStencilClearValue{ 1.0f, 0u } } }
				, renderer::SubpassContents::eInline );
			commandBuffer.writeTimestamp( renderer::PipelineStageFlag::eTopOfPipe
				, *m_queryPool
				, 0u );
			commandBuffer.setViewport( { uint32_t( dimensions.x )
				, uint32_t( dimensions.y )
				, 0
				, 0 } );
			commandBuffer.setScissor( { 0
				, 0
				, uint32_t( dimensions.x )
				, uint32_t( dimensions.y ) } );
			commandBuffer.bindVertexBuffer( 0u, m_offscreenVertexBuffer->getBuffer(), 0u );
			commandBuffer.bindIndexBuffer( m_offscreenIndexBuffer->getBuffer(), 0u, renderer::IndexType::eUInt16 );

			// Red cube
			commandBuffer.bindPipeline( *m_offscreenPipelines.red );
			commandBuffer.bindDescriptorSet( *m_offscreenDescriptorSet
				, *m_offscreenPipelineLayout
				, renderer::UInt32Array{ 0u } );
			commandBuffer.pushConstants( *m_offscreenPipelineLayout
				, m_objectPcb );
			commandBuffer.drawIndexed( uint32_t( m_offscreenIndexData.size() ) );

			// Green cube
			commandBuffer.bindPipeline( *m_offscreenPipelines.green );
			commandBuffer.bindDescriptorSet( *m_offscreenDescriptorSet
				, *m_offscreenPipelineLayout
				, renderer::UInt32Array{ m_objectUbo->getAlignedSize() } );
			commandBuffer.pushConstants( *m_offscreenPipelineLayout
				, m_objectPcb );
			commandBuffer.drawIndexed( uint32_t( m_offscreenIndexData.size() ) );

			commandBuffer.writeTimestamp( renderer::PipelineStageFlag::eBottomOfPipe
				, *m_queryPool
				, 1u );
			commandBuffer.endRenderPass();
			auto res = commandBuffer.end();

			if ( !res )
			{
				std::stringstream stream;
				stream << "Command buffers recording failed.";
				throw std::runtime_error{ stream.str() };
			}
		}
	}

	void RenderPanel::doCreateMainVertexBuffer()
	{
		m_mainVertexLayout = renderer::makeLayout< TexturedVertexData >( 0 );
		m_mainVertexLayout->createAttribute< renderer::Vec4 >( 0u
			, uint32_t( offsetof( TexturedVertexData, position ) ) );
		m_mainVertexLayout->createAttribute< renderer::Vec2 >( 1u
			, uint32_t( offsetof( TexturedVertexData, uv ) ) );

		m_mainVertexBuffer = renderer::makeVertexBuffer< TexturedVertexData >( *m_device
			, uint32_t( m_mainVertexData.size() )
			, renderer::BufferTarget::eTransferDst
			, renderer::MemoryPropertyFlag::eDeviceLocal );
		m_stagingBuffer->uploadVertexData( m_swapChain->getDefaultResources().getCommandBuffer()
			, m_mainVertexData
			, *m_mainVertexBuffer
			, renderer::PipelineStageFlag::eVertexInput );
	}

	void RenderPanel::doCreateMainPipeline()
	{
		m_mainPipelineLayout = m_device->createPipelineLayout( *m_mainDescriptorLayout );
		wxSize size{ GetClientSize() };
		std::string shadersFolder = common::getPath( common::getExecutableDirectory() ) / "share" / AppName / "Shaders";

		if ( !wxFileExists( shadersFolder / "main.vert" )
			|| !wxFileExists( shadersFolder / "main.frag" ) )
		{
			throw std::runtime_error{ "Shader files are missing" };
		}

		std::vector< renderer::ShaderStageState > shaderStages;
		shaderStages.emplace_back( m_device->createShaderModule( renderer::ShaderStageFlag::eVertex ) );
		shaderStages.emplace_back( m_device->createShaderModule( renderer::ShaderStageFlag::eFragment ) );
		shaderStages[0].getModule().loadShader( common::parseShaderFile( *m_device, shadersFolder / "main.vert" ) );
		shaderStages[1].getModule().loadShader( common::parseShaderFile( *m_device, shadersFolder / "main.frag" ) );

		m_mainPipeline = m_mainPipelineLayout->createPipeline( renderer::GraphicsPipelineCreateInfo
		{
			std::move( shaderStages ),
			*m_mainRenderPass,
			renderer::VertexInputState::create( *m_mainVertexLayout ),
			renderer::InputAssemblyState{ renderer::PrimitiveTopology::eTriangleStrip },
			renderer::RasterisationState{ 1.0f }
		} );
	}

	void RenderPanel::doPrepareMainFrames()
	{
		m_frameBuffers = m_swapChain->createFrameBuffers( *m_mainRenderPass );
		m_commandBuffers = m_swapChain->createCommandBuffers();

		for ( size_t i = 0u; i < m_frameBuffers.size(); ++i )
		{
			auto & frameBuffer = *m_frameBuffers[i];
			auto & commandBuffer = *m_commandBuffers[i];

			wxSize size{ GetClientSize() };

			if ( commandBuffer.begin( renderer::CommandBufferUsageFlag::eSimultaneousUse ) )
			{
				auto dimensions = m_swapChain->getDimensions();
				commandBuffer.beginRenderPass( *m_mainRenderPass
					, frameBuffer
					, { renderer::ClearValue{ { 1.0, 0.0, 0.0, 1.0 } } }
					, renderer::SubpassContents::eInline );
				commandBuffer.bindPipeline( *m_mainPipeline );
				commandBuffer.setViewport( { uint32_t( dimensions.x )
					, uint32_t( dimensions.y )
					, 0
					, 0 } );
				commandBuffer.setScissor( { 0
					, 0
					, uint32_t( dimensions.x )
					, uint32_t( dimensions.y ) } );
				commandBuffer.bindVertexBuffer( 0u, m_mainVertexBuffer->getBuffer(), 0u );
				commandBuffer.bindDescriptorSet( *m_mainDescriptorSet
					, *m_mainPipelineLayout );
				commandBuffer.draw( 4u );
				commandBuffer.endRenderPass();

				auto res = commandBuffer.end();

				if ( !res )
				{
					std::stringstream stream;
					stream << "Command buffers recording failed.";
					throw std::runtime_error{ stream.str() };
				}
			}
		}
	}

	void RenderPanel::doUpdate()
	{
		static renderer::Mat4 const originalTranslate1 = []()
		{
			renderer::Mat4 result;
			result = utils::translate( result, { 2, 0, -5 } );
			return result;
		}();
		static renderer::Mat4 const originalTranslate2 = []()
		{
			renderer::Mat4 result;
			result = utils::translate( result, { -2, 0, -5 } );
			return result;
		}();
		static renderer::Mat4 const originalRotate = []()
		{
			renderer::Mat4 result;
			result = utils::rotate( result
				, float( utils::DegreeToRadian * 45.0 )
				, { 0, 0, 1 } );
			return result;
		}();
		m_rotate[0] = utils::rotate( m_rotate[0]
			, float( utils::DegreeToRadian )
			, { 0, 1, 0 } );
		m_rotate[1] = utils::rotate( m_rotate[1]
			, -float( utils::DegreeToRadian )
			, { 0, 1, 0 } );
		m_objectUbo->getData( 0u ) = originalTranslate1 * m_rotate[0] * originalRotate;
		m_objectUbo->getData( 1u ) = originalTranslate2 * m_rotate[1] * originalRotate;
		m_stagingBuffer->uploadUniformData( *m_updateCommandBuffer
			, m_objectUbo->getDatas()
			, *m_objectUbo
			, renderer::PipelineStageFlag::eVertexShader );
	}

	void RenderPanel::doDraw()
	{
		auto resources = m_swapChain->getResources();

		if ( resources )
		{
			auto before = std::chrono::high_resolution_clock::now();
			auto & queue = m_device->getGraphicsQueue();
			auto res = queue.submit( *m_commandBuffer
				, nullptr );

			if ( res )
			{
				auto res = queue.submit( *m_commandBuffers[resources->getBackBuffer()]
					, resources->getImageAvailableSemaphore()
					, renderer::PipelineStageFlag::eColourAttachmentOutput
					, resources->getRenderingFinishedSemaphore()
					, &resources->getFence() );
				m_swapChain->present( *resources );
				renderer::UInt32Array values{ 0u, 0u };
				m_queryPool->getResults( 0u
					, 2u
					, 0u
					, renderer::QueryResultFlag::eWait
					, values );

				// Elapsed time in nanoseconds
				auto elapsed = std::chrono::nanoseconds{ uint64_t( ( values[1] - values[0] ) / float( m_device->getTimestampPeriod() ) ) };
				auto after = std::chrono::high_resolution_clock::now();
				wxGetApp().updateFps( std::chrono::duration_cast< std::chrono::microseconds >( elapsed )
					, std::chrono::duration_cast< std::chrono::microseconds >( after - before ) );
			}
		}
		else
		{
			m_timer->Stop();
		}
	}

	void RenderPanel::doResetSwapChain()
	{
		m_device->waitIdle();
		wxSize size{ GetClientSize() };
		m_swapChain->reset( { size.GetWidth(), size.GetHeight() } );
	}

	void RenderPanel::onTimer( wxTimerEvent & event )
	{
		if ( event.GetId() == int( Ids::RenderTimer ) )
		{
			doUpdate();
			doDraw();
		}
	}

	void RenderPanel::onSize( wxSizeEvent & event )
	{
		m_timer->Stop();
		doResetSwapChain();
		m_timer->Start( TimerTimeMs );
		event.Skip();
	}
}
