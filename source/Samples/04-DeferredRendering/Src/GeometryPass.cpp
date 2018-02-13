#include "GeometryPass.hpp"

#include "RenderTarget.hpp"

#include <Buffer/Buffer.hpp>
#include <Buffer/GeometryBuffers.hpp>
#include <Buffer/StagingBuffer.hpp>
#include <Buffer/VertexBuffer.hpp>
#include <Command/CommandBuffer.hpp>
#include <Command/CommandPool.hpp>
#include <Core/Device.hpp>
#include <Descriptor/DescriptorSet.hpp>
#include <Descriptor/DescriptorSetLayout.hpp>
#include <Descriptor/DescriptorSetLayoutBinding.hpp>
#include <Descriptor/DescriptorSetPool.hpp>
#include <Image/Texture.hpp>
#include <Image/TextureView.hpp>
#include <Pipeline/DepthStencilState.hpp>
#include <Pipeline/InputAssemblyState.hpp>
#include <Pipeline/MultisampleState.hpp>
#include <Pipeline/Pipeline.hpp>
#include <Pipeline/PipelineLayout.hpp>
#include <Pipeline/Scissor.hpp>
#include <Pipeline/VertexLayout.hpp>
#include <Pipeline/Viewport.hpp>
#include <RenderPass/RenderPass.hpp>
#include <RenderPass/RenderPassState.hpp>
#include <RenderPass/RenderSubpass.hpp>
#include <RenderPass/RenderSubpassState.hpp>
#include <RenderPass/FrameBufferAttachment.hpp>
#include <Shader/ShaderProgram.hpp>
#include <Sync/ImageMemoryBarrier.hpp>

#include <FileUtils.hpp>

#include <algorithm>

namespace vkapp
{
	namespace
	{
		renderer::ShaderProgramPtr doCreateProgram( renderer::Device const & device )
		{
			renderer::ShaderProgramPtr result = device.createShaderProgram();
			std::string shadersFolder = common::getPath( common::getExecutableDirectory() ) / "share" / AppName / "Shaders";

			if ( !wxFileExists( shadersFolder / "opaque_gp.vert" )
				|| !wxFileExists( shadersFolder / "opaque_gp.frag" ) )
			{
				throw std::runtime_error{ "Shader files are missing" };
			}

			result->createModule( common::dumpTextFile( shadersFolder / "opaque_gp.vert" )
				, renderer::ShaderStageFlag::eVertex );
			result->createModule( common::dumpTextFile( shadersFolder / "opaque_gp.frag" )
				, renderer::ShaderStageFlag::eFragment );
			return result;
		}

		std::vector< renderer::PixelFormat > doGetFormats( GeometryPassResult const & gbuffer
			, renderer::PixelFormat depthFormat )
		{
			std::vector< renderer::PixelFormat > result
			{
				depthFormat,
			};

			for ( auto & texture : gbuffer )
			{
				result.push_back( texture.view->getFormat() );
			}

			return result;
		}

		renderer::TextureViewCRefArray doGetViews( GeometryPassResult const & gbuffer
			, renderer::TextureView const & depthview )
		{
			renderer::TextureViewCRefArray result
			{
				depthview
			};

			for ( auto & texture : gbuffer )
			{
				result.emplace_back( *texture.view );
			}

			return result;
		}
	}

	GeometryPass::GeometryPass( renderer::Device const & device
		, renderer::ShaderProgramPtr && program
		, GeometryPassResult const & gbuffer
		, renderer::PixelFormat depthFormat
		, renderer::UniformBuffer< renderer::Mat4 > const & matrixUbo
		, renderer::UniformBuffer< renderer::Mat4 > const & objectUbo )
		: common::NodesRenderer{ device
			, std::move( program )
			, doGetFormats( gbuffer, depthFormat )
			, true
			, true }
		, m_matrixUbo{ matrixUbo }
		, m_objectUbo{ objectUbo }
	{
	}

	void GeometryPass::update( common::RenderTarget const & target )
	{
		doUpdate( doGetViews( static_cast< RenderTarget const & >( target ).getGBuffer()
			, target.getDepthView() ) );
	}

	void GeometryPass::doFillDescriptorLayoutBindings( renderer::DescriptorSetLayoutBindingArray & bindings )
	{
		bindings.emplace_back( 1u, renderer::DescriptorType::eUniformBuffer, renderer::ShaderStageFlag::eVertex );
		bindings.emplace_back( 2u, renderer::DescriptorType::eUniformBuffer, renderer::ShaderStageFlag::eVertex );
	}

	void GeometryPass::doFillDescriptorSet( renderer::DescriptorSetLayout & descriptorLayout
		, renderer::DescriptorSet & descriptorSet )
	{
		descriptorSet.createBinding( descriptorLayout.getBinding( 1u )
			, m_matrixUbo
			, 0u
			, 1u );
		descriptorSet.createBinding( descriptorLayout.getBinding( 2u )
			, m_objectUbo
			, 0u
			, 1u );
	}
}
