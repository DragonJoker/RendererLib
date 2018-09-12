#include "Pipeline/GlComputePipeline.hpp"

#include "Core/GlDevice.hpp"
#include "Pipeline/GlPipelineLayout.hpp"
#include "Shader/GlShaderModule.hpp"

namespace gl_renderer
{
	ComputePipeline::ComputePipeline( Device const & device
		, renderer::PipelineLayout const & layout
		, renderer::ComputePipelineCreateInfo && createInfo )
		: renderer::ComputePipeline{ device
			, layout
			, std::move( createInfo ) }
		, m_device{ device }
		, m_layout{ layout }
		, m_program{ m_device, m_createInfo.stage }
	{
		m_program.link( m_device.getContext() );

		if ( m_createInfo.stage.specialisationInfo )
		{
			m_constantsPcbs.push_back( convert( device
				, ~( 0u )
				, m_createInfo.stage.module->getStage()
				, *m_createInfo.stage.specialisationInfo ) );
		}
	}
}
