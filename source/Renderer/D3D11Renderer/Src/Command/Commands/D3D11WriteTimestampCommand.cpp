/*
This file belongs to GlRenderer.
See LICENSE file in root folder.
*/
#include "D3D11WriteTimestampCommand.hpp"

#include "Miscellaneous/D3D11QueryPool.hpp"

namespace d3d11_renderer
{
	WriteTimestampCommand::WriteTimestampCommand( Device const & device
		, renderer::PipelineStageFlag pipelineStage
		, renderer::QueryPool const & pool
		, uint32_t query )
		: CommandBase{ device }
		, m_query{ *( static_cast< QueryPool const & >( pool ).begin() + query ) }
	{
	}

	void WriteTimestampCommand::apply( Context const & context )const
	{
		context.context->End( m_query );
	}

	CommandPtr WriteTimestampCommand::clone()const
	{
		return std::make_unique< WriteTimestampCommand >( *this );
	}
}
