/*
This file belongs to Ashes.
See LICENSE file in root folder.
*/
#ifndef ___Ashes_PipelineColorBlendStateCreateInfo_HPP___
#define ___Ashes_PipelineColorBlendStateCreateInfo_HPP___
#pragma once

#include "AshesPP/AshesPPPrerequisites.hpp"

#include <renderer/RendererCommon/Helper/ColourBlendState.hpp>

namespace ashes
{
	struct PipelineColorBlendStateCreateInfo
	{
		PipelineColorBlendStateCreateInfo( PipelineColorBlendStateCreateInfo const & ) = delete;
		PipelineColorBlendStateCreateInfo & operator=( PipelineColorBlendStateCreateInfo const & ) = delete;

		PipelineColorBlendStateCreateInfo( VkPipelineColorBlendStateCreateFlags flags = 0u
			, VkBool32 logicOpEnable = VK_FALSE
			, VkLogicOp logicOp = VK_LOGIC_OP_COPY
			, VkPipelineColorBlendAttachmentStateArray attachments = {
				{
					VK_FALSE,
					VK_BLEND_FACTOR_ONE,
					VK_BLEND_FACTOR_ZERO,
					VK_BLEND_OP_ADD,
					VK_BLEND_FACTOR_ONE,
					VK_BLEND_FACTOR_ZERO,
					VK_BLEND_OP_ADD,
					VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT
				} }
			, std::array< float, 4u > blendConstants = { 0.0f, 0.0f, 0.0f, 0.0f } )
			: attachments{ std::move( attachments ) }
			, vk
			{
				VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO,
				nullptr,
				flags,
				logicOpEnable,
				logicOp,
				uint32_t( this->attachments.size() ),
				this->attachments.data(),
				{
					blendConstants[0],
					blendConstants[1],
					blendConstants[2],
					blendConstants[3]
				},
			}
		{
		}
		
		PipelineColorBlendStateCreateInfo( PipelineColorBlendStateCreateInfo && rhs )
			: attachments{ std::move( rhs.attachments ) }
			, vk
			{
				VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO,
				nullptr,
				rhs.vk.flags,
				rhs.vk.logicOpEnable,
				rhs.vk.logicOp,
				uint32_t( this->attachments.size() ),
				this->attachments.data(),
				{
					rhs.vk.blendConstants[0],
					rhs.vk.blendConstants[1],
					rhs.vk.blendConstants[2],
					rhs.vk.blendConstants[3]
				},
			}
		{
		}
		
		PipelineColorBlendStateCreateInfo & operator=( PipelineColorBlendStateCreateInfo && rhs )
		{
			attachments = std::move( rhs.attachments );
			vk =
			{
				VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO,
				nullptr,
				rhs.vk.flags,
				rhs.vk.logicOpEnable,
				rhs.vk.logicOp,
				uint32_t( this->attachments.size() ),
				this->attachments.data(),
				{
					rhs.vk.blendConstants[0],
					rhs.vk.blendConstants[1],
					rhs.vk.blendConstants[2],
					rhs.vk.blendConstants[3]
				},
			};

			return *this;
		}

		inline operator VkPipelineColorBlendStateCreateInfo const &()const
		{
			return vk;
		}

		VkPipelineColorBlendAttachmentStateArray attachments;

	private:
		VkPipelineColorBlendStateCreateInfo vk;
	};
}

#endif
