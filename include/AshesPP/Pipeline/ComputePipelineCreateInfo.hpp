/*
This file belongs to Ashes.
See LICENSE file in root folder.
*/
#ifndef ___Ashes_ComputePipelineCreateInfo_HPP___
#define ___Ashes_ComputePipelineCreateInfo_HPP___
#pragma once

#include "PipelineShaderStageCreateInfo.hpp"

namespace ashes
{
	/**
	*\~english
	*\brief
	*	Holds the data used to create a compute pipeline.
	*\~french
	*\brief
	*	Contient les données utilisées pour créer un pipeline de calcul.
	*/
	struct ComputePipelineCreateInfo
	{
		ComputePipelineCreateInfo( ComputePipelineCreateInfo const & ) = delete;
		ComputePipelineCreateInfo & operator=( ComputePipelineCreateInfo const & ) = delete;

		ComputePipelineCreateInfo( VkPipelineCreateFlags flags
			, PipelineShaderStageCreateInfo stage
			, VkPipelineLayout layout
			, VkPipeline basePipelineHandle = VK_NULL_HANDLE
			, int32_t basePipelineIndex = 0 )
			: stage{ std::move( stage ) }
			, vk
			{
				VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO,
				nullptr,
				flags,
				this->stage,
				layout,
				basePipelineHandle,
				basePipelineIndex,
			}
		{
		}

		ComputePipelineCreateInfo( ComputePipelineCreateInfo && rhs )
			: stage{ std::move( rhs.stage ) }
			, vk
			{
				VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO,
				nullptr,
				rhs.vk.flags,
				this->stage,
				rhs.vk.layout,
				rhs.vk.basePipelineHandle,
				rhs.vk.basePipelineIndex,
			}
		{
		}

		ComputePipelineCreateInfo & operator=( ComputePipelineCreateInfo && rhs )
		{
			stage = std::move( rhs.stage );
			vk =
			{
				VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO,
				nullptr,
				rhs.vk.flags,
				this->stage,
				rhs.vk.layout,
				rhs.vk.basePipelineHandle,
				rhs.vk.basePipelineIndex,
			};

			return *this;
		}

		inline operator VkComputePipelineCreateInfo const & ()const
		{
			return vk;
		}

		PipelineShaderStageCreateInfo stage;

	private:
		VkComputePipelineCreateInfo vk;
	};
}

#endif
