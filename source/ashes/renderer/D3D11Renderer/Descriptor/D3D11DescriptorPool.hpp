/**
*\file
*	DescriptorSetPool.h
*\author
*	Sylvain Doremus
*/
#ifndef ___D3D11Renderer_DescriptorPool_HPP___
#define ___D3D11Renderer_DescriptorPool_HPP___
#pragma once

#include "renderer/D3D11Renderer/D3D11RendererPrerequisites.hpp"

#include <vector>

namespace ashes::d3d11
{
	class DescriptorPool
	{
	public:
		DescriptorPool( VkDevice device
			, VkDescriptorPoolCreateInfo createInfos );
		/**
		*\~french
		*\brief
		*	Destructeur.
		*\~english
		*\brief
		*	Destructor.
		*/
		~DescriptorPool();

		void registerSet( VkDescriptorSet set );
		VkResult reset( VkDescriptorPoolResetFlags flags );
		VkResult free( VkDescriptorSetArray sets );

	private:
		VkDevice m_device;
		VkDescriptorPoolSizeArray m_poolSizes;
		VkDescriptorPoolCreateInfo m_createInfos;
		VkDescriptorSetArray m_sets;
		VkDescriptorSetArray m_allSets;
	};
}

#endif