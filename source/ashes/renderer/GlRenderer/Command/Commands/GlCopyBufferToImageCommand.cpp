/*
This file belongs to Ashes.
See LICENSE file in root folder.
*/
#include "Command/Commands/GlCopyBufferToImageCommand.hpp"

#include "Buffer/GlBuffer.hpp"
#include "Image/GlImage.hpp"
#include "Image/GlImageView.hpp"
#include "Miscellaneous/GlCallLogger.hpp"

#include "ashesgl_api.hpp"

namespace ashes::gl
{
	void buildCopyBufferToImageCommand( VkDevice device
		, VkBufferImageCopy copyInfo
		, VkBuffer src
		, VkImage dst
		, CmdList & list )
	{
		glLogCommand( list, "CopyBufferToImageCommand" );
		auto copyTarget = convert( device
			, get( dst )->getType()
			, get( dst )->getArrayLayers()
			, get( dst )->getCreateFlags() );
		list.push_back( makeCmd< OpType::eBindBuffer >( GL_BUFFER_TARGET_PIXEL_UNPACK
			, get( src )->getInternal() ) );
		list.push_back( makeCmd< OpType::ePixelStore >( GL_UNPACK_ALIGNMENT, 1 ) );
		list.push_back( makeCmd< OpType::eBindTexture >( copyTarget
			, get( dst )->getInternal() ) );

		if ( isCompressedFormat( get( dst )->getFormat() ) )
		{
			switch ( copyTarget )
			{
			case GL_TEXTURE_1D:
				list.push_back( makeCmd< OpType::eCompressedTexSubImage1D >( copyTarget
					, copyInfo.imageSubresource.mipLevel
					, copyInfo.imageOffset.x
					, copyInfo.imageExtent.width
					, getInternalFormat( get( dst )->getFormat() )
					, int32_t( getSize( copyInfo.imageExtent, get( dst )->getFormat() ) )
					, int32_t( copyInfo.bufferOffset ) ) );
				break;

			case GL_TEXTURE_2D:
				list.push_back( makeCmd< OpType::eCompressedTexSubImage2D >( copyTarget
					, copyInfo.imageSubresource.mipLevel
					, copyInfo.imageOffset.x
					, copyInfo.imageOffset.y
					, copyInfo.imageExtent.width
					, copyInfo.imageExtent.height
					, getInternalFormat( get( dst )->getFormat() )
					, int32_t( getSize( copyInfo.imageExtent, get( dst )->getFormat() ) )
					, int32_t( copyInfo.bufferOffset ) ) );
				break;

			case GL_TEXTURE_3D:
				list.push_back( makeCmd< OpType::eCompressedTexSubImage3D >( copyTarget
					, copyInfo.imageSubresource.mipLevel
					, copyInfo.imageOffset.x
					, copyInfo.imageOffset.y
					, copyInfo.imageOffset.z
					, copyInfo.imageExtent.width
					, copyInfo.imageExtent.height
					, copyInfo.imageExtent.depth
					, getInternalFormat( get( dst )->getFormat() )
					, int32_t( getSize( copyInfo.imageExtent, get( dst )->getFormat() ) )
					, int32_t( copyInfo.bufferOffset ) ) );

			case GL_TEXTURE_1D_ARRAY:
				list.push_back( makeCmd< OpType::eCompressedTexSubImage2D >( copyTarget
					, copyInfo.imageSubresource.mipLevel
					, copyInfo.imageOffset.x
					, int32_t( copyInfo.imageSubresource.baseArrayLayer )
					, copyInfo.imageExtent.width
					, copyInfo.imageSubresource.layerCount
					, getInternalFormat( get( dst )->getFormat() )
					, int32_t( getSize( copyInfo.imageExtent, get( dst )->getFormat() ) )
					, int32_t( copyInfo.bufferOffset ) ) );
				break;

			case GL_TEXTURE_2D_ARRAY:
				list.push_back( makeCmd< OpType::eCompressedTexSubImage3D >( copyTarget
					, copyInfo.imageSubresource.mipLevel
					, copyInfo.imageOffset.x
					, copyInfo.imageOffset.y
					, int32_t( copyInfo.imageSubresource.baseArrayLayer )
					, copyInfo.imageExtent.width
					, copyInfo.imageExtent.height
					, copyInfo.imageSubresource.layerCount
					, getInternalFormat( get( dst )->getFormat() )
					, int32_t( getSize( copyInfo.imageExtent, get( dst )->getFormat() ) )
					, int32_t( copyInfo.bufferOffset ) ) );
				break;

			case GL_TEXTURE_CUBE:
				list.push_back( makeCmd< OpType::eCompressedTexSubImage2D >( GlTextureType( GL_TEXTURE_CUBE_POSITIVE_X + copyInfo.imageSubresource.baseArrayLayer )
					, copyInfo.imageSubresource.mipLevel
					, copyInfo.imageOffset.x
					, copyInfo.imageOffset.y
					, copyInfo.imageExtent.width
					, copyInfo.imageExtent.height
					, getInternalFormat( get( dst )->getFormat() )
					, int32_t( getSize( copyInfo.imageExtent, get( dst )->getFormat() ) )
					, int32_t( copyInfo.bufferOffset ) ) );
				break;

			case GL_TEXTURE_CUBE_ARRAY:
				list.push_back( makeCmd< OpType::eCompressedTexSubImage3D >( GlTextureType( GL_TEXTURE_CUBE_POSITIVE_X + ( copyInfo.imageSubresource.baseArrayLayer % 6u ) )
					, copyInfo.imageSubresource.mipLevel
					, copyInfo.imageOffset.x
					, copyInfo.imageOffset.y
					, int32_t( copyInfo.imageSubresource.baseArrayLayer / 6u )
					, copyInfo.imageExtent.width
					, copyInfo.imageExtent.height
					, copyInfo.imageSubresource.layerCount / 6u
					, getInternalFormat( get( dst )->getFormat() )
					, int32_t( getSize( copyInfo.imageExtent, get( dst )->getFormat() ) )
					, int32_t( copyInfo.bufferOffset ) ) );
				break;

			default:
				// Noop
				break;
			}
		}
		else
		{
			auto internal = getInternalFormat( get( dst )->getFormat() );
			auto format{ getFormat( internal ) };
			auto type{ getType( internal ) };

			switch ( copyTarget )
			{
			case GL_TEXTURE_1D:
				list.push_back( makeCmd< OpType::eTexSubImage1D >( copyTarget
					, copyInfo.imageSubresource.mipLevel
					, copyInfo.imageOffset.x
					, copyInfo.imageExtent.width
					, format
					, type
					, int32_t( copyInfo.bufferOffset ) ) );
				break;

			case GL_TEXTURE_2D:
				list.push_back( makeCmd< OpType::eTexSubImage2D >( copyTarget
					, copyInfo.imageSubresource.mipLevel
					, copyInfo.imageOffset.x
					, copyInfo.imageOffset.y
					, copyInfo.imageExtent.width
					, copyInfo.imageExtent.height
					, format
					, type
					, int32_t( copyInfo.bufferOffset ) ) );
				break;

			case GL_TEXTURE_3D:
				list.push_back( makeCmd< OpType::eTexSubImage3D >( copyTarget
					, copyInfo.imageSubresource.mipLevel
					, copyInfo.imageOffset.x
					, copyInfo.imageOffset.y
					, copyInfo.imageOffset.z
					, copyInfo.imageExtent.width
					, copyInfo.imageExtent.height
					, copyInfo.imageExtent.depth
					, format
					, type
					, int32_t( copyInfo.bufferOffset ) ) );
				break;

			case GL_TEXTURE_1D_ARRAY:
				list.push_back( makeCmd< OpType::eTexSubImage2D >( copyTarget
					, copyInfo.imageSubresource.mipLevel
					, copyInfo.imageOffset.x
					, int32_t( copyInfo.imageSubresource.baseArrayLayer )
					, copyInfo.imageExtent.width
					, copyInfo.imageSubresource.layerCount
					, format
					, type
					, int32_t( copyInfo.bufferOffset ) ) );
				break;

			case GL_TEXTURE_2D_ARRAY:
				list.push_back( makeCmd< OpType::eTexSubImage3D >( copyTarget
					, copyInfo.imageSubresource.mipLevel
					, copyInfo.imageOffset.x
					, copyInfo.imageOffset.y
					, int32_t( copyInfo.imageSubresource.baseArrayLayer )
					, copyInfo.imageExtent.width
					, copyInfo.imageExtent.height
					, copyInfo.imageSubresource.layerCount
					, format
					, type
					, int32_t( copyInfo.bufferOffset ) ) );
				break;

			case GL_TEXTURE_CUBE:
				list.push_back( makeCmd< OpType::eTexSubImage2D >( GlTextureType( GL_TEXTURE_CUBE_POSITIVE_X + copyInfo.imageSubresource.baseArrayLayer )
					, copyInfo.imageSubresource.mipLevel
					, copyInfo.imageOffset.x
					, copyInfo.imageOffset.y
					, copyInfo.imageExtent.width
					, copyInfo.imageExtent.height
					, format
					, type
					, int32_t( copyInfo.bufferOffset ) ) );
				break;

			case GL_TEXTURE_CUBE_ARRAY:
				list.push_back( makeCmd< OpType::eTexSubImage3D >( GlTextureType( GL_TEXTURE_CUBE_POSITIVE_X + ( copyInfo.imageSubresource.baseArrayLayer % 6u ) )
					, copyInfo.imageSubresource.mipLevel
					, copyInfo.imageOffset.x
					, copyInfo.imageOffset.y
					, int32_t( copyInfo.imageSubresource.baseArrayLayer / 6u )
					, copyInfo.imageExtent.width
					, copyInfo.imageExtent.height
					, copyInfo.imageSubresource.layerCount / 6u
					, format
					, type
					, int32_t( copyInfo.bufferOffset ) ) );
				break;

			default:
				// Noop
				break;
			}
		}

		list.push_back( makeCmd< OpType::eBindBuffer >( GL_BUFFER_TARGET_PIXEL_UNPACK
			, 0u ) );
		list.push_back( makeCmd< OpType::eBindTexture >( copyTarget
			, 0u ) );
	}
}
