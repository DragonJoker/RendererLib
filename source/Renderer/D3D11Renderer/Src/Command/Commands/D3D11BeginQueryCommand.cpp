/*
This file belongs to GlRenderer.
See LICENSE file in root folder.
*/
#include "D3D11BeginQueryCommand.hpp"

#include "Miscellaneous/D3D11QueryPool.hpp"

namespace d3d11_renderer
{
	BeginQueryCommand::BeginQueryCommand( Device const & device
		, renderer::QueryPool const & pool
		, uint32_t query
		, renderer::QueryControlFlags flags )
		: CommandBase{ device }
		, m_query{ *( static_cast< QueryPool const & >( pool ).begin() + query ) }
	{
	}

	void BeginQueryCommand::apply( Context const & context )const
	{
		context.context->Begin( m_query );
	}

	CommandPtr BeginQueryCommand::clone()const
	{
		return std::make_unique< BeginQueryCommand >( *this );
	}
}
