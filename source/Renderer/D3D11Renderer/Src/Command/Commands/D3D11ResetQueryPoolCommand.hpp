/*
This file belongs to RendererLib.
See LICENSE file in root folder
*/
#pragma once

#include "D3D11CommandBase.hpp"

namespace d3d11_renderer
{
	/**
	*\brief
	*	Commande de fin d'une passe de rendu, unbind son framebuffer.
	*/
	class ResetQueryPoolCommand
		: public CommandBase
	{
	public:
		ResetQueryPoolCommand( Device const & device
			, renderer::QueryPool const & pool
			, uint32_t firstQuery
			, uint32_t queryCount );
		void apply( Context const & context )const override;
		CommandPtr clone()const override;
	};
}
