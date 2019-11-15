/*
This file belongs to GlInstance.
See LICENSE file in root folder.
*/
#include "Command/Commands/GlPushConstantsCommand.hpp"

#include "ashesgl4_api.hpp"

namespace ashes::gl4
{	
	void apply( ContextLock const & context
		, CmdUniform1fv const & cmd )
	{
		glLogCall( context
			, glProgramUniform1fv
			, cmd.program
			, cmd.location
			, 1u
			, &cmd.buffer );
	}
	
	void apply( ContextLock const & context
		, CmdUniform2fv const & cmd )
	{
		glLogCall( context
			, glProgramUniform2fv
			, cmd.program
			, cmd.location
			, 1u
			, cmd.buffer );
	}
	
	void apply( ContextLock const & context
		, CmdUniform3fv const & cmd )
	{
		glLogCall( context
			, glProgramUniform3fv
			, cmd.program
			, cmd.location
			, 1u
			, cmd.buffer );
	}
	
	void apply( ContextLock const & context
		, CmdUniform4fv const & cmd )
	{
		glLogCall( context
			, glProgramUniform4fv
			, cmd.program
			, cmd.location
			, 1u
			, cmd.buffer );
	}
	
	void apply( ContextLock const & context
		, CmdUniformMatrix2fv const & cmd )
	{
		glLogCall( context
			, glProgramUniformMatrix2fv
			, cmd.program
			, cmd.location
			, 1u
			, cmd.transpose
			, cmd.buffer );
	}
	
	void apply( ContextLock const & context
		, CmdUniformMatrix3fv const & cmd )
	{
		glLogCall( context
			, glProgramUniformMatrix3fv
			, cmd.program
			, cmd.location
			, 1u
			, cmd.transpose
			, cmd.buffer );
	}
	
	void apply( ContextLock const & context
		, CmdUniformMatrix4fv const & cmd )
	{
		glLogCall( context
			, glProgramUniformMatrix4fv
			, cmd.program
			, cmd.location
			, 1u
			, cmd.transpose
			, cmd.buffer );
	}

	void apply( ContextLock const & context
		, CmdUniform1iv const & cmd )
	{
		glLogCall( context
			, glProgramUniform1iv
			, cmd.program
			, cmd.location
			, 1u
			, &cmd.buffer );
	}

	void apply( ContextLock const & context
		, CmdUniform2iv const & cmd )
	{
		glLogCall( context
			, glProgramUniform2iv
			, cmd.program
			, cmd.location
			, 1u
			, cmd.buffer );
	}

	void apply( ContextLock const & context
		, CmdUniform3iv const & cmd )
	{
		glLogCall( context
			, glProgramUniform3iv
			, cmd.program
			, cmd.location
			, 1u
			, cmd.buffer );
	}

	void apply( ContextLock const & context
		, CmdUniform4iv const & cmd )
	{
		glLogCall( context
			, glProgramUniform4iv
			, cmd.program
			, cmd.location
			, 1u
			, cmd.buffer );
	}

	void apply( ContextLock const & context
		, CmdUniform1uiv const & cmd )
	{
		glLogCall( context
			, glProgramUniform1uiv
			, cmd.program
			, cmd.location
			, 1u
			, &cmd.buffer );
	}

	void apply( ContextLock const & context
		, CmdUniform2uiv const & cmd )
	{
		glLogCall( context
			, glProgramUniform2uiv
			, cmd.program
			, cmd.location
			, 1u
			, cmd.buffer );
	}

	void apply( ContextLock const & context
		, CmdUniform3uiv const & cmd )
	{
		glLogCall( context
			, glProgramUniform3uiv
			, cmd.program
			, cmd.location
			, 1u
			, cmd.buffer );
	}

	void apply( ContextLock const & context
		, CmdUniform4uiv const & cmd )
	{
		glLogCall( context
			, glProgramUniform4uiv
			, cmd.program
			, cmd.location
			, 1u
			, cmd.buffer );
	}

	template< OpType OpT, typename T >
	void buildPushConstantMtxCommand( ConstantDesc const & constant
		, uint8_t const *& buffer
		, CmdList & list )
	{
		auto arraySize = std::min( 1u, constant.arraySize );

		for ( auto layer = 0u; layer < arraySize; ++layer )
		{
			list.push_back( makeCmd< OpT >( constant.program
				, constant.location + layer
				, GL_FALSE
				, reinterpret_cast< T const * >( buffer ) ) );
			buffer += constant.size;
		}
	}

	template< OpType OpT, typename T >
	void buildPushConstantCommand( ConstantDesc const & constant
		, uint8_t const *& buffer
		, CmdList & list )
	{
		auto arraySize = std::max( 1u, constant.arraySize );

		for ( auto layer = 0u; layer < arraySize; ++layer )
		{
			list.push_back( makeCmd< OpT >( constant.program
				, constant.location + layer
				, reinterpret_cast< T const * >( buffer ) ) );
			buffer += constant.size;
		}
	}

	void buildPushConstantsCommand( VkShaderStageFlags stageFlags
		, PushConstantsDesc const & pcb
		, CmdList & list )
	{
		glLogCommand( "PushConstantsCommand" );

		for ( auto & constant : pcb.constants )
		{
			if ( ( constant.stageFlag & stageFlags ) != 0 )
			{
				auto buffer = pcb.data.data() + constant.offset;

				switch ( constant.format )
				{
				case ConstantFormat::eFloat:
					buildPushConstantCommand< OpType::eUniform1fv, GLfloat >( constant, buffer, list );
					break;

				case ConstantFormat::eVec2f:
					buildPushConstantCommand< OpType::eUniform2fv, GLfloat >( constant, buffer, list );
					break;

				case ConstantFormat::eVec3f:
					buildPushConstantCommand< OpType::eUniform3fv, GLfloat >( constant, buffer, list );
					break;

				case ConstantFormat::eVec4f:
					buildPushConstantCommand< OpType::eUniform4fv, GLfloat >( constant, buffer, list );
					break;

				case ConstantFormat::eMat2f:
					buildPushConstantMtxCommand< OpType::eUniformMatrix2fv, GLfloat >( constant, buffer, list );
					break;

				case ConstantFormat::eMat3f:
					buildPushConstantMtxCommand< OpType::eUniformMatrix3fv, GLfloat >( constant, buffer, list );
					break;

				case ConstantFormat::eMat4f:
					buildPushConstantMtxCommand< OpType::eUniformMatrix4fv, GLfloat >( constant, buffer, list );
					break;

				case ConstantFormat::eInt:
					buildPushConstantCommand< OpType::eUniform1iv, GLint >( constant, buffer, list );
					break;

				case ConstantFormat::eVec2i:
					buildPushConstantCommand< OpType::eUniform2iv, GLint >( constant, buffer, list );
					break;

				case ConstantFormat::eVec3i:
					buildPushConstantCommand< OpType::eUniform3iv, GLint >( constant, buffer, list );
					break;

				case ConstantFormat::eVec4i:
					buildPushConstantCommand< OpType::eUniform4iv, GLint >( constant, buffer, list );
					break;

				case ConstantFormat::eUInt:
					buildPushConstantCommand< OpType::eUniform1uiv, GLuint >( constant, buffer, list );
					break;

				case ConstantFormat::eVec2ui:
					buildPushConstantCommand< OpType::eUniform2uiv, GLuint >( constant, buffer, list );
					break;

				case ConstantFormat::eVec3ui:
					buildPushConstantCommand< OpType::eUniform3uiv, GLuint >( constant, buffer, list );
					break;

				case ConstantFormat::eVec4ui:
					buildPushConstantCommand< OpType::eUniform4uiv, GLuint >( constant, buffer, list );
					break;

				case ConstantFormat::eColour:
					buildPushConstantCommand< OpType::eUniform4fv, GLfloat >( constant, buffer, list );
					break;

				default:
					assert( false && "Unsupported constant format" );
					break;
				}
			}
		}
	}
}
