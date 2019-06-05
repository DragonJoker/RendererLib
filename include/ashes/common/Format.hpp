/*
This file belongs to Ashes.
See LICENSE file in root folder
*/
#pragma once
#ifndef ___Ashes_common_Format_HPP___
#define ___Ashes_common_Format_HPP___

#define VK_NO_PROTOTYPES
#include <vulkan/vulkan.h>

#include <cstdint>
#include <string>
#include <algorithm>

#ifdef min
#	undef min
#	undef max
#	undef abs
#endif

namespace ashes
{
	/**
	*\brief
	*	Computes an aligned size.
	*\param[in] size
	*	The unaligned size.
	*\param[in] align
	*	The alignment value.
	*\return
	*	The aligned size.
	*/
	inline VkDeviceSize getAlignedSize( VkDeviceSize size, VkDeviceSize align )
	{
		VkDeviceSize result = 0u;

		while ( size > align )
		{
			size -= align;
			result += align;
		}

		return result + align;
	}
	/**
	*\param[in] format
	*	The pixel format.
	*\return
	*	The byte size of given non compressed pixel format.
	*/
	uint32_t getSize( VkFormat format )noexcept;
	/**
	*\return
	*	The given format components count.
	*\param[in] format
	*	The VkFormat.
	*/
	uint32_t getCount( VkFormat format )noexcept;
	/**
	*\param[in] format
	*	The pixel format.
	*\return
	*	The byte size of given BC compressed pixel format, for a 4x4 pixels block.
	*/
	uint32_t getBCSize( VkFormat format )noexcept;
	/**
	*\param[in] format
	*	The pixel format.
	*\return
	*	The byte size of given ETC2 compressed pixel format, for a 4x4 pixels block.
	*/
	uint32_t getETC2Size( VkFormat format )noexcept;
	/**
	*\param[in] format
	*	The pixel format.
	*\return
	*	The byte size of given EAC compressed pixel format, for a 4x4 pixels block.
	*/
	uint32_t getEACSize( VkFormat format )noexcept;
	/**
	*\brief
	*	Tells if the given VkFormat is usable in depth and stencil buffers.
	*\param[in] format
	*	The VkFormat.
	*\return
	*	\p true if it is usable in depth and stencil buffers.
	*/
	bool isDepthStencilFormat( VkFormat format )noexcept;
	/**
	*\brief
	*	Tells if the given VkFormat is usable in stencil buffers.
	*\param[in] format
	*	The VkFormat.
	*\return
	*	\p true if it is usable in stencil buffers.
	*/
	bool isStencilFormat( VkFormat format )noexcept;
	/**
	*\brief
	*	Tells if the given VkFormat is usable in depth buffers.
	*\param[in] format
	*	The VkFormat.
	*\return
	*	\p true if it is usable in depth buffers.
	*/
	bool isDepthFormat( VkFormat format )noexcept;
	/**
	*\return
	*	\p true if given pixel format is a BC pixel format.
	*\param[in] format
	*	The pixel format.
	*/
	bool isBCFormat( VkFormat format )noexcept;
	/**
	*\return
	*	\p true if given pixel format is a ETC2 pixel format.
	*\param[in] format
	*	The pixel format.
	*/
	bool isETC2Format( VkFormat format )noexcept;
	/**
	*\return
	*	\p true if given pixel format is a EAC pixel format.
	*\param[in] format
	*	The pixel format.
	*/
	bool isEACFormat( VkFormat format )noexcept;
	/**
	*\return
	*	\p true if given pixel format is a ASTC pixel format.
	*\param[in] format
	*	The pixel format.
	*/
	bool isASTCFormat( VkFormat format )noexcept;
	/**
	*\return
	*	\p true if given pixel format is a YCBCR pixel format.
	*\param[in] format
	*	The pixel format.
	*/
	bool isYCBCRFormat( VkFormat format )noexcept;
	/**
	*\return
	*	\p true if given pixel format is a PVRTC pixel format.
	*\param[in] format
	*	The pixel format.
	*/
	bool isPVRTCFormat( VkFormat format )noexcept;
	/**
	*\return
	*	\p true if given pixel format is a compressed pixel format.
	*\param[in] format
	*	The pixel format.
	*/
	inline bool isCompressedFormat( VkFormat format )noexcept
	{
		return isBCFormat( format )
			|| isEACFormat( format )
			|| isETC2Format( format )
			|| isASTCFormat( format )
			|| isYCBCRFormat( format )
			|| isPVRTCFormat( format );
	}
	/**
	*\brief
	*	Tells if the given VkFormat is usable in depth and/or stencil buffers.
	*\param[in] format
	*	The VkFormat.
	*\return
	*	\p true if it is usable in depth and/or stencil buffers.
	*/
	inline bool isDepthOrStencilFormat( VkFormat format )noexcept
	{
		return isDepthStencilFormat( format )
			|| isStencilFormat( format )
			|| isDepthFormat( format );
	}
	/**
	*\brief
	*	Gets the name of the given element.
	*\param[in] value
	*	The element.
	*\return
	*	The name.
	*/
	std::string getName( VkFormat value );
	/**
	*\brief
	*	Retrieves the minimal VkExtent2D for given pixel format.
	*\param[in] format
	*	The pixel format.
	*\return
	*	The VkExtent2D.
	*/
	VkExtent2D getMinimalExtent2D( VkFormat format )noexcept;
	/**
	*\brief
	*	Checks if the given extent fits the given format.
	*\param[in] extent
	*	The dimensions.
	*\param[in] format
	*	The pixel format.
	*\return
	*	\p true if the extent is compatible with the format.
	*/
	inline bool checkExtent( VkFormat format, VkExtent2D const & extent )
	{
		auto minimal = getMinimalExtent2D( format );
		return extent.width >= minimal.width
			&& extent.height >= minimal.height;
	}
	/**
	*\brief
	*	Retrieves the byte size of given pixel format and dimensions.
	*\param[in] extent
	*	The dimensions.
	*\param[in] format
	*	The pixel format.
	*\return
	*	The byte size.
	*/
	VkDeviceSize getSize( VkExtent2D const & extent
		, VkFormat format )noexcept;
	/**
	*\brief
	*	Retrieves the minimal VkExtent2D for given pixel format.
	*\param[in] format
	*	The pixel format.
	*\return
	*	The VkExtent2D.
	*/
	inline VkExtent3D getMinimalExtent3D( VkFormat format )noexcept
	{
		auto const minimal = getMinimalExtent2D( format );
		return VkExtent3D{ minimal.width, minimal.height, 1 };
	}
	/**
	*\brief
	*	Checks if the given extent fits the given format.
	*\param[in] extent
	*	The dimensions.
	*\param[in] format
	*	The pixel format.
	*\return
	*	\p true if the extent is compatible with the format.
	*/
	inline bool checkExtent( VkFormat format, VkExtent3D const & extent )
	{
		return checkExtent( format, VkExtent2D{ extent.width, extent.height } );
	}
	/**
	*\brief
	*	Retrieves the byte size of given pixel format and dimensions.
	*\param[in] extent
	*	The dimensions.
	*\param[in] format
	*	The pixel format.
	*\return
	*	The byte size.
	*/
	inline VkDeviceSize getSize( VkExtent3D const & extent
		, VkFormat format )noexcept
	{
		return getSize( VkExtent2D{ extent.width, extent.height }, format )
			* std::max( 1u, extent.depth );
	}
	/**
	*\brief
	*	Retrieves the aspects mask matching given VkFormat.
	*\param[in] format
	*	The VkFormat.
	*\return
	*	The aspects.
	*/
	inline VkImageAspectFlags getAspectMask( VkFormat format )noexcept
	{
		return isDepthStencilFormat( format )
			? VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT
			: ( isDepthFormat( format )
				? VK_IMAGE_ASPECT_DEPTH_BIT
				: ( isStencilFormat( format )
					? VK_IMAGE_ASPECT_STENCIL_BIT
					: VK_IMAGE_ASPECT_COLOR_BIT ) );
	}
	/**
	*\brief
	*	Retrieves the real extent for the given mipmap level.
	*\param[in] extent
	*	The level 0 extent.
	*\param[in] mipLevel
	*	The mipmap level.
	*\return
	*	The mipmap level extent.
	*/
	template< typename T >
	inline T getSubresourceDimension( T const & extent
		, uint32_t mipLevel )
	{
		return extent >> mipLevel;
	}
	/**
	*\brief
	*	Retrieves the real extent for the given mipmap level.
	*\param[in] extent
	*	The level 0 extent.
	*\param[in] mipLevel
	*	The mipmap level.
	*\return
	*	The dimensions.
	*/
	inline VkExtent3D getSubresourceDimensions( VkExtent3D const & extent
		, uint32_t mipLevel )
	{
		return
		{
			getSubresourceDimension( extent.width, mipLevel ),
			getSubresourceDimension( extent.height, mipLevel ),
			extent.depth
		};
	}
	/**
	*\param[in] extent
	*	The dimensions.
	*\param[in] format
	*	The pixel format.
	*\param[in] mipLevel
	*	The mipmap level for which dimensions are computed.
	*\return
	*	The byte size of given pixel format and dimensions.
	*/
	inline VkDeviceSize getSize( VkExtent3D const & extent
		, VkFormat format
		, uint32_t mipLevel )noexcept
	{
		return getSize( getSubresourceDimensions( extent, mipLevel ), format );
	}
	/**
	*\brief
	*	Retrieves the real extent for the given mipmap level.
	*\param[in] extent
	*	The level 0 extent.
	*\param[in] mipLevel
	*	The mipmap level for which dimensions are computed.
	*\return
	*	The dimensions.
	*/
	inline VkExtent3D getSubresourceDimensions( VkExtent2D const & extent
		, uint32_t mipLevel )
	{
		return
		{
			getSubresourceDimension( extent.width, mipLevel ),
			getSubresourceDimension( extent.height, mipLevel ),
		};
	}
	/**
	*\brief
	*	Retrieves the byte size of given pixel format and dimensions.
	*\param[in] extent
	*	The dimensions.
	*\param[in] format
	*	The pixel format.
	*\param[in] mipLevel
	*	The mipmap level for which dimensions are computed.
	*\return
	*	The byte size.
	*/
	inline VkDeviceSize getSize( VkExtent2D const & extent
		, VkFormat format
		, uint32_t mipLevel )noexcept
	{
		return getSize( getSubresourceDimensions( extent, mipLevel ), format );
	}
}

#endif
