/*
This file belongs to GlRenderer.
See LICENSE file in root folder.
*/
#include "GlClearAttachmentsCommand.hpp"

#include "Core/GlDevice.hpp"
#include "Image/GlTextureView.hpp"

namespace gl_renderer
{
	namespace
	{
		void doClear( Device const & device
			, renderer::ClearAttachment const & clearAttach )
		{
			if ( renderer::checkFlag( clearAttach.aspectMask, renderer::ImageAspectFlag::eColour ) )
			{
				assert( clearAttach.clearValue.isColour() );
				auto & colour = clearAttach.clearValue.colour();
				glLogCall( device.getContext(), glClearBufferfv
					, GL_CLEAR_TARGET_COLOR
					, clearAttach.colourAttachment
					, colour.float32.data() );
			}
			else
			{
				assert( !clearAttach.clearValue.isColour() );
				auto & depthStencil = clearAttach.clearValue.depthStencil();
				auto stencil = GLint( depthStencil.stencil );

				if ( renderer::checkFlag( clearAttach.aspectMask, renderer::ImageAspectFlag::eDepth | renderer::ImageAspectFlag::eStencil ) )
				{
					glLogCall( device.getContext(), glClearBufferfi
						, GL_CLEAR_TARGET_DEPTH_STENCIL
						, 0u
						, depthStencil.depth
						, stencil );
				}
				else if ( renderer::checkFlag( clearAttach.aspectMask, renderer::ImageAspectFlag::eDepth ) )
				{
					glLogCall( device.getContext(), glClearBufferfv
						, GL_CLEAR_TARGET_DEPTH
						, 0u
						, &depthStencil.depth );
				}
				else if ( renderer::checkFlag( clearAttach.aspectMask, renderer::ImageAspectFlag::eStencil ) )
				{
					glLogCall( device.getContext(), glClearBufferiv
						, GL_CLEAR_TARGET_STENCIL
						, 0u
						, &stencil );
				}
			}
		}

	}

	ClearAttachmentsCommand::ClearAttachmentsCommand( Device const & device
		, renderer::ClearAttachmentArray const & clearAttaches
		, renderer::ClearRectArray const & clearRects )
		: CommandBase{ device }
		, m_clearAttaches{ clearAttaches }
		, m_clearRects{ clearRects }
	{
	}

	void ClearAttachmentsCommand::apply()const
	{
		glLogCommand( "ClearAttachmentsCommand" );
		auto scissor = m_device.getCurrentScissor();

		for ( auto & clearAttach : m_clearAttaches )
		{
			for ( auto & rect : m_clearRects )
			{
				glLogCall( m_device.getContext(), glScissor
					, rect.offset.x
					, rect.offset.x
					, rect.extent.width
					, rect.extent.height );
				doClear( m_device, clearAttach );
			}
		}

		glLogCall( m_device.getContext(), glScissor
			, scissor.offset.x
			, scissor.offset.y
			, scissor.size.width
			, scissor.size.height );
	}

	CommandPtr ClearAttachmentsCommand::clone()const
	{
		return std::make_unique< ClearAttachmentsCommand >( *this );
	}
}
