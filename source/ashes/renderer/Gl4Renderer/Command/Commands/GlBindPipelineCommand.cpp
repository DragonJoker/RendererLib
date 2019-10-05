/*
This file belongs to GlInstance.
See LICENSE file in root folder.
*/
#include "Command/Commands/GlBindPipelineCommand.hpp"

#include "Core/GlDevice.hpp"
#include "Pipeline/GlPipeline.hpp"
#include "Pipeline/GlPipelineLayout.hpp"

#include "ashesgl4_api.hpp"

using ashes::operator==;
using ashes::operator!=;

namespace ashes::gl4
{
	void apply( ContextLock const & context
		, CmdBindContextState const & cmd )
	{
		cmd.stack->apply( context, *cmd.state );
	}

	void buildBindPipelineCommand( ContextStateStack & stack
		, VkDevice device
		, VkPipeline pipeline
		, VkPipelineBindPoint bindingPoint
		, CmdList & list )
	{
		glLogCommand( "BindPipelineCommand" );
		GLuint program;
		auto glpipeline = get( pipeline );

		if ( !stack.hasCurrentFramebuffer() )
		{
			// Can happen in case of secondary command buffers
			stack.apply( list, glpipeline->getRtotContextState() );
			program = glpipeline->getRtotProgram();
		}
		else if ( !get( stack.getCurrentFramebuffer() )->hasSwapchainImage() )
		{
			stack.apply( list, glpipeline->getRtotContextState() );
			program = glpipeline->getRtotProgram();
		}
		else
		{
			stack.apply( list, glpipeline->getBackContextState() );
			program = glpipeline->getBackProgram();
		}

		if ( stack.getCurrentProgram() != program )
		{
			list.push_back( makeCmd< OpType::eUseProgram >( program ) );
			stack.setCurrentProgram( program );
		}

		if ( glpipeline->getViewports().size() == 1u )
		{
			auto & viewport = glpipeline->getViewports().front();

			if ( stack.getCurrentViewport() != viewport )
			{
				list.push_back( makeCmd< OpType::eApplyViewport >( viewport ) );
				stack.setCurrentViewport( viewport );
			}
		}
		else if ( !glpipeline->getViewports().empty() )
		{
			list.push_back( makeCmd< OpType::eApplyViewports >( glpipeline->getViewports() ) );
		}

		if ( glpipeline->getScissors().size() == 1u )
		{
			auto & scissor = glpipeline->getScissors().front();

			if ( stack.getCurrentScissor() != scissor )
			{
				list.push_back( makeCmd< OpType::eApplyScissor >( scissor ) );
				stack.setCurrentScissor( scissor );
			}
		}
		else if ( !glpipeline->getScissors().empty() )
		{
			list.push_back( makeCmd< OpType::eApplyScissors >( glpipeline->getScissors() ) );
		}
	}

	void buildUnbindPipelineCommand( ContextStateStack & stack
		, VkDevice device
		, VkPipeline pipeline
		, VkImageView view
		, CmdList & list )
	{
		stack.setCurrentProgram( 0u );
		list.push_back( makeCmd< OpType::eUseProgram >( 0u ) );
	}
}
