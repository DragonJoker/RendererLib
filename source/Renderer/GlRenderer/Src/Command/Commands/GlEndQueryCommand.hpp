/*
This file belongs to RendererLib.
See LICENSE file in root folder
*/
#pragma once

#include "GlCommandBase.hpp"

namespace gl_renderer
{
	/**
	*\brief
	*	Commande de fin d'une requ�te.
	*/
	class EndQueryCommand
		: public CommandBase
	{
	public:
		EndQueryCommand( Device const & device
			, renderer::QueryPool const & pool
			, uint32_t query );
		void apply( ContextLock const & context )const override;
		CommandPtr clone()const override;

	private:
		GlQueryType m_target;
	};
}
