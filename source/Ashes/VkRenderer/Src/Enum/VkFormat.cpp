#include "VkRendererPrerequisites.hpp"

namespace vk_renderer
{
	VkFormat convert( ashes::Format const & format )noexcept
	{
		switch ( format )
		{
		case ashes::Format::eUndefined: return VK_FORMAT_UNDEFINED;
		case ashes::Format::eR4G4_UNORM_PACK8: return VK_FORMAT_R4G4_UNORM_PACK8;
		case ashes::Format::eR4G4B4A4_UNORM_PACK16: return VK_FORMAT_R4G4B4A4_UNORM_PACK16;
		case ashes::Format::eB4G4R4A4_UNORM_PACK16: return VK_FORMAT_B4G4R4A4_UNORM_PACK16;
		case ashes::Format::eR5G6B5_UNORM_PACK16: return VK_FORMAT_R5G6B5_UNORM_PACK16;
		case ashes::Format::eB5G6R5_UNORM_PACK16: return VK_FORMAT_B5G6R5_UNORM_PACK16;
		case ashes::Format::eR5G5B5A1_UNORM_PACK16: return VK_FORMAT_R5G5B5A1_UNORM_PACK16;
		case ashes::Format::eB5G5R5A1_UNORM_PACK16: return VK_FORMAT_B5G5R5A1_UNORM_PACK16;
		case ashes::Format::eA1R5G5B5_UNORM_PACK16: return VK_FORMAT_A1R5G5B5_UNORM_PACK16;
		case ashes::Format::eR8_UNORM: return VK_FORMAT_R8_UNORM;
		case ashes::Format::eR8_SNORM: return VK_FORMAT_R8_SNORM;
		case ashes::Format::eR8_USCALED: return VK_FORMAT_R8_USCALED;
		case ashes::Format::eR8_SSCALED: return VK_FORMAT_R8_SSCALED;
		case ashes::Format::eR8_UINT: return VK_FORMAT_R8_UINT;
		case ashes::Format::eR8_SINT: return VK_FORMAT_R8_SINT;
		case ashes::Format::eR8_SRGB: return VK_FORMAT_R8_SRGB;
		case ashes::Format::eR8G8_UNORM: return VK_FORMAT_R8G8_UNORM;
		case ashes::Format::eR8G8_SNORM: return VK_FORMAT_R8G8_SNORM;
		case ashes::Format::eR8G8_USCALED: return VK_FORMAT_R8G8_USCALED;
		case ashes::Format::eR8G8_SSCALED: return VK_FORMAT_R8G8_SSCALED;
		case ashes::Format::eR8G8_UINT: return VK_FORMAT_R8G8_UINT;
		case ashes::Format::eR8G8_SINT: return VK_FORMAT_R8G8_SINT;
		case ashes::Format::eR8G8_SRGB: return VK_FORMAT_R8G8_SRGB;
		case ashes::Format::eR8G8B8_UNORM: return VK_FORMAT_R8G8B8_UNORM;
		case ashes::Format::eR8G8B8_SNORM: return VK_FORMAT_R8G8B8_SNORM;
		case ashes::Format::eR8G8B8_USCALED: return VK_FORMAT_R8G8B8_USCALED;
		case ashes::Format::eR8G8B8_SSCALED: return VK_FORMAT_R8G8B8_SSCALED;
		case ashes::Format::eR8G8B8_UINT: return VK_FORMAT_R8G8B8_UINT;
		case ashes::Format::eR8G8B8_SINT: return VK_FORMAT_R8G8B8_SINT;
		case ashes::Format::eR8G8B8_SRGB: return VK_FORMAT_R8G8B8_SRGB;
		case ashes::Format::eB8G8R8_UNORM: return VK_FORMAT_B8G8R8_UNORM;
		case ashes::Format::eB8G8R8_SNORM: return VK_FORMAT_B8G8R8_SNORM;
		case ashes::Format::eB8G8R8_USCALED: return VK_FORMAT_B8G8R8_USCALED;
		case ashes::Format::eB8G8R8_SSCALED: return VK_FORMAT_B8G8R8_SSCALED;
		case ashes::Format::eB8G8R8_UINT: return VK_FORMAT_B8G8R8_UINT;
		case ashes::Format::eB8G8R8_SINT: return VK_FORMAT_B8G8R8_SINT;
		case ashes::Format::eB8G8R8_SRGB: return VK_FORMAT_B8G8R8_SRGB;
		case ashes::Format::eR8G8B8A8_UNORM: return VK_FORMAT_R8G8B8A8_UNORM;
		case ashes::Format::eR8G8B8A8_SNORM: return VK_FORMAT_R8G8B8A8_SNORM;
		case ashes::Format::eR8G8B8A8_USCALED: return VK_FORMAT_R8G8B8A8_USCALED;
		case ashes::Format::eR8G8B8A8_SSCALED: return VK_FORMAT_R8G8B8A8_SSCALED;
		case ashes::Format::eR8G8B8A8_UINT: return VK_FORMAT_R8G8B8A8_UINT;
		case ashes::Format::eR8G8B8A8_SINT: return VK_FORMAT_R8G8B8A8_SINT;
		case ashes::Format::eR8G8B8A8_SRGB: return VK_FORMAT_R8G8B8A8_SRGB;
		case ashes::Format::eB8G8R8A8_UNORM: return VK_FORMAT_B8G8R8A8_UNORM;
		case ashes::Format::eB8G8R8A8_SNORM: return VK_FORMAT_B8G8R8A8_SNORM;
		case ashes::Format::eB8G8R8A8_USCALED: return VK_FORMAT_B8G8R8A8_USCALED;
		case ashes::Format::eB8G8R8A8_SSCALED: return VK_FORMAT_B8G8R8A8_SSCALED;
		case ashes::Format::eB8G8R8A8_UINT: return VK_FORMAT_B8G8R8A8_UINT;
		case ashes::Format::eB8G8R8A8_SINT: return VK_FORMAT_B8G8R8A8_SINT;
		case ashes::Format::eB8G8R8A8_SRGB: return VK_FORMAT_B8G8R8A8_SRGB;
		case ashes::Format::eA8B8G8R8_UNORM_PACK32: return VK_FORMAT_A8B8G8R8_UNORM_PACK32;
		case ashes::Format::eA8B8G8R8_SNORM_PACK32: return VK_FORMAT_A8B8G8R8_SNORM_PACK32;
		case ashes::Format::eA8B8G8R8_USCALED_PACK32: return VK_FORMAT_A8B8G8R8_USCALED_PACK32;
		case ashes::Format::eA8B8G8R8_SSCALED_PACK32: return VK_FORMAT_A8B8G8R8_SSCALED_PACK32;
		case ashes::Format::eA8B8G8R8_UINT_PACK32: return VK_FORMAT_A8B8G8R8_UINT_PACK32;
		case ashes::Format::eA8B8G8R8_SINT_PACK32: return VK_FORMAT_A8B8G8R8_SINT_PACK32;
		case ashes::Format::eA8B8G8R8_SRGB_PACK32: return VK_FORMAT_A8B8G8R8_SRGB_PACK32;
		case ashes::Format::eA2R10G10B10_UNORM_PACK32: return VK_FORMAT_A2R10G10B10_UNORM_PACK32;
		case ashes::Format::eA2R10G10B10_SNORM_PACK32: return VK_FORMAT_A2R10G10B10_SNORM_PACK32;
		case ashes::Format::eA2R10G10B10_USCALED_PACK32: return VK_FORMAT_A2R10G10B10_USCALED_PACK32;
		case ashes::Format::eA2R10G10B10_SSCALED_PACK32: return VK_FORMAT_A2R10G10B10_SSCALED_PACK32;
		case ashes::Format::eA2R10G10B10_UINT_PACK32: return VK_FORMAT_A2R10G10B10_UINT_PACK32;
		case ashes::Format::eA2R10G10B10_SINT_PACK32: return VK_FORMAT_A2R10G10B10_SINT_PACK32;
		case ashes::Format::eA2B10G10R10_UNORM_PACK32: return VK_FORMAT_A2B10G10R10_UNORM_PACK32;
		case ashes::Format::eA2B10G10R10_SNORM_PACK32: return VK_FORMAT_A2B10G10R10_SNORM_PACK32;
		case ashes::Format::eA2B10G10R10_USCALED_PACK32: return VK_FORMAT_A2B10G10R10_USCALED_PACK32;
		case ashes::Format::eA2B10G10R10_SSCALED_PACK32: return VK_FORMAT_A2B10G10R10_SSCALED_PACK32;
		case ashes::Format::eA2B10G10R10_UINT_PACK32: return VK_FORMAT_A2B10G10R10_UINT_PACK32;
		case ashes::Format::eA2B10G10R10_SINT_PACK32: return VK_FORMAT_A2B10G10R10_SINT_PACK32;
		case ashes::Format::eR16_UNORM: return VK_FORMAT_R16_UNORM;
		case ashes::Format::eR16_SNORM: return VK_FORMAT_R16_SNORM;
		case ashes::Format::eR16_USCALED: return VK_FORMAT_R16_USCALED;
		case ashes::Format::eR16_SSCALED: return VK_FORMAT_R16_SSCALED;
		case ashes::Format::eR16_UINT: return VK_FORMAT_R16_UINT;
		case ashes::Format::eR16_SINT: return VK_FORMAT_R16_SINT;
		case ashes::Format::eR16_SFLOAT: return VK_FORMAT_R16_SFLOAT;
		case ashes::Format::eR16G16_UNORM: return VK_FORMAT_R16G16_UNORM;
		case ashes::Format::eR16G16_SNORM: return VK_FORMAT_R16G16_SNORM;
		case ashes::Format::eR16G16_USCALED: return VK_FORMAT_R16G16_USCALED;
		case ashes::Format::eR16G16_SSCALED: return VK_FORMAT_R16G16_SSCALED;
		case ashes::Format::eR16G16_UINT: return VK_FORMAT_R16G16_UINT;
		case ashes::Format::eR16G16_SINT: return VK_FORMAT_R16G16_SINT;
		case ashes::Format::eR16G16_SFLOAT: return VK_FORMAT_R16G16_SFLOAT;
		case ashes::Format::eR16G16B16_UNORM: return VK_FORMAT_R16G16B16_UNORM;
		case ashes::Format::eR16G16B16_SNORM: return VK_FORMAT_R16G16B16_SNORM;
		case ashes::Format::eR16G16B16_USCALED: return VK_FORMAT_R16G16B16_USCALED;
		case ashes::Format::eR16G16B16_SSCALED: return VK_FORMAT_R16G16B16_SSCALED;
		case ashes::Format::eR16G16B16_UINT: return VK_FORMAT_R16G16B16_UINT;
		case ashes::Format::eR16G16B16_SINT: return VK_FORMAT_R16G16B16_SINT;
		case ashes::Format::eR16G16B16_SFLOAT: return VK_FORMAT_R16G16B16_SFLOAT;
		case ashes::Format::eR16G16B16A16_UNORM: return VK_FORMAT_R16G16B16A16_UNORM;
		case ashes::Format::eR16G16B16A16_SNORM: return VK_FORMAT_R16G16B16A16_SNORM;
		case ashes::Format::eR16G16B16A16_USCALED: return VK_FORMAT_R16G16B16A16_USCALED;
		case ashes::Format::eR16G16B16A16_SSCALED: return VK_FORMAT_R16G16B16A16_SSCALED;
		case ashes::Format::eR16G16B16A16_UINT: return VK_FORMAT_R16G16B16A16_UINT;
		case ashes::Format::eR16G16B16A16_SINT: return VK_FORMAT_R16G16B16A16_SINT;
		case ashes::Format::eR16G16B16A16_SFLOAT: return VK_FORMAT_R16G16B16A16_SFLOAT;
		case ashes::Format::eR32_UINT: return VK_FORMAT_R32_UINT;
		case ashes::Format::eR32_SINT: return VK_FORMAT_R32_SINT;
		case ashes::Format::eR32_SFLOAT: return VK_FORMAT_R32_SFLOAT;
		case ashes::Format::eR32G32_UINT: return VK_FORMAT_R32G32_UINT;
		case ashes::Format::eR32G32_SINT: return VK_FORMAT_R32G32_SINT;
		case ashes::Format::eR32G32_SFLOAT: return VK_FORMAT_R32G32_SFLOAT;
		case ashes::Format::eR32G32B32_UINT: return VK_FORMAT_R32G32B32_UINT;
		case ashes::Format::eR32G32B32_SINT: return VK_FORMAT_R32G32B32_SINT;
		case ashes::Format::eR32G32B32_SFLOAT: return VK_FORMAT_R32G32B32_SFLOAT;
		case ashes::Format::eR32G32B32A32_UINT: return VK_FORMAT_R32G32B32A32_UINT;
		case ashes::Format::eR32G32B32A32_SINT: return VK_FORMAT_R32G32B32A32_SINT;
		case ashes::Format::eR32G32B32A32_SFLOAT: return VK_FORMAT_R32G32B32A32_SFLOAT;
		case ashes::Format::eR64_UINT: return VK_FORMAT_R64_UINT;
		case ashes::Format::eR64_SINT: return VK_FORMAT_R64_SINT;
		case ashes::Format::eR64_SFLOAT: return VK_FORMAT_R64_SFLOAT;
		case ashes::Format::eR64G64_UINT: return VK_FORMAT_R64G64_UINT;
		case ashes::Format::eR64G64_SINT: return VK_FORMAT_R64G64_SINT;
		case ashes::Format::eR64G64_SFLOAT: return VK_FORMAT_R64G64_SFLOAT;
		case ashes::Format::eR64G64B64_UINT: return VK_FORMAT_R64G64B64_UINT;
		case ashes::Format::eR64G64B64_SINT: return VK_FORMAT_R64G64B64_SINT;
		case ashes::Format::eR64G64B64_SFLOAT: return VK_FORMAT_R64G64B64_SFLOAT;
		case ashes::Format::eR64G64B64A64_UINT: return VK_FORMAT_R64G64B64A64_UINT;
		case ashes::Format::eR64G64B64A64_SINT: return VK_FORMAT_R64G64B64A64_SINT;
		case ashes::Format::eR64G64B64A64_SFLOAT: return VK_FORMAT_R64G64B64A64_SFLOAT;
		case ashes::Format::eB10G11R11_UFLOAT_PACK32: return VK_FORMAT_B10G11R11_UFLOAT_PACK32;
		case ashes::Format::eE5B9G9R9_UFLOAT_PACK32: return VK_FORMAT_E5B9G9R9_UFLOAT_PACK32;
		case ashes::Format::eD16_UNORM: return VK_FORMAT_D16_UNORM;
		case ashes::Format::eX8_D24_UNORM_PACK32: return VK_FORMAT_X8_D24_UNORM_PACK32;
		case ashes::Format::eD32_SFLOAT: return VK_FORMAT_D32_SFLOAT;
		case ashes::Format::eS8_UINT: return VK_FORMAT_S8_UINT;
		case ashes::Format::eD16_UNORM_S8_UINT: return VK_FORMAT_D16_UNORM_S8_UINT;
		case ashes::Format::eD24_UNORM_S8_UINT: return VK_FORMAT_D24_UNORM_S8_UINT;
		case ashes::Format::eD32_SFLOAT_S8_UINT: return VK_FORMAT_D32_SFLOAT_S8_UINT;
		case ashes::Format::eBC1_RGB_UNORM_BLOCK: return VK_FORMAT_BC1_RGB_UNORM_BLOCK;
		case ashes::Format::eBC1_RGB_SRGB_BLOCK: return VK_FORMAT_BC1_RGB_SRGB_BLOCK;
		case ashes::Format::eBC1_RGBA_UNORM_BLOCK: return VK_FORMAT_BC1_RGBA_UNORM_BLOCK;
		case ashes::Format::eBC1_RGBA_SRGB_BLOCK: return VK_FORMAT_BC1_RGBA_SRGB_BLOCK;
		case ashes::Format::eBC2_UNORM_BLOCK: return VK_FORMAT_BC2_UNORM_BLOCK;
		case ashes::Format::eBC2_SRGB_BLOCK: return VK_FORMAT_BC2_SRGB_BLOCK;
		case ashes::Format::eBC3_UNORM_BLOCK: return VK_FORMAT_BC3_UNORM_BLOCK;
		case ashes::Format::eBC3_SRGB_BLOCK: return VK_FORMAT_BC3_SRGB_BLOCK;
		case ashes::Format::eBC4_UNORM_BLOCK: return VK_FORMAT_BC4_UNORM_BLOCK;
		case ashes::Format::eBC4_SNORM_BLOCK: return VK_FORMAT_BC4_SNORM_BLOCK;
		case ashes::Format::eBC5_UNORM_BLOCK: return VK_FORMAT_BC5_UNORM_BLOCK;
		case ashes::Format::eBC5_SNORM_BLOCK: return VK_FORMAT_BC5_SNORM_BLOCK;
		case ashes::Format::eBC6H_UFLOAT_BLOCK: return VK_FORMAT_BC6H_UFLOAT_BLOCK;
		case ashes::Format::eBC6H_SFLOAT_BLOCK: return VK_FORMAT_BC6H_SFLOAT_BLOCK;
		case ashes::Format::eBC7_UNORM_BLOCK: return VK_FORMAT_BC7_UNORM_BLOCK;
		case ashes::Format::eBC7_SRGB_BLOCK: return VK_FORMAT_BC7_SRGB_BLOCK;
		case ashes::Format::eETC2_R8G8B8_UNORM_BLOCK: return VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK;
		case ashes::Format::eETC2_R8G8B8_SRGB_BLOCK: return VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK;
		case ashes::Format::eETC2_R8G8B8A1_UNORM_BLOCK: return VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK;
		case ashes::Format::eETC2_R8G8B8A1_SRGB_BLOCK: return VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK;
		case ashes::Format::eETC2_R8G8B8A8_UNORM_BLOCK: return VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK;
		case ashes::Format::eETC2_R8G8B8A8_SRGB_BLOCK: return VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK;
		case ashes::Format::eEAC_R11_UNORM_BLOCK: return VK_FORMAT_EAC_R11_UNORM_BLOCK;
		case ashes::Format::eEAC_R11_SNORM_BLOCK: return VK_FORMAT_EAC_R11_SNORM_BLOCK;
		case ashes::Format::eEAC_R11G11_UNORM_BLOCK: return VK_FORMAT_EAC_R11G11_UNORM_BLOCK;
		case ashes::Format::eEAC_R11G11_SNORM_BLOCK: return VK_FORMAT_EAC_R11G11_SNORM_BLOCK;
		case ashes::Format::eASTC_4x4_UNORM_BLOCK: return VK_FORMAT_ASTC_4x4_UNORM_BLOCK;
		case ashes::Format::eASTC_4x4_SRGB_BLOCK: return VK_FORMAT_ASTC_4x4_SRGB_BLOCK;
		case ashes::Format::eASTC_5x4_UNORM_BLOCK: return VK_FORMAT_ASTC_5x4_UNORM_BLOCK;
		case ashes::Format::eASTC_5x4_SRGB_BLOCK: return VK_FORMAT_ASTC_5x4_SRGB_BLOCK;
		case ashes::Format::eASTC_5x5_UNORM_BLOCK: return VK_FORMAT_ASTC_5x5_UNORM_BLOCK;
		case ashes::Format::eASTC_5x5_SRGB_BLOCK: return VK_FORMAT_ASTC_5x5_SRGB_BLOCK;
		case ashes::Format::eASTC_6x5_UNORM_BLOCK: return VK_FORMAT_ASTC_6x5_UNORM_BLOCK;
		case ashes::Format::eASTC_6x5_SRGB_BLOCK: return VK_FORMAT_ASTC_6x5_SRGB_BLOCK;
		case ashes::Format::eASTC_6x6_UNORM_BLOCK: return VK_FORMAT_ASTC_6x6_UNORM_BLOCK;
		case ashes::Format::eASTC_6x6_SRGB_BLOCK: return VK_FORMAT_ASTC_6x6_SRGB_BLOCK;
		case ashes::Format::eASTC_8x5_UNORM_BLOCK: return VK_FORMAT_ASTC_8x5_UNORM_BLOCK;
		case ashes::Format::eASTC_8x5_SRGB_BLOCK: return VK_FORMAT_ASTC_8x5_SRGB_BLOCK;
		case ashes::Format::eASTC_8x6_UNORM_BLOCK: return VK_FORMAT_ASTC_8x6_UNORM_BLOCK;
		case ashes::Format::eASTC_8x6_SRGB_BLOCK: return VK_FORMAT_ASTC_8x6_SRGB_BLOCK;
		case ashes::Format::eASTC_8x8_UNORM_BLOCK: return VK_FORMAT_ASTC_8x8_UNORM_BLOCK;
		case ashes::Format::eASTC_8x8_SRGB_BLOCK: return VK_FORMAT_ASTC_8x8_SRGB_BLOCK;
		case ashes::Format::eASTC_10x5_UNORM_BLOCK: return VK_FORMAT_ASTC_10x5_UNORM_BLOCK;
		case ashes::Format::eASTC_10x5_SRGB_BLOCK: return VK_FORMAT_ASTC_10x5_SRGB_BLOCK;
		case ashes::Format::eASTC_10x6_UNORM_BLOCK: return VK_FORMAT_ASTC_10x6_UNORM_BLOCK;
		case ashes::Format::eASTC_10x6_SRGB_BLOCK: return VK_FORMAT_ASTC_10x6_SRGB_BLOCK;
		case ashes::Format::eASTC_10x8_UNORM_BLOCK: return VK_FORMAT_ASTC_10x8_UNORM_BLOCK;
		case ashes::Format::eASTC_10x8_SRGB_BLOCK: return VK_FORMAT_ASTC_10x8_SRGB_BLOCK;
		case ashes::Format::eASTC_10x10_UNORM_BLOCK: return VK_FORMAT_ASTC_10x10_UNORM_BLOCK;
		case ashes::Format::eASTC_10x10_SRGB_BLOCK: return VK_FORMAT_ASTC_10x10_SRGB_BLOCK;
		case ashes::Format::eASTC_12x10_UNORM_BLOCK: return VK_FORMAT_ASTC_12x10_UNORM_BLOCK;
		case ashes::Format::eASTC_12x10_SRGB_BLOCK: return VK_FORMAT_ASTC_12x10_SRGB_BLOCK;
		case ashes::Format::eASTC_12x12_UNORM_BLOCK: return VK_FORMAT_ASTC_12x12_UNORM_BLOCK;
		case ashes::Format::eASTC_12x12_SRGB_BLOCK: return VK_FORMAT_ASTC_12x12_SRGB_BLOCK;
		default:
			assert( false && "Unsupported pixel format." );
			return VK_FORMAT_UNDEFINED;
		}
	}

	ashes::Format convert( VkFormat const & format )noexcept
	{
		switch ( format )
		{
		case VK_FORMAT_UNDEFINED: return ashes::Format::eUndefined;
		case VK_FORMAT_R4G4_UNORM_PACK8: return ashes::Format::eR4G4_UNORM_PACK8;
		case VK_FORMAT_R4G4B4A4_UNORM_PACK16: return ashes::Format::eR4G4B4A4_UNORM_PACK16;
		case VK_FORMAT_B4G4R4A4_UNORM_PACK16: return ashes::Format::eB4G4R4A4_UNORM_PACK16;
		case VK_FORMAT_R5G6B5_UNORM_PACK16: return ashes::Format::eR5G6B5_UNORM_PACK16;
		case VK_FORMAT_B5G6R5_UNORM_PACK16: return ashes::Format::eB5G6R5_UNORM_PACK16;
		case VK_FORMAT_R5G5B5A1_UNORM_PACK16: return ashes::Format::eR5G5B5A1_UNORM_PACK16;
		case VK_FORMAT_B5G5R5A1_UNORM_PACK16: return ashes::Format::eB5G5R5A1_UNORM_PACK16;
		case VK_FORMAT_A1R5G5B5_UNORM_PACK16: return ashes::Format::eA1R5G5B5_UNORM_PACK16;
		case VK_FORMAT_R8_UNORM: return ashes::Format::eR8_UNORM;
		case VK_FORMAT_R8_SNORM: return ashes::Format::eR8_SNORM;
		case VK_FORMAT_R8_USCALED: return ashes::Format::eR8_USCALED;
		case VK_FORMAT_R8_SSCALED: return ashes::Format::eR8_SSCALED;
		case VK_FORMAT_R8_UINT: return ashes::Format::eR8_UINT;
		case VK_FORMAT_R8_SINT: return ashes::Format::eR8_SINT;
		case VK_FORMAT_R8_SRGB: return ashes::Format::eR8_SRGB;
		case VK_FORMAT_R8G8_UNORM: return ashes::Format::eR8G8_UNORM;
		case VK_FORMAT_R8G8_SNORM: return ashes::Format::eR8G8_SNORM;
		case VK_FORMAT_R8G8_USCALED: return ashes::Format::eR8G8_USCALED;
		case VK_FORMAT_R8G8_SSCALED: return ashes::Format::eR8G8_SSCALED;
		case VK_FORMAT_R8G8_UINT: return ashes::Format::eR8G8_UINT;
		case VK_FORMAT_R8G8_SINT: return ashes::Format::eR8G8_SINT;
		case VK_FORMAT_R8G8_SRGB: return ashes::Format::eR8G8_SRGB;
		case VK_FORMAT_R8G8B8_UNORM: return ashes::Format::eR8G8B8_UNORM;
		case VK_FORMAT_R8G8B8_SNORM: return ashes::Format::eR8G8B8_SNORM;
		case VK_FORMAT_R8G8B8_USCALED: return ashes::Format::eR8G8B8_USCALED;
		case VK_FORMAT_R8G8B8_SSCALED: return ashes::Format::eR8G8B8_SSCALED;
		case VK_FORMAT_R8G8B8_UINT: return ashes::Format::eR8G8B8_UINT;
		case VK_FORMAT_R8G8B8_SINT: return ashes::Format::eR8G8B8_SINT;
		case VK_FORMAT_R8G8B8_SRGB: return ashes::Format::eR8G8B8_SRGB;
		case VK_FORMAT_B8G8R8_UNORM: return ashes::Format::eB8G8R8_UNORM;
		case VK_FORMAT_B8G8R8_SNORM: return ashes::Format::eB8G8R8_SNORM;
		case VK_FORMAT_B8G8R8_USCALED: return ashes::Format::eB8G8R8_USCALED;
		case VK_FORMAT_B8G8R8_SSCALED: return ashes::Format::eB8G8R8_SSCALED;
		case VK_FORMAT_B8G8R8_UINT: return ashes::Format::eB8G8R8_UINT;
		case VK_FORMAT_B8G8R8_SINT: return ashes::Format::eB8G8R8_SINT;
		case VK_FORMAT_B8G8R8_SRGB: return ashes::Format::eB8G8R8_SRGB;
		case VK_FORMAT_R8G8B8A8_UNORM: return ashes::Format::eR8G8B8A8_UNORM;
		case VK_FORMAT_R8G8B8A8_SNORM: return ashes::Format::eR8G8B8A8_SNORM;
		case VK_FORMAT_R8G8B8A8_USCALED: return ashes::Format::eR8G8B8A8_USCALED;
		case VK_FORMAT_R8G8B8A8_SSCALED: return ashes::Format::eR8G8B8A8_SSCALED;
		case VK_FORMAT_R8G8B8A8_UINT: return ashes::Format::eR8G8B8A8_UINT;
		case VK_FORMAT_R8G8B8A8_SINT: return ashes::Format::eR8G8B8A8_SINT;
		case VK_FORMAT_R8G8B8A8_SRGB: return ashes::Format::eR8G8B8A8_SRGB;
		case VK_FORMAT_B8G8R8A8_UNORM: return ashes::Format::eB8G8R8A8_UNORM;
		case VK_FORMAT_B8G8R8A8_SNORM: return ashes::Format::eB8G8R8A8_SNORM;
		case VK_FORMAT_B8G8R8A8_USCALED: return ashes::Format::eB8G8R8A8_USCALED;
		case VK_FORMAT_B8G8R8A8_SSCALED: return ashes::Format::eB8G8R8A8_SSCALED;
		case VK_FORMAT_B8G8R8A8_UINT: return ashes::Format::eB8G8R8A8_UINT;
		case VK_FORMAT_B8G8R8A8_SINT: return ashes::Format::eB8G8R8A8_SINT;
		case VK_FORMAT_B8G8R8A8_SRGB: return ashes::Format::eB8G8R8A8_SRGB;
		case VK_FORMAT_A8B8G8R8_UNORM_PACK32: return ashes::Format::eA8B8G8R8_UNORM_PACK32;
		case VK_FORMAT_A8B8G8R8_SNORM_PACK32: return ashes::Format::eA8B8G8R8_SNORM_PACK32;
		case VK_FORMAT_A8B8G8R8_USCALED_PACK32: return ashes::Format::eA8B8G8R8_USCALED_PACK32;
		case VK_FORMAT_A8B8G8R8_SSCALED_PACK32: return ashes::Format::eA8B8G8R8_SSCALED_PACK32;
		case VK_FORMAT_A8B8G8R8_UINT_PACK32: return ashes::Format::eA8B8G8R8_UINT_PACK32;
		case VK_FORMAT_A8B8G8R8_SINT_PACK32: return ashes::Format::eA8B8G8R8_SINT_PACK32;
		case VK_FORMAT_A8B8G8R8_SRGB_PACK32: return ashes::Format::eA8B8G8R8_SRGB_PACK32;
		case VK_FORMAT_A2R10G10B10_UNORM_PACK32: return ashes::Format::eA2R10G10B10_UNORM_PACK32;
		case VK_FORMAT_A2R10G10B10_SNORM_PACK32: return ashes::Format::eA2R10G10B10_SNORM_PACK32;
		case VK_FORMAT_A2R10G10B10_USCALED_PACK32: return ashes::Format::eA2R10G10B10_USCALED_PACK32;
		case VK_FORMAT_A2R10G10B10_SSCALED_PACK32: return ashes::Format::eA2R10G10B10_SSCALED_PACK32;
		case VK_FORMAT_A2R10G10B10_UINT_PACK32: return ashes::Format::eA2R10G10B10_UINT_PACK32;
		case VK_FORMAT_A2R10G10B10_SINT_PACK32: return ashes::Format::eA2R10G10B10_SINT_PACK32;
		case VK_FORMAT_A2B10G10R10_UNORM_PACK32: return ashes::Format::eA2B10G10R10_UNORM_PACK32;
		case VK_FORMAT_A2B10G10R10_SNORM_PACK32: return ashes::Format::eA2B10G10R10_SNORM_PACK32;
		case VK_FORMAT_A2B10G10R10_USCALED_PACK32: return ashes::Format::eA2B10G10R10_USCALED_PACK32;
		case VK_FORMAT_A2B10G10R10_SSCALED_PACK32: return ashes::Format::eA2B10G10R10_SSCALED_PACK32;
		case VK_FORMAT_A2B10G10R10_UINT_PACK32: return ashes::Format::eA2B10G10R10_UINT_PACK32;
		case VK_FORMAT_A2B10G10R10_SINT_PACK32: return ashes::Format::eA2B10G10R10_SINT_PACK32;
		case VK_FORMAT_R16_UNORM: return ashes::Format::eR16_UNORM;
		case VK_FORMAT_R16_SNORM: return ashes::Format::eR16_SNORM;
		case VK_FORMAT_R16_USCALED: return ashes::Format::eR16_USCALED;
		case VK_FORMAT_R16_SSCALED: return ashes::Format::eR16_SSCALED;
		case VK_FORMAT_R16_UINT: return ashes::Format::eR16_UINT;
		case VK_FORMAT_R16_SINT: return ashes::Format::eR16_SINT;
		case VK_FORMAT_R16_SFLOAT: return ashes::Format::eR16_SFLOAT;
		case VK_FORMAT_R16G16_UNORM: return ashes::Format::eR16G16_UNORM;
		case VK_FORMAT_R16G16_SNORM: return ashes::Format::eR16G16_SNORM;
		case VK_FORMAT_R16G16_USCALED: return ashes::Format::eR16G16_USCALED;
		case VK_FORMAT_R16G16_SSCALED: return ashes::Format::eR16G16_SSCALED;
		case VK_FORMAT_R16G16_UINT: return ashes::Format::eR16G16_UINT;
		case VK_FORMAT_R16G16_SINT: return ashes::Format::eR16G16_SINT;
		case VK_FORMAT_R16G16_SFLOAT: return ashes::Format::eR16G16_SFLOAT;
		case VK_FORMAT_R16G16B16_UNORM: return ashes::Format::eR16G16B16_UNORM;
		case VK_FORMAT_R16G16B16_SNORM: return ashes::Format::eR16G16B16_SNORM;
		case VK_FORMAT_R16G16B16_USCALED: return ashes::Format::eR16G16B16_USCALED;
		case VK_FORMAT_R16G16B16_SSCALED: return ashes::Format::eR16G16B16_SSCALED;
		case VK_FORMAT_R16G16B16_UINT: return ashes::Format::eR16G16B16_UINT;
		case VK_FORMAT_R16G16B16_SINT: return ashes::Format::eR16G16B16_SINT;
		case VK_FORMAT_R16G16B16_SFLOAT: return ashes::Format::eR16G16B16_SFLOAT;
		case VK_FORMAT_R16G16B16A16_UNORM: return ashes::Format::eR16G16B16A16_UNORM;
		case VK_FORMAT_R16G16B16A16_SNORM: return ashes::Format::eR16G16B16A16_SNORM;
		case VK_FORMAT_R16G16B16A16_USCALED: return ashes::Format::eR16G16B16A16_USCALED;
		case VK_FORMAT_R16G16B16A16_SSCALED: return ashes::Format::eR16G16B16A16_SSCALED;
		case VK_FORMAT_R16G16B16A16_UINT: return ashes::Format::eR16G16B16A16_UINT;
		case VK_FORMAT_R16G16B16A16_SINT: return ashes::Format::eR16G16B16A16_SINT;
		case VK_FORMAT_R16G16B16A16_SFLOAT: return ashes::Format::eR16G16B16A16_SFLOAT;
		case VK_FORMAT_R32_UINT: return ashes::Format::eR32_UINT;
		case VK_FORMAT_R32_SINT: return ashes::Format::eR32_SINT;
		case VK_FORMAT_R32_SFLOAT: return ashes::Format::eR32_SFLOAT;
		case VK_FORMAT_R32G32_UINT: return ashes::Format::eR32G32_UINT;
		case VK_FORMAT_R32G32_SINT: return ashes::Format::eR32G32_SINT;
		case VK_FORMAT_R32G32_SFLOAT: return ashes::Format::eR32G32_SFLOAT;
		case VK_FORMAT_R32G32B32_UINT: return ashes::Format::eR32G32B32_UINT;
		case VK_FORMAT_R32G32B32_SINT: return ashes::Format::eR32G32B32_SINT;
		case VK_FORMAT_R32G32B32_SFLOAT: return ashes::Format::eR32G32B32_SFLOAT;
		case VK_FORMAT_R32G32B32A32_UINT: return ashes::Format::eR32G32B32A32_UINT;
		case VK_FORMAT_R32G32B32A32_SINT: return ashes::Format::eR32G32B32A32_SINT;
		case VK_FORMAT_R32G32B32A32_SFLOAT: return ashes::Format::eR32G32B32A32_SFLOAT;
		case VK_FORMAT_R64_UINT: return ashes::Format::eR64_UINT;
		case VK_FORMAT_R64_SINT: return ashes::Format::eR64_SINT;
		case VK_FORMAT_R64_SFLOAT: return ashes::Format::eR64_SFLOAT;
		case VK_FORMAT_R64G64_UINT: return ashes::Format::eR64G64_UINT;
		case VK_FORMAT_R64G64_SINT: return ashes::Format::eR64G64_SINT;
		case VK_FORMAT_R64G64_SFLOAT: return ashes::Format::eR64G64_SFLOAT;
		case VK_FORMAT_R64G64B64_UINT: return ashes::Format::eR64G64B64_UINT;
		case VK_FORMAT_R64G64B64_SINT: return ashes::Format::eR64G64B64_SINT;
		case VK_FORMAT_R64G64B64_SFLOAT: return ashes::Format::eR64G64B64_SFLOAT;
		case VK_FORMAT_R64G64B64A64_UINT: return ashes::Format::eR64G64B64A64_UINT;
		case VK_FORMAT_R64G64B64A64_SINT: return ashes::Format::eR64G64B64A64_SINT;
		case VK_FORMAT_R64G64B64A64_SFLOAT: return ashes::Format::eR64G64B64A64_SFLOAT;
		case VK_FORMAT_B10G11R11_UFLOAT_PACK32: return ashes::Format::eB10G11R11_UFLOAT_PACK32;
		case VK_FORMAT_E5B9G9R9_UFLOAT_PACK32: return ashes::Format::eE5B9G9R9_UFLOAT_PACK32;
		case VK_FORMAT_D16_UNORM: return ashes::Format::eD16_UNORM;
		case VK_FORMAT_X8_D24_UNORM_PACK32: return ashes::Format::eX8_D24_UNORM_PACK32;
		case VK_FORMAT_D32_SFLOAT: return ashes::Format::eD32_SFLOAT;
		case VK_FORMAT_S8_UINT: return ashes::Format::eS8_UINT;
		case VK_FORMAT_D16_UNORM_S8_UINT: return ashes::Format::eD16_UNORM_S8_UINT;
		case VK_FORMAT_D24_UNORM_S8_UINT: return ashes::Format::eD24_UNORM_S8_UINT;
		case VK_FORMAT_D32_SFLOAT_S8_UINT: return ashes::Format::eD32_SFLOAT_S8_UINT;
		case VK_FORMAT_BC1_RGB_UNORM_BLOCK: return ashes::Format::eBC1_RGB_UNORM_BLOCK;
		case VK_FORMAT_BC1_RGB_SRGB_BLOCK: return ashes::Format::eBC1_RGB_SRGB_BLOCK;
		case VK_FORMAT_BC1_RGBA_UNORM_BLOCK: return ashes::Format::eBC1_RGBA_UNORM_BLOCK;
		case VK_FORMAT_BC1_RGBA_SRGB_BLOCK: return ashes::Format::eBC1_RGBA_SRGB_BLOCK;
		case VK_FORMAT_BC2_UNORM_BLOCK: return ashes::Format::eBC2_UNORM_BLOCK;
		case VK_FORMAT_BC2_SRGB_BLOCK: return ashes::Format::eBC2_SRGB_BLOCK;
		case VK_FORMAT_BC3_UNORM_BLOCK: return ashes::Format::eBC3_UNORM_BLOCK;
		case VK_FORMAT_BC3_SRGB_BLOCK: return ashes::Format::eBC3_SRGB_BLOCK;
		case VK_FORMAT_BC4_UNORM_BLOCK: return ashes::Format::eBC4_UNORM_BLOCK;
		case VK_FORMAT_BC4_SNORM_BLOCK: return ashes::Format::eBC4_SNORM_BLOCK;
		case VK_FORMAT_BC5_UNORM_BLOCK: return ashes::Format::eBC5_UNORM_BLOCK;
		case VK_FORMAT_BC5_SNORM_BLOCK: return ashes::Format::eBC5_SNORM_BLOCK;
		case VK_FORMAT_BC6H_UFLOAT_BLOCK: return ashes::Format::eBC6H_UFLOAT_BLOCK;
		case VK_FORMAT_BC6H_SFLOAT_BLOCK: return ashes::Format::eBC6H_SFLOAT_BLOCK;
		case VK_FORMAT_BC7_UNORM_BLOCK: return ashes::Format::eBC7_UNORM_BLOCK;
		case VK_FORMAT_BC7_SRGB_BLOCK: return ashes::Format::eBC7_SRGB_BLOCK;
		case VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK: return ashes::Format::eETC2_R8G8B8_UNORM_BLOCK;
		case VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK: return ashes::Format::eETC2_R8G8B8_SRGB_BLOCK;
		case VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK: return ashes::Format::eETC2_R8G8B8A1_UNORM_BLOCK;
		case VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK: return ashes::Format::eETC2_R8G8B8A1_SRGB_BLOCK;
		case VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK: return ashes::Format::eETC2_R8G8B8A8_UNORM_BLOCK;
		case VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK: return ashes::Format::eETC2_R8G8B8A8_SRGB_BLOCK;
		case VK_FORMAT_EAC_R11_UNORM_BLOCK: return ashes::Format::eEAC_R11_UNORM_BLOCK;
		case VK_FORMAT_EAC_R11_SNORM_BLOCK: return ashes::Format::eEAC_R11_SNORM_BLOCK;
		case VK_FORMAT_EAC_R11G11_UNORM_BLOCK: return ashes::Format::eEAC_R11G11_UNORM_BLOCK;
		case VK_FORMAT_EAC_R11G11_SNORM_BLOCK: return ashes::Format::eEAC_R11G11_SNORM_BLOCK;
		case VK_FORMAT_ASTC_4x4_UNORM_BLOCK: return ashes::Format::eASTC_4x4_UNORM_BLOCK;
		case VK_FORMAT_ASTC_4x4_SRGB_BLOCK: return ashes::Format::eASTC_4x4_SRGB_BLOCK;
		case VK_FORMAT_ASTC_5x4_UNORM_BLOCK: return ashes::Format::eASTC_5x4_UNORM_BLOCK;
		case VK_FORMAT_ASTC_5x4_SRGB_BLOCK: return ashes::Format::eASTC_5x4_SRGB_BLOCK;
		case VK_FORMAT_ASTC_5x5_UNORM_BLOCK: return ashes::Format::eASTC_5x5_UNORM_BLOCK;
		case VK_FORMAT_ASTC_5x5_SRGB_BLOCK: return ashes::Format::eASTC_5x5_SRGB_BLOCK;
		case VK_FORMAT_ASTC_6x5_UNORM_BLOCK: return ashes::Format::eASTC_6x5_UNORM_BLOCK;
		case VK_FORMAT_ASTC_6x5_SRGB_BLOCK: return ashes::Format::eASTC_6x5_SRGB_BLOCK;
		case VK_FORMAT_ASTC_6x6_UNORM_BLOCK: return ashes::Format::eASTC_6x6_UNORM_BLOCK;
		case VK_FORMAT_ASTC_6x6_SRGB_BLOCK: return ashes::Format::eASTC_6x6_SRGB_BLOCK;
		case VK_FORMAT_ASTC_8x5_UNORM_BLOCK: return ashes::Format::eASTC_8x5_UNORM_BLOCK;
		case VK_FORMAT_ASTC_8x5_SRGB_BLOCK: return ashes::Format::eASTC_8x5_SRGB_BLOCK;
		case VK_FORMAT_ASTC_8x6_UNORM_BLOCK: return ashes::Format::eASTC_8x6_UNORM_BLOCK;
		case VK_FORMAT_ASTC_8x6_SRGB_BLOCK: return ashes::Format::eASTC_8x6_SRGB_BLOCK;
		case VK_FORMAT_ASTC_8x8_UNORM_BLOCK: return ashes::Format::eASTC_8x8_UNORM_BLOCK;
		case VK_FORMAT_ASTC_8x8_SRGB_BLOCK: return ashes::Format::eASTC_8x8_SRGB_BLOCK;
		case VK_FORMAT_ASTC_10x5_UNORM_BLOCK: return ashes::Format::eASTC_10x5_UNORM_BLOCK;
		case VK_FORMAT_ASTC_10x5_SRGB_BLOCK: return ashes::Format::eASTC_10x5_SRGB_BLOCK;
		case VK_FORMAT_ASTC_10x6_UNORM_BLOCK: return ashes::Format::eASTC_10x6_UNORM_BLOCK;
		case VK_FORMAT_ASTC_10x6_SRGB_BLOCK: return ashes::Format::eASTC_10x6_SRGB_BLOCK;
		case VK_FORMAT_ASTC_10x8_UNORM_BLOCK: return ashes::Format::eASTC_10x8_UNORM_BLOCK;
		case VK_FORMAT_ASTC_10x8_SRGB_BLOCK: return ashes::Format::eASTC_10x8_SRGB_BLOCK;
		case VK_FORMAT_ASTC_10x10_UNORM_BLOCK: return ashes::Format::eASTC_10x10_UNORM_BLOCK;
		case VK_FORMAT_ASTC_10x10_SRGB_BLOCK: return ashes::Format::eASTC_10x10_SRGB_BLOCK;
		case VK_FORMAT_ASTC_12x10_UNORM_BLOCK: return ashes::Format::eASTC_12x10_UNORM_BLOCK;
		case VK_FORMAT_ASTC_12x10_SRGB_BLOCK: return ashes::Format::eASTC_12x10_SRGB_BLOCK;
		case VK_FORMAT_ASTC_12x12_UNORM_BLOCK: return ashes::Format::eASTC_12x12_UNORM_BLOCK;
		case VK_FORMAT_ASTC_12x12_SRGB_BLOCK: return ashes::Format::eASTC_12x12_SRGB_BLOCK;
		default:
			assert( false && "Unsupported pixel format." );
			return ashes::Format::eR8G8B8A8_UNORM;
		}
	}
}
