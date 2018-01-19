/*
This file belongs to Renderer.
See LICENSE file in root folder
*/
#pragma once

#include <Enum/DescriptorType.hpp>

namespace vk_renderer
{
	/**
	*\brief
	*	Convertit un renderer::DescriptorType en VkDescriptorType.
	*\param[in] type
	*	Le renderer::DescriptorType.
	*\return
	*	Le VkDescriptorType.
	*/
	VkDescriptorType convert( renderer::DescriptorType const & type );
}