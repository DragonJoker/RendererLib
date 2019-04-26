#include "Pipeline/D3D11Pipeline.hpp"

#include "Core/D3D11Device.hpp"
#include "Pipeline/D3D11VertexInputState.hpp"
#include "Shader/D3D11ShaderModule.hpp"

#include "ashesd3d11_api.hpp"

namespace ashes::d3d11
{
	namespace
	{
		template<typename T>
		void doHashCombine( size_t & seed, T const & v )
		{
			const uint64_t kMul = 0x9ddfea08eb382d69ULL;

			std::hash< T > hasher;
			uint64_t a = ( hasher( v ) ^ seed ) * kMul;
			a ^= ( a >> 47 );

			uint64_t b = ( seed ^ a ) * kMul;
			b ^= ( b >> 47 );

			seed = static_cast< std::size_t >( b * kMul );
		}

		size_t doHash( VkVertexInputAttributeDescription const & desc )
		{
			size_t result = 0u;
			doHashCombine( result, desc.binding );
			doHashCombine( result, desc.format );
			doHashCombine( result, desc.location );
			doHashCombine( result, desc.offset );
			return result;
		}

		size_t doHash( VkVertexInputBindingDescription const & desc )
		{
			size_t result = 0u;
			doHashCombine( result, desc.binding );
			doHashCombine( result, desc.inputRate );
			doHashCombine( result, desc.stride );
			return result;
		}

		size_t doHash( VkPipelineVertexInputStateCreateInfo const & state )
		{
			size_t result = 0u;

			for ( auto & desc : makeArrayView( state.pVertexAttributeDescriptions, state.vertexAttributeDescriptionCount ) )
			{
				doHashCombine( result, doHash( desc ) );
			}

			for ( auto & desc : makeArrayView( state.pVertexBindingDescriptions, state.vertexBindingDescriptionCount ) )
			{
				doHashCombine( result, doHash( desc ) );
			}

			return result;
		}
	}

	Pipeline::Pipeline( VkDevice device
		, VkGraphicsPipelineCreateInfo createInfo )
		: m_device{ device }
		, m_layout{ createInfo.layout }
		, m_graphicsCreateInfo{ std::move( createInfo ) }
		, m_scissors{ makeScissors( m_graphicsCreateInfo.pViewportState->pScissors, m_graphicsCreateInfo.pViewportState->scissorCount ) }
		, m_viewports{ makeViewports( m_graphicsCreateInfo.pViewportState->pViewports, m_graphicsCreateInfo.pViewportState->viewportCount ) }
		, m_vertexInputStateHash{ doHash( *m_graphicsCreateInfo.pVertexInputState ) }
	{
		doCreateBlendState( device );
		doCreateRasterizerState( device );
		doCreateDepthStencilState( device );
		doCompileProgram( device, { m_graphicsCreateInfo.pStages, m_graphicsCreateInfo.pStages + m_graphicsCreateInfo.stageCount } );
		doCreateInputLayout( device );
	}

	Pipeline::Pipeline( VkDevice device
		, VkComputePipelineCreateInfo createInfo )
		: m_device{ device }
		, m_layout{ createInfo.layout }
		, m_computeCreateInfo{ std::move( createInfo ) }
	{
		doCompileProgram( device, { createInfo.stage } );
	}

	PushConstantsBuffer Pipeline::findPushConstantBuffer( PushConstantsDesc const & pushConstants )const
	{
		// Try to find a PCB that has the same flags, and the same size as the push constants.
		auto it = std::find_if( m_constantsPcbs.begin()
			, m_constantsPcbs.end()
			, [&pushConstants]( PushConstantsBuffer const & lookup )
			{
				return lookup.data.stageFlags == pushConstants.stageFlags
					&& lookup.data.size == pushConstants.offset + pushConstants.size;
			} );

		if ( it == m_constantsPcbs.end() )
		{
			// Try a PCB that has the same flags, but is larger than the push constants.
			it = std::find_if( m_constantsPcbs.begin()
				, m_constantsPcbs.end()
				, [&pushConstants]( PushConstantsBuffer const & lookup )
				{
					return lookup.data.stageFlags == pushConstants.stageFlags
						&& lookup.data.size > pushConstants.offset + pushConstants.size;
				} );
		}

		if ( it == m_constantsPcbs.end() )
		{
			// Try a PCB that contains the flags of the push constants.
			it = std::find_if( m_constantsPcbs.begin()
				, m_constantsPcbs.end()
				, [&pushConstants]( PushConstantsBuffer const & lookup )
				{
					return checkFlag( lookup.data.stageFlags, pushConstants.stageFlags )
						&& lookup.data.size == pushConstants.offset + pushConstants.size;
				} );
		}

		if ( it == m_constantsPcbs.end() )
		{
			// Try a PCB that contains the flags of the push constants, and is larger than them.
			it = std::find_if( m_constantsPcbs.begin()
				, m_constantsPcbs.end()
				, [&pushConstants]( PushConstantsBuffer const & lookup )
				{
					return checkFlag( lookup.data.stageFlags, pushConstants.stageFlags )
						&& lookup.data.size > pushConstants.offset + pushConstants.size;
				} );
		}

		if ( it != m_constantsPcbs.end() )
		{
			return PushConstantsBuffer
			{
				it->ubo,
				it->location,
				pushConstants
			};
		}

		static PushConstantsBuffer const dummy{};
		return dummy;
	}

	void Pipeline::doCreateBlendState( VkDevice device )
	{
		auto d3ddevice = get( device )->getDevice();
		auto blendDesc = convert( *m_graphicsCreateInfo.pColorBlendState );
		HRESULT hr = d3ddevice->CreateBlendState( &blendDesc, &m_bdState );

		if ( !checkError( device, hr, "CreateBlendState" ) )
		{
			throw std::runtime_error( "CreateBlendState() failed" );
		}

		dxDebugName( m_bdState, PipelineBlendState );
	}

	void Pipeline::doCreateRasterizerState( VkDevice device )
	{
		auto d3ddevice = get( device )->getDevice();
		auto rasterizerDesc = convert( *m_graphicsCreateInfo.pRasterizationState
			, *m_graphicsCreateInfo.pMultisampleState );
		auto hr = d3ddevice->CreateRasterizerState( &rasterizerDesc, &m_rsState );

		if ( !checkError( device, hr, "CreateRasterizerState" ) )
		{
			throw std::runtime_error( "CreateRasterizerState() failed" );
		}

		dxDebugName( m_rsState, PipelineRasterizerState );
	}

	void Pipeline::doCreateDepthStencilState( VkDevice device )
	{
		if ( m_graphicsCreateInfo.pDepthStencilState )
		{
			auto d3ddevice = get( device )->getDevice();
			auto depthStencilDesc = convert( *m_graphicsCreateInfo.pDepthStencilState );
			auto hr = d3ddevice->CreateDepthStencilState( &depthStencilDesc, &m_dsState );

			if ( !checkError( device, hr, "CreateDepthStencilState" ) )
			{
				throw std::runtime_error( "CreateDepthStencilState() failed" );
			}

			dxDebugName( m_dsState, PipelineDepthStencilState );
		}
	}

	void Pipeline::doCompileProgram( VkDevice device
		, VkPipelineShaderStageCreateInfoArray const & stages )
	{
		for ( auto & state : stages )
		{
			auto module = get( state.module );
			m_programModules.push_back( module->compile( state ) );
			m_programLayout.emplace( state.stage, m_programModules.back().getLayout() );
		}

		for ( auto & shaderLayoutIt : m_programLayout )
		{
			for ( auto & blockLayout : shaderLayoutIt.second.interfaceBlockLayout )
			{
				PushConstantsBuffer pcb
				{
					VK_NULL_HANDLE,
					blockLayout.binding,
				{
					VkShaderStageFlags( shaderLayoutIt.first ),
					0u,
					blockLayout.size
				},
					VK_NULL_HANDLE,
				};
				allocate( pcb.ubo
					, nullptr
					, device
					, VkBufferCreateInfo
					{
						VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
						nullptr,
						0u,
						blockLayout.size,
						VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT,
						VK_SHARING_MODE_EXCLUSIVE,
						0u,
						nullptr,
					} );
				auto requirements = get( pcb.ubo )->getMemoryRequirements();
				auto deduced = deduceMemoryType( requirements.memoryTypeBits
					, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT );
				allocate( pcb.memory
					, nullptr
					, m_device
					, VkMemoryAllocateInfo
					{
						VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
						nullptr,
						requirements.size,
						deduced
					} );
				get( pcb.ubo )->bindMemory( pcb.memory, 0u );
				m_constantsPcbs.push_back( std::move( pcb ) );
			}
		}
	}

	void Pipeline::doCreateInputLayout( VkDevice device )
	{
		auto it = m_programLayout.find( VK_SHADER_STAGE_VERTEX_BIT );

		if ( it != m_programLayout.end() )
		{
			auto compiled = it->second.module->getCompiled();
			auto & inputLayout = it->second.inputLayout;
			auto d3ddevice = get( device )->getDevice();
			auto inputDesc = convert( *m_graphicsCreateInfo.pVertexInputState, inputLayout );

			if ( !inputDesc.empty() )
			{
				auto hr = d3ddevice->CreateInputLayout( inputDesc.data()
					, UINT( inputDesc.size() )
					, compiled->GetBufferPointer()
					, compiled->GetBufferSize()
					, &m_iaState );

				if ( !checkError( device, hr, "CreateInputLayout" ) )
				{
					throw std::runtime_error( "CreateInputLayout() failed" );
				}

				dxDebugName( m_iaState, PipelineInputLayout );
			}
		}
	}

	Pipeline::~Pipeline()
	{
		for ( auto & pcb : m_constantsPcbs )
		{
			deallocate( pcb.memory, nullptr );
			deallocate( pcb.ubo, nullptr );
		}

		safeRelease( m_bdState );
		safeRelease( m_rsState );
		safeRelease( m_iaState );
		safeRelease( m_dsState );
	}
}
