/*
This file belongs to Ashes.
See LICENSE file in root folder
*/
#pragma once

#include "Gl3Renderer/Command/Commands/GlCommandBase.hpp"

#include <Ashes/Pipeline/Viewport.hpp>

namespace gl_renderer
{
	/**
	*\brief
	*	Commande d'application d'un viewport.
	*/
	class ViewportCommand
		: public CommandBase
	{
	public:
		/**
		*\brief
		*	Constructeur.
		*\param[in] viewport
		*	Le viewport.
		*/
		ViewportCommand( Device const & device
			, uint32_t firstViewport
			, ashes::VkViewportArray const & viewports );

		void apply( ContextLock const & context )const override;
		CommandPtr clone()const override;

	private:
		ashes::VkViewportArray m_viewports;
	};
}
