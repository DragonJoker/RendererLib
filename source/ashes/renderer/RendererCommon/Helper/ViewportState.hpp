/*
This file belongs to Ashes.
See LICENSE file in root folder.
*/
#ifndef ___Ashes_ViewportState_HPP___
#define ___Ashes_ViewportState_HPP___
#pragma once

#include "ashes/renderer/RendererCommon/AshesRendererPrerequisites.hpp"

namespace ashes
{
	/**
	*\~english
	*\brief
	*	The viewport state.
	*\~french
	*\brief
	*	L'état de viewport.
	*/
	inline VkPipelineViewportStateCreateInfo getDefaultViewportState()
	{
		return
		{
			VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO,
			nullptr,
			0u,
			1u,
			nullptr,
			1u,
			nullptr,
		};
	}

	VkPipelineViewportStateCreateInfo const & getDeactivatedViewportState();

	inline bool operator==( VkPipelineViewportStateCreateInfo const & lhs
		, VkPipelineViewportStateCreateInfo const & rhs )
	{
		return lhs.flags == rhs.flags
			&& makeArrayView( lhs.pViewports, lhs.viewportCount ) == makeArrayView( rhs.pViewports, rhs.viewportCount )
			&& makeArrayView( lhs.pScissors, lhs.scissorCount ) == makeArrayView( rhs.pScissors, rhs.scissorCount );
	}

	inline bool operator!=( VkPipelineViewportStateCreateInfo const & lhs
		, VkPipelineViewportStateCreateInfo const & rhs )
	{
		return !( lhs == rhs );
	}
}

#endif
