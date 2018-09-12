/*
This file belongs to GlRenderer.
See LICENSE file in root folder.
*/
#include "D3D11BindComputePipelineCommand.hpp"

#include "Buffer/D3D11Buffer.hpp"
#include "Buffer/D3D11BufferView.hpp"
#include "Core/D3D11Device.hpp"
#include "Image/D3D11TextureView.hpp"
#include "Pipeline/D3D11ComputePipeline.hpp"
#include "Pipeline/D3D11PipelineLayout.hpp"
#include "Shader/D3D11ShaderModule.hpp"

namespace d3d11_renderer
{
	BindComputePipelineCommand::BindComputePipelineCommand( Device const & device
		, renderer::ComputePipeline const & pipeline
		, renderer::PipelineBindPoint bindingPoint )
		: CommandBase{ device }
		, m_pipeline{ static_cast< ComputePipeline const & > ( pipeline ) }
		, m_layout{ static_cast< PipelineLayout const & > ( m_pipeline.getLayout() ) }
		, m_program{ m_pipeline.getProgram() }
		, m_bindingPoint{ bindingPoint }
	{
	}

	void BindComputePipelineCommand::apply( Context const & context )const
	{
		context.context->CSSetShader( std::static_pointer_cast< ShaderModule >( m_program.module )->getCSShader()
			, nullptr
			, 0u );
	}

	void BindComputePipelineCommand::remove( Context const & context )const
	{
		context.context->CSSetShader( nullptr, nullptr, 0u );
	}

	CommandPtr BindComputePipelineCommand::clone()const
	{
		return std::make_unique< BindComputePipelineCommand >( *this );
	}
}
