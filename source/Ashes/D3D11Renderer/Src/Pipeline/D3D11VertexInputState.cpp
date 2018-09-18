#include "Pipeline/D3D11VertexInputState.hpp"

namespace d3d11_renderer
{
	std::vector< D3D11_INPUT_ELEMENT_DESC > convert( ashes::VertexInputState const & state
		, InputLayout const & inputLayout )
	{
		static uint32_t id = 0u;
		std::vector< D3D11_INPUT_ELEMENT_DESC > result;
		UINT index = 0u;

		for ( auto attribute : state.vertexAttributeDescriptions )
		{
			auto & binding = state.vertexBindingDescriptions[attribute.binding];
			auto it = std::find_if( inputLayout.begin()
				, inputLayout.end()
				, [attribute]( InputElementDesc const & desc )
				{
					return attribute.location == desc.BaseSemanticIndex;
				} );

			if ( it != inputLayout.end() )
			{
				auto & inputDesc = *it;
				result.push_back( D3D11_INPUT_ELEMENT_DESC
					{
						inputDesc.SemanticName.c_str(),
						inputDesc.SemanticIndex,
						getBufferFormat( attribute.format ),
						attribute.binding,
						attribute.offset,
						convert( binding.inputRate ),
						( binding.inputRate == ashes::VertexInputRate::eInstance
							? 1u
							: 0u )
					} );
			}
		}

		return result;
	}
}
