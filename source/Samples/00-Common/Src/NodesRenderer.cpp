#include "NodesRenderer.hpp"

#include "FileUtils.hpp"
#include "RenderTarget.hpp"
#include "Scene.hpp"

#include <Buffer/Buffer.hpp>
#include <Buffer/StagingBuffer.hpp>
#include <Buffer/VertexBuffer.hpp>
#include <Command/CommandBuffer.hpp>
#include <Command/CommandPool.hpp>
#include <Core/Device.hpp>
#include <Descriptor/DescriptorSet.hpp>
#include <Descriptor/DescriptorSetLayout.hpp>
#include <Descriptor/DescriptorSetLayoutBinding.hpp>
#include <Descriptor/DescriptorSetPool.hpp>
#include <Image/Texture.hpp>
#include <Image/TextureView.hpp>
#include <Miscellaneous/QueryPool.hpp>
#include <Pipeline/DepthStencilState.hpp>
#include <Pipeline/InputAssemblyState.hpp>
#include <Pipeline/MultisampleState.hpp>
#include <Pipeline/Pipeline.hpp>
#include <Pipeline/PipelineLayout.hpp>
#include <Pipeline/Scissor.hpp>
#include <Pipeline/VertexLayout.hpp>
#include <Pipeline/Viewport.hpp>
#include <RenderPass/RenderPass.hpp>
#include <RenderPass/RenderPassCreateInfo.hpp>
#include <RenderPass/RenderSubpass.hpp>
#include <RenderPass/RenderSubpassState.hpp>
#include <RenderPass/FrameBufferAttachment.hpp>
#include <GlslToSpv.hpp>
#include <Sync/ImageMemoryBarrier.hpp>

#include <algorithm>

namespace common
{
	namespace
	{
		std::vector< ashes::ShaderStageState > doCreateObjectProgram( ashes::Device const & device
			, std::string const & fragmentShaderFile )
		{
			std::string shadersFolder = common::getPath( common::getExecutableDirectory() ) / "share" / "Sample-00-Common" / "Shaders";

			if ( !wxFileExists( shadersFolder / "object.vert" )
				|| !wxFileExists( fragmentShaderFile ) )
			{
				throw std::runtime_error{ "Shader files are missing" };
			}

			std::vector< ashes::ShaderStageState > result;
			result.push_back( { device.createShaderModule( ashes::ShaderStageFlag::eVertex ) } );
			result.push_back( { device.createShaderModule( ashes::ShaderStageFlag::eFragment ) } );
			result[0].module->loadShader( dumpShaderFile( device, ashes::ShaderStageFlag::eVertex, shadersFolder / "object.vert" ) );
			result[1].module->loadShader( dumpShaderFile( device, ashes::ShaderStageFlag::eFragment, fragmentShaderFile ) );
			return result;
		}

		std::vector< ashes::ShaderStageState > doCreateBillboardProgram( ashes::Device const & device
			, std::string const & fragmentShaderFile )
		{
			std::string shadersFolder = common::getPath( common::getExecutableDirectory() ) / "share" / "Sample-00-Common" / "Shaders";

			if ( !wxFileExists( shadersFolder / "billboard.vert" )
				|| !wxFileExists( fragmentShaderFile ) )
			{
				throw std::runtime_error{ "Shader files are missing" };
			}

			std::vector< ashes::ShaderStageState > result;
			result.push_back( { device.createShaderModule( ashes::ShaderStageFlag::eVertex ) } );
			result.push_back( { device.createShaderModule( ashes::ShaderStageFlag::eFragment ) } );
			result[0].module->loadShader( dumpShaderFile( device, ashes::ShaderStageFlag::eVertex, shadersFolder / "billboard.vert" ) );
			result[1].module->loadShader( dumpShaderFile( device, ashes::ShaderStageFlag::eFragment, fragmentShaderFile ) );
			return result;
		}

		ashes::RenderPassPtr doCreateRenderPass( ashes::Device const & device
			, std::vector< ashes::Format > const & formats
			, bool clearViews )
		{
			uint32_t index{ 0u };
			ashes::RenderPassCreateInfo renderPass;
			renderPass.subpasses.resize( 1u );

			for ( auto format : formats )
			{
				if ( ashes::isDepthOrStencilFormat( format ) )
				{
					renderPass.attachments.push_back(
					{
						format,
						ashes::SampleCountFlag::e1,
						( clearViews
							? ashes::AttachmentLoadOp::eClear
							: ashes::AttachmentLoadOp::eDontCare ),
						ashes::AttachmentStoreOp::eStore,
						( ( clearViews && ashes::isStencilFormat( format ) )
							? ashes::AttachmentLoadOp::eClear
							: ashes::AttachmentLoadOp::eDontCare ),
						ashes::AttachmentStoreOp::eDontCare,
						ashes::ImageLayout::eUndefined,
						ashes::ImageLayout::eDepthStencilAttachmentOptimal
					} );
					renderPass.subpasses[0].depthStencilAttachment = { index, ashes::ImageLayout::eDepthStencilAttachmentOptimal };
				}
				else
				{
					renderPass.attachments.push_back(
					{
						format,
						ashes::SampleCountFlag::e1,
						( clearViews
							? ashes::AttachmentLoadOp::eClear
							: ashes::AttachmentLoadOp::eDontCare ),
						ashes::AttachmentStoreOp::eStore,
						ashes::AttachmentLoadOp::eDontCare,
						ashes::AttachmentStoreOp::eDontCare,
						ashes::ImageLayout::eUndefined,
						( clearViews
							? ashes::ImageLayout::eColourAttachmentOptimal
							: ashes::ImageLayout::eShaderReadOnlyOptimal )
					} );
					renderPass.subpasses[0].colorAttachments.emplace_back( ashes::AttachmentReference{ index, ashes::ImageLayout::eColourAttachmentOptimal } );
				}

				++index;
			}

			renderPass.dependencies.resize( 2u );
			renderPass.dependencies[0].srcSubpass = ashes::ExternalSubpass;
			renderPass.dependencies[0].dstSubpass = 0u;
			renderPass.dependencies[0].srcStageMask = ashes::PipelineStageFlag::eFragmentShader;
			renderPass.dependencies[0].dstStageMask = ashes::PipelineStageFlag::eColourAttachmentOutput;
			renderPass.dependencies[0].srcAccessMask = ashes::AccessFlag::eShaderRead;
			renderPass.dependencies[0].dstAccessMask = ashes::AccessFlag::eColourAttachmentWrite;
			renderPass.dependencies[0].dependencyFlags = ashes::DependencyFlag::eByRegion;

			renderPass.dependencies[1].srcSubpass = 0u;
			renderPass.dependencies[1].dstSubpass = ashes::ExternalSubpass;
			renderPass.dependencies[1].srcStageMask = ashes::PipelineStageFlag::eColourAttachmentOutput;
			renderPass.dependencies[1].dstStageMask = ashes::PipelineStageFlag::eFragmentShader;
			renderPass.dependencies[1].srcAccessMask = ashes::AccessFlag::eColourAttachmentWrite;
			renderPass.dependencies[1].dstAccessMask = ashes::AccessFlag::eShaderRead;
			renderPass.dependencies[1].dependencyFlags = ashes::DependencyFlag::eByRegion;

			return device.createRenderPass( renderPass );
		}

		ashes::FrameBufferPtr doCreateFrameBuffer( ashes::RenderPass const & renderPass
			, ashes::TextureViewCRefArray const & views )
		{
			assert( !views.empty() );
			assert( views.size() == renderPass.getAttachmentCount() );
			ashes::FrameBufferAttachmentArray attaches;
			auto it = renderPass.getAttachments().begin();

			for ( auto view : views )
			{
				attaches.emplace_back( *it, view.get() );
				++it;
			}

			auto dimensions = views[0].get().getTexture().getDimensions();
			return renderPass.createFrameBuffer( ashes::Extent2D{ dimensions.width, dimensions.height }
			, std::move( attaches ) );
		}

		ashes::UniformBufferPtr< common::MaterialData > doCreateMaterialsUbo( ashes::Device const & device
			, Scene const & scene
			, bool m_opaqueNodes
			, uint32_t & objectsCount
			, uint32_t & billboardsCount )
		{
			objectsCount = 0u;
			billboardsCount = 0u;

			for ( auto & submesh : scene.object )
			{
				objectsCount += std::count_if( submesh.materials.begin()
					, submesh.materials.end()
					, [&m_opaqueNodes]( common::Material const & lookup )
				{
					return lookup.hasOpacity == !m_opaqueNodes;
				} );
			}

			if ( !scene.billboard.list.empty()
				&& scene.billboard.material.hasOpacity != m_opaqueNodes )
			{
				++billboardsCount;
			}

			ashes::UniformBufferPtr< common::MaterialData > result;

			if ( objectsCount + billboardsCount )
			{
				result = std::make_unique< ashes::UniformBuffer< common::MaterialData > >( device
					, objectsCount + billboardsCount
					, ashes::BufferTarget::eTransferDst
					, ashes::MemoryPropertyFlag::eDeviceLocal );
			}

			return result;
		}
	}

	NodesRenderer::NodesRenderer( ashes::Device const & device
		, std::string const & fragmentShaderFile
		, std::vector< ashes::Format > const & formats
		, bool clearViews
		, bool opaqueNodes )
		: m_device{ device }
		, m_opaqueNodes{ opaqueNodes }
		, m_fragmentShaderFile{ fragmentShaderFile }
		, m_sampler{ m_device.createSampler( ashes::WrapMode::eClampToEdge
			, ashes::WrapMode::eClampToEdge
			, ashes::WrapMode::eClampToEdge
			, ashes::Filter::eLinear
			, ashes::Filter::eLinear ) }
		, m_updateCommandBuffer{ m_device.getGraphicsCommandPool().createCommandBuffer() }
		, m_commandBuffer{ m_device.getGraphicsCommandPool().createCommandBuffer() }
		, m_renderPass{ doCreateRenderPass( m_device, formats, clearViews ) }
		, m_queryPool{ m_device.createQueryPool( ashes::QueryType::eTimestamp, 2u, 0u ) }
	{
	}

	void NodesRenderer::update( RenderTarget const & target )
	{
		doUpdate( { target.getDepthView(), target.getColourView() } );
	}

	void NodesRenderer::draw( std::chrono::nanoseconds & gpu )const
	{
		m_device.getGraphicsQueue().submit( *m_commandBuffer, nullptr );
		ashes::UInt64Array values{ 0u, 0u };
		m_queryPool->getResults( 0u
			, 2u
			, 0u
			, ashes::QueryResultFlag::eWait
			, values );
		gpu = std::chrono::nanoseconds{ uint64_t( ( values[1] - values[0] ) / float( m_device.getTimestampPeriod() ) ) };
	}

	void NodesRenderer::initialise( Scene const & scene
		, ashes::StagingBuffer & stagingBuffer
		, ashes::TextureViewCRefArray const & views
		, common::TextureNodePtrArray const & textureNodes )
	{
		m_materialsUbo = doCreateMaterialsUbo( m_device
			, scene
			, m_opaqueNodes
			, m_objectsCount
			, m_billboardsCount );

		uint32_t matIndex = 0u;
		doInitialiseObject( scene.object
			, stagingBuffer
			, textureNodes
			, matIndex );
		doInitialiseBillboard( scene.billboard
			, stagingBuffer
			, textureNodes
			, matIndex );

		if ( m_objectsCount || m_billboardsCount )
		{
			stagingBuffer.uploadUniformData( *m_updateCommandBuffer
				, m_materialsUbo->getDatas()
				, *m_materialsUbo
				, ashes::PipelineStageFlag::eFragmentShader );
		}

		doUpdate( views );
	}

	void NodesRenderer::doUpdate( ashes::TextureViewCRefArray const & views )
	{
		assert( !views.empty() );
		auto dimensions = views[0].get().getTexture().getDimensions();
		auto size = ashes::Extent2D{ dimensions.width, dimensions.height };

		if ( size != m_size )
		{
			m_size = size;
			m_views.clear();
			static ashes::ClearColorValue const colour{ 1.0f, 0.8f, 0.4f, 0.0f };
			static ashes::DepthStencilClearValue const depth{ 1.0, 0 };
			ashes::ClearValueArray clearValues;

			for ( auto & view : views )
			{
				m_views.push_back( &view.get() );

				if ( !ashes::isDepthOrStencilFormat( view.get().getFormat() ) )
				{
					clearValues.emplace_back( colour );
				}
				else
				{
					clearValues.emplace_back( depth );
				}
			}

			m_frameBuffer = doCreateFrameBuffer( *m_renderPass, views );
			m_commandBuffer->reset();
			auto & commandBuffer = *m_commandBuffer;

			commandBuffer.begin( ashes::CommandBufferUsageFlag::eSimultaneousUse );
			commandBuffer.resetQueryPool( *m_queryPool, 0u, 2u );
			commandBuffer.writeTimestamp( ashes::PipelineStageFlag::eTopOfPipe
				, *m_queryPool
				, 0u );
			commandBuffer.beginRenderPass( *m_renderPass
				, *m_frameBuffer
				, clearValues
				, ashes::SubpassContents::eInline );

			for ( auto & node : m_submeshRenderNodes )
			{
				commandBuffer.bindPipeline( *node.pipeline );
				commandBuffer.setViewport( { size.width
					, size.height
					, 0
					, 0 } );
				commandBuffer.setScissor( { 0
					, 0
					, size.width
					, size.height } );
				m_commandBuffer->bindVertexBuffer( 0u, node.instance->vbo->getBuffer(), 0u );
				m_commandBuffer->bindIndexBuffer( node.instance->ibo->getBuffer(), 0u, ashes::IndexType::eUInt32 );
				commandBuffer.bindDescriptorSet( *node.descriptorSetUbos
					, *node.pipelineLayout );
				commandBuffer.bindDescriptorSet( *node.descriptorSetTextures
					, *node.pipelineLayout );
				commandBuffer.drawIndexed( node.instance->ibo->getCount() * 3u );
			}

			for ( BillboardMaterialNode & node : m_billboardRenderNodes )
			{
				commandBuffer.bindPipeline( *node.pipeline );
				commandBuffer.setViewport( { size.width
					, size.height
					, 0
					, 0 } );
				commandBuffer.setScissor( { 0
					, 0
					, size.width
					, size.height } );
				m_commandBuffer->bindVertexBuffers( 0u
					, { node.instance->vbo->getBuffer(), node.instance->instance->getBuffer() }
					, { 0u, 0u } );
				commandBuffer.bindDescriptorSet( *node.descriptorSetUbos
					, *node.pipelineLayout );
				commandBuffer.bindDescriptorSet( *node.descriptorSetTextures
					, *node.pipelineLayout );
				commandBuffer.draw( 4u, node.instance->instance->getCount() );
			}

			commandBuffer.endRenderPass();
			commandBuffer.writeTimestamp( ashes::PipelineStageFlag::eBottomOfPipe
				, *m_queryPool
				, 1u );
			commandBuffer.end();
		}
	}

	void NodesRenderer::doInitialiseBillboard( Billboard const & billboard
		, ashes::StagingBuffer & stagingBuffer
		, TextureNodePtrArray const & textureNodes
		, uint32_t & matIndex )
	{
		if ( !billboard.list.empty() )
		{
			std::vector< ashes::DescriptorSetLayoutBinding > bindings
			{
				ashes::DescriptorSetLayoutBinding{ 0u, ashes::DescriptorType::eUniformBuffer, ashes::ShaderStageFlag::eFragment },
			};
			doFillBillboardDescriptorLayoutBindings( bindings );
			m_billboardDescriptorLayout = m_device.createDescriptorSetLayout( std::move( bindings ) );
			m_billboardDescriptorPool = m_billboardDescriptorLayout->createPool( m_billboardsCount );

			// Initialise vertex layout.
			m_billboardVertexLayout = ashes::makeLayout< Vertex >( 0u, ashes::VertexInputRate::eVertex );
			m_billboardVertexLayout->createAttribute( 0u
				, ashes::Format::eR32G32B32_SFLOAT
				, offsetof( Vertex, position ) );
			m_billboardVertexLayout->createAttribute( 1u
				, ashes::Format::eR32G32B32_SFLOAT
				, offsetof( Vertex, normal ) );
			m_billboardVertexLayout->createAttribute( 2u
				, ashes::Format::eR32G32B32_SFLOAT
				, offsetof( Vertex, tangent ) );
			m_billboardVertexLayout->createAttribute( 3u
				, ashes::Format::eR32G32B32_SFLOAT
				, offsetof( Vertex, bitangent ) );
			m_billboardVertexLayout->createAttribute( 4u
				, ashes::Format::eR32G32_SFLOAT
				, offsetof( Vertex, texture ) );
			// Initialise instance layout.
			m_billboardInstanceLayout = ashes::makeLayout< BillboardInstanceData >( 1u, ashes::VertexInputRate::eInstance );
			m_billboardInstanceLayout->createAttribute( 5u
				, ashes::Format::eR32G32B32_SFLOAT
				, offsetof( BillboardInstanceData, offset ) );
			m_billboardInstanceLayout->createAttribute( 6u
				, ashes::Format::eR32G32_SFLOAT
				, offsetof( BillboardInstanceData, dimensions ) );

			if ( billboard.material.hasOpacity == !m_opaqueNodes )
			{
				std::vector< Vertex > vertexData
				{
					{ { 0.0, 0.0, 0.0 }, { 0.0, 0.0, -1.0 }, { 1.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0 }, { -0.5, -0.5 } },
					{ { 0.0, 0.0, 0.0 }, { 0.0, 0.0, -1.0 }, { 1.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0 }, { -0.5, +0.5 } },
					{ { 0.0, 0.0, 0.0 }, { 0.0, 0.0, -1.0 }, { 1.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0 }, { +0.5, -0.5 } },
					{ { 0.0, 0.0, 0.0 }, { 0.0, 0.0, -1.0 }, { 1.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0 }, { +0.5, +0.5 } },
				};
				m_billboardNodes.push_back( std::make_shared< BillboardNode >() );
				BillboardNodePtr billboardNode = m_billboardNodes.back();

				// Initialise geometry buffers.
				billboardNode->vbo = ashes::makeVertexBuffer< Vertex >( m_device
					, uint32_t( vertexData.size() )
					, ashes::BufferTarget::eTransferDst
					, ashes::MemoryPropertyFlag::eDeviceLocal );
				stagingBuffer.uploadVertexData( *m_updateCommandBuffer
					, vertexData
					, *billboardNode->vbo );
				billboardNode->instance = ashes::makeVertexBuffer< BillboardInstanceData >( m_device
					, uint32_t( billboard.list.size() )
					, ashes::BufferTarget::eTransferDst
					, ashes::MemoryPropertyFlag::eDeviceLocal );
				stagingBuffer.uploadVertexData( *m_updateCommandBuffer
					, billboard.list
					, *billboardNode->instance );

				auto & material = billboard.material;
				BillboardMaterialNode materialNode{ billboardNode };

				// Initialise material textures.
				for ( uint32_t index = 0u; index < material.data.texturesCount; ++index )
				{
					auto & texture = material.textures[index];
					auto it = std::find_if( textureNodes.begin()
						, textureNodes.end()
						, [&texture]( TextureNodePtr const & lookup )
					{
						return lookup->image == texture;
					} );
					assert( it != textureNodes.end() );
					materialNode.textures.push_back( *it );
				}

				m_materialsUbo->getData( matIndex ) = material.data;

				// Initialise descriptor set for UBOs
				materialNode.descriptorSetUbos = m_billboardDescriptorPool->createDescriptorSet( 0u );
				materialNode.descriptorSetUbos->createBinding( m_billboardDescriptorLayout->getBinding( 0u )
					, *m_materialsUbo
					, matIndex
					, 1u );
				doFillBillboardDescriptorSet( *m_billboardDescriptorLayout, *materialNode.descriptorSetUbos );
				materialNode.descriptorSetUbos->update();

				// Initialise descriptor set for textures.
				ashes::DescriptorSetLayoutBindingArray bindings;
				bindings.emplace_back( 0u, ashes::DescriptorType::eCombinedImageSampler, ashes::ShaderStageFlag::eFragment, 6u );
				materialNode.layout = m_device.createDescriptorSetLayout( std::move( bindings ) );
				materialNode.pool = materialNode.layout->createPool( 1u );
				materialNode.descriptorSetTextures = materialNode.pool->createDescriptorSet( 1u );

				for ( uint32_t index = 0u; index < material.data.texturesCount; ++index )
				{
					materialNode.descriptorSetTextures->createBinding( materialNode.layout->getBinding( 0u, index )
						, *materialNode.textures[index]->view
						, *m_sampler
						, ashes::ImageLayout::eShaderReadOnlyOptimal
						, index );
				}

				materialNode.descriptorSetTextures->update();
				ashes::RasterisationState rasterisationState;
				rasterisationState.cullMode = ashes::CullModeFlag::eNone;

				// Initialise the pipeline
				if ( materialNode.layout )
				{
					materialNode.pipelineLayout = m_device.createPipelineLayout( { *m_billboardDescriptorLayout, *materialNode.layout } );
				}
				else
				{
					materialNode.pipelineLayout = m_device.createPipelineLayout( *m_billboardDescriptorLayout );
				}

				ashes::ColourBlendState blendState;

				for ( auto & attach : m_renderPass->getAttachments() )
				{
					if ( !ashes::isDepthOrStencilFormat( attach.format ) )
					{
						blendState.attachs.push_back( ashes::ColourBlendStateAttachment{} );
					}
				}

				std::vector< ashes::DynamicState > dynamicStateEnables
				{
					ashes::DynamicState::eViewport,
					ashes::DynamicState::eScissor
				};

				materialNode.pipeline = materialNode.pipelineLayout->createPipeline( 
				{
					doCreateBillboardProgram( m_device, m_fragmentShaderFile ),
					*m_renderPass,
					ashes::VertexInputState::create( { *m_billboardVertexLayout, *m_billboardInstanceLayout } ),
					{ ashes::PrimitiveTopology::eTriangleStrip },
					rasterisationState,
					ashes::MultisampleState{},
					blendState,
					dynamicStateEnables,
					ashes::DepthStencilState{}
				} );
				m_billboardRenderNodes.emplace_back( std::move( materialNode ) );
				++matIndex;
			}
		}
	}

	void NodesRenderer::doInitialiseObject( Object const & object
		, ashes::StagingBuffer & stagingBuffer
		, common::TextureNodePtrArray const & textureNodes
		, uint32_t & matIndex )
	{
		std::vector< ashes::DescriptorSetLayoutBinding > bindings
		{
			ashes::DescriptorSetLayoutBinding{ 0u, ashes::DescriptorType::eUniformBuffer, ashes::ShaderStageFlag::eFragment },
		};
		doFillObjectDescriptorLayoutBindings( bindings );
		m_objectDescriptorLayout = m_device.createDescriptorSetLayout( std::move( bindings ) );
		m_objectDescriptorPool = m_objectDescriptorLayout->createPool( m_objectsCount );

		// Initialise vertex layout.
		m_objectVertexLayout = ashes::makeLayout< Vertex >( 0u );
		m_objectVertexLayout->createAttribute( 0u
			, ashes::Format::eR32G32B32_SFLOAT
			, offsetof( common::Vertex, position ) );
		m_objectVertexLayout->createAttribute( 1u
			, ashes::Format::eR32G32B32_SFLOAT
			, offsetof( common::Vertex, normal ) );
		m_objectVertexLayout->createAttribute( 2u
			, ashes::Format::eR32G32B32_SFLOAT
			, offsetof( common::Vertex, tangent ) );
		m_objectVertexLayout->createAttribute( 3u
			, ashes::Format::eR32G32B32_SFLOAT
			, offsetof( common::Vertex, bitangent ) );
		m_objectVertexLayout->createAttribute( 4u
			, ashes::Format::eR32G32_SFLOAT
			, offsetof( common::Vertex, texture ) );

		for ( auto & submesh : object )
		{
			std::vector< Material > compatibleMaterials;

			for ( auto & material : submesh.materials )
			{
				if ( material.hasOpacity == !m_opaqueNodes )
				{
					compatibleMaterials.push_back( material );
				}
			}

			if ( !compatibleMaterials.empty() )
			{
				m_submeshNodes.push_back( std::make_shared< common::SubmeshNode >() );
				common::SubmeshNodePtr submeshNode = m_submeshNodes.back();

				// Initialise geometry buffers.
				submeshNode->vbo = ashes::makeVertexBuffer< common::Vertex >( m_device
					, uint32_t( submesh.vbo.data.size() )
					, ashes::BufferTarget::eTransferDst
					, ashes::MemoryPropertyFlag::eDeviceLocal );
				stagingBuffer.uploadVertexData( *m_updateCommandBuffer
					, submesh.vbo.data
					, *submeshNode->vbo );
				submeshNode->ibo = ashes::makeBuffer< common::Face >( m_device
					, uint32_t( submesh.ibo.data.size() )
					, ashes::BufferTarget::eIndexBuffer | ashes::BufferTarget::eTransferDst
					, ashes::MemoryPropertyFlag::eDeviceLocal );
				stagingBuffer.uploadBufferData( *m_updateCommandBuffer
					, submesh.ibo.data
					, *submeshNode->ibo );

				for ( auto & material : compatibleMaterials )
				{
					common::SubmeshMaterialNode materialNode{ submeshNode };

					// Initialise material textures.
					for ( uint32_t index = 0u; index < material.data.texturesCount; ++index )
					{
						auto & texture = material.textures[index];
						auto it = std::find_if( textureNodes.begin()
							, textureNodes.end()
							, [&texture]( common::TextureNodePtr const & lookup )
							{
								return lookup->image == texture;
							} );
						assert( it != textureNodes.end() );
						materialNode.textures.push_back( *it );
					}

					m_materialsUbo->getData( matIndex ) = material.data;

					// Initialise descriptor set for UBOs
					materialNode.descriptorSetUbos = m_objectDescriptorPool->createDescriptorSet( 0u );
					materialNode.descriptorSetUbos->createBinding( m_objectDescriptorLayout->getBinding( 0u )
						, *m_materialsUbo
						, matIndex
						, 1u );
					doFillObjectDescriptorSet( *m_objectDescriptorLayout, *materialNode.descriptorSetUbos );
					materialNode.descriptorSetUbos->update();

					// Initialise descriptor set for textures.
					ashes::DescriptorSetLayoutBindingArray bindings;
					bindings.emplace_back( 0u, ashes::DescriptorType::eCombinedImageSampler, ashes::ShaderStageFlag::eFragment, 6u );
					materialNode.layout = m_device.createDescriptorSetLayout( std::move( bindings ) );
					materialNode.pool = materialNode.layout->createPool( 1u );
					materialNode.descriptorSetTextures = materialNode.pool->createDescriptorSet( 1u );

					for ( uint32_t index = 0u; index < material.data.texturesCount; ++index )
					{
						materialNode.descriptorSetTextures->createBinding( materialNode.layout->getBinding( 0u, index )
							, *materialNode.textures[index]->view
							, *m_sampler
							, ashes::ImageLayout::eShaderReadOnlyOptimal
							, index );
					}

					materialNode.descriptorSetTextures->update();
					ashes::RasterisationState rasterisationState;

					if ( material.data.backFace )
					{
						rasterisationState.cullMode = ashes::CullModeFlag::eFront;
					}

					// Initialise the pipeline
					if ( materialNode.layout )
					{
						materialNode.pipelineLayout = m_device.createPipelineLayout( { *m_objectDescriptorLayout, *materialNode.layout } );
					}
					else
					{
						materialNode.pipelineLayout = m_device.createPipelineLayout( *m_objectDescriptorLayout );
					}

					ashes::ColourBlendState blendState;

					for ( auto & attach : m_renderPass->getAttachments() )
					{
						if ( !ashes::isDepthOrStencilFormat( attach.format ) )
						{
							blendState.attachs.push_back( ashes::ColourBlendStateAttachment{} );
						}
					}

					std::vector< ashes::DynamicState > dynamicStateEnables
					{
						ashes::DynamicState::eViewport,
						ashes::DynamicState::eScissor
					};

					materialNode.pipeline = materialNode.pipelineLayout->createPipeline(
					{
						doCreateObjectProgram( m_device, m_fragmentShaderFile ),
						*m_renderPass,
						ashes::VertexInputState::create( *m_objectVertexLayout ),
						{ ashes::PrimitiveTopology::eTriangleList },
						rasterisationState,
						ashes::MultisampleState{},
						blendState,
						dynamicStateEnables,
						ashes::DepthStencilState{}
					} );
					m_submeshRenderNodes.emplace_back( std::move( materialNode ) );
					++matIndex;
				}
			}
		}
	}
}
