/*
This file belongs to Ashes.
See LICENSE file in root folder
*/
#pragma once

#include "renderer/D3D11Renderer/Core/D3D11Layer.hpp"

#include "renderer/D3D11Renderer/Buffer/D3D11Buffer.hpp"
#include "renderer/D3D11Renderer/Core/D3D11Surface.hpp"

namespace ashes::d3d11
{
	class Device
	{
	public:
		Device( VkInstance instance
			, VkPhysicalDevice physicalDevice
			, VkDeviceCreateInfo createInfos );
		~Device();
		VkImage getStagingImage( VkImage image
			, VkDeviceMemory & memory );
		/**
		*\copydoc	ashes::Device::getImageSubresourceLayout
		*/
		void getImageSubresourceLayout( VkImage image
			, VkImageSubresource const & subresource
			, VkSubresourceLayout & layout )const;
		/**
		*\copydoc	ashes::Device::debugMarkerSetObjectName
		*/
		void debugMarkerSetObjectName( VkDebugMarkerObjectNameInfoEXT const & nameInfo )const;
		/**
		*\copydoc	ashes::Device::getQueue
		*/
		VkQueue getQueue( uint32_t familyIndex
			, uint32_t index )const;
		/**
		*\brief
		*	Attend que le périphérique soit inactif.
		*/
		VkResult waitIdle()const;
		/**
		*\~english
		*name
		*	Layers delegation.
		*\~french
		*name
		*	Délégation aux layers.
		*/
		/**@{*/
		bool onCopyToImageCommand( VkCommandBuffer cmd
			, VkBufferImageCopyArray const & copyInfo
			, VkBuffer src
			, VkImage dst )const;
		bool onCheckHResultCommand( HRESULT hresult
			, std::string message )const;
		/**@}*/
		/**
		*\~french
		*\return
		*	L'API de rendu.
		*\~english
		*\return
		*	The rendering API.
		*/
		inline VkInstance getInstance()const
		{
			return m_instance;
		}
		/**
		*\~french
		*\return
		*	La connection à l'application.
		*\~english
		*\return
		*	The connection to the application.
		*/
		inline D3D_FEATURE_LEVEL getFeatureLevel()const
		{
			return m_featureLevel;
		}

		inline ID3D11Device * getDevice()const
		{
			return m_d3dDevice;
		}

		inline VkBuffer getEmptyIndexedVaoIdx()const
		{
			return m_dummyIndexed.buffer;
		}

		inline VkPhysicalDevice getGpu()const
		{
			return m_physicalDevice;
		}

#if !defined( NDEBUG )

		inline ID3D11Debug * getDebug()
		{
			return m_debug;
		}

#endif

	private:
		void doCreateD3D11Device();
		void doCreateDummyIndexBuffer();
		void doCreateQueues();

	private:
		struct QueueCreates
		{
			VkDeviceQueueCreateInfo createInfo;
			std::vector< VkQueue > queues;
		};
		using QueueCreateCountMap = std::map< uint32_t, QueueCreates >;

	private:
		VkInstance m_instance;
		VkPhysicalDevice m_physicalDevice;
		VkDeviceCreateInfo m_createInfos;
		ID3D11Device * m_d3dDevice;
		ID3D11DeviceContext * m_deviceContext;
		ID3D11Query * m_waitIdleQuery;
		D3D_FEATURE_LEVEL m_featureLevel;
		QueueCreateCountMap m_queues;
#if !defined( NDEBUG )
		ID3D11Debug * m_debug;
#endif
		// Mimic the behavior in Vulkan, when no IBO nor VBO is bound.
		struct Buffer
		{
			VkBuffer buffer;
			VkDeviceMemory memory;
		};
		Buffer m_dummyIndexed;
		std::unordered_map< size_t, std::pair< VkImage, VkDeviceMemory > > m_stagingTextures;
	};
}
