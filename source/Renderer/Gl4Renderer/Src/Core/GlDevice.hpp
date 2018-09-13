/*
This file belongs to RendererLib.
See LICENSE file in root folder
*/
#pragma once

#include "Core/GlContext.hpp"
#include "Core/GlPhysicalDevice.hpp"

#include <Buffer/VertexBuffer.hpp>
#include <Core/Device.hpp>
#include <Pipeline/ColourBlendState.hpp>
#include <Pipeline/DepthStencilState.hpp>
#include <Pipeline/InputAssemblyState.hpp>
#include <Pipeline/MultisampleState.hpp>
#include <Pipeline/RasterisationState.hpp>
#include <Pipeline/Scissor.hpp>
#include <Pipeline/TessellationState.hpp>
#include <Pipeline/Viewport.hpp>

namespace gl_renderer
{
	class ContextLock
	{
	public:
		ContextLock( ContextLock const & ) = delete;
		ContextLock & operator=( ContextLock const & ) = delete;

		inline ContextLock( Context const & context )
			: m_context{ &context }
			, m_disable{ !context.isEnabled() }
		{
			if ( m_disable )
			{
				m_context->enable();
			}
		}

		ContextLock( ContextLock && rhs )
			: m_context{ rhs.m_context }
			, m_disable{ rhs.m_disable }
		{
			rhs.m_context = nullptr;
		}

		ContextLock & operator=( ContextLock && rhs )
		{
			if ( &rhs != this )
			{
				m_context = rhs.m_context;
				m_disable = rhs.m_disable;
				rhs.m_context = nullptr;
			}

			return *this;
		}

		inline ~ContextLock()
		{
			if ( m_context && m_disable )
			{
				m_context->disable();
			}
		}

		Context const * operator->()const
		{
			return m_context;
		}

	private:
		Context const * m_context;
		bool m_disable;
	};
	/**
	*\brief
	*	Classe contenant les informations liées au GPU logique.
	*/
	class Device
		: public renderer::Device
	{
		friend class Renderer;

	public:
		/**
		*\brief
		*	Constructeur.
		*\param[in] renderer
		*	L'instance de Renderer.
		*\param[in] connection
		*	La connection à l'application.
		*/
		Device( Renderer const & renderer
			, PhysicalDevice const & gpu
			, renderer::ConnectionPtr && connection );
		~Device();
		/**
		*\copydoc	renderer::Device::createStagingTexture
		*/
		renderer::StagingTexturePtr createStagingTexture( renderer::Format format
			, renderer::Extent3D const & extent )const;
		/**
		*\copydoc		renderer::Device::createRenderPass
		*/
		renderer::RenderPassPtr createRenderPass( renderer::RenderPassCreateInfo createInfo )const override;
		/**
		*\copydoc		renderer::Device::createPipelineLayout
		*/
		renderer::PipelineLayoutPtr createPipelineLayout( renderer::DescriptorSetLayoutCRefArray const & setLayouts
			, renderer::PushConstantRangeCRefArray const & pushConstantRanges )const override;
		/**
		*\copydoc		renderer::Device::createDescriptorSetLayout
		*/
		renderer::DescriptorSetLayoutPtr createDescriptorSetLayout( renderer::DescriptorSetLayoutBindingArray && bindings )const override;
		/**
		*\copydoc	renderer::Device::createDescriptorPool
		*/
		renderer::DescriptorPoolPtr createDescriptorPool( renderer::DescriptorPoolCreateFlags flags
			, uint32_t maxSets
			, renderer::DescriptorPoolSizeArray poolSizes )const override;
		/**
		*\copydoc	renderer::Device::allocateMemory
		*/
		renderer::DeviceMemoryPtr allocateMemory( renderer::MemoryRequirements const & requirements
			, renderer::MemoryPropertyFlags flags )const override;
		/**
		*\copydoc		renderer::Device::createTexture
		*/
		renderer::TexturePtr createTexture( renderer::ImageCreateInfo const & createInfo )const override;
		/**
		*\copydoc	renderer::Device::getImageSubresourceLayout
		*/
		void getImageSubresourceLayout( renderer::Texture const & image
			, renderer::ImageSubresource const & subresource
			, renderer::SubresourceLayout & layout )const override;
		/**
		*\copydoc		renderer::Device::createSampler
		*/
		renderer::SamplerPtr createSampler( renderer::SamplerCreateInfo const & createInfo )const override;
		/**
		*\copydoc		renderer::Device::createBuffer
		*/
		renderer::BufferBasePtr createBuffer( uint32_t size
			, renderer::BufferTargets targets )const override;
		/**
		*\copydoc		renderer::Device::createBufferView
		*/
		renderer::BufferViewPtr createBufferView( renderer::BufferBase const & buffer
			, renderer::Format format
			, uint32_t offset
			, uint32_t range )const override;
		/**
		*\copydoc		renderer::Device::createUniformBuffer
		*/
		renderer::UniformBufferBasePtr createUniformBuffer( uint32_t count
			, uint32_t size
			, renderer::BufferTargets target
			, renderer::MemoryPropertyFlags memoryFlags )const override;
		/**
		*\copydoc		renderer::Device::createSwapChain
		*/
		renderer::SwapChainPtr createSwapChain( renderer::Extent2D const & size )const override;
		/**
		*\copydoc		renderer::Device::createSemaphore
		*/
		renderer::SemaphorePtr createSemaphore()const override;
		/**
		*\copydoc	renderer::Device::createFence
		*/
		renderer::FencePtr createFence( renderer::FenceCreateFlags flags = 0 )const override;
		/**
		*\copydoc	renderer::Device::createEvent
		*/
		renderer::EventPtr createEvent()const override;
		/**
		*\copydoc		renderer::Device::createCommandPool
		*/
		renderer::CommandPoolPtr createCommandPool( uint32_t queueFamilyIndex
			, renderer::CommandPoolCreateFlags const & flags )const override;
		/**
		*\copydoc		renderer::Device::createShaderProgram
		*/
		virtual renderer::ShaderModulePtr createShaderModule( renderer::ShaderStageFlag stage )const override;
		/**
		*\copydoc	renderer::Device::createQueryPool
		*/
		renderer::QueryPoolPtr createQueryPool( renderer::QueryType type
			, uint32_t count
			, renderer::QueryPipelineStatisticFlags pipelineStatistics )const override;
		/**
		*\copydoc	renderer::Device::createQueryPool
		*/
		void waitIdle()const override;
		/**
		*\brief
		*	Echange les tampons.
		*/
		void swapBuffers()const;

		inline ContextLock getContext()const
		{
			return { *m_context };
		}

		inline renderer::Scissor & getCurrentScissor()const
		{
			return m_scissor;
		}

		inline renderer::Viewport & getCurrentViewport()const
		{
			return m_viewport;
		}

		inline renderer::ColourBlendState & getCurrentBlendState()const
		{
			return m_cbState;
		}

		inline renderer::DepthStencilState & getCurrentDepthStencilState()const
		{
			return m_dsState;
		}

		inline renderer::MultisampleState & getCurrentMultisampleState()const
		{
			return m_msState;
		}

		inline renderer::RasterisationState & getCurrentRasterisationState()const
		{
			return m_rsState;
		}

		inline renderer::TessellationState & getCurrentTessellationState()const
		{
			return m_tsState;
		}

		inline renderer::InputAssemblyState & getCurrentInputAssemblyState()const
		{
			return m_iaState;
		}

		inline GLuint & getCurrentProgram()const
		{
			return m_currentProgram;
		}

		inline GeometryBuffers & getEmptyIndexedVao()const
		{
			return *m_dummyIndexed.geometryBuffers;
		}

		inline renderer::BufferBase const & getEmptyIndexedVaoIdx()const
		{
			return m_dummyIndexed.indexBuffer->getBuffer();
		}

		inline GLuint getBlitSrcFbo()const
		{
			return m_blitFbos[0];
		}

		inline GLuint getBlitDstFbo()const
		{
			return m_blitFbos[1];
		}

	private:
		Renderer const & m_renderer;
		renderer::ConnectionPtr m_connection;
		ContextPtr m_context;
		struct Vertex
		{
			float x;
			float y;
			float z;
		};
		// Mimic the behavior in Vulkan, when no IBO nor VBO is bound.
		mutable struct
		{
			renderer::BufferPtr< uint32_t > indexBuffer;
			renderer::VertexBufferPtr< Vertex > vertexBuffer;
			GeometryBuffersPtr geometryBuffers;
		} m_dummyIndexed;
		mutable renderer::Scissor m_scissor{ 0, 0, 0, 0 };
		mutable renderer::Viewport m_viewport{ 0, 0, 0, 0 };
		mutable renderer::ColourBlendState m_cbState;
		mutable renderer::DepthStencilState m_dsState;
		mutable renderer::MultisampleState m_msState;
		mutable renderer::RasterisationState m_rsState;
		mutable renderer::TessellationState m_tsState;
		mutable renderer::InputAssemblyState m_iaState;
		mutable GLuint m_currentProgram;
		GLuint m_blitFbos[2];
	};
}