/*
This file belongs to Ashes.
See LICENSE file in root folder.
*/
#ifndef ___AshesPP_Extent2D_HPP___
#define ___AshesPP_Extent2D_HPP___
#pragma once

#include "AshesPP/AshesPPPrerequisites.hpp"

#include <algorithm>
#include <cassert>

#if defined( max )
#undef max
#endif

namespace ashespp
{
	/**
	*\~english
	*\brief
	*	Retrieves the minimal VkExtent2D for given pixel format.
	*\param[in] format
	*	The pixel format.
	*\return
	*	The VkExtent2D.
	*\~french
	*\brief
	*	Donne l'VkExtent2D minimales pour le format de pixels donné.
	*\param[in] format
	*	Le format de pixel.
	*\return
	*	L'VkExtent2D.
	*/
	inline VkExtent2D getMinimalExtent2D( VkFormat format )noexcept
	{
		VkExtent2D result{ 1, 1 };

		if ( isCompressedFormat( format ) )
		{
			if ( isBCFormat( format )
				|| isETC2Format( format )
				|| isEACFormat( format ) )
			{
				result.width = 4;
				result.height = 4;
			}
			else if ( isASTCFormat( format ) )
			{
				switch ( format )
				{
				case VkFormat::VK_FORMAT_ASTC_4x4_UNORM_BLOCK:
				case VkFormat::VK_FORMAT_ASTC_4x4_SRGB_BLOCK:
					result.width = 4;
					result.height = 4;
					break;
				case VkFormat::VK_FORMAT_ASTC_5x4_UNORM_BLOCK:
				case VkFormat::VK_FORMAT_ASTC_5x4_SRGB_BLOCK:
					result.width = 5;
					result.height = 4;
					break;
				case VkFormat::VK_FORMAT_ASTC_5x5_UNORM_BLOCK:
				case VkFormat::VK_FORMAT_ASTC_5x5_SRGB_BLOCK:
					result.width = 5;
					result.height = 5;
					break;
				case VkFormat::VK_FORMAT_ASTC_6x5_UNORM_BLOCK:
				case VkFormat::VK_FORMAT_ASTC_6x5_SRGB_BLOCK:
					result.width = 6;
					result.height = 5;
					break;
				case VkFormat::VK_FORMAT_ASTC_6x6_UNORM_BLOCK:
				case VkFormat::VK_FORMAT_ASTC_6x6_SRGB_BLOCK:
					result.width = 6;
					result.height = 6;
					break;
				case VkFormat::VK_FORMAT_ASTC_8x5_UNORM_BLOCK:
				case VkFormat::VK_FORMAT_ASTC_8x5_SRGB_BLOCK:
					result.width = 8;
					result.height = 5;
					break;
				case VkFormat::VK_FORMAT_ASTC_8x6_UNORM_BLOCK:
				case VkFormat::VK_FORMAT_ASTC_8x6_SRGB_BLOCK:
					result.width = 8;
					result.height = 6;
					break;
				case VkFormat::VK_FORMAT_ASTC_8x8_UNORM_BLOCK:
				case VkFormat::VK_FORMAT_ASTC_8x8_SRGB_BLOCK:
					result.width = 8;
					result.height = 8;
					break;
				case VkFormat::VK_FORMAT_ASTC_10x5_UNORM_BLOCK:
				case VkFormat::VK_FORMAT_ASTC_10x5_SRGB_BLOCK:
					result.width = 10;
					result.height = 5;
					break;
				case VkFormat::VK_FORMAT_ASTC_10x6_UNORM_BLOCK:
				case VkFormat::VK_FORMAT_ASTC_10x6_SRGB_BLOCK:
					result.width = 10;
					result.height = 6;
					break;
				case VkFormat::VK_FORMAT_ASTC_10x8_UNORM_BLOCK:
				case VkFormat::VK_FORMAT_ASTC_10x8_SRGB_BLOCK:
					result.width = 10;
					result.height = 8;
					break;
				case VkFormat::VK_FORMAT_ASTC_10x10_UNORM_BLOCK:
				case VkFormat::VK_FORMAT_ASTC_10x10_SRGB_BLOCK:
					result.width = 10;
					result.height = 10;
					break;
				case VkFormat::VK_FORMAT_ASTC_12x10_UNORM_BLOCK:
				case VkFormat::VK_FORMAT_ASTC_12x10_SRGB_BLOCK:
					result.width = 12;
					result.height = 10;
					break;
				case VkFormat::VK_FORMAT_ASTC_12x12_UNORM_BLOCK:
				case VkFormat::VK_FORMAT_ASTC_12x12_SRGB_BLOCK:
					result.width = 12;
					result.height = 12;
					break;
				}
			}
			else
			{
				assert( false && "Unsupported compressed format." );
			}
		}

		return result;
	}
	/**
	*\~english
	*\brief
	*	Checks if the given extent fits the given format.
	*\param[in] extent
	*	The dimensions.
	*\param[in] format
	*	The pixel format.
	*\return
	*	\p true if the extent is compatible with the format.
	*\~french
	*\brief
	*	Vérifie que les dimensiosn données sont compatibles avec le format donné.
	*\param[in] extent
	*	Les dimensions.
	*\param[in] format
	*	Le format de pixel.
	*\return
	*	\p true si les dimensiosn sont compatibles avec le format.
	*/
	inline bool checkExtent( VkFormat format, VkExtent2D const & extent )
	{
		auto minimal = getMinimalExtent2D( format );
		return extent.width >= minimal.width
			&& extent.height >= minimal.height;
	}
	/**
	*\~english
	*\brief
	*	Retrieves the byte size of given pixel format and dimensions.
	*\param[in] extent
	*	The dimensions.
	*\param[in] format
	*	The pixel format.
	*\return
	*	The byte size.
	*\~french
	*\brief
	*	Donne le nombre d'octets du format de pixels et les dimensions donnés.
	*\param[in] extent
	*	Les dimensions.
	*\param[in] format
	*	Le format de pixel.
	*\return
	*	Le nombre d'octets.
	*/
	inline uint32_t getSize( VkExtent2D const & extent
		, VkFormat format )noexcept
	{
		auto result = std::max( 1u, extent.width )
			* std::max( 1u, extent.height );

		if ( !isCompressedFormat( format ) )
		{
			result *= getSize( format );
		}
		else
		{
			auto minimal = getMinimalExtent2D( format );
			auto size = minimal.width * minimal.height;

			if ( ( result % size ) == 0 )
			{
				result /= size;

				if ( isBCFormat( format ) )
				{
					result *= getBCSize( format );
				}
				else if ( isETC2Format( format ) )
				{
					result *= getETC2Size( format );
				}
				else if ( isEACFormat( format ) )
				{
					result *= getEACSize( format );
				}
			}
			else if ( result < size )
			{
				if ( isBCFormat( format ) )
				{
					result = getBCSize( format );
				}
				else if ( isETC2Format( format ) )
				{
					result = getETC2Size( format );
				}
				else if ( isEACFormat( format ) )
				{
					result = getEACSize( format );
				}
			}
			else
			{
				assert( false );
			}
		}

		return result;
	}
}

#endif
