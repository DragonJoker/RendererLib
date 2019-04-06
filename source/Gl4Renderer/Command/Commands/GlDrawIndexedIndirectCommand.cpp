/*
This file belongs to GlInstance.
See LICENSE file in root folder.
*/
#include "Command/Commands/GlDrawIndexedIndirectCommand.hpp"

#include "Buffer/GlBuffer.hpp"

#include "ashesgl4_api.hpp"

namespace ashes::gl4
{
	DrawIndexedIndirectCommand::DrawIndexedIndirectCommand( VkDevice device
		, VkBuffer buffer
		, VkDeviceSize offset
		, uint32_t drawCount
		, uint32_t stride
		, VkPrimitiveTopology mode
		, VkIndexType type )
		: CommandBase{ device }
		, m_buffer{ static_cast< VkBuffer >( buffer ) }
		, m_offset{ offset }
		, m_drawCount{ drawCount }
		, m_stride{ stride }
		, m_mode{ convert( mode ) }
		, m_type{ convert( type ) }
	{
	}

	void DrawIndexedIndirectCommand::apply( ContextLock const & context )const
	{
		glLogCommand( "DrawIndexedIndirectCommand" );
		glLogCall( context
			, glBindBuffer
			, GL_BUFFER_TARGET_DRAW_INDIRECT
			, get( m_buffer )->getInternal() );
		glLogCall( context
			, glMultiDrawElementsIndirect
			, m_mode
			, m_type
			, getBufferOffset( m_offset )
			, m_drawCount
			, m_stride );
		glLogCall( context
			, glBindBuffer
			, GL_BUFFER_TARGET_DRAW_INDIRECT
			, 0 );
	}

	CommandPtr DrawIndexedIndirectCommand::clone()const
	{
		return std::make_unique< DrawIndexedIndirectCommand >( *this );
	}
}
