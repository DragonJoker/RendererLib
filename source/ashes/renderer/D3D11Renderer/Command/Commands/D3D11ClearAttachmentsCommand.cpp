/*
This file belongs to GlInstance.
See LICENSE file in root folder.
*/
#include "Command/Commands/D3D11ClearAttachmentsCommand.hpp"

#include "Core/D3D11Device.hpp"
#include "Image/D3D11ImageView.hpp"
#include "RenderPass/D3D11FrameBuffer.hpp"

#include <Ashes/RenderPass/RenderSubpass.hpp>

namespace ashes::d3d11
{
	namespace
	{
		void doClear( Context const & context
			, ClearAttachmentView const & clearAttach )
		{
			if ( ashes::checkFlag( clearAttach.clear.aspectMask, VK_IMAGE_ASPECT_COLOR_BIT ) )
			{
				assert( clearAttach.clear.clearValue.isColour() );
				auto & colour = clearAttach.clear.clearValue.colour();
				context.context->ClearRenderTargetView( reinterpret_cast< ID3D11RenderTargetView * >( clearAttach.view )
					, colour.float32.data() );
			}
			else
			{
				assert( !clearAttach.clear.clearValue.isColour() );
				auto & depthStencil = clearAttach.clear.clearValue.depthStencil();
				UINT flags = ( ashes::checkFlag( clearAttach.clear.aspectMask, VK_IMAGE_ASPECT_DEPTH_BIT )
						? D3D11_CLEAR_DEPTH
						: 0u )
					| ( ashes::checkFlag( clearAttach.clear.aspectMask, VK_IMAGE_ASPECT_STENCIL_BIT )
						? D3D11_CLEAR_STENCIL
						: 0u );
				context.context->ClearDepthStencilView( reinterpret_cast< ID3D11DepthStencilView * >( clearAttach.view )
					, flags
					, depthStencil.depth
					, depthStencil.stencil );
			}
		}

	}

	ClearAttachmentsCommand::ClearAttachmentsCommand( VkDevice device
		, RenderPass const & renderPass
		, ashes::SubpassDescription const & subpass
		, FrameBuffer const & framebuffer
		, ashes::ClearAttachmentArray const & clearAttaches
		, ashes::ClearRectArray const & clearRects )
		: CommandBase{ device }
		, m_clearRects{ clearRects }
	{
		for ( auto & attach : clearAttaches )
		{
			if ( checkFlag( attach.aspectMask, VK_IMAGE_ASPECT_COLOR_BIT ) )
			{
				auto ref = subpass.colorAttachments[attach.colourAttachment];
				m_clearViews.push_back( { attach, framebuffer.getAllViews()[ref.attachment] } );
			}
			else if ( attach.aspectMask )
			{
				m_clearViews.push_back( { attach, framebuffer.getDSView() } );
			}
		}
	}

	void ClearAttachmentsCommand::apply( Context const & context )const
	{
		for ( auto & clearAttach : m_clearViews )
		{
			for ( auto & rect : m_clearRects )
			{
				D3D11_RECT scissor
				{
					LONG( rect.offset.x ),
					LONG( rect.offset.y ),
					LONG( rect.extent.width ),
					LONG( rect.extent.height ),
				};
				context.context->RSSetScissorRects( 1u, &scissor );
				doClear( context, clearAttach );
			}
		}
	}

	CommandPtr ClearAttachmentsCommand::clone()const
	{
		return std::make_unique< ClearAttachmentsCommand >( *this );
	}
}
