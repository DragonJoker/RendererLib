#include "Descriptor/GlDescriptorSet.hpp"

#include "Buffer/GlBuffer.hpp"
#include "Descriptor/GlDescriptorPool.hpp"
#include "Image/GlSampler.hpp"
#include "Image/GlImage.hpp"

#include "ashesgl4_api.hpp"

#include <algorithm>

namespace ashes::gl4
{
	DescriptorSet::DescriptorSet( VkDescriptorSetLayout layout )
	{
		for ( auto & binding : *get( layout ) )
		{
			LayoutBindingWrites bindingWrites
			{
				binding.binding,
				binding.descriptorCount,
				binding.descriptorType
			};
			m_writes.insert( { binding.binding, bindingWrites } );

			switch ( binding.descriptorType )
			{
			case VK_DESCRIPTOR_TYPE_SAMPLER:
				m_samplers.push_back( &bindingWrites );
				break;
			case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
				m_combinedTextureSamplers.push_back( &bindingWrites );
				break;
			case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
				m_sampledTextures.push_back( &bindingWrites );
				break;
			case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
				m_storageTextures.push_back( &bindingWrites );
				break;
			case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
				m_texelBuffers.push_back( &bindingWrites );
				break;
			case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
				m_texelBuffers.push_back( &bindingWrites );
				break;
			case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
				m_uniformBuffers.push_back( &bindingWrites );
				break;
			case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
				m_storageBuffers.push_back( &bindingWrites );
				break;
			case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
				m_dynamicUniformBuffers.push_back( &bindingWrites );
				m_dynamicBuffers.push_back( &bindingWrites );
				break;
			case VkDescriptorType::VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
				m_dynamicStorageBuffers.push_back( &bindingWrites );
				m_dynamicBuffers.push_back( &bindingWrites );
				break;
			case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
				break;
			}
		}

		std::sort( m_dynamicBuffers.begin()
			, m_dynamicBuffers.end()
			, []( LayoutBindingWrites const * lhs
				, LayoutBindingWrites const * rhs )
			{
				return lhs->binding < rhs->binding;
			} );
	}

	void DescriptorSet::mergeWrites( LayoutBindingWrites & writes, VkWriteDescriptorSet const & write )
	{
		writes.writes.push_back( write );
	}

	void DescriptorSet::update( VkWriteDescriptorSet const & write )
	{
		auto it = m_writes.find( write.dstBinding );
		assert( it != m_writes.end() );
		assert( it->second.descriptorType == write.descriptorType );
		assert( it->second.descriptorCount >= write.dstArrayElement + write.descriptorCount );
		assert( write.dstSet == get( this ) );
		mergeWrites( it->second, write );
	}

	void DescriptorSet::update( VkCopyDescriptorSet const & copy )
	{
		//m_writes[copy.dstBinding].dstBinding = copy.srcBinding;
		//m_writes[copy.dstBinding].dstArrayElement = copy.srcArrayElement;
	}

	void DescriptorSet::update()
	{
		m_combinedTextureSamplers.clear();
		m_samplers.clear();
		m_sampledTextures.clear();
		m_storageTextures.clear();
		m_uniformBuffers.clear();
		m_storageBuffers.clear();
		m_texelBuffers.clear();
		m_dynamicUniformBuffers.clear();
		m_dynamicStorageBuffers.clear();
		m_dynamicBuffers.clear();
	}
}
