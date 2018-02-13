#pragma once

#include "Prerequisites.hpp"

#include <NodesRenderer.hpp>

namespace vkapp
{
	class TransparentRendering
		: public common::NodesRenderer
	{
	public:
		TransparentRendering( renderer::Device const & device
			, renderer::ShaderProgramPtr && program
			, std::vector< renderer::PixelFormat > const & formats
			, renderer::UniformBuffer< renderer::Mat4 > const & matrixUbo
			, renderer::UniformBuffer< renderer::Mat4 > const & objectUbo
			, renderer::UniformBuffer< common::LightsData > const & lightsUbo );

	private:
		void doFillDescriptorLayoutBindings( renderer::DescriptorSetLayoutBindingArray & bindings )override;
		void doFillDescriptorSet( renderer::DescriptorSetLayout & descriptorLayout
			, renderer::DescriptorSet & descriptorSet )override;

	private:
		renderer::UniformBuffer< renderer::Mat4 > const & m_matrixUbo;
		renderer::UniformBuffer< renderer::Mat4 > const & m_objectUbo;
		renderer::UniformBuffer< common::LightsData > const & m_lightsUbo;
	};
}
