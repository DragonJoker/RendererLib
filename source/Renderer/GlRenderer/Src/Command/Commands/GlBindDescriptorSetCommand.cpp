/*
This file belongs to GlRenderer.
See LICENSE file in root folder.
*/
#include "GlBindDescriptorSetCommand.hpp"

#include "Buffer/GlBuffer.hpp"
#include "Buffer/GlBufferView.hpp"
#include "Descriptor/GlDescriptorSet.hpp"
#include "Pipeline/GlPipelineLayout.hpp"
#include "Image/GlSampler.hpp"
#include "Image/GlTexture.hpp"
#include "Image/GlTextureView.hpp"
#include "Buffer/GlUniformBuffer.hpp"

#include <Descriptor/DescriptorSetLayoutBinding.hpp>

namespace gl_renderer
{
	namespace
	{
		renderer::TextureView const & getView( renderer::WriteDescriptorSet const & write, uint32_t index )
		{
			assert( index < write.imageInfo.size() );
			return write.imageInfo[index].imageView.value().get();
		}

		renderer::Sampler const & getSampler( renderer::WriteDescriptorSet const & write, uint32_t index )
		{
			assert( index < write.imageInfo.size() );
			return write.imageInfo[index].sampler.value().get();
		}

		renderer::BufferBase const & getBuffer( renderer::WriteDescriptorSet const & write, uint32_t index )
		{
			assert( index < write.bufferInfo.size() );
			return write.bufferInfo[index].buffer.get();
		}

		void bindCombinedSampler( Device const & device
			, renderer::WriteDescriptorSet const & write )
		{
			for ( auto i = 0u; i < write.imageInfo.size(); ++i )
			{
				uint32_t bindingIndex = write.dstBinding + write.dstArrayElement + i;
				auto & view = getView( write, i );
				auto & sampler = getSampler( write, i );
				glLogCall( device.getContext(), glActiveTexture
					, GlTextureUnit( GL_TEXTURE0 + bindingIndex ) );
				glLogCall( device.getContext(), glBindTexture
					, convert( view.getType() )
					, static_cast< TextureView const & >( view ).getImage() );
				glLogCall( device.getContext(), glBindSampler
					, bindingIndex
					, static_cast< Sampler const & >( sampler ).getSampler() );
			}
		}

		void bindSampler( Device const & device
			, renderer::WriteDescriptorSet const & write )
		{
			for ( auto i = 0u; i < write.imageInfo.size(); ++i )
			{
				uint32_t bindingIndex = write.dstBinding + write.dstArrayElement + i;
				auto & sampler = getSampler( write, i );
				glLogCall( device.getContext(), glBindSampler
					, bindingIndex
					, static_cast< Sampler const & >( sampler ).getSampler() );
			}
		}

		void bindSampledTexture( Device const & device
			, renderer::WriteDescriptorSet const & write )
		{
			for ( auto i = 0u; i < write.imageInfo.size(); ++i )
			{
				uint32_t bindingIndex = write.dstBinding + write.dstArrayElement + i;
				auto & view = getView( write, i );
				glLogCall( device.getContext(), glActiveTexture
					, GlTextureUnit( GL_TEXTURE0 + bindingIndex ) );
				glLogCall( device.getContext(), glBindTexture
					, convert( view.getType() )
					, static_cast< TextureView const & >( view ).getImage() );
			}
		}

		void bindStorageTexture( Device const & device
			, renderer::WriteDescriptorSet const & write )
		{
			for ( auto i = 0u; i < write.imageInfo.size(); ++i )
			{
				uint32_t bindingIndex = write.dstBinding + write.dstArrayElement + i;
				auto & view = getView( write, i );
				auto & range = view.getSubResourceRange();
				glLogCall( device.getContext(), glActiveTexture
					, GlTextureUnit( GL_TEXTURE0 + bindingIndex ) );
				glLogCall( device.getContext(), glBindImageTexture
					, bindingIndex
					, static_cast< TextureView const & >( view ).getImage()
					, range.baseMipLevel
					, range.layerCount
					, range.baseArrayLayer
					, GL_ACCESS_TYPE_READ_WRITE
					, getInternal( view.getFormat() ) );
			}
		}

		void bindUniformBuffer( Device const & device
			, renderer::WriteDescriptorSet const & write )
		{
			for ( auto i = 0u; i < write.bufferInfo.size(); ++i )
			{
				uint32_t bindingIndex = write.dstBinding + write.dstArrayElement + i;
				auto & buffer = getBuffer( write, i );
				glLogCall( device.getContext(), glBindBufferRange
					, GL_BUFFER_TARGET_UNIFORM
					, bindingIndex
					, static_cast< Buffer const & >( buffer ).getBuffer()
					, GLintptr( write.bufferInfo[i].offset )
					, GLsizeiptr( write.bufferInfo[i].range ) );
			}
		}

		void bindStorageBuffer( Device const & device
			, renderer::WriteDescriptorSet const & write )
		{
			for ( auto i = 0u; i < write.bufferInfo.size(); ++i )
			{
				uint32_t bindingIndex = write.dstBinding + write.dstArrayElement + i;
				auto & buffer = getBuffer( write, i );
				glLogCall( device.getContext(), glBindBufferRange
					, GL_BUFFER_TARGET_SHADER_STORAGE
					, bindingIndex
					, static_cast< Buffer const & >( buffer ).getBuffer()
					, GLintptr( write.bufferInfo[i].offset )
					, GLsizeiptr( write.bufferInfo[i].range ) );
			}
		}

		void bindTexelBuffer( Device const & device
			, renderer::WriteDescriptorSet const & write )
		{
			for ( auto i = 0u; i < write.bufferInfo.size(); ++i )
			{
				uint32_t bindingIndex = write.dstBinding + write.dstArrayElement + i;
				auto & buffer = getBuffer( write, i );
				glLogCall( device.getContext(), glActiveTexture
					, GlTextureUnit( GL_TEXTURE0 + bindingIndex ) );
				glLogCall( device.getContext(), glBindTexture
					, GL_BUFFER_TARGET_TEXTURE
					, static_cast< BufferView const & >( write.texelBufferView[i].get() ).getImage() );
			}
		}

		void bindDynamicUniformBuffer( Device const & device
			, renderer::WriteDescriptorSet const & write, uint32_t offset )
		{
			for ( auto i = 0u; i < write.bufferInfo.size(); ++i )
			{
				uint32_t bindingIndex = write.dstBinding + write.dstArrayElement + i;
				auto & buffer = getBuffer( write, i );
				glLogCall( device.getContext(), glBindBufferRange
					, GL_BUFFER_TARGET_UNIFORM
					, bindingIndex
					, static_cast< Buffer const & >( buffer ).getBuffer()
					, GLintptr( write.bufferInfo[i].offset + offset )
					, GLsizeiptr( write.bufferInfo[i].range ) );
			}
		}

		void bindDynamicStorageBuffer( Device const & device
			, renderer::WriteDescriptorSet const & write, uint32_t offset )
		{
			for ( auto i = 0u; i < write.bufferInfo.size(); ++i )
			{
				uint32_t bindingIndex = write.dstBinding + write.dstArrayElement + i;
				auto & buffer = getBuffer( write, i );
				glLogCall( device.getContext(), glBindBufferRange
					, GL_BUFFER_TARGET_SHADER_STORAGE
					, bindingIndex
					, static_cast< Buffer const & >( buffer ).getBuffer()
					, GLintptr( write.bufferInfo[i].offset + offset )
					, GLsizeiptr( write.bufferInfo[i].range ) );
			}
		}

		void bindDynamicBuffers( Device const & device
			, renderer::WriteDescriptorSetArray const & writes
			, renderer::UInt32Array const & offsets )
		{
			for ( auto i = 0u; i < offsets.size(); ++i )
			{
				auto & write = writes[i];

				switch ( write.descriptorType )
				{
				case renderer::DescriptorType::eUniformBufferDynamic:
					bindDynamicUniformBuffer( device, write, offsets[i] );
					break;

				case renderer::DescriptorType::eStorageBufferDynamic:
					bindDynamicStorageBuffer( device, write, offsets[i] );
					break;

				default:
					assert( false && "Unsupported dynamic descriptor type" );
					throw std::runtime_error{ "Unsupported dynamic descriptor type" };
					break;
				}
			}
		}
	}

	BindDescriptorSetCommand::BindDescriptorSetCommand( Device const & device
		, renderer::DescriptorSet const & descriptorSet
		, renderer::PipelineLayout const & layout
		, renderer::UInt32Array const & dynamicOffsets
		, renderer::PipelineBindPoint bindingPoint )
		: CommandBase{ device }
		, m_descriptorSet{ static_cast< DescriptorSet const & >( descriptorSet ) }
		, m_layout{ static_cast< PipelineLayout const & >( layout ) }
		, m_bindingPoint{ bindingPoint }
		, m_dynamicOffsets{ dynamicOffsets }
	{
		assert( m_descriptorSet.getDynamicBuffers().size() == m_dynamicOffsets.size()
			&& "Dynamic descriptors and dynamic offsets sizes must match." );
	}

	void BindDescriptorSetCommand::apply()const
	{
		glLogCommand( "BindDescriptorSetCommand" );
		for ( auto & write : m_descriptorSet.getCombinedTextureSamplers() )
		{
			bindCombinedSampler( m_device, write );
		}

		for ( auto & write : m_descriptorSet.getSamplers() )
		{
			bindSampler( m_device, write );
		}

		for ( auto & write : m_descriptorSet.getSampledTextures() )
		{
			bindSampledTexture( m_device, write );
		}

		for ( auto & write : m_descriptorSet.getStorageTextures() )
		{
			bindStorageTexture( m_device, write );
		}

		for ( auto & write : m_descriptorSet.getUniformBuffers() )
		{
			bindUniformBuffer( m_device, write );
		}

		for ( auto & write : m_descriptorSet.getStorageBuffers() )
		{
			bindStorageBuffer( m_device, write );
		}

		for ( auto & write : m_descriptorSet.getTexelBuffers() )
		{
			bindTexelBuffer( m_device, write );
		}

		bindDynamicBuffers( m_device, m_descriptorSet.getDynamicBuffers(), m_dynamicOffsets );
	}

	CommandPtr BindDescriptorSetCommand::clone()const
	{
		return std::make_unique< BindDescriptorSetCommand >( *this );
	}
}
