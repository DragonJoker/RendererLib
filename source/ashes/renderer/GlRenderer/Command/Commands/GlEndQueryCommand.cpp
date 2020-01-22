/*
This file belongs to Ashes.
See LICENSE file in root folder.
*/
#include "Command/Commands/GlEndQueryCommand.hpp"

#include "Miscellaneous/GlQueryPool.hpp"

#include "ashesgl_api.hpp"

namespace ashes::gl
{
	void apply( ContextLock const & context
		, CmdEndQuery const & cmd )
	{
		glLogCall( context
			, glEndQuery
			, cmd.target );
	}

	void buildEndQueryCommand( VkQueryPool pool
		, uint32_t query
		, CmdList & list )
	{
		glLogCommand( list, "EndQueryCommand" );
		if ( get( pool )->getType() == VK_QUERY_TYPE_PIPELINE_STATISTICS )
		{
			assert( query == 0u );

			for ( auto type : get( pool )->getTypes() )
			{
				list.push_back( makeCmd< OpType::eEndQuery >( type ) );
				++query;
			}
		}
		else
		{
			list.push_back( makeCmd< OpType::eEndQuery >( convert( get( pool )->getType() ) ) );
		}
	}
}
