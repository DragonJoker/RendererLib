/*
This file belongs to RendererLib.
See LICENSE file in root folder
*/
#pragma once

#include "GlCommandBase.hpp"

#include <RenderPass/ClearAttachment.hpp>
#include <RenderPass/ClearRect.hpp>

namespace gl_renderer
{
	class ClearAttachmentsCommand
		: public CommandBase
	{
	public:
		ClearAttachmentsCommand( Device const & device
			, renderer::ClearAttachmentArray const & clearAttaches
			, renderer::ClearRectArray const & clearRects );

		void apply( ContextLock const & context )const override;
		CommandPtr clone()const override;

	private:
		renderer::ClearAttachmentArray m_clearAttaches;
		renderer::ClearRectArray m_clearRects;
	};
}
