/*
This file belongs to Renderer.
See LICENSE file in root folder
*/
#pragma once

#include "VkRendererPrerequisites.hpp"

#include <Renderer/RasterisationState.hpp>

namespace vk_renderer
{
	/**
	*\brief
	*	Convertit un renderer::RasterisationState en VkPipelineRasterizationStateCreateInfo.
	*\param[in] state
	*	Le renderer::RasterisationState.
	*\return
	*	Le VkPipelineRasterizationStateCreateInfo.
	*/
	VkPipelineRasterizationStateCreateInfo convert( renderer::RasterisationState const & state );
}