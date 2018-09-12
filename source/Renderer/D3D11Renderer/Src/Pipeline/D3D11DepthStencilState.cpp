/*
This file belongs to RendererLib.
See LICENSE file in root folder.
*/
#include "D3D11RendererPrerequisites.hpp"

namespace d3d11_renderer
{
	D3D11_DEPTH_STENCIL_DESC convert( renderer::DepthStencilState const & state )
	{
		return D3D11_DEPTH_STENCIL_DESC
		{
			state.depthTestEnable,
			( state.depthWriteEnable
				? D3D11_DEPTH_WRITE_MASK_ALL
				: D3D11_DEPTH_WRITE_MASK_ZERO ),
			convert( state.depthCompareOp ),
			state.stencilTestEnable,
			UINT8( state.front.compareMask ),
			UINT8( state.front.writeMask ),
			convert( state.front ),
			convert( state.back ),
		};
	}
}
