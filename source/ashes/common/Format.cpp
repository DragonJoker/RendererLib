#include "common/Format.hpp"

#include <cassert>
#include <map>

namespace ashes
{
	uint32_t getSize( VkFormat format )noexcept
	{
		assert( !isCompressedFormat( format ) );

		switch ( format )
		{
		case VK_FORMAT_R4G4_UNORM_PACK8:
		case VK_FORMAT_R8_UNORM:
		case VK_FORMAT_R8_SNORM:
		case VK_FORMAT_R8_USCALED:
		case VK_FORMAT_R8_SSCALED:
		case VK_FORMAT_R8_UINT:
		case VK_FORMAT_R8_SINT:
		case VK_FORMAT_R8_SRGB:
		case VK_FORMAT_S8_UINT:
			return 1u;

		case VK_FORMAT_R4G4B4A4_UNORM_PACK16:
		case VK_FORMAT_R5G6B5_UNORM_PACK16:
		case VK_FORMAT_B5G6R5_UNORM_PACK16:
		case VK_FORMAT_R5G5B5A1_UNORM_PACK16:
		case VK_FORMAT_B5G5R5A1_UNORM_PACK16:
		case VK_FORMAT_A1R5G5B5_UNORM_PACK16:
		case VK_FORMAT_R8G8_UNORM:
		case VK_FORMAT_R8G8_SNORM:
		case VK_FORMAT_R8G8_USCALED:
		case VK_FORMAT_R8G8_SSCALED:
		case VK_FORMAT_R8G8_UINT:
		case VK_FORMAT_R8G8_SINT:
		case VK_FORMAT_R8G8_SRGB:
		case VK_FORMAT_R16_UNORM:
		case VK_FORMAT_R16_SNORM:
		case VK_FORMAT_R16_USCALED:
		case VK_FORMAT_R16_SSCALED:
		case VK_FORMAT_R16_UINT:
		case VK_FORMAT_R16_SINT:
		case VK_FORMAT_R16_SFLOAT:
		case VK_FORMAT_D16_UNORM:
			return 2u;

		case VK_FORMAT_R8G8B8_UNORM:
		case VK_FORMAT_R8G8B8_SNORM:
		case VK_FORMAT_R8G8B8_USCALED:
		case VK_FORMAT_R8G8B8_SSCALED:
		case VK_FORMAT_R8G8B8_UINT:
		case VK_FORMAT_R8G8B8_SINT:
		case VK_FORMAT_R8G8B8_SRGB:
		case VK_FORMAT_B8G8R8_UNORM:
		case VK_FORMAT_B8G8R8_SNORM:
		case VK_FORMAT_B8G8R8_USCALED:
		case VK_FORMAT_B8G8R8_SSCALED:
		case VK_FORMAT_B8G8R8_UINT:
		case VK_FORMAT_B8G8R8_SINT:
		case VK_FORMAT_B8G8R8_SRGB:
		case VK_FORMAT_D16_UNORM_S8_UINT:
			return 3u;

		case VK_FORMAT_R8G8B8A8_UNORM:
		case VK_FORMAT_R8G8B8A8_SNORM:
		case VK_FORMAT_R8G8B8A8_USCALED:
		case VK_FORMAT_R8G8B8A8_SSCALED:
		case VK_FORMAT_R8G8B8A8_UINT:
		case VK_FORMAT_R8G8B8A8_SINT:
		case VK_FORMAT_R8G8B8A8_SRGB:
		case VK_FORMAT_B8G8R8A8_UNORM:
		case VK_FORMAT_B8G8R8A8_SNORM:
		case VK_FORMAT_B8G8R8A8_USCALED:
		case VK_FORMAT_B8G8R8A8_SSCALED:
		case VK_FORMAT_B8G8R8A8_UINT:
		case VK_FORMAT_B8G8R8A8_SINT:
		case VK_FORMAT_B8G8R8A8_SRGB:
		case VK_FORMAT_A8B8G8R8_UNORM_PACK32:
		case VK_FORMAT_A8B8G8R8_SNORM_PACK32:
		case VK_FORMAT_A8B8G8R8_USCALED_PACK32:
		case VK_FORMAT_A8B8G8R8_SSCALED_PACK32:
		case VK_FORMAT_A8B8G8R8_UINT_PACK32:
		case VK_FORMAT_A8B8G8R8_SINT_PACK32:
		case VK_FORMAT_A8B8G8R8_SRGB_PACK32:
		case VK_FORMAT_A2R10G10B10_UNORM_PACK32:
		case VK_FORMAT_A2R10G10B10_SNORM_PACK32:
		case VK_FORMAT_A2R10G10B10_USCALED_PACK32:
		case VK_FORMAT_A2R10G10B10_SSCALED_PACK32:
		case VK_FORMAT_A2R10G10B10_UINT_PACK32:
		case VK_FORMAT_A2R10G10B10_SINT_PACK32:
		case VK_FORMAT_A2B10G10R10_UNORM_PACK32:
		case VK_FORMAT_A2B10G10R10_SNORM_PACK32:
		case VK_FORMAT_A2B10G10R10_USCALED_PACK32:
		case VK_FORMAT_A2B10G10R10_SSCALED_PACK32:
		case VK_FORMAT_A2B10G10R10_UINT_PACK32:
		case VK_FORMAT_A2B10G10R10_SINT_PACK32:
		case VK_FORMAT_R16G16_UNORM:
		case VK_FORMAT_R16G16_SNORM:
		case VK_FORMAT_R16G16_USCALED:
		case VK_FORMAT_R16G16_SSCALED:
		case VK_FORMAT_R16G16_UINT:
		case VK_FORMAT_R16G16_SINT:
		case VK_FORMAT_R16G16_SFLOAT:
		case VK_FORMAT_R32_UINT:
		case VK_FORMAT_R32_SINT:
		case VK_FORMAT_R32_SFLOAT:
		case VK_FORMAT_B10G11R11_UFLOAT_PACK32:
		case VK_FORMAT_E5B9G9R9_UFLOAT_PACK32:
		case VK_FORMAT_X8_D24_UNORM_PACK32:
		case VK_FORMAT_D32_SFLOAT:
		case VK_FORMAT_D24_UNORM_S8_UINT:
		case VK_FORMAT_D32_SFLOAT_S8_UINT:
			return 4u;

		case VK_FORMAT_R16G16B16_UNORM:
		case VK_FORMAT_R16G16B16_SNORM:
		case VK_FORMAT_R16G16B16_USCALED:
		case VK_FORMAT_R16G16B16_SSCALED:
		case VK_FORMAT_R16G16B16_UINT:
		case VK_FORMAT_R16G16B16_SINT:
		case VK_FORMAT_R16G16B16_SFLOAT:
			return 6u;

		case VK_FORMAT_R16G16B16A16_UNORM:
		case VK_FORMAT_R16G16B16A16_SNORM:
		case VK_FORMAT_R16G16B16A16_USCALED:
		case VK_FORMAT_R16G16B16A16_SSCALED:
		case VK_FORMAT_R16G16B16A16_UINT:
		case VK_FORMAT_R16G16B16A16_SINT:
		case VK_FORMAT_R16G16B16A16_SFLOAT:
		case VK_FORMAT_R32G32_UINT:
		case VK_FORMAT_R32G32_SINT:
		case VK_FORMAT_R32G32_SFLOAT:
		case VK_FORMAT_R64_UINT:
		case VK_FORMAT_R64_SINT:
		case VK_FORMAT_R64_SFLOAT:
			return 8u;

		case VK_FORMAT_R32G32B32_UINT:
		case VK_FORMAT_R32G32B32_SINT:
		case VK_FORMAT_R32G32B32_SFLOAT:
			return 12u;

		case VK_FORMAT_R32G32B32A32_UINT:
		case VK_FORMAT_R32G32B32A32_SINT:
		case VK_FORMAT_R32G32B32A32_SFLOAT:
		case VK_FORMAT_R64G64_UINT:
		case VK_FORMAT_R64G64_SINT:
		case VK_FORMAT_R64G64_SFLOAT:
			return 16u;

		case VK_FORMAT_R64G64B64_UINT:
		case VK_FORMAT_R64G64B64_SINT:
		case VK_FORMAT_R64G64B64_SFLOAT:
			return 24u;

		case VK_FORMAT_R64G64B64A64_UINT:
		case VK_FORMAT_R64G64B64A64_SINT:
		case VK_FORMAT_R64G64B64A64_SFLOAT:
			return 32u;

		default:
			assert( false && "Unsupported pixel format" );
			return 0u;
		}
	}
	
	uint32_t getCount( VkFormat format )noexcept
	{
		assert( !isCompressedFormat( format ) );

		switch ( format )
		{
		case VK_FORMAT_R8_UNORM:
		case VK_FORMAT_R8_SNORM:
		case VK_FORMAT_R8_USCALED:
		case VK_FORMAT_R8_SSCALED:
		case VK_FORMAT_R8_UINT:
		case VK_FORMAT_R8_SINT:
		case VK_FORMAT_R8_SRGB:
		case VK_FORMAT_S8_UINT:
		case VK_FORMAT_R16_UNORM:
		case VK_FORMAT_R16_SNORM:
		case VK_FORMAT_R16_USCALED:
		case VK_FORMAT_R16_SSCALED:
		case VK_FORMAT_R16_UINT:
		case VK_FORMAT_R16_SINT:
		case VK_FORMAT_R16_SFLOAT:
		case VK_FORMAT_D16_UNORM:
		case VK_FORMAT_R32_UINT:
		case VK_FORMAT_R32_SINT:
		case VK_FORMAT_R32_SFLOAT:
		case VK_FORMAT_X8_D24_UNORM_PACK32:
		case VK_FORMAT_D32_SFLOAT:
		case VK_FORMAT_R64_UINT:
		case VK_FORMAT_R64_SINT:
		case VK_FORMAT_R64_SFLOAT:
		case VK_FORMAT_EAC_R11_UNORM_BLOCK:
		case VK_FORMAT_EAC_R11_SNORM_BLOCK:
		case VK_FORMAT_R12X4_UNORM_PACK16:
		case VK_FORMAT_R10X6_UNORM_PACK16:
			return 1u;

		case VK_FORMAT_R4G4_UNORM_PACK8:
		case VK_FORMAT_R8G8_UNORM:
		case VK_FORMAT_R8G8_SNORM:
		case VK_FORMAT_R8G8_USCALED:
		case VK_FORMAT_R8G8_SSCALED:
		case VK_FORMAT_R8G8_UINT:
		case VK_FORMAT_R8G8_SINT:
		case VK_FORMAT_R8G8_SRGB:
		case VK_FORMAT_D16_UNORM_S8_UINT:
		case VK_FORMAT_R16G16_UNORM:
		case VK_FORMAT_R16G16_SNORM:
		case VK_FORMAT_R16G16_USCALED:
		case VK_FORMAT_R16G16_SSCALED:
		case VK_FORMAT_R16G16_UINT:
		case VK_FORMAT_R16G16_SINT:
		case VK_FORMAT_R16G16_SFLOAT:
		case VK_FORMAT_D24_UNORM_S8_UINT:
		case VK_FORMAT_D32_SFLOAT_S8_UINT:
		case VK_FORMAT_R32G32_UINT:
		case VK_FORMAT_R32G32_SINT:
		case VK_FORMAT_R32G32_SFLOAT:
		case VK_FORMAT_R64G64_UINT:
		case VK_FORMAT_R64G64_SINT:
		case VK_FORMAT_R64G64_SFLOAT:
		case VK_FORMAT_EAC_R11G11_UNORM_BLOCK:
		case VK_FORMAT_EAC_R11G11_SNORM_BLOCK:
		case VK_FORMAT_R12X4G12X4_UNORM_2PACK16:
		case VK_FORMAT_R10X6G10X6_UNORM_2PACK16:
			return 2u;

		case VK_FORMAT_R5G6B5_UNORM_PACK16:
		case VK_FORMAT_B5G6R5_UNORM_PACK16:
		case VK_FORMAT_R8G8B8_UNORM:
		case VK_FORMAT_R8G8B8_SNORM:
		case VK_FORMAT_R8G8B8_USCALED:
		case VK_FORMAT_R8G8B8_SSCALED:
		case VK_FORMAT_R8G8B8_UINT:
		case VK_FORMAT_R8G8B8_SINT:
		case VK_FORMAT_R8G8B8_SRGB:
		case VK_FORMAT_B8G8R8_UNORM:
		case VK_FORMAT_B8G8R8_SNORM:
		case VK_FORMAT_B8G8R8_USCALED:
		case VK_FORMAT_B8G8R8_SSCALED:
		case VK_FORMAT_B8G8R8_UINT:
		case VK_FORMAT_B8G8R8_SINT:
		case VK_FORMAT_B8G8R8_SRGB:
		case VK_FORMAT_B10G11R11_UFLOAT_PACK32:
		case VK_FORMAT_E5B9G9R9_UFLOAT_PACK32:
		case VK_FORMAT_R16G16B16_UNORM:
		case VK_FORMAT_R16G16B16_SNORM:
		case VK_FORMAT_R16G16B16_USCALED:
		case VK_FORMAT_R16G16B16_SSCALED:
		case VK_FORMAT_R16G16B16_UINT:
		case VK_FORMAT_R16G16B16_SINT:
		case VK_FORMAT_R16G16B16_SFLOAT:
		case VK_FORMAT_R32G32B32_UINT:
		case VK_FORMAT_R32G32B32_SINT:
		case VK_FORMAT_R32G32B32_SFLOAT:
		case VK_FORMAT_R64G64B64_UINT:
		case VK_FORMAT_R64G64B64_SINT:
		case VK_FORMAT_R64G64B64_SFLOAT:
		case VK_FORMAT_BC1_RGB_SRGB_BLOCK:
		case VK_FORMAT_BC1_RGB_UNORM_BLOCK:
		case VK_FORMAT_BC2_UNORM_BLOCK:
		case VK_FORMAT_BC2_SRGB_BLOCK:
		case VK_FORMAT_BC3_UNORM_BLOCK:
		case VK_FORMAT_BC3_SRGB_BLOCK:
		case VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK:
		case VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK:
		case VK_FORMAT_ASTC_4x4_UNORM_BLOCK:
		case VK_FORMAT_ASTC_4x4_SRGB_BLOCK:
		case VK_FORMAT_ASTC_5x4_UNORM_BLOCK:
		case VK_FORMAT_ASTC_5x4_SRGB_BLOCK:
		case VK_FORMAT_ASTC_5x5_UNORM_BLOCK:
		case VK_FORMAT_ASTC_5x5_SRGB_BLOCK:
		case VK_FORMAT_ASTC_6x5_UNORM_BLOCK:
		case VK_FORMAT_ASTC_6x5_SRGB_BLOCK:
		case VK_FORMAT_ASTC_6x6_UNORM_BLOCK:
		case VK_FORMAT_ASTC_6x6_SRGB_BLOCK:
		case VK_FORMAT_ASTC_8x5_UNORM_BLOCK:
		case VK_FORMAT_ASTC_8x5_SRGB_BLOCK:
		case VK_FORMAT_ASTC_8x6_UNORM_BLOCK:
		case VK_FORMAT_ASTC_8x6_SRGB_BLOCK:
		case VK_FORMAT_ASTC_8x8_UNORM_BLOCK:
		case VK_FORMAT_ASTC_8x8_SRGB_BLOCK:
		case VK_FORMAT_ASTC_10x5_UNORM_BLOCK:
		case VK_FORMAT_ASTC_10x5_SRGB_BLOCK:
		case VK_FORMAT_ASTC_10x6_UNORM_BLOCK:
		case VK_FORMAT_ASTC_10x6_SRGB_BLOCK:
		case VK_FORMAT_ASTC_10x8_UNORM_BLOCK:
		case VK_FORMAT_ASTC_10x8_SRGB_BLOCK:
		case VK_FORMAT_ASTC_10x10_UNORM_BLOCK:
		case VK_FORMAT_ASTC_10x10_SRGB_BLOCK:
		case VK_FORMAT_ASTC_12x10_UNORM_BLOCK:
		case VK_FORMAT_ASTC_12x10_SRGB_BLOCK:
		case VK_FORMAT_ASTC_12x12_UNORM_BLOCK:
		case VK_FORMAT_ASTC_12x12_SRGB_BLOCK:
		case VK_FORMAT_G8B8G8R8_422_UNORM:
		case VK_FORMAT_B8G8R8G8_422_UNORM:
		case VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM:
		case VK_FORMAT_G8_B8R8_2PLANE_420_UNORM:
		case VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM:
		case VK_FORMAT_G8_B8R8_2PLANE_422_UNORM:
		case VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM:
		case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16:
		case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16:
		case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16:
		case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16:
		case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16:
		case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16:
		case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16:
		case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16:
		case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16:
		case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16:
		case VK_FORMAT_G16B16G16R16_422_UNORM:
		case VK_FORMAT_B16G16R16G16_422_UNORM:
		case VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM:
		case VK_FORMAT_G16_B16R16_2PLANE_420_UNORM:
		case VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM:
		case VK_FORMAT_G16_B16R16_2PLANE_422_UNORM:
		case VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM:
		case VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG:
		case VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG:
		case VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG:
		case VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG:
		case VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG:
		case VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG:
		case VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG:
		case VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG:
			return 3u;

		case VK_FORMAT_R5G5B5A1_UNORM_PACK16:
		case VK_FORMAT_B5G5R5A1_UNORM_PACK16:
		case VK_FORMAT_A1R5G5B5_UNORM_PACK16:
		case VK_FORMAT_R4G4B4A4_UNORM_PACK16:
		case VK_FORMAT_R8G8B8A8_UNORM:
		case VK_FORMAT_R8G8B8A8_SNORM:
		case VK_FORMAT_R8G8B8A8_USCALED:
		case VK_FORMAT_R8G8B8A8_SSCALED:
		case VK_FORMAT_R8G8B8A8_UINT:
		case VK_FORMAT_R8G8B8A8_SINT:
		case VK_FORMAT_R8G8B8A8_SRGB:
		case VK_FORMAT_B8G8R8A8_UNORM:
		case VK_FORMAT_B8G8R8A8_SNORM:
		case VK_FORMAT_B8G8R8A8_USCALED:
		case VK_FORMAT_B8G8R8A8_SSCALED:
		case VK_FORMAT_B8G8R8A8_UINT:
		case VK_FORMAT_B8G8R8A8_SINT:
		case VK_FORMAT_B8G8R8A8_SRGB:
		case VK_FORMAT_A8B8G8R8_UNORM_PACK32:
		case VK_FORMAT_A8B8G8R8_SNORM_PACK32:
		case VK_FORMAT_A8B8G8R8_USCALED_PACK32:
		case VK_FORMAT_A8B8G8R8_SSCALED_PACK32:
		case VK_FORMAT_A8B8G8R8_UINT_PACK32:
		case VK_FORMAT_A8B8G8R8_SINT_PACK32:
		case VK_FORMAT_A8B8G8R8_SRGB_PACK32:
		case VK_FORMAT_A2R10G10B10_UNORM_PACK32:
		case VK_FORMAT_A2R10G10B10_SNORM_PACK32:
		case VK_FORMAT_A2R10G10B10_USCALED_PACK32:
		case VK_FORMAT_A2R10G10B10_SSCALED_PACK32:
		case VK_FORMAT_A2R10G10B10_UINT_PACK32:
		case VK_FORMAT_A2R10G10B10_SINT_PACK32:
		case VK_FORMAT_A2B10G10R10_UNORM_PACK32:
		case VK_FORMAT_A2B10G10R10_SNORM_PACK32:
		case VK_FORMAT_A2B10G10R10_USCALED_PACK32:
		case VK_FORMAT_A2B10G10R10_SSCALED_PACK32:
		case VK_FORMAT_A2B10G10R10_UINT_PACK32:
		case VK_FORMAT_A2B10G10R10_SINT_PACK32:
		case VK_FORMAT_R16G16B16A16_UNORM:
		case VK_FORMAT_R16G16B16A16_SNORM:
		case VK_FORMAT_R16G16B16A16_USCALED:
		case VK_FORMAT_R16G16B16A16_SSCALED:
		case VK_FORMAT_R16G16B16A16_UINT:
		case VK_FORMAT_R16G16B16A16_SINT:
		case VK_FORMAT_R16G16B16A16_SFLOAT:
		case VK_FORMAT_R32G32B32A32_UINT:
		case VK_FORMAT_R32G32B32A32_SINT:
		case VK_FORMAT_R32G32B32A32_SFLOAT:
		case VK_FORMAT_R64G64B64A64_UINT:
		case VK_FORMAT_R64G64B64A64_SINT:
		case VK_FORMAT_R64G64B64A64_SFLOAT:
		case VK_FORMAT_BC1_RGBA_SRGB_BLOCK:
		case VK_FORMAT_BC1_RGBA_UNORM_BLOCK:
		case VK_FORMAT_BC4_UNORM_BLOCK:
		case VK_FORMAT_BC4_SNORM_BLOCK:
		case VK_FORMAT_BC5_UNORM_BLOCK:
		case VK_FORMAT_BC5_SNORM_BLOCK:
		case VK_FORMAT_BC6H_UFLOAT_BLOCK:
		case VK_FORMAT_BC6H_SFLOAT_BLOCK:
		case VK_FORMAT_BC7_UNORM_BLOCK:
		case VK_FORMAT_BC7_SRGB_BLOCK:
		case VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK:
		case VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK:
		case VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK:
		case VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK:
		case VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16:
		case VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16:
		case VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16:
		case VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16:
		case VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16:
		case VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16:
			return 4u;

		default:
			assert( false && "Unsupported pixel format" );
			return 0u;
		}
	}

	uint32_t getBCSize( VkFormat format )noexcept
	{
		assert( isBCFormat( format ) );

		switch ( format )
		{
		case VK_FORMAT_BC1_RGBA_SRGB_BLOCK:
		case VK_FORMAT_BC1_RGBA_UNORM_BLOCK:
		case VK_FORMAT_BC1_RGB_SRGB_BLOCK:
		case VK_FORMAT_BC1_RGB_UNORM_BLOCK:
			return 8u;

		case VK_FORMAT_BC2_UNORM_BLOCK:
		case VK_FORMAT_BC2_SRGB_BLOCK:
			return 16u;

		case VK_FORMAT_BC3_UNORM_BLOCK:
		case VK_FORMAT_BC3_SRGB_BLOCK:
			return 16u;

		case VK_FORMAT_BC4_UNORM_BLOCK:
		case VK_FORMAT_BC4_SNORM_BLOCK:
			return 8u;

		case VK_FORMAT_BC5_UNORM_BLOCK:
		case VK_FORMAT_BC5_SNORM_BLOCK:
			return 16u;

		case VK_FORMAT_BC6H_UFLOAT_BLOCK:
		case VK_FORMAT_BC6H_SFLOAT_BLOCK:
			return 16u;

		case VK_FORMAT_BC7_UNORM_BLOCK:
		case VK_FORMAT_BC7_SRGB_BLOCK:
			return 16u;

		default:
			assert( false && "Unsupported pixel format" );
			return 0u;
		}
	}

	uint32_t getETC2Size( VkFormat format )noexcept
	{
		assert( isETC2Format( format ) );

		switch ( format )
		{
		case VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK:
		case VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK:
			return 8u;

		case VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK:
		case VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK:
			return 8u;

		case VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK:
		case VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK:
			return 16u;

		default:
			assert( false && "Unsupported pixel format" );
			return 0u;
		}
	}

	uint32_t getEACSize( VkFormat format )noexcept
	{
		assert( isEACFormat( format ) );

		switch ( format )
		{
		case VK_FORMAT_EAC_R11_UNORM_BLOCK:
		case VK_FORMAT_EAC_R11_SNORM_BLOCK:
			return 8u;

		case VK_FORMAT_EAC_R11G11_UNORM_BLOCK:
		case VK_FORMAT_EAC_R11G11_SNORM_BLOCK:
			return 16u;

		default:
			assert( false && "Unsupported pixel format" );
			return 0u;
		}
	}

	bool isDepthStencilFormat( VkFormat format )noexcept
	{
		return format == VK_FORMAT_D16_UNORM_S8_UINT
			|| format == VK_FORMAT_D24_UNORM_S8_UINT
			|| format == VK_FORMAT_D32_SFLOAT_S8_UINT;
	}

	bool isStencilFormat( VkFormat format )noexcept
	{
		return format == VK_FORMAT_S8_UINT;
	}

	bool isDepthFormat( VkFormat format )noexcept
	{
		return format == VK_FORMAT_D16_UNORM
			|| format == VK_FORMAT_X8_D24_UNORM_PACK32
			|| format == VK_FORMAT_D32_SFLOAT;
	}

	bool isBCFormat( VkFormat format )noexcept
	{
		return format >= VK_FORMAT_BC1_RGB_UNORM_BLOCK
			&& format <= VK_FORMAT_BC7_SRGB_BLOCK;
	}

	bool isETC2Format( VkFormat format )noexcept
	{
		return format >= VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK
			&& format <= VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK;
	}

	bool isEACFormat( VkFormat format )noexcept
	{
		return format >= VK_FORMAT_EAC_R11_UNORM_BLOCK
			&& format <= VK_FORMAT_EAC_R11G11_SNORM_BLOCK;
	}

	bool isASTCFormat( VkFormat format )noexcept
	{
		return format >= VK_FORMAT_ASTC_4x4_UNORM_BLOCK
			&& format <= VK_FORMAT_ASTC_12x12_SRGB_BLOCK;
	}

	bool isYCBCRFormat( VkFormat format )noexcept
	{
		return format >= VK_FORMAT_G8B8G8R8_422_UNORM
			&& format <= VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM;
	}

	bool isPVRTCFormat( VkFormat format )noexcept
	{
		return format >= VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG
			&& format <= VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG;
	}

	std::string getName( VkFormat value )
	{
		static std::map< VkFormat, std::string > const names
		{
			{ VK_FORMAT_UNDEFINED, "UNDEFINED" },
			{ VK_FORMAT_R4G4_UNORM_PACK8, "R4G4_UNORM_PACK8" },
			{ VK_FORMAT_R4G4B4A4_UNORM_PACK16, "R4G4B4A4_UNORM_PACK16" },
			{ VK_FORMAT_B4G4R4A4_UNORM_PACK16, "B4G4R4A4_UNORM_PACK16" },
			{ VK_FORMAT_R5G6B5_UNORM_PACK16, "R5G6B5_UNORM_PACK16" },
			{ VK_FORMAT_B5G6R5_UNORM_PACK16, "B5G6R5_UNORM_PACK16" },
			{ VK_FORMAT_R5G5B5A1_UNORM_PACK16, "R5G5B5A1_UNORM_PACK16" },
			{ VK_FORMAT_B5G5R5A1_UNORM_PACK16, "B5G5R5A1_UNORM_PACK16" },
			{ VK_FORMAT_A1R5G5B5_UNORM_PACK16, "A1R5G5B5_UNORM_PACK16" },
			{ VK_FORMAT_R8_UNORM, "R8_UNORM" },
			{ VK_FORMAT_R8_SNORM, "R8_SNORM" },
			{ VK_FORMAT_R8_USCALED, "R8_USCALED" },
			{ VK_FORMAT_R8_SSCALED, "R8_SSCALED" },
			{ VK_FORMAT_R8_UINT, "R8_UINT" },
			{ VK_FORMAT_R8_SINT, "R8_SINT" },
			{ VK_FORMAT_R8_SRGB, "R8_SRGB" },
			{ VK_FORMAT_R8G8_UNORM, "R8G8_UNORM" },
			{ VK_FORMAT_R8G8_SNORM, "R8G8_SNORM" },
			{ VK_FORMAT_R8G8_USCALED, "R8G8_USCALED" },
			{ VK_FORMAT_R8G8_SSCALED, "R8G8_SSCALED" },
			{ VK_FORMAT_R8G8_UINT, "R8G8_UINT" },
			{ VK_FORMAT_R8G8_SINT, "R8G8_SINT" },
			{ VK_FORMAT_R8G8_SRGB, "R8G8_SRGB" },
			{ VK_FORMAT_R8G8B8_UNORM, "R8G8B8_UNORM" },
			{ VK_FORMAT_R8G8B8_SNORM, "R8G8B8_SNORM" },
			{ VK_FORMAT_R8G8B8_USCALED, "R8G8B8_USCALED" },
			{ VK_FORMAT_R8G8B8_SSCALED, "R8G8B8_SSCALED" },
			{ VK_FORMAT_R8G8B8_UINT, "R8G8B8_UINT" },
			{ VK_FORMAT_R8G8B8_SINT, "R8G8B8_SINT" },
			{ VK_FORMAT_R8G8B8_SRGB, "R8G8B8_SRGB" },
			{ VK_FORMAT_B8G8R8_UNORM, "B8G8R8_UNORM" },
			{ VK_FORMAT_B8G8R8_SNORM, "B8G8R8_SNORM" },
			{ VK_FORMAT_B8G8R8_USCALED, "B8G8R8_USCALED" },
			{ VK_FORMAT_B8G8R8_SSCALED, "B8G8R8_SSCALED" },
			{ VK_FORMAT_B8G8R8_UINT, "B8G8R8_UINT" },
			{ VK_FORMAT_B8G8R8_SINT, "B8G8R8_SINT" },
			{ VK_FORMAT_B8G8R8_SRGB, "B8G8R8_SRGB" },
			{ VK_FORMAT_R8G8B8A8_UNORM, "R8G8B8A8_UNORM" },
			{ VK_FORMAT_R8G8B8A8_SNORM, "R8G8B8A8_SNORM" },
			{ VK_FORMAT_R8G8B8A8_USCALED, "R8G8B8A8_USCALED" },
			{ VK_FORMAT_R8G8B8A8_SSCALED, "R8G8B8A8_SSCALED" },
			{ VK_FORMAT_R8G8B8A8_UINT, "R8G8B8A8_UINT" },
			{ VK_FORMAT_R8G8B8A8_SINT, "R8G8B8A8_SINT" },
			{ VK_FORMAT_R8G8B8A8_SRGB, "R8G8B8A8_SRGB" },
			{ VK_FORMAT_B8G8R8A8_UNORM, "B8G8R8A8_UNORM" },
			{ VK_FORMAT_B8G8R8A8_SNORM, "B8G8R8A8_SNORM" },
			{ VK_FORMAT_B8G8R8A8_USCALED, "B8G8R8A8_USCALED" },
			{ VK_FORMAT_B8G8R8A8_SSCALED, "B8G8R8A8_SSCALED" },
			{ VK_FORMAT_B8G8R8A8_UINT, "B8G8R8A8_UINT" },
			{ VK_FORMAT_B8G8R8A8_SINT, "B8G8R8A8_SINT" },
			{ VK_FORMAT_B8G8R8A8_SRGB, "B8G8R8A8_SRGB" },
			{ VK_FORMAT_A8B8G8R8_UNORM_PACK32, "A8B8G8R8_UNORM_PACK32" },
			{ VK_FORMAT_A8B8G8R8_SNORM_PACK32, "A8B8G8R8_SNORM_PACK32" },
			{ VK_FORMAT_A8B8G8R8_USCALED_PACK32, "A8B8G8R8_USCALED_PACK32" },
			{ VK_FORMAT_A8B8G8R8_SSCALED_PACK32, "A8B8G8R8_SSCALED_PACK32" },
			{ VK_FORMAT_A8B8G8R8_UINT_PACK32, "A8B8G8R8_UINT_PACK32" },
			{ VK_FORMAT_A8B8G8R8_SINT_PACK32, "A8B8G8R8_SINT_PACK32" },
			{ VK_FORMAT_A8B8G8R8_SRGB_PACK32, "A8B8G8R8_SRGB_PACK32" },
			{ VK_FORMAT_A2R10G10B10_UNORM_PACK32, "A2R10G10B10_UNORM_PACK32" },
			{ VK_FORMAT_A2R10G10B10_SNORM_PACK32, "A2R10G10B10_SNORM_PACK32" },
			{ VK_FORMAT_A2R10G10B10_USCALED_PACK32, "A2R10G10B10_USCALED_PACK32" },
			{ VK_FORMAT_A2R10G10B10_SSCALED_PACK32, "A2R10G10B10_SSCALED_PACK32" },
			{ VK_FORMAT_A2R10G10B10_UINT_PACK32, "A2R10G10B10_UINT_PACK32" },
			{ VK_FORMAT_A2R10G10B10_SINT_PACK32, "A2R10G10B10_SINT_PACK32" },
			{ VK_FORMAT_A2B10G10R10_UNORM_PACK32, "A2B10G10R10_UNORM_PACK32" },
			{ VK_FORMAT_A2B10G10R10_SNORM_PACK32, "A2B10G10R10_SNORM_PACK32" },
			{ VK_FORMAT_A2B10G10R10_USCALED_PACK32, "A2B10G10R10_USCALED_PACK32" },
			{ VK_FORMAT_A2B10G10R10_SSCALED_PACK32, "A2B10G10R10_SSCALED_PACK32" },
			{ VK_FORMAT_A2B10G10R10_UINT_PACK32, "A2B10G10R10_UINT_PACK32" },
			{ VK_FORMAT_A2B10G10R10_SINT_PACK32, "A2B10G10R10_SINT_PACK32" },
			{ VK_FORMAT_R16_UNORM, "R16_UNORM" },
			{ VK_FORMAT_R16_SNORM, "R16_SNORM" },
			{ VK_FORMAT_R16_USCALED, "R16_USCALED" },
			{ VK_FORMAT_R16_SSCALED, "R16_SSCALED" },
			{ VK_FORMAT_R16_UINT, "R16_UINT" },
			{ VK_FORMAT_R16_SINT, "R16_SINT" },
			{ VK_FORMAT_R16_SFLOAT, "R16_SFLOAT" },
			{ VK_FORMAT_R16G16_UNORM, "R16G16_UNORM" },
			{ VK_FORMAT_R16G16_SNORM, "R16G16_SNORM" },
			{ VK_FORMAT_R16G16_USCALED, "R16G16_USCALED" },
			{ VK_FORMAT_R16G16_SSCALED, "R16G16_SSCALED" },
			{ VK_FORMAT_R16G16_UINT, "R16G16_UINT" },
			{ VK_FORMAT_R16G16_SINT, "R16G16_SINT" },
			{ VK_FORMAT_R16G16_SFLOAT, "R16G16_SFLOAT" },
			{ VK_FORMAT_R16G16B16_UNORM, "R16G16B16_UNORM" },
			{ VK_FORMAT_R16G16B16_SNORM, "R16G16B16_SNORM" },
			{ VK_FORMAT_R16G16B16_USCALED, "R16G16B16_USCALED" },
			{ VK_FORMAT_R16G16B16_SSCALED, "R16G16B16_SSCALED" },
			{ VK_FORMAT_R16G16B16_UINT, "R16G16B16_UINT" },
			{ VK_FORMAT_R16G16B16_SINT, "R16G16B16_SINT" },
			{ VK_FORMAT_R16G16B16_SFLOAT, "R16G16B16_SFLOAT" },
			{ VK_FORMAT_R16G16B16A16_UNORM, "R16G16B16A16_UNORM" },
			{ VK_FORMAT_R16G16B16A16_SNORM, "R16G16B16A16_SNORM" },
			{ VK_FORMAT_R16G16B16A16_USCALED, "R16G16B16A16_USCALED" },
			{ VK_FORMAT_R16G16B16A16_SSCALED, "R16G16B16A16_SSCALED" },
			{ VK_FORMAT_R16G16B16A16_UINT, "R16G16B16A16_UINT" },
			{ VK_FORMAT_R16G16B16A16_SINT, "R16G16B16A16_SINT" },
			{ VK_FORMAT_R16G16B16A16_SFLOAT, "R16G16B16A16_SFLOAT" },
			{ VK_FORMAT_R32_UINT, "R32_UINT" },
			{ VK_FORMAT_R32_SINT, "R32_SINT" },
			{ VK_FORMAT_R32_SFLOAT, "R32_SFLOAT" },
			{ VK_FORMAT_R32G32_UINT, "R32G32_UINT" },
			{ VK_FORMAT_R32G32_SINT, "R32G32_SINT" },
			{ VK_FORMAT_R32G32_SFLOAT, "R32G32_SFLOAT" },
			{ VK_FORMAT_R32G32B32_UINT, "R32G32B32_UINT" },
			{ VK_FORMAT_R32G32B32_SINT, "R32G32B32_SINT" },
			{ VK_FORMAT_R32G32B32_SFLOAT, "R32G32B32_SFLOAT" },
			{ VK_FORMAT_R32G32B32A32_UINT, "R32G32B32A32_UINT" },
			{ VK_FORMAT_R32G32B32A32_SINT, "R32G32B32A32_SINT" },
			{ VK_FORMAT_R32G32B32A32_SFLOAT, "R32G32B32A32_SFLOAT" },
			{ VK_FORMAT_R64_UINT, "R64_UINT" },
			{ VK_FORMAT_R64_SINT, "R64_SINT" },
			{ VK_FORMAT_R64_SFLOAT, "R64_SFLOAT" },
			{ VK_FORMAT_R64G64_UINT, "R64G64_UINT" },
			{ VK_FORMAT_R64G64_SINT, "R64G64_SINT" },
			{ VK_FORMAT_R64G64_SFLOAT, "R64G64_SFLOAT" },
			{ VK_FORMAT_R64G64B64_UINT, "R64G64B64_UINT" },
			{ VK_FORMAT_R64G64B64_SINT, "R64G64B64_SINT" },
			{ VK_FORMAT_R64G64B64_SFLOAT, "R64G64B64_SFLOAT" },
			{ VK_FORMAT_R64G64B64A64_UINT, "R64G64B64A64_UINT" },
			{ VK_FORMAT_R64G64B64A64_SINT, "R64G64B64A64_SINT" },
			{ VK_FORMAT_R64G64B64A64_SFLOAT, "R64G64B64A64_SFLOAT" },
			{ VK_FORMAT_B10G11R11_UFLOAT_PACK32, "B10G11R11_UFLOAT_PACK32" },
			{ VK_FORMAT_E5B9G9R9_UFLOAT_PACK32, "E5B9G9R9_UFLOAT_PACK32" },
			{ VK_FORMAT_D16_UNORM, "D16_UNORM" },
			{ VK_FORMAT_X8_D24_UNORM_PACK32, "X8_D24_UNORM_PACK32" },
			{ VK_FORMAT_D32_SFLOAT, "D32_SFLOAT" },
			{ VK_FORMAT_S8_UINT, "S8_UINT" },
			{ VK_FORMAT_D16_UNORM_S8_UINT, "D16_UNORM_S8_UINT" },
			{ VK_FORMAT_D24_UNORM_S8_UINT, "D24_UNORM_S8_UINT" },
			{ VK_FORMAT_D32_SFLOAT_S8_UINT, "D32_SFLOAT_S8_UINT" },
			{ VK_FORMAT_BC1_RGB_UNORM_BLOCK, "BC1_RGB_UNORM_BLOCK" },
			{ VK_FORMAT_BC1_RGB_SRGB_BLOCK, "BC1_RGB_SRGB_BLOCK" },
			{ VK_FORMAT_BC1_RGBA_UNORM_BLOCK, "BC1_RGBA_UNORM_BLOCK" },
			{ VK_FORMAT_BC1_RGBA_SRGB_BLOCK, "BC1_RGBA_SRGB_BLOCK" },
			{ VK_FORMAT_BC2_UNORM_BLOCK, "BC2_UNORM_BLOCK" },
			{ VK_FORMAT_BC2_SRGB_BLOCK, "BC2_SRGB_BLOCK" },
			{ VK_FORMAT_BC3_UNORM_BLOCK, "BC3_UNORM_BLOCK" },
			{ VK_FORMAT_BC3_SRGB_BLOCK, "BC3_SRGB_BLOCK" },
			{ VK_FORMAT_BC4_UNORM_BLOCK, "BC4_UNORM_BLOCK" },
			{ VK_FORMAT_BC4_SNORM_BLOCK, "BC4_SNORM_BLOCK" },
			{ VK_FORMAT_BC5_UNORM_BLOCK, "BC5_UNORM_BLOCK" },
			{ VK_FORMAT_BC5_SNORM_BLOCK, "BC5_SNORM_BLOCK" },
			{ VK_FORMAT_BC6H_UFLOAT_BLOCK, "BC6H_UFLOAT_BLOCK" },
			{ VK_FORMAT_BC6H_SFLOAT_BLOCK, "BC6H_SFLOAT_BLOCK" },
			{ VK_FORMAT_BC7_UNORM_BLOCK, "BC7_UNORM_BLOCK" },
			{ VK_FORMAT_BC7_SRGB_BLOCK, "BC7_SRGB_BLOCK" },
			{ VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK, "ETC2_R8G8B8_UNORM_BLOCK" },
			{ VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK, "ETC2_R8G8B8_SRGB_BLOCK" },
			{ VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK, "ETC2_R8G8B8A1_UNORM_BLOCK" },
			{ VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK, "ETC2_R8G8B8A1_SRGB_BLOCK" },
			{ VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK, "ETC2_R8G8B8A8_UNORM_BLOCK" },
			{ VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK, "ETC2_R8G8B8A8_SRGB_BLOCK" },
			{ VK_FORMAT_EAC_R11_UNORM_BLOCK, "EAC_R11_UNORM_BLOCK" },
			{ VK_FORMAT_EAC_R11_SNORM_BLOCK, "EAC_R11_SNORM_BLOCK" },
			{ VK_FORMAT_EAC_R11G11_UNORM_BLOCK, "EAC_R11G11_UNORM_BLOCK" },
			{ VK_FORMAT_EAC_R11G11_SNORM_BLOCK, "EAC_R11G11_SNORM_BLOCK" },
			{ VK_FORMAT_ASTC_4x4_UNORM_BLOCK, "ASTC_4x4_UNORM_BLOCK" },
			{ VK_FORMAT_ASTC_4x4_SRGB_BLOCK, "ASTC_4x4_SRGB_BLOCK" },
			{ VK_FORMAT_ASTC_5x4_UNORM_BLOCK, "ASTC_5x4_UNORM_BLOCK" },
			{ VK_FORMAT_ASTC_5x4_SRGB_BLOCK, "ASTC_5x4_SRGB_BLOCK" },
			{ VK_FORMAT_ASTC_5x5_UNORM_BLOCK, "ASTC_5x5_UNORM_BLOCK" },
			{ VK_FORMAT_ASTC_5x5_SRGB_BLOCK, "ASTC_5x5_SRGB_BLOCK" },
			{ VK_FORMAT_ASTC_6x5_UNORM_BLOCK, "ASTC_6x5_UNORM_BLOCK" },
			{ VK_FORMAT_ASTC_6x5_SRGB_BLOCK, "ASTC_6x5_SRGB_BLOCK" },
			{ VK_FORMAT_ASTC_6x6_UNORM_BLOCK, "ASTC_6x6_UNORM_BLOCK" },
			{ VK_FORMAT_ASTC_6x6_SRGB_BLOCK, "ASTC_6x6_SRGB_BLOCK" },
			{ VK_FORMAT_ASTC_8x5_UNORM_BLOCK, "ASTC_8x5_UNORM_BLOCK" },
			{ VK_FORMAT_ASTC_8x5_SRGB_BLOCK, "ASTC_8x5_SRGB_BLOCK" },
			{ VK_FORMAT_ASTC_8x6_UNORM_BLOCK, "ASTC_8x6_UNORM_BLOCK" },
			{ VK_FORMAT_ASTC_8x6_SRGB_BLOCK, "ASTC_8x6_SRGB_BLOCK" },
			{ VK_FORMAT_ASTC_8x8_UNORM_BLOCK, "ASTC_8x8_UNORM_BLOCK" },
			{ VK_FORMAT_ASTC_8x8_SRGB_BLOCK, "ASTC_8x8_SRGB_BLOCK" },
			{ VK_FORMAT_ASTC_10x5_UNORM_BLOCK, "ASTC_10x5_UNORM_BLOCK" },
			{ VK_FORMAT_ASTC_10x5_SRGB_BLOCK, "ASTC_10x5_SRGB_BLOCK" },
			{ VK_FORMAT_ASTC_10x6_UNORM_BLOCK, "ASTC_10x6_UNORM_BLOCK" },
			{ VK_FORMAT_ASTC_10x6_SRGB_BLOCK, "ASTC_10x6_SRGB_BLOCK" },
			{ VK_FORMAT_ASTC_10x8_UNORM_BLOCK, "ASTC_10x8_UNORM_BLOCK" },
			{ VK_FORMAT_ASTC_10x8_SRGB_BLOCK, "ASTC_10x8_SRGB_BLOCK" },
			{ VK_FORMAT_ASTC_10x10_UNORM_BLOCK, "ASTC_10x10_UNORM_BLOCK" },
			{ VK_FORMAT_ASTC_10x10_SRGB_BLOCK, "ASTC_10x10_SRGB_BLOCK" },
			{ VK_FORMAT_ASTC_12x10_UNORM_BLOCK, "ASTC_12x10_UNORM_BLOCK" },
			{ VK_FORMAT_ASTC_12x10_SRGB_BLOCK, "ASTC_12x10_SRGB_BLOCK" },
			{ VK_FORMAT_ASTC_12x12_UNORM_BLOCK, "ASTC_12x12_UNORM_BLOCK" },
			{ VK_FORMAT_ASTC_12x12_SRGB_BLOCK, "ASTC_12x12_SRGB_BLOCK" },
			{ VK_FORMAT_G8B8G8R8_422_UNORM, "G8B8G8R8_422_UNORM" },
			{ VK_FORMAT_B8G8R8G8_422_UNORM, "B8G8R8G8_422_UNORM" },
			{ VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM, "G8_B8_R8_3PLANE_420_UNORM" },
			{ VK_FORMAT_G8_B8R8_2PLANE_420_UNORM, "G8_B8R8_2PLANE_420_UNORM" },
			{ VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM, "G8_B8_R8_3PLANE_422_UNORM" },
			{ VK_FORMAT_G8_B8R8_2PLANE_422_UNORM, "G8_B8R8_2PLANE_422_UNORM" },
			{ VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM, "G8_B8_R8_3PLANE_444_UNORM" },
			{ VK_FORMAT_R10X6_UNORM_PACK16, "R10X6_UNORM_PACK16" },
			{ VK_FORMAT_R10X6G10X6_UNORM_2PACK16, "R10X6G10X6_UNORM_2PACK16" },
			{ VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16, "R10X6G10X6B10X6A10X6_UNORM_4PACK16" },
			{ VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16, "G10X6B10X6G10X6R10X6_422_UNORM_4PACK16" },
			{ VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16, "B10X6G10X6R10X6G10X6_422_UNORM_4PACK16" },
			{ VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16, "G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16" },
			{ VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16, "G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16" },
			{ VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16, "G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16" },
			{ VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16, "G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16" },
			{ VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16, "G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16" },
			{ VK_FORMAT_R12X4_UNORM_PACK16, "R12X4_UNORM_PACK16" },
			{ VK_FORMAT_R12X4G12X4_UNORM_2PACK16, "R12X4G12X4_UNORM_2PACK16" },
			{ VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16, "R12X4G12X4B12X4A12X4_UNORM_4PACK16" },
			{ VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16, "G12X4B12X4G12X4R12X4_422_UNORM_4PACK16" },
			{ VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16, "B12X4G12X4R12X4G12X4_422_UNORM_4PACK16" },
			{ VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16, "G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16" },
			{ VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16, "G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16" },
			{ VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16, "G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16" },
			{ VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16, "G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16" },
			{ VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16, "G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16" },
			{ VK_FORMAT_G16B16G16R16_422_UNORM, "G16B16G16R16_422_UNORM" },
			{ VK_FORMAT_B16G16R16G16_422_UNORM, "B16G16R16G16_422_UNORM" },
			{ VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM, "G16_B16_R16_3PLANE_420_UNORM" },
			{ VK_FORMAT_G16_B16R16_2PLANE_420_UNORM, "G16_B16R16_2PLANE_420_UNORM" },
			{ VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM, "G16_B16_R16_3PLANE_422_UNORM" },
			{ VK_FORMAT_G16_B16R16_2PLANE_422_UNORM, "G16_B16R16_2PLANE_422_UNORM" },
			{ VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM, "G16_B16_R16_3PLANE_444_UNORM" },
			{ VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG, "PVRTC1_2BPP_UNORM_BLOCK_IMG" },
			{ VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG, "PVRTC1_4BPP_UNORM_BLOCK_IMG" },
			{ VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG, "PVRTC2_2BPP_UNORM_BLOCK_IMG" },
			{ VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG, "PVRTC2_4BPP_UNORM_BLOCK_IMG" },
			{ VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG, "PVRTC1_2BPP_SRGB_BLOCK_IMG" },
			{ VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG, "PVRTC1_4BPP_SRGB_BLOCK_IMG" },
			{ VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG, "PVRTC2_2BPP_SRGB_BLOCK_IMG" },
			{ VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG, "PVRTC2_4BPP_SRGB_BLOCK_IMG" },
		};
		return names.at( value );
	}

	VkExtent2D getMinimalExtent2D( VkFormat format )noexcept
	{
		VkExtent2D result{ 1, 1 };

		if ( ashes::isCompressedFormat( format ) )
		{
			if ( ashes::isBCFormat( format )
				|| ashes::isETC2Format( format )
				|| ashes::isEACFormat( format ) )
			{
				result.width = 4;
				result.height = 4;
			}
			else if ( ashes::isASTCFormat( format ) )
			{
				switch ( format )
				{
				case VK_FORMAT_ASTC_4x4_UNORM_BLOCK:
				case VK_FORMAT_ASTC_4x4_SRGB_BLOCK:
					result.width = 4;
					result.height = 4;
					break;
				case VK_FORMAT_ASTC_5x4_UNORM_BLOCK:
				case VK_FORMAT_ASTC_5x4_SRGB_BLOCK:
					result.width = 5;
					result.height = 4;
					break;
				case VK_FORMAT_ASTC_5x5_UNORM_BLOCK:
				case VK_FORMAT_ASTC_5x5_SRGB_BLOCK:
					result.width = 5;
					result.height = 5;
					break;
				case VK_FORMAT_ASTC_6x5_UNORM_BLOCK:
				case VK_FORMAT_ASTC_6x5_SRGB_BLOCK:
					result.width = 6;
					result.height = 5;
					break;
				case VK_FORMAT_ASTC_6x6_UNORM_BLOCK:
				case VK_FORMAT_ASTC_6x6_SRGB_BLOCK:
					result.width = 6;
					result.height = 6;
					break;
				case VK_FORMAT_ASTC_8x5_UNORM_BLOCK:
				case VK_FORMAT_ASTC_8x5_SRGB_BLOCK:
					result.width = 8;
					result.height = 5;
					break;
				case VK_FORMAT_ASTC_8x6_UNORM_BLOCK:
				case VK_FORMAT_ASTC_8x6_SRGB_BLOCK:
					result.width = 8;
					result.height = 6;
					break;
				case VK_FORMAT_ASTC_8x8_UNORM_BLOCK:
				case VK_FORMAT_ASTC_8x8_SRGB_BLOCK:
					result.width = 8;
					result.height = 8;
					break;
				case VK_FORMAT_ASTC_10x5_UNORM_BLOCK:
				case VK_FORMAT_ASTC_10x5_SRGB_BLOCK:
					result.width = 10;
					result.height = 5;
					break;
				case VK_FORMAT_ASTC_10x6_UNORM_BLOCK:
				case VK_FORMAT_ASTC_10x6_SRGB_BLOCK:
					result.width = 10;
					result.height = 6;
					break;
				case VK_FORMAT_ASTC_10x8_UNORM_BLOCK:
				case VK_FORMAT_ASTC_10x8_SRGB_BLOCK:
					result.width = 10;
					result.height = 8;
					break;
				case VK_FORMAT_ASTC_10x10_UNORM_BLOCK:
				case VK_FORMAT_ASTC_10x10_SRGB_BLOCK:
					result.width = 10;
					result.height = 10;
					break;
				case VK_FORMAT_ASTC_12x10_UNORM_BLOCK:
				case VK_FORMAT_ASTC_12x10_SRGB_BLOCK:
					result.width = 12;
					result.height = 10;
					break;
				case VK_FORMAT_ASTC_12x12_UNORM_BLOCK:
				case VK_FORMAT_ASTC_12x12_SRGB_BLOCK:
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

	VkDeviceSize getSize( VkExtent2D const & extent
		, VkFormat format )noexcept
	{
		VkDeviceSize result = std::max( 1u, extent.width )
			* std::max( 1u, extent.height );

		if ( !ashes::isCompressedFormat( format ) )
		{
			result *= ashes::getSize( format );
		}
		else
		{
			auto minimal = getMinimalExtent2D( format );
			auto size = minimal.width * minimal.height;

			if ( ( result % size ) == 0 )
			{
				result /= size;

				if ( ashes::isBCFormat( format ) )
				{
					result *= ashes::getBCSize( format );
				}
				else if ( ashes::isETC2Format( format ) )
				{
					result *= ashes::getETC2Size( format );
				}
				else if ( ashes::isEACFormat( format ) )
				{
					result *= ashes::getEACSize( format );
				}
			}
			else if ( result < size )
			{
				if ( ashes::isBCFormat( format ) )
				{
					result = ashes::getBCSize( format );
				}
				else if ( ashes::isETC2Format( format ) )
				{
					result = ashes::getETC2Size( format );
				}
				else if ( ashes::isEACFormat( format ) )
				{
					result = ashes::getEACSize( format );
				}
			}
			else
			{
				assert( false );
			}
		}

		return result;
	}

	VkPipelineColorBlendStateCreateInfo const & getDeactivatedColorBlendState()
	{
		static VkPipelineColorBlendStateCreateInfo const value
		{
			VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO,
			nullptr,
			0u,
			VK_FALSE,
			VK_LOGIC_OP_COPY,
			0u,			// Not sure this is valid
			nullptr,	// ...
			{ 0.0f, 0.0f, 0.0f, 0.0f }
		};
		return value;
	}

	VkPipelineDepthStencilStateCreateInfo const & getDeactivatedDepthStencilState()
	{
		static VkPipelineDepthStencilStateCreateInfo const value
		{
			VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO,
			nullptr,
			0u,
			VK_FALSE,
			VK_FALSE,
			VK_COMPARE_OP_ALWAYS,
			VK_FALSE,
			VK_FALSE,
		{
			VK_STENCIL_OP_KEEP,
			VK_STENCIL_OP_KEEP,
			VK_STENCIL_OP_KEEP,
			VK_COMPARE_OP_ALWAYS,
			0xFFFFFFFFu,
			0xFFFFFFFFu,
			0u,
		},
			{
				VK_STENCIL_OP_KEEP,
				VK_STENCIL_OP_KEEP,
				VK_STENCIL_OP_KEEP,
				VK_COMPARE_OP_ALWAYS,
				0xFFFFFFFFu,
				0xFFFFFFFFu,
				0u,
			},
			0.0f,
			1.0f,
		};
		return value;
	}

	VkPipelineDynamicStateCreateInfo const & getDeactivatedDynamicState()
	{
		static VkPipelineDynamicStateCreateInfo const value
		{
			VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO,
			nullptr,
			0u,
			0u,
			nullptr,
		};
		return value;
	}

	VkPipelineInputAssemblyStateCreateInfo const & getDeactivatedInputAssemblyState()
	{
		static VkPipelineInputAssemblyStateCreateInfo const value
		{
			VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO,
			nullptr,
			0u,
			VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST,
			VK_FALSE,
		};
		return value;
	}

	VkPipelineMultisampleStateCreateInfo const & getDeactivatedMultisampleState()
	{
		static VkPipelineMultisampleStateCreateInfo const value
		{
			VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO,
			nullptr,
			0u,
			VK_SAMPLE_COUNT_1_BIT,
			VK_FALSE,
			1.0f,
			nullptr,
			VK_FALSE,
			VK_FALSE,
		};
		return value;
	}

	VkPipelineRasterizationStateCreateInfo const & getDeactivatedRasterizationState()
	{
		static VkPipelineRasterizationStateCreateInfo const value
		{
			VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO,
			nullptr,
			0u,
			VK_FALSE,
			VK_TRUE,	// rasterizerDiscardEnable.
			VK_POLYGON_MODE_FILL,
			VK_CULL_MODE_BACK_BIT,
			VK_FRONT_FACE_COUNTER_CLOCKWISE,
			VK_FALSE,
			0.0f,
			0.0f,
			0.0f,
			1.0f,
		};
		return value;
	}

	VkPipelineTessellationStateCreateInfo const & getDeactivatedTessellationState()
	{
		static VkPipelineTessellationStateCreateInfo const value
		{
			VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO,
			nullptr,
			0u,
			0u,
		};
		return value;
	}

	VkPipelineViewportStateCreateInfo const & getDeactivatedViewportState()
	{
		static VkPipelineViewportStateCreateInfo const value
		{
			VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO,
			nullptr,
			0u,
			0u,
			nullptr,
			0u,
			nullptr,
		};
		return value;
	}
}
