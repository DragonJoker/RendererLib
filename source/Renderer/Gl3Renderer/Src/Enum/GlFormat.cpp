#include "GlRendererPrerequisites.hpp"

namespace gl_renderer
{
	std::string getName( GlInternal value )
	{
		switch ( value )
		{
		case GL_INTERNAL_R4G4B4A4_UNORM_PACK16:
			return "GL_RGBA4";

		case GL_INTERNAL_R5G6B5_UNORM_PACK16:
			return "GL_R5G6B5";

		case GL_INTERNAL_R5G5B5A1_UNORM_PACK16:
			return "GL_RGB5_A1";

		case GL_INTERNAL_R8_UNORM:
			return "GL_R8";

		case GL_INTERNAL_R8_SNORM:
			return "GL_R8_SNORM";

		case GL_INTERNAL_R8_UINT:
			return "GL_R8UI";

		case GL_INTERNAL_R8_SINT:
			return "GL_R8I";

		case GL_INTERNAL_R8_SRGB:
			return "GL_SR8";

		case GL_INTERNAL_R8G8_UNORM:
			return "GL_RG8";

		case GL_INTERNAL_R8G8_SNORM:
			return "GL_RG8_SNORM";

		case GL_INTERNAL_R8G8_UINT:
			return "GL_RG8UI";

		case GL_INTERNAL_R8G8_SINT:
			return "GL_RG8I";

		case GL_INTERNAL_R8G8_SRGB:
			return "GL_SRG8";

		case GL_INTERNAL_R8G8B8_UNORM:
			return "GL_RGB8";

		case GL_INTERNAL_R8G8B8_SNORM:
			return "GL_RGB8_SNORM";

		case GL_INTERNAL_R8G8B8_UINT:
			return "GL_RGB8UI";

		case GL_INTERNAL_R8G8B8_SINT:
			return "GL_RGB8I";

		case GL_INTERNAL_R8G8B8_SRGB:
			return "GL_SRGB8";

		case GL_INTERNAL_R8G8B8A8_UNORM:
			return "GL_RGBA8";

		case GL_INTERNAL_R8G8B8A8_SNORM:
			return "GL_RGBA8_SNORM";

		case GL_INTERNAL_R8G8B8A8_UINT:
			return "GL_RGBA8UI";

		case GL_INTERNAL_R8G8B8A8_SINT:
			return "GL_RGBA8I";

		case GL_INTERNAL_R8G8B8A8_SRGB:
			return "GL_SRGBA8";

		case GL_INTERNAL_B8G8R8A8_UNORM:
			return "GL_BGRA8";

		case GL_INTERNAL_A2R10G10B10_UNORM_PACK32:
			return "GL_RGB10_A2";

		case GL_INTERNAL_A2R10G10B10_UINT_PACK32:
			return "GL_RGB10_A2UI";

		case GL_INTERNAL_R16_UNORM:
			return "GL_R16";

		case GL_INTERNAL_R16_SNORM:
			return "GL_R16_SNORM";

		case GL_INTERNAL_R16_SINT:
			return "GL_R16I";

		case GL_INTERNAL_R16_UINT:
			return "GL_R16UI";

		case GL_INTERNAL_R16_SFLOAT:
			return "GL_R16F";

		case GL_INTERNAL_R16G16_UNORM:
			return "GL_RG16";

		case GL_INTERNAL_R16G16_SNORM:
			return "GL_RG16_SNORM";

		case GL_INTERNAL_R16G16_UINT:
			return "GL_RG16UI";

		case GL_INTERNAL_R16G16_SINT:
			return "GL_RG16I";

		case GL_INTERNAL_R16G16_SFLOAT:
			return "GL_RG16F";

		case GL_INTERNAL_R16G16B16_UNORM:
			return "GL_RGB16";

		case GL_INTERNAL_R16G16B16_SNORM:
			return "GL_RGB16_SNORM";

		case GL_INTERNAL_R16G16B16_UINT:
			return "GL_RGB16UI";

		case GL_INTERNAL_R16G16B16_SINT:
			return "GL_RGB16I";

		case GL_INTERNAL_R16G16B16_SFLOAT:
			return "GL_RGB16F";

		case GL_INTERNAL_R16G16B16A16_UNORM:
			return "GL_RGBA16";

		case GL_INTERNAL_R16G16B16A16_SNORM:
			return "GL_RGBA16_SNORM";

		case GL_INTERNAL_R16G16B16A16_UINT:
			return "GL_RGBA16UI";

		case GL_INTERNAL_R16G16B16A16_SINT:
			return "GL_RGBA16I";

		case GL_INTERNAL_R16G16B16A16_SFLOAT:
			return "GL_RGBA16F";

		case GL_INTERNAL_R32_SINT:
			return "GL_R32I";

		case GL_INTERNAL_R32_UINT:
			return "GL_R32UI";

		case GL_INTERNAL_R32_SFLOAT:
			return "GL_R32F";

		case GL_INTERNAL_R32G32_UINT:
			return "GL_RG32UI";

		case GL_INTERNAL_R32G32_SINT:
			return "GL_RG32I";

		case GL_INTERNAL_R32G32_SFLOAT:
			return "GL_RG32F";

		case GL_INTERNAL_R32G32B32_UINT:
			return "GL_RGB32UI";

		case GL_INTERNAL_R32G32B32_SINT:
			return "GL_RGB32I";

		case GL_INTERNAL_R32G32B32_SFLOAT:
			return "GL_RGB32F";

		case GL_INTERNAL_R32G32B32A32_UINT:
			return "GL_RGBA32UI";

		case GL_INTERNAL_R32G32B32A32_SINT:
			return "GL_RGBA32I";

		case GL_INTERNAL_R32G32B32A32_SFLOAT:
			return "GL_RGBA32F";

		case GL_INTERNAL_B10G11R11_UFLOAT_PACK32:
			return "GL_R11F_G11F_B10F";

		case GL_INTERNAL_E5B9G9R9_UFLOAT_PACK32:
			return "GL_RGB9_E5";

		case GL_INTERNAL_D16_UNORM:
			return "GL_DEPTH_COMPONENT16";

		case GL_INTERNAL_D24_UNORM:
			return "GL_DEPTH_COMPONENT24";

		case GL_INTERNAL_D24_UNORM_S8_UINT:
			return "GL_DEPTH_COMPONENT24_S8";

		case GL_INTERNAL_D32_SFLOAT:
			return "GL_DEPTH_COMPONENT32F";

		case GL_INTERNAL_D32_SFLOAT_S8_UINT:
			return "GL_DEPTH32F_STENCIL8";

		case GL_INTERNAL_S8_UINT:
			return "GL_STENCIL_INDEX8";

		case GL_INTERNAL_BC1_RGB_UNORM_BLOCK:
			return "GL_COMPRESSED_RGB_S3TC_DXT1";

		case GL_INTERNAL_BC1_RGBA_UNORM_BLOCK:
			return "GL_COMPRESSED_RGBA_S3TC_DXT1";

		case GL_INTERNAL_BC2_UNORM_BLOCK:
			return "GL_COMPRESSED_RGBA_S3TC_DXT3";

		case GL_INTERNAL_BC3_UNORM_BLOCK:
			return "GL_COMPRESSED_RGBA_S3TC_DXT5";

		case GL_INTERNAL_BC1_RGB_SRGB_BLOCK:
			return "GL_COMPRESSED_SRGB_S3TC_DXT1";

		case GL_INTERNAL_BC1_RGBA_SRGB_BLOCK:
			return "GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1";

		case GL_INTERNAL_BC2_SRGB_BLOCK:
			return "GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3";

		case GL_INTERNAL_BC3_SRGB_BLOCK:
			return "GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5";

		case GL_INTERNAL_BC4_UNORM_BLOCK:
			return "GL_COMPRESSED_RED_RGTC1";

		case GL_INTERNAL_BC4_SNORM_BLOCK:
			return "GL_COMPRESSED_SIGNED_RED_RGTC1";

		case GL_INTERNAL_BC5_UNORM_BLOCK:
			return "GL_COMPRESSED_RG_RGTC2";

		case GL_INTERNAL_BC5_SNORM_BLOCK:
			return "GL_COMPRESSED_SIGNED_RG_RGTC2";

		case GL_INTERNAL_ETC2_R8G8B8_UNORM_BLOCK:
			return "GL_COMPRESSED_RGB8_ETC2";

		case GL_INTERNAL_ETC2_R8G8B8_SRGB_BLOCK:
			return "GL_COMPRESSED_SRGB8_ETC2";

		case GL_INTERNAL_ETC2_R8G8B8A1_UNORM_BLOCK:
			return "GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2";

		case GL_INTERNAL_ETC2_R8G8B8A1_SRGB_BLOCK:
			return "GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2";

		case GL_INTERNAL_ETC2_R8G8B8A8_UNORM_BLOCK:
			return "GL_COMPRESSED_RGBA8_ETC2_EAC";

		case GL_INTERNAL_ETC2_R8G8B8A8_SRGB_BLOCK:
			return "GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC";

		case GL_INTERNAL_EAC_R11_UNORM_BLOCK:
			return "GL_COMPRESSED_R11_EAC";

		case GL_INTERNAL_EAC_R11_SNORM_BLOCK:
			return "GL_COMPRESSED_SIGNED_R11_EAC";

		case GL_INTERNAL_EAC_R11G11_UNORM_BLOCK:
			return "GL_COMPRESSED_RG11_EAC";

		case GL_INTERNAL_EAC_R11G11_SNORM_BLOCK:
			return "GL_COMPRESSED_SIGNED_RG11_EAC";

		case GL_INTERNAL_ASTC_4x4_UNORM_BLOCK:
			return "GL_COMPRESSED_RGBA_ASTC_4x4";

		case GL_INTERNAL_ASTC_5x4_UNORM_BLOCK:
			return "GL_COMPRESSED_RGBA_ASTC_5x4";

		case GL_INTERNAL_ASTC_5x5_UNORM_BLOCK:
			return "GL_COMPRESSED_RGBA_ASTC_5x5";

		case GL_INTERNAL_ASTC_6x5_UNORM_BLOCK:
			return "GL_COMPRESSED_RGBA_ASTC_6x5";

		case GL_INTERNAL_ASTC_6x6_UNORM_BLOCK:
			return "GL_COMPRESSED_RGBA_ASTC_6x6";

		case GL_INTERNAL_ASTC_8x5_UNORM_BLOCK:
			return "GL_COMPRESSED_RGBA_ASTC_8x5";

		case GL_INTERNAL_ASTC_8x6_UNORM_BLOCK:
			return "GL_COMPRESSED_RGBA_ASTC_8x6";

		case GL_INTERNAL_ASTC_8x8_UNORM_BLOCK:
			return "GL_COMPRESSED_RGBA_ASTC_8x8";

		case GL_INTERNAL_ASTC_10x5_UNORM_BLOCK:
			return "GL_COMPRESSED_RGBA_ASTC_10x5";

		case GL_INTERNAL_ASTC_10x6_UNORM_BLOCK:
			return "GL_COMPRESSED_RGBA_ASTC_10x6";

		case GL_INTERNAL_ASTC_10x8_UNORM_BLOCK:
			return "GL_COMPRESSED_RGBA_ASTC_10x8";

		case GL_INTERNAL_ASTC_10x10_UNORM_BLOCK:
			return "GL_COMPRESSED_RGBA_ASTC_10x10";

		case GL_INTERNAL_ASTC_12x10_UNORM_BLOCK:
			return "GL_COMPRESSED_RGBA_ASTC_12x10";

		case GL_INTERNAL_ASTC_12x12_UNORM_BLOCK:
			return "GL_COMPRESSED_RGBA_ASTC_12x12";

		case GL_INTERNAL_ASTC_4x4_SRGB_BLOCK:
			return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4";

		case GL_INTERNAL_ASTC_5x4_SRGB_BLOCK:
			return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4";

		case GL_INTERNAL_ASTC_5x5_SRGB_BLOCK:
			return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5";

		case GL_INTERNAL_ASTC_6x5_SRGB_BLOCK:
			return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5";

		case GL_INTERNAL_ASTC_6x6_SRGB_BLOCK:
			return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6";

		case GL_INTERNAL_ASTC_8x5_SRGB_BLOCK:
			return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5";

		case GL_INTERNAL_ASTC_8x6_SRGB_BLOCK:
			return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6";

		case GL_INTERNAL_ASTC_8x8_SRGB_BLOCK:
			return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8";

		case GL_INTERNAL_ASTC_10x5_SRGB_BLOCK:
			return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5";

		case GL_INTERNAL_ASTC_10x6_SRGB_BLOCK:
			return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6";

		case GL_INTERNAL_ASTC_10x8_SRGB_BLOCK:
			return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8";

		case GL_INTERNAL_ASTC_10x10_SRGB_BLOCK:
			return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10";

		case GL_INTERNAL_ASTC_12x10_SRGB_BLOCK:
			return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10";

		case GL_INTERNAL_ASTC_12x12_SRGB_BLOCK:
			return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12";


		default:
			assert( false && "Unupported GlInternal" );
			return "GlInternal_UNKNOWN";
		}
	}

	std::string getName( GlFormat value )
	{
		switch ( value )
		{
		case GL_FORMAT_S:
			return "GL_STENCIL_INDEX";

		case GL_FORMAT_D:
			return "GL_DEPTH_COMPONENT";

		case GL_FORMAT_R:
			return "GL_RED";

		case GL_FORMAT_RGB:
			return "GL_RGB";

		case GL_FORMAT_RGBA:
			return "GL_RGBA";

		case GL_FORMAT_ABGR:
			return "GL_ABGR";

		case GL_FORMAT_BGR:
			return "GL_BGR";

		case GL_FORMAT_BGRA:
			return "GL_BGRA";

		case GL_FORMAT_RG:
			return "GL_RG";

		case GL_FORMAT_DS:
			return "GL_DEPTH_STENCIL";

		default:
			assert( false && "Unupported GlFormat" );
			return "GlFormat_UNKNOWN";
		}
	}

	std::string getName( GlType value )
	{
		switch ( value )
		{
		case GL_TYPE_UI8:
			return "GL_UNSIGNED_BYTE";

		case GL_TYPE_UI16:
			return "GL_UNSIGNED_SHORT";

		case GL_TYPE_F32:
			return "GL_FLOAT";

		case GL_TYPE_US4444:
			return "GL_UNSIGNED_SHORT_4_4_4_4";

		case GL_TYPE_US5551:
			return "GL_UNSIGNED_SHORT_5_5_5_1";

		case GL_TYPE_UI8888:
			return "GL_UNSIGNED_INT_8_8_8_8";

		case GL_TYPE_UI_10_10_10_2:
			return "GL_UNSIGNED_INT_10_10_10_2";

		case GL_TYPE_UI565:
			return "GL_UNSIGNED_SHORT_5_6_5";

		case GL_TYPE_UI24_8:
			return "GL_UNSIGNED_INT_24_8";

		default:
			assert( false && "Unupported GlType" );
			return "GlType_UNKNOWN";
		}
	}

	bool isDepthStencilFormat( GlInternal format )noexcept
	{
		return format == GL_INTERNAL_D16_UNORM
			|| format == GL_INTERNAL_D24_UNORM_S8_UINT
			|| format == GL_INTERNAL_D32_SFLOAT_S8_UINT;
	}

	bool isStencilFormat( GlInternal format )noexcept
	{
		return format == GL_INTERNAL_S8_UINT;
	}

	bool isDepthFormat( GlInternal format )noexcept
	{
		return format == GL_INTERNAL_D16_UNORM
			|| format == GL_INTERNAL_D32_SFLOAT;
	}

	bool isSupportedInternal( renderer::Format const & format )noexcept
	{
		switch ( format )
		{
		case renderer::Format::eR4G4B4A4_UNORM_PACK16:
		case renderer::Format::eR5G6B5_UNORM_PACK16:
		case renderer::Format::eR5G5B5A1_UNORM_PACK16:
		case renderer::Format::eR8_UNORM:
		case renderer::Format::eR8_SNORM:
		case renderer::Format::eR8_UINT:
		case renderer::Format::eR8_SINT:
		case renderer::Format::eR8_SRGB:
		case renderer::Format::eR8G8_UNORM:
		case renderer::Format::eR8G8_SNORM:
		case renderer::Format::eR8G8_UINT:
		case renderer::Format::eR8G8_SINT:
		case renderer::Format::eR8G8_SRGB:
		case renderer::Format::eR8G8B8_UNORM:
		case renderer::Format::eR8G8B8_SNORM:
		case renderer::Format::eR8G8B8_UINT:
		case renderer::Format::eR8G8B8_SINT:
		case renderer::Format::eR8G8B8_SRGB:
		case renderer::Format::eR8G8B8A8_UNORM:
		case renderer::Format::eR8G8B8A8_SNORM:
		case renderer::Format::eR8G8B8A8_UINT:
		case renderer::Format::eR8G8B8A8_SINT:
		case renderer::Format::eR8G8B8A8_SRGB:
		case renderer::Format::eB8G8R8A8_UNORM:
		case renderer::Format::eA2R10G10B10_UNORM_PACK32:
		case renderer::Format::eA2R10G10B10_UINT_PACK32:
		case renderer::Format::eR16_UNORM:
		case renderer::Format::eR16_SNORM:
		case renderer::Format::eR16_UINT:
		case renderer::Format::eR16_SINT:
		case renderer::Format::eR16_SFLOAT:
		case renderer::Format::eR16G16_UNORM:
		case renderer::Format::eR16G16_SNORM:
		case renderer::Format::eR16G16_UINT:
		case renderer::Format::eR16G16_SINT:
		case renderer::Format::eR16G16_SFLOAT:
		case renderer::Format::eR16G16B16_UNORM:
		case renderer::Format::eR16G16B16_SNORM:
		case renderer::Format::eR16G16B16_UINT:
		case renderer::Format::eR16G16B16_SINT:
		case renderer::Format::eR16G16B16_SFLOAT:
		case renderer::Format::eR16G16B16A16_UNORM:
		case renderer::Format::eR16G16B16A16_SNORM:
		case renderer::Format::eR16G16B16A16_UINT:
		case renderer::Format::eR16G16B16A16_SINT:
		case renderer::Format::eR16G16B16A16_SFLOAT:
		case renderer::Format::eR32_UINT:
		case renderer::Format::eR32_SINT:
		case renderer::Format::eR32_SFLOAT:
		case renderer::Format::eR32G32_UINT:
		case renderer::Format::eR32G32_SINT:
		case renderer::Format::eR32G32_SFLOAT:
		case renderer::Format::eR32G32B32_UINT:
		case renderer::Format::eR32G32B32_SINT:
		case renderer::Format::eR32G32B32_SFLOAT:
		case renderer::Format::eR32G32B32A32_UINT:
		case renderer::Format::eR32G32B32A32_SINT:
		case renderer::Format::eR32G32B32A32_SFLOAT:
		case renderer::Format::eB10G11R11_UFLOAT_PACK32:
		case renderer::Format::eE5B9G9R9_UFLOAT_PACK32:
		case renderer::Format::eD16_UNORM:
		case renderer::Format::eD32_SFLOAT:
		case renderer::Format::eS8_UINT:
		case renderer::Format::eD24_UNORM_S8_UINT:
		case renderer::Format::eD32_SFLOAT_S8_UINT:
		case renderer::Format::eBC1_RGB_UNORM_BLOCK:
		case renderer::Format::eBC1_RGB_SRGB_BLOCK:
		case renderer::Format::eBC1_RGBA_UNORM_BLOCK:
		case renderer::Format::eBC1_RGBA_SRGB_BLOCK:
		case renderer::Format::eBC2_UNORM_BLOCK:
		case renderer::Format::eBC2_SRGB_BLOCK:
		case renderer::Format::eBC3_UNORM_BLOCK:
		case renderer::Format::eBC3_SRGB_BLOCK:
		case renderer::Format::eBC4_UNORM_BLOCK:
		case renderer::Format::eBC4_SNORM_BLOCK:
		case renderer::Format::eBC5_UNORM_BLOCK:
		case renderer::Format::eBC5_SNORM_BLOCK:
		case renderer::Format::eBC6H_UFLOAT_BLOCK:
		case renderer::Format::eBC6H_SFLOAT_BLOCK:
		case renderer::Format::eBC7_UNORM_BLOCK:
		case renderer::Format::eBC7_SRGB_BLOCK:
		case renderer::Format::eETC2_R8G8B8_UNORM_BLOCK:
		case renderer::Format::eETC2_R8G8B8_SRGB_BLOCK:
		case renderer::Format::eETC2_R8G8B8A1_UNORM_BLOCK:
		case renderer::Format::eETC2_R8G8B8A1_SRGB_BLOCK:
		case renderer::Format::eETC2_R8G8B8A8_UNORM_BLOCK:
		case renderer::Format::eETC2_R8G8B8A8_SRGB_BLOCK:
		case renderer::Format::eEAC_R11_UNORM_BLOCK:
		case renderer::Format::eEAC_R11_SNORM_BLOCK:
		case renderer::Format::eEAC_R11G11_UNORM_BLOCK:
		case renderer::Format::eEAC_R11G11_SNORM_BLOCK:
		case renderer::Format::eASTC_4x4_UNORM_BLOCK:
		case renderer::Format::eASTC_4x4_SRGB_BLOCK:
		case renderer::Format::eASTC_5x4_UNORM_BLOCK:
		case renderer::Format::eASTC_5x4_SRGB_BLOCK:
		case renderer::Format::eASTC_5x5_UNORM_BLOCK:
		case renderer::Format::eASTC_5x5_SRGB_BLOCK:
		case renderer::Format::eASTC_6x5_UNORM_BLOCK:
		case renderer::Format::eASTC_6x5_SRGB_BLOCK:
		case renderer::Format::eASTC_6x6_UNORM_BLOCK:
		case renderer::Format::eASTC_6x6_SRGB_BLOCK:
		case renderer::Format::eASTC_8x5_UNORM_BLOCK:
		case renderer::Format::eASTC_8x5_SRGB_BLOCK:
		case renderer::Format::eASTC_8x6_UNORM_BLOCK:
		case renderer::Format::eASTC_8x6_SRGB_BLOCK:
		case renderer::Format::eASTC_8x8_UNORM_BLOCK:
		case renderer::Format::eASTC_8x8_SRGB_BLOCK:
		case renderer::Format::eASTC_10x5_UNORM_BLOCK:
		case renderer::Format::eASTC_10x5_SRGB_BLOCK:
		case renderer::Format::eASTC_10x6_UNORM_BLOCK:
		case renderer::Format::eASTC_10x6_SRGB_BLOCK:
		case renderer::Format::eASTC_10x8_UNORM_BLOCK:
		case renderer::Format::eASTC_10x8_SRGB_BLOCK:
		case renderer::Format::eASTC_10x10_UNORM_BLOCK:
		case renderer::Format::eASTC_10x10_SRGB_BLOCK:
		case renderer::Format::eASTC_12x10_UNORM_BLOCK:
		case renderer::Format::eASTC_12x10_SRGB_BLOCK:
		case renderer::Format::eASTC_12x12_UNORM_BLOCK:
		case renderer::Format::eASTC_12x12_SRGB_BLOCK:
			return true;

		default:
			return false;
		}
	}

	GlInternal getInternal( renderer::Format const & format )noexcept
	{
		switch ( format )
		{
		case renderer::Format::eR4G4B4A4_UNORM_PACK16: return GL_INTERNAL_R4G4B4A4_UNORM_PACK16;
		case renderer::Format::eR5G6B5_UNORM_PACK16: return GL_INTERNAL_R5G6B5_UNORM_PACK16;
		case renderer::Format::eR5G5B5A1_UNORM_PACK16: return GL_INTERNAL_R5G5B5A1_UNORM_PACK16;
		case renderer::Format::eR8_UNORM: return GL_INTERNAL_R8_UNORM;
		case renderer::Format::eR8_SNORM: return GL_INTERNAL_R8_SNORM;
		case renderer::Format::eR8_UINT: return GL_INTERNAL_R8_UINT;
		case renderer::Format::eR8_SINT: return GL_INTERNAL_R8_SINT;
		case renderer::Format::eR8_SRGB: return GL_INTERNAL_R8_SRGB;
		case renderer::Format::eR8G8_UNORM: return GL_INTERNAL_R8G8_UNORM;
		case renderer::Format::eR8G8_SNORM: return GL_INTERNAL_R8G8_SNORM;
		case renderer::Format::eR8G8_UINT: return GL_INTERNAL_R8G8_UINT;
		case renderer::Format::eR8G8_SINT: return GL_INTERNAL_R8G8_SINT;
		case renderer::Format::eR8G8_SRGB: return GL_INTERNAL_R8G8_SRGB;
		case renderer::Format::eR8G8B8_UNORM: return GL_INTERNAL_R8G8B8_UNORM;
		case renderer::Format::eR8G8B8_SNORM: return GL_INTERNAL_R8G8B8_SNORM;
		case renderer::Format::eR8G8B8_UINT: return GL_INTERNAL_R8G8B8_UINT;
		case renderer::Format::eR8G8B8_SINT: return GL_INTERNAL_R8G8B8_SINT;
		case renderer::Format::eR8G8B8_SRGB: return GL_INTERNAL_R8G8B8_SRGB;
		case renderer::Format::eR8G8B8A8_UNORM: return GL_INTERNAL_R8G8B8A8_UNORM;
		case renderer::Format::eR8G8B8A8_SNORM: return GL_INTERNAL_R8G8B8A8_SNORM;
		case renderer::Format::eR8G8B8A8_UINT: return GL_INTERNAL_R8G8B8A8_UINT;
		case renderer::Format::eR8G8B8A8_SINT: return GL_INTERNAL_R8G8B8A8_SINT;
		case renderer::Format::eR8G8B8A8_SRGB: return GL_INTERNAL_R8G8B8A8_SRGB;
		case renderer::Format::eB8G8R8A8_UNORM: return GL_INTERNAL_B8G8R8A8_UNORM;
		case renderer::Format::eA2R10G10B10_UNORM_PACK32: return GL_INTERNAL_A2R10G10B10_UNORM_PACK32;
		case renderer::Format::eA2R10G10B10_UINT_PACK32: return GL_INTERNAL_A2R10G10B10_UINT_PACK32;
		case renderer::Format::eR16_UNORM: return GL_INTERNAL_R16_UNORM;
		case renderer::Format::eR16_SNORM: return GL_INTERNAL_R16_SNORM;
		case renderer::Format::eR16_UINT: return GL_INTERNAL_R16_UINT;
		case renderer::Format::eR16_SINT: return GL_INTERNAL_R16_SINT;
		case renderer::Format::eR16_SFLOAT: return GL_INTERNAL_R16_SFLOAT;
		case renderer::Format::eR16G16_UNORM: return GL_INTERNAL_R16G16_UNORM;
		case renderer::Format::eR16G16_SNORM: return GL_INTERNAL_R16G16_SNORM;
		case renderer::Format::eR16G16_UINT: return GL_INTERNAL_R16G16_UINT;
		case renderer::Format::eR16G16_SINT: return GL_INTERNAL_R16G16_SINT;
		case renderer::Format::eR16G16_SFLOAT: return GL_INTERNAL_R16G16_SFLOAT;
		case renderer::Format::eR16G16B16_UNORM: return GL_INTERNAL_R16G16B16_UNORM;
		case renderer::Format::eR16G16B16_SNORM: return GL_INTERNAL_R16G16B16_SNORM;
		case renderer::Format::eR16G16B16_UINT: return GL_INTERNAL_R16G16B16_UINT;
		case renderer::Format::eR16G16B16_SINT: return GL_INTERNAL_R16G16B16_SINT;
		case renderer::Format::eR16G16B16_SFLOAT: return GL_INTERNAL_R16G16B16_SFLOAT;
		case renderer::Format::eR16G16B16A16_UNORM: return GL_INTERNAL_R16G16B16A16_UNORM;
		case renderer::Format::eR16G16B16A16_SNORM: return GL_INTERNAL_R16G16B16A16_SNORM;
		case renderer::Format::eR16G16B16A16_UINT: return GL_INTERNAL_R16G16B16A16_UINT;
		case renderer::Format::eR16G16B16A16_SINT: return GL_INTERNAL_R16G16B16A16_SINT;
		case renderer::Format::eR16G16B16A16_SFLOAT: return GL_INTERNAL_R16G16B16A16_SFLOAT;
		case renderer::Format::eR32_UINT: return GL_INTERNAL_R32_UINT;
		case renderer::Format::eR32_SINT: return GL_INTERNAL_R32_SINT;
		case renderer::Format::eR32_SFLOAT: return GL_INTERNAL_R32_SFLOAT;
		case renderer::Format::eR32G32_UINT: return GL_INTERNAL_R32G32_UINT;
		case renderer::Format::eR32G32_SINT: return GL_INTERNAL_R32G32_SINT;
		case renderer::Format::eR32G32_SFLOAT: return GL_INTERNAL_R32G32_SFLOAT;
		case renderer::Format::eR32G32B32_UINT: return GL_INTERNAL_R32G32B32_UINT;
		case renderer::Format::eR32G32B32_SINT: return GL_INTERNAL_R32G32B32_SINT;
		case renderer::Format::eR32G32B32_SFLOAT: return GL_INTERNAL_R32G32B32_SFLOAT;
		case renderer::Format::eR32G32B32A32_UINT: return GL_INTERNAL_R32G32B32A32_UINT;
		case renderer::Format::eR32G32B32A32_SINT: return GL_INTERNAL_R32G32B32A32_SINT;
		case renderer::Format::eR32G32B32A32_SFLOAT: return GL_INTERNAL_R32G32B32A32_SFLOAT;
		case renderer::Format::eB10G11R11_UFLOAT_PACK32: return GL_INTERNAL_B10G11R11_UFLOAT_PACK32;
		case renderer::Format::eE5B9G9R9_UFLOAT_PACK32: return GL_INTERNAL_E5B9G9R9_UFLOAT_PACK32;
		case renderer::Format::eD16_UNORM: return GL_INTERNAL_D16_UNORM;
		case renderer::Format::eD32_SFLOAT: return GL_INTERNAL_D32_SFLOAT;
		case renderer::Format::eS8_UINT: return GL_INTERNAL_S8_UINT;
		case renderer::Format::eD24_UNORM_S8_UINT: return GL_INTERNAL_D24_UNORM_S8_UINT;
		case renderer::Format::eD32_SFLOAT_S8_UINT: return GL_INTERNAL_D32_SFLOAT;
		case renderer::Format::eBC1_RGB_UNORM_BLOCK: return GL_INTERNAL_BC1_RGB_UNORM_BLOCK;
		case renderer::Format::eBC1_RGB_SRGB_BLOCK: return GL_INTERNAL_BC1_RGB_SRGB_BLOCK;
		case renderer::Format::eBC1_RGBA_UNORM_BLOCK: return GL_INTERNAL_BC1_RGBA_UNORM_BLOCK;
		case renderer::Format::eBC1_RGBA_SRGB_BLOCK: return GL_INTERNAL_BC1_RGBA_SRGB_BLOCK;
		case renderer::Format::eBC2_UNORM_BLOCK: return GL_INTERNAL_BC2_UNORM_BLOCK;
		case renderer::Format::eBC2_SRGB_BLOCK: return GL_INTERNAL_BC2_SRGB_BLOCK;
		case renderer::Format::eBC3_UNORM_BLOCK: return GL_INTERNAL_BC3_UNORM_BLOCK;
		case renderer::Format::eBC3_SRGB_BLOCK: return GL_INTERNAL_BC3_SRGB_BLOCK;
		case renderer::Format::eBC4_UNORM_BLOCK: return GL_INTERNAL_BC4_UNORM_BLOCK;
		case renderer::Format::eBC4_SNORM_BLOCK: return GL_INTERNAL_BC4_SNORM_BLOCK;
		case renderer::Format::eBC5_UNORM_BLOCK: return GL_INTERNAL_BC5_UNORM_BLOCK;
		case renderer::Format::eBC5_SNORM_BLOCK: return GL_INTERNAL_BC5_SNORM_BLOCK;
		case renderer::Format::eBC6H_UFLOAT_BLOCK: return GL_INTERNAL_BC6H_UFLOAT_BLOCK;
		case renderer::Format::eBC6H_SFLOAT_BLOCK: return GL_INTERNAL_BC6H_SFLOAT_BLOCK;
		case renderer::Format::eBC7_UNORM_BLOCK: return GL_INTERNAL_BC7_UNORM_BLOCK;
		case renderer::Format::eBC7_SRGB_BLOCK: return GL_INTERNAL_BC7_SRGB_BLOCK;
		case renderer::Format::eETC2_R8G8B8_UNORM_BLOCK: return GL_INTERNAL_ETC2_R8G8B8_UNORM_BLOCK;
		case renderer::Format::eETC2_R8G8B8_SRGB_BLOCK: return GL_INTERNAL_ETC2_R8G8B8_SRGB_BLOCK;
		case renderer::Format::eETC2_R8G8B8A1_UNORM_BLOCK: return GL_INTERNAL_ETC2_R8G8B8A1_UNORM_BLOCK;
		case renderer::Format::eETC2_R8G8B8A1_SRGB_BLOCK: return GL_INTERNAL_ETC2_R8G8B8A1_SRGB_BLOCK;
		case renderer::Format::eETC2_R8G8B8A8_UNORM_BLOCK: return GL_INTERNAL_ETC2_R8G8B8A8_UNORM_BLOCK;
		case renderer::Format::eETC2_R8G8B8A8_SRGB_BLOCK: return GL_INTERNAL_ETC2_R8G8B8A8_SRGB_BLOCK;
		case renderer::Format::eEAC_R11_UNORM_BLOCK: return GL_INTERNAL_EAC_R11_UNORM_BLOCK;
		case renderer::Format::eEAC_R11_SNORM_BLOCK: return GL_INTERNAL_EAC_R11_SNORM_BLOCK;
		case renderer::Format::eEAC_R11G11_UNORM_BLOCK: return GL_INTERNAL_EAC_R11G11_UNORM_BLOCK;
		case renderer::Format::eEAC_R11G11_SNORM_BLOCK: return GL_INTERNAL_EAC_R11G11_SNORM_BLOCK;
		case renderer::Format::eASTC_4x4_UNORM_BLOCK: return GL_INTERNAL_ASTC_4x4_UNORM_BLOCK;
		case renderer::Format::eASTC_4x4_SRGB_BLOCK: return GL_INTERNAL_ASTC_4x4_SRGB_BLOCK;
		case renderer::Format::eASTC_5x4_UNORM_BLOCK: return GL_INTERNAL_ASTC_5x4_UNORM_BLOCK;
		case renderer::Format::eASTC_5x4_SRGB_BLOCK: return GL_INTERNAL_ASTC_5x4_SRGB_BLOCK;
		case renderer::Format::eASTC_5x5_UNORM_BLOCK: return GL_INTERNAL_ASTC_5x5_UNORM_BLOCK;
		case renderer::Format::eASTC_5x5_SRGB_BLOCK: return GL_INTERNAL_ASTC_5x5_SRGB_BLOCK;
		case renderer::Format::eASTC_6x5_UNORM_BLOCK: return GL_INTERNAL_ASTC_6x5_UNORM_BLOCK;
		case renderer::Format::eASTC_6x5_SRGB_BLOCK: return GL_INTERNAL_ASTC_6x5_SRGB_BLOCK;
		case renderer::Format::eASTC_6x6_UNORM_BLOCK: return GL_INTERNAL_ASTC_6x6_UNORM_BLOCK;
		case renderer::Format::eASTC_6x6_SRGB_BLOCK: return GL_INTERNAL_ASTC_6x6_SRGB_BLOCK;
		case renderer::Format::eASTC_8x5_UNORM_BLOCK: return GL_INTERNAL_ASTC_8x5_UNORM_BLOCK;
		case renderer::Format::eASTC_8x5_SRGB_BLOCK: return GL_INTERNAL_ASTC_8x5_SRGB_BLOCK;
		case renderer::Format::eASTC_8x6_UNORM_BLOCK: return GL_INTERNAL_ASTC_8x6_UNORM_BLOCK;
		case renderer::Format::eASTC_8x6_SRGB_BLOCK: return GL_INTERNAL_ASTC_8x6_SRGB_BLOCK;
		case renderer::Format::eASTC_8x8_UNORM_BLOCK: return GL_INTERNAL_ASTC_8x8_UNORM_BLOCK;
		case renderer::Format::eASTC_8x8_SRGB_BLOCK: return GL_INTERNAL_ASTC_8x8_SRGB_BLOCK;
		case renderer::Format::eASTC_10x5_UNORM_BLOCK: return GL_INTERNAL_ASTC_10x5_UNORM_BLOCK;
		case renderer::Format::eASTC_10x5_SRGB_BLOCK: return GL_INTERNAL_ASTC_10x5_SRGB_BLOCK;
		case renderer::Format::eASTC_10x6_UNORM_BLOCK: return GL_INTERNAL_ASTC_10x6_UNORM_BLOCK;
		case renderer::Format::eASTC_10x6_SRGB_BLOCK: return GL_INTERNAL_ASTC_10x6_SRGB_BLOCK;
		case renderer::Format::eASTC_10x8_UNORM_BLOCK: return GL_INTERNAL_ASTC_10x8_UNORM_BLOCK;
		case renderer::Format::eASTC_10x8_SRGB_BLOCK: return GL_INTERNAL_ASTC_10x8_SRGB_BLOCK;
		case renderer::Format::eASTC_10x10_UNORM_BLOCK: return GL_INTERNAL_ASTC_10x10_UNORM_BLOCK;
		case renderer::Format::eASTC_10x10_SRGB_BLOCK: return GL_INTERNAL_ASTC_10x10_SRGB_BLOCK;
		case renderer::Format::eASTC_12x10_UNORM_BLOCK: return GL_INTERNAL_ASTC_12x10_UNORM_BLOCK;
		case renderer::Format::eASTC_12x10_SRGB_BLOCK: return GL_INTERNAL_ASTC_12x10_SRGB_BLOCK;
		case renderer::Format::eASTC_12x12_UNORM_BLOCK: return GL_INTERNAL_ASTC_12x12_UNORM_BLOCK;
		case renderer::Format::eASTC_12x12_SRGB_BLOCK: return GL_INTERNAL_ASTC_12x12_SRGB_BLOCK;

		default:
			assert( false && "Unsupported pixel format." );
			return GL_INTERNAL_R8G8B8A8_UNORM;
		}
	}

	GlFormat getFormat( GlInternal format )noexcept
	{
		switch ( format )
		{
		case GL_INTERNAL_R8_UNORM:
		case GL_INTERNAL_R8_SNORM:
		case GL_INTERNAL_R8_UINT:
		case GL_INTERNAL_R8_SINT:
		case GL_INTERNAL_R8_SRGB:
		case GL_INTERNAL_R16_UNORM:
		case GL_INTERNAL_R16_SNORM:
		case GL_INTERNAL_R16_UINT:
		case GL_INTERNAL_R16_SINT:
		case GL_INTERNAL_R16_SFLOAT:
		case GL_INTERNAL_R32_UINT:
		case GL_INTERNAL_R32_SINT:
		case GL_INTERNAL_R32_SFLOAT:
		case GL_INTERNAL_EAC_R11_UNORM_BLOCK:
		case GL_INTERNAL_EAC_R11_SNORM_BLOCK:
			return GL_FORMAT_R;

		case GL_INTERNAL_R8G8_UNORM:
		case GL_INTERNAL_R8G8_SNORM:
		case GL_INTERNAL_R8G8_UINT:
		case GL_INTERNAL_R8G8_SINT:
		case GL_INTERNAL_R8G8_SRGB:
		case GL_INTERNAL_R16G16_UNORM:
		case GL_INTERNAL_R16G16_SNORM:
		case GL_INTERNAL_R16G16_UINT:
		case GL_INTERNAL_R16G16_SINT:
		case GL_INTERNAL_R16G16_SFLOAT:
		case GL_INTERNAL_R32G32_UINT:
		case GL_INTERNAL_R32G32_SINT:
		case GL_INTERNAL_R32G32_SFLOAT:
		case GL_INTERNAL_BC5_UNORM_BLOCK:
		case GL_INTERNAL_BC5_SNORM_BLOCK:
		case GL_INTERNAL_EAC_R11G11_UNORM_BLOCK:
		case GL_INTERNAL_EAC_R11G11_SNORM_BLOCK:
			return GL_FORMAT_RG;

		case GL_INTERNAL_R8G8B8_UNORM:
		case GL_INTERNAL_R8G8B8_SNORM:
		case GL_INTERNAL_R8G8B8_UINT:
		case GL_INTERNAL_R8G8B8_SINT:
		case GL_INTERNAL_R8G8B8_SRGB:
		case GL_INTERNAL_R16G16B16_UNORM:
		case GL_INTERNAL_R16G16B16_SNORM:
		case GL_INTERNAL_R16G16B16_UINT:
		case GL_INTERNAL_R16G16B16_SINT:
		case GL_INTERNAL_R16G16B16_SFLOAT:
		case GL_INTERNAL_R32G32B32_UINT:
		case GL_INTERNAL_R32G32B32_SINT:
		case GL_INTERNAL_R32G32B32_SFLOAT:
		case GL_INTERNAL_BC1_RGB_UNORM_BLOCK:
		case GL_INTERNAL_BC1_RGB_SRGB_BLOCK:
		case GL_INTERNAL_ETC2_R8G8B8_UNORM_BLOCK:
		case GL_INTERNAL_ETC2_R8G8B8_SRGB_BLOCK:
			return GL_FORMAT_RGB;

		case GL_INTERNAL_R8G8B8A8_UNORM:
		case GL_INTERNAL_R8G8B8A8_SNORM:
		case GL_INTERNAL_R8G8B8A8_UINT:
		case GL_INTERNAL_R8G8B8A8_SINT:
		case GL_INTERNAL_R8G8B8A8_SRGB:
		case GL_INTERNAL_R16G16B16A16_UNORM:
		case GL_INTERNAL_R16G16B16A16_SNORM:
		case GL_INTERNAL_R16G16B16A16_UINT:
		case GL_INTERNAL_R16G16B16A16_SINT:
		case GL_INTERNAL_R16G16B16A16_SFLOAT:
		case GL_INTERNAL_R32G32B32A32_UINT:
		case GL_INTERNAL_R32G32B32A32_SINT:
		case GL_INTERNAL_R32G32B32A32_SFLOAT:
		case GL_INTERNAL_BC1_RGBA_UNORM_BLOCK:
		case GL_INTERNAL_BC1_RGBA_SRGB_BLOCK:
		case GL_INTERNAL_BC2_UNORM_BLOCK:
		case GL_INTERNAL_BC2_SRGB_BLOCK:
		case GL_INTERNAL_BC3_UNORM_BLOCK:
		case GL_INTERNAL_BC3_SRGB_BLOCK:
		case GL_INTERNAL_ETC2_R8G8B8A1_UNORM_BLOCK:
		case GL_INTERNAL_ETC2_R8G8B8A1_SRGB_BLOCK:
		case GL_INTERNAL_ETC2_R8G8B8A8_UNORM_BLOCK:
		case GL_INTERNAL_ETC2_R8G8B8A8_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_4x4_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_4x4_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_5x4_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_5x4_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_5x5_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_5x5_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_6x5_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_6x5_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_6x6_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_6x6_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_8x5_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_8x5_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_8x6_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_8x6_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_8x8_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_8x8_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_10x5_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_10x5_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_10x6_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_10x6_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_10x8_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_10x8_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_10x10_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_10x10_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_12x10_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_12x10_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_12x12_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_12x12_SRGB_BLOCK:
			return GL_FORMAT_RGBA;

		case GL_INTERNAL_B8G8R8A8_UNORM:
			return GL_FORMAT_BGRA;

		case GL_INTERNAL_D16_UNORM:
		case GL_INTERNAL_D24_UNORM:
		case GL_INTERNAL_D32_SFLOAT:
			return GL_FORMAT_D;

		case GL_INTERNAL_D24_UNORM_S8_UINT:
		case GL_INTERNAL_D32_SFLOAT_S8_UINT:
			return GL_FORMAT_DS;

		case GL_INTERNAL_S8_UINT:
			return GL_FORMAT_S;

		default:
			assert( false && "Unsupported pixel format." );
			return GL_FORMAT_RGBA;
		}
	}

	GlType getType( GlInternal format )noexcept
	{
		switch ( format )
		{
		case GL_INTERNAL_R4G4B4A4_UNORM_PACK16:
			return GL_TYPE_US4444;

		case GL_INTERNAL_R5G6B5_UNORM_PACK16:
			return GL_TYPE_UI565;

		case GL_INTERNAL_R5G5B5A1_UNORM_PACK16:
			return GL_TYPE_US5551;

		case GL_INTERNAL_R8_SNORM:
		case GL_INTERNAL_R8G8_SNORM:
		case GL_INTERNAL_R8G8B8_SNORM:
		case GL_INTERNAL_R8G8B8A8_SNORM:
		case GL_INTERNAL_R8_SINT:
		case GL_INTERNAL_R8G8_SINT:
		case GL_INTERNAL_R8G8B8_SINT:
		case GL_INTERNAL_R8G8B8A8_SINT:
			return GL_TYPE_I8;

		case GL_INTERNAL_R8_UNORM:
		case GL_INTERNAL_R8G8_UNORM:
		case GL_INTERNAL_R8G8B8_UNORM:
		case GL_INTERNAL_R8G8B8A8_UNORM:
		case GL_INTERNAL_R8_UINT:
		case GL_INTERNAL_R8G8_UINT:
		case GL_INTERNAL_R8G8B8_UINT:
		case GL_INTERNAL_R8G8B8A8_UINT:
		case GL_INTERNAL_R8_SRGB:
		case GL_INTERNAL_R8G8_SRGB:
		case GL_INTERNAL_R8G8B8_SRGB:
		case GL_INTERNAL_R8G8B8A8_SRGB:
		case GL_INTERNAL_B8G8R8A8_UNORM:
			return GL_TYPE_UI8;

		case GL_INTERNAL_A2R10G10B10_UNORM_PACK32:
		case GL_INTERNAL_A2R10G10B10_UINT_PACK32:
			return GL_TYPE_UI_2_10_10_10;

		case GL_INTERNAL_R16_SNORM:
		case GL_INTERNAL_R16G16_SNORM:
		case GL_INTERNAL_R16G16B16_SNORM:
		case GL_INTERNAL_R16G16B16A16_SNORM:
		case GL_INTERNAL_R16_SINT:
		case GL_INTERNAL_R16G16_SINT:
		case GL_INTERNAL_R16G16B16_SINT:
		case GL_INTERNAL_R16G16B16A16_SINT:
			return GL_TYPE_I16;

		case GL_INTERNAL_R16_UNORM:
		case GL_INTERNAL_R16G16_UNORM:
		case GL_INTERNAL_R16G16B16_UNORM:
		case GL_INTERNAL_R16G16B16A16_UNORM:
		case GL_INTERNAL_R16_UINT:
		case GL_INTERNAL_R16G16_UINT:
		case GL_INTERNAL_R16G16B16_UINT:
		case GL_INTERNAL_R16G16B16A16_UINT:
			return GL_TYPE_UI16;

		case GL_INTERNAL_R16_SFLOAT:
		case GL_INTERNAL_R16G16_SFLOAT:
		case GL_INTERNAL_R16G16B16_SFLOAT:
		case GL_INTERNAL_R16G16B16A16_SFLOAT:
			return GL_TYPE_F16;

		case GL_INTERNAL_R32_SINT:
		case GL_INTERNAL_R32G32_SINT:
		case GL_INTERNAL_R32G32B32_SINT:
		case GL_INTERNAL_R32G32B32A32_SINT:
			return GL_TYPE_I32;

		case GL_INTERNAL_R32_UINT:
		case GL_INTERNAL_R32G32_UINT:
		case GL_INTERNAL_R32G32B32_UINT:
		case GL_INTERNAL_R32G32B32A32_UINT:
			return GL_TYPE_UI32;

		case GL_INTERNAL_R32_SFLOAT:
		case GL_INTERNAL_R32G32_SFLOAT:
		case GL_INTERNAL_R32G32B32_SFLOAT:
		case GL_INTERNAL_R32G32B32A32_SFLOAT:
			return GL_TYPE_F32;

		case GL_INTERNAL_B10G11R11_UFLOAT_PACK32:
			return GL_UI_10F_11F_11F;

		case GL_INTERNAL_E5B9G9R9_UFLOAT_PACK32:
			return GL_UI_5_9_9_9;

		case GL_INTERNAL_D16_UNORM:
			return GL_TYPE_UI16;

		case GL_INTERNAL_D24_UNORM:
			return GL_TYPE_UI32;

		case GL_INTERNAL_D32_SFLOAT:
			return GL_TYPE_F32;

		case GL_INTERNAL_S8_UINT:
			return GL_TYPE_UI8;

		case GL_INTERNAL_D24_UNORM_S8_UINT:
			return GL_TYPE_UI24_8;

		case GL_INTERNAL_D32_SFLOAT_S8_UINT:
			return GL_TYPE_32F_UI24_8;

		case GL_INTERNAL_BC1_RGB_UNORM_BLOCK:
		case GL_INTERNAL_BC1_RGB_SRGB_BLOCK:
		case GL_INTERNAL_BC1_RGBA_UNORM_BLOCK:
		case GL_INTERNAL_BC1_RGBA_SRGB_BLOCK:
		case GL_INTERNAL_BC2_UNORM_BLOCK:
		case GL_INTERNAL_BC2_SRGB_BLOCK:
		case GL_INTERNAL_BC3_UNORM_BLOCK:
		case GL_INTERNAL_BC3_SRGB_BLOCK:
		case GL_INTERNAL_BC5_UNORM_BLOCK:
		case GL_INTERNAL_BC5_SNORM_BLOCK:
		case GL_INTERNAL_ETC2_R8G8B8_UNORM_BLOCK:
		case GL_INTERNAL_ETC2_R8G8B8_SRGB_BLOCK:
		case GL_INTERNAL_ETC2_R8G8B8A1_UNORM_BLOCK:
		case GL_INTERNAL_ETC2_R8G8B8A1_SRGB_BLOCK:
		case GL_INTERNAL_ETC2_R8G8B8A8_UNORM_BLOCK:
		case GL_INTERNAL_ETC2_R8G8B8A8_SRGB_BLOCK:
		case GL_INTERNAL_EAC_R11_UNORM_BLOCK:
		case GL_INTERNAL_EAC_R11_SNORM_BLOCK:
		case GL_INTERNAL_EAC_R11G11_UNORM_BLOCK:
		case GL_INTERNAL_EAC_R11G11_SNORM_BLOCK:
		case GL_INTERNAL_ASTC_4x4_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_4x4_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_5x4_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_5x4_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_5x5_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_5x5_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_6x5_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_6x5_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_6x6_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_6x6_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_8x5_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_8x5_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_8x6_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_8x6_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_8x8_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_8x8_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_10x5_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_10x5_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_10x6_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_10x6_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_10x8_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_10x8_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_10x10_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_10x10_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_12x10_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_12x10_SRGB_BLOCK:
		case GL_INTERNAL_ASTC_12x12_UNORM_BLOCK:
		case GL_INTERNAL_ASTC_12x12_SRGB_BLOCK:
			return GL_TYPE_UI8;

		default:
			assert( false && "Unsupported pixel format." );
			return GL_TYPE_UI8888;
		}
	}

	renderer::Format convert( GlInternal format )noexcept
	{
		switch ( format )
		{
		case GL_INTERNAL_R4G4B4A4_UNORM_PACK16: return renderer::Format::eR4G4B4A4_UNORM_PACK16;
		case GL_INTERNAL_R5G6B5_UNORM_PACK16: return renderer::Format::eR5G6B5_UNORM_PACK16;
		case GL_INTERNAL_R5G5B5A1_UNORM_PACK16: return renderer::Format::eR5G5B5A1_UNORM_PACK16;
		case GL_INTERNAL_R8_UNORM: return renderer::Format::eR8_UNORM;
		case GL_INTERNAL_R8_SNORM: return renderer::Format::eR8_SNORM;
		case GL_INTERNAL_R8_UINT: return renderer::Format::eR8_UINT;
		case GL_INTERNAL_R8_SINT: return renderer::Format::eR8_SINT;
		case GL_INTERNAL_R8_SRGB: return renderer::Format::eR8_SRGB;
		case GL_INTERNAL_R8G8_UNORM: return renderer::Format::eR8G8_UNORM;
		case GL_INTERNAL_R8G8_SNORM: return renderer::Format::eR8G8_SNORM;
		case GL_INTERNAL_R8G8_UINT: return renderer::Format::eR8G8_UINT;
		case GL_INTERNAL_R8G8_SINT: return renderer::Format::eR8G8_SINT;
		case GL_INTERNAL_R8G8_SRGB: return renderer::Format::eR8G8_SRGB;
		case GL_INTERNAL_R8G8B8_UNORM: return renderer::Format::eR8G8B8_UNORM;
		case GL_INTERNAL_R8G8B8_SNORM: return renderer::Format::eR8G8B8_SNORM;
		case GL_INTERNAL_R8G8B8_UINT: return renderer::Format::eR8G8B8_UINT;
		case GL_INTERNAL_R8G8B8_SINT: return renderer::Format::eR8G8B8_SINT;
		case GL_INTERNAL_R8G8B8_SRGB: return renderer::Format::eR8G8B8_SRGB;
		case GL_INTERNAL_R8G8B8A8_UNORM: return renderer::Format::eR8G8B8A8_UNORM;
		case GL_INTERNAL_R8G8B8A8_SNORM: return renderer::Format::eR8G8B8A8_SNORM;
		case GL_INTERNAL_R8G8B8A8_UINT: return renderer::Format::eR8G8B8A8_UINT;
		case GL_INTERNAL_R8G8B8A8_SINT: return renderer::Format::eR8G8B8A8_SINT;
		case GL_INTERNAL_R8G8B8A8_SRGB: return renderer::Format::eR8G8B8A8_SRGB;
		case GL_INTERNAL_B8G8R8A8_UNORM: return renderer::Format::eB8G8R8A8_UNORM;
		case GL_INTERNAL_A2R10G10B10_UNORM_PACK32: return renderer::Format::eA2R10G10B10_UNORM_PACK32;
		case GL_INTERNAL_A2R10G10B10_UINT_PACK32: return renderer::Format::eA2R10G10B10_UINT_PACK32;
		case GL_INTERNAL_R16_UNORM: return renderer::Format::eR16_UNORM;
		case GL_INTERNAL_R16_SNORM: return renderer::Format::eR16_SNORM;
		case GL_INTERNAL_R16_UINT: return renderer::Format::eR16_UINT;
		case GL_INTERNAL_R16_SINT: return renderer::Format::eR16_SINT;
		case GL_INTERNAL_R16_SFLOAT: return renderer::Format::eR16_SFLOAT;
		case GL_INTERNAL_R16G16_UNORM: return renderer::Format::eR16G16_UNORM;
		case GL_INTERNAL_R16G16_SNORM: return renderer::Format::eR16G16_SNORM;
		case GL_INTERNAL_R16G16_UINT: return renderer::Format::eR16G16_UINT;
		case GL_INTERNAL_R16G16_SINT: return renderer::Format::eR16G16_SINT;
		case GL_INTERNAL_R16G16_SFLOAT: return renderer::Format::eR16G16_SFLOAT;
		case GL_INTERNAL_R16G16B16_UNORM: return renderer::Format::eR16G16B16_UNORM;
		case GL_INTERNAL_R16G16B16_SNORM: return renderer::Format::eR16G16B16_SNORM;
		case GL_INTERNAL_R16G16B16_UINT: return renderer::Format::eR16G16B16_UINT;
		case GL_INTERNAL_R16G16B16_SINT: return renderer::Format::eR16G16B16_SINT;
		case GL_INTERNAL_R16G16B16_SFLOAT: return renderer::Format::eR16G16B16_SFLOAT;
		case GL_INTERNAL_R16G16B16A16_UNORM: return renderer::Format::eR16G16B16A16_UNORM;
		case GL_INTERNAL_R16G16B16A16_SNORM: return renderer::Format::eR16G16B16A16_SNORM;
		case GL_INTERNAL_R16G16B16A16_UINT: return renderer::Format::eR16G16B16A16_UINT;
		case GL_INTERNAL_R16G16B16A16_SINT: return renderer::Format::eR16G16B16A16_SINT;
		case GL_INTERNAL_R16G16B16A16_SFLOAT: return renderer::Format::eR16G16B16A16_SFLOAT;
		case GL_INTERNAL_R32_UINT: return renderer::Format::eR32_UINT;
		case GL_INTERNAL_R32_SINT: return renderer::Format::eR32_SINT;
		case GL_INTERNAL_R32_SFLOAT: return renderer::Format::eR32_SFLOAT;
		case GL_INTERNAL_R32G32_UINT: return renderer::Format::eR32G32_UINT;
		case GL_INTERNAL_R32G32_SINT: return renderer::Format::eR32G32_SINT;
		case GL_INTERNAL_R32G32_SFLOAT: return renderer::Format::eR32G32_SFLOAT;
		case GL_INTERNAL_R32G32B32_UINT: return renderer::Format::eR32G32B32_UINT;
		case GL_INTERNAL_R32G32B32_SINT: return renderer::Format::eR32G32B32_SINT;
		case GL_INTERNAL_R32G32B32_SFLOAT: return renderer::Format::eR32G32B32_SFLOAT;
		case GL_INTERNAL_R32G32B32A32_UINT: return renderer::Format::eR32G32B32A32_UINT;
		case GL_INTERNAL_R32G32B32A32_SINT: return renderer::Format::eR32G32B32A32_SINT;
		case GL_INTERNAL_R32G32B32A32_SFLOAT: return renderer::Format::eR32G32B32A32_SFLOAT;
		case GL_INTERNAL_B10G11R11_UFLOAT_PACK32: return renderer::Format::eB10G11R11_UFLOAT_PACK32;
		case GL_INTERNAL_E5B9G9R9_UFLOAT_PACK32: return renderer::Format::eE5B9G9R9_UFLOAT_PACK32;
		case GL_INTERNAL_D16_UNORM: return renderer::Format::eD16_UNORM;
		case GL_INTERNAL_D32_SFLOAT: return renderer::Format::eD32_SFLOAT;
		case GL_INTERNAL_S8_UINT: return renderer::Format::eS8_UINT;
		case GL_INTERNAL_D24_UNORM_S8_UINT: return renderer::Format::eD24_UNORM_S8_UINT;
		case GL_INTERNAL_D32_SFLOAT_S8_UINT: return renderer::Format::eD32_SFLOAT_S8_UINT;
		case GL_INTERNAL_BC1_RGB_UNORM_BLOCK: return renderer::Format::eBC1_RGB_UNORM_BLOCK;
		case GL_INTERNAL_BC1_RGB_SRGB_BLOCK: return renderer::Format::eBC1_RGB_SRGB_BLOCK;
		case GL_INTERNAL_BC1_RGBA_UNORM_BLOCK: return renderer::Format::eBC1_RGBA_UNORM_BLOCK;
		case GL_INTERNAL_BC1_RGBA_SRGB_BLOCK: return renderer::Format::eBC1_RGBA_SRGB_BLOCK;
		case GL_INTERNAL_BC2_UNORM_BLOCK: return renderer::Format::eBC2_UNORM_BLOCK;
		case GL_INTERNAL_BC2_SRGB_BLOCK: return renderer::Format::eBC2_SRGB_BLOCK;
		case GL_INTERNAL_BC3_UNORM_BLOCK: return renderer::Format::eBC3_UNORM_BLOCK;
		case GL_INTERNAL_BC3_SRGB_BLOCK: return renderer::Format::eBC3_SRGB_BLOCK;
		case GL_INTERNAL_BC4_UNORM_BLOCK: return renderer::Format::eBC4_UNORM_BLOCK;
		case GL_INTERNAL_BC4_SNORM_BLOCK: return renderer::Format::eBC4_SNORM_BLOCK;
		case GL_INTERNAL_BC5_UNORM_BLOCK: return renderer::Format::eBC5_UNORM_BLOCK;
		case GL_INTERNAL_BC5_SNORM_BLOCK: return renderer::Format::eBC5_SNORM_BLOCK;
		case GL_INTERNAL_BC6H_UFLOAT_BLOCK: return renderer::Format::eBC6H_UFLOAT_BLOCK;
		case GL_INTERNAL_BC6H_SFLOAT_BLOCK: return renderer::Format::eBC6H_SFLOAT_BLOCK;
		case GL_INTERNAL_BC7_UNORM_BLOCK: return renderer::Format::eBC7_UNORM_BLOCK;
		case GL_INTERNAL_BC7_SRGB_BLOCK: return renderer::Format::eBC7_SRGB_BLOCK;
		case GL_INTERNAL_ETC2_R8G8B8_UNORM_BLOCK: return renderer::Format::eETC2_R8G8B8_UNORM_BLOCK;
		case GL_INTERNAL_ETC2_R8G8B8_SRGB_BLOCK: return renderer::Format::eETC2_R8G8B8_SRGB_BLOCK;
		case GL_INTERNAL_ETC2_R8G8B8A1_UNORM_BLOCK: return renderer::Format::eETC2_R8G8B8A1_UNORM_BLOCK;
		case GL_INTERNAL_ETC2_R8G8B8A1_SRGB_BLOCK: return renderer::Format::eETC2_R8G8B8A1_SRGB_BLOCK;
		case GL_INTERNAL_ETC2_R8G8B8A8_UNORM_BLOCK: return renderer::Format::eETC2_R8G8B8A8_UNORM_BLOCK;
		case GL_INTERNAL_ETC2_R8G8B8A8_SRGB_BLOCK: return renderer::Format::eETC2_R8G8B8A8_SRGB_BLOCK;
		case GL_INTERNAL_EAC_R11_UNORM_BLOCK: return renderer::Format::eEAC_R11_UNORM_BLOCK;
		case GL_INTERNAL_EAC_R11_SNORM_BLOCK: return renderer::Format::eEAC_R11_SNORM_BLOCK;
		case GL_INTERNAL_EAC_R11G11_UNORM_BLOCK: return renderer::Format::eEAC_R11G11_UNORM_BLOCK;
		case GL_INTERNAL_EAC_R11G11_SNORM_BLOCK: return renderer::Format::eEAC_R11G11_SNORM_BLOCK;
		case GL_INTERNAL_ASTC_4x4_UNORM_BLOCK: return renderer::Format::eASTC_4x4_UNORM_BLOCK;
		case GL_INTERNAL_ASTC_4x4_SRGB_BLOCK: return renderer::Format::eASTC_4x4_SRGB_BLOCK;
		case GL_INTERNAL_ASTC_5x4_UNORM_BLOCK: return renderer::Format::eASTC_5x4_UNORM_BLOCK;
		case GL_INTERNAL_ASTC_5x4_SRGB_BLOCK: return renderer::Format::eASTC_5x4_SRGB_BLOCK;
		case GL_INTERNAL_ASTC_5x5_UNORM_BLOCK: return renderer::Format::eASTC_5x5_UNORM_BLOCK;
		case GL_INTERNAL_ASTC_5x5_SRGB_BLOCK: return renderer::Format::eASTC_5x5_SRGB_BLOCK;
		case GL_INTERNAL_ASTC_6x5_UNORM_BLOCK: return renderer::Format::eASTC_6x5_UNORM_BLOCK;
		case GL_INTERNAL_ASTC_6x5_SRGB_BLOCK: return renderer::Format::eASTC_6x5_SRGB_BLOCK;
		case GL_INTERNAL_ASTC_6x6_UNORM_BLOCK: return renderer::Format::eASTC_6x6_UNORM_BLOCK;
		case GL_INTERNAL_ASTC_6x6_SRGB_BLOCK: return renderer::Format::eASTC_6x6_SRGB_BLOCK;
		case GL_INTERNAL_ASTC_8x5_UNORM_BLOCK: return renderer::Format::eASTC_8x5_UNORM_BLOCK;
		case GL_INTERNAL_ASTC_8x5_SRGB_BLOCK: return renderer::Format::eASTC_8x5_SRGB_BLOCK;
		case GL_INTERNAL_ASTC_8x6_UNORM_BLOCK: return renderer::Format::eASTC_8x6_UNORM_BLOCK;
		case GL_INTERNAL_ASTC_8x6_SRGB_BLOCK: return renderer::Format::eASTC_8x6_SRGB_BLOCK;
		case GL_INTERNAL_ASTC_8x8_UNORM_BLOCK: return renderer::Format::eASTC_8x8_UNORM_BLOCK;
		case GL_INTERNAL_ASTC_8x8_SRGB_BLOCK: return renderer::Format::eASTC_8x8_SRGB_BLOCK;
		case GL_INTERNAL_ASTC_10x5_UNORM_BLOCK: return renderer::Format::eASTC_10x5_UNORM_BLOCK;
		case GL_INTERNAL_ASTC_10x5_SRGB_BLOCK: return renderer::Format::eASTC_10x5_SRGB_BLOCK;
		case GL_INTERNAL_ASTC_10x6_UNORM_BLOCK: return renderer::Format::eASTC_10x6_UNORM_BLOCK;
		case GL_INTERNAL_ASTC_10x6_SRGB_BLOCK: return renderer::Format::eASTC_10x6_SRGB_BLOCK;
		case GL_INTERNAL_ASTC_10x8_UNORM_BLOCK: return renderer::Format::eASTC_10x8_UNORM_BLOCK;
		case GL_INTERNAL_ASTC_10x8_SRGB_BLOCK: return renderer::Format::eASTC_10x8_SRGB_BLOCK;
		case GL_INTERNAL_ASTC_10x10_UNORM_BLOCK: return renderer::Format::eASTC_10x10_UNORM_BLOCK;
		case GL_INTERNAL_ASTC_10x10_SRGB_BLOCK: return renderer::Format::eASTC_10x10_SRGB_BLOCK;
		case GL_INTERNAL_ASTC_12x10_UNORM_BLOCK: return renderer::Format::eASTC_12x10_UNORM_BLOCK;
		case GL_INTERNAL_ASTC_12x10_SRGB_BLOCK: return renderer::Format::eASTC_12x10_SRGB_BLOCK;
		case GL_INTERNAL_ASTC_12x12_UNORM_BLOCK: return renderer::Format::eASTC_12x12_UNORM_BLOCK;
		case GL_INTERNAL_ASTC_12x12_SRGB_BLOCK: return renderer::Format::eASTC_12x12_SRGB_BLOCK;

		default:
			assert( false && "Unsupported pixel format." );
			return renderer::Format::eR8G8B8A8_UNORM;
		}
	}

	uint32_t getCount( renderer::Format format )noexcept
	{
		switch ( format )
		{
		case renderer::Format::eR8_UNORM:
		case renderer::Format::eR8_SNORM:
		case renderer::Format::eR8_UINT:
		case renderer::Format::eR8_SINT:
		case renderer::Format::eR8_SRGB:
		case renderer::Format::eR16_UNORM:
		case renderer::Format::eR16_SNORM:
		case renderer::Format::eR16_UINT:
		case renderer::Format::eR16_SINT:
		case renderer::Format::eR16_SFLOAT:
		case renderer::Format::eR32_UINT:
		case renderer::Format::eR32_SINT:
		case renderer::Format::eR32_SFLOAT:
		case renderer::Format::eEAC_R11_UNORM_BLOCK:
		case renderer::Format::eEAC_R11_SNORM_BLOCK:
			return 1u;

		case renderer::Format::eR8G8_UNORM:
		case renderer::Format::eR8G8_SNORM:
		case renderer::Format::eR8G8_UINT:
		case renderer::Format::eR8G8_SINT:
		case renderer::Format::eR8G8_SRGB:
		case renderer::Format::eR16G16_UNORM:
		case renderer::Format::eR16G16_SNORM:
		case renderer::Format::eR16G16_UINT:
		case renderer::Format::eR16G16_SINT:
		case renderer::Format::eR16G16_SFLOAT:
		case renderer::Format::eR32G32_UINT:
		case renderer::Format::eR32G32_SINT:
		case renderer::Format::eR32G32_SFLOAT:
		case renderer::Format::eBC5_UNORM_BLOCK:
		case renderer::Format::eBC5_SNORM_BLOCK:
		case renderer::Format::eEAC_R11G11_UNORM_BLOCK:
		case renderer::Format::eEAC_R11G11_SNORM_BLOCK:
			return 2u;

		case renderer::Format::eR8G8B8_UNORM:
		case renderer::Format::eR8G8B8_SNORM:
		case renderer::Format::eR8G8B8_UINT:
		case renderer::Format::eR8G8B8_SINT:
		case renderer::Format::eR8G8B8_SRGB:
		case renderer::Format::eR16G16B16_UNORM:
		case renderer::Format::eR16G16B16_SNORM:
		case renderer::Format::eR16G16B16_UINT:
		case renderer::Format::eR16G16B16_SINT:
		case renderer::Format::eR16G16B16_SFLOAT:
		case renderer::Format::eR32G32B32_UINT:
		case renderer::Format::eR32G32B32_SINT:
		case renderer::Format::eR32G32B32_SFLOAT:
		case renderer::Format::eBC1_RGB_UNORM_BLOCK:
		case renderer::Format::eBC1_RGB_SRGB_BLOCK:
		case renderer::Format::eETC2_R8G8B8_UNORM_BLOCK:
		case renderer::Format::eETC2_R8G8B8_SRGB_BLOCK:
			return 3u;

		case renderer::Format::eR8G8B8A8_UNORM:
		case renderer::Format::eR8G8B8A8_SNORM:
		case renderer::Format::eR8G8B8A8_UINT:
		case renderer::Format::eR8G8B8A8_SINT:
		case renderer::Format::eR8G8B8A8_SRGB:
		case renderer::Format::eB8G8R8A8_UNORM:
		case renderer::Format::eR16G16B16A16_UNORM:
		case renderer::Format::eR16G16B16A16_SNORM:
		case renderer::Format::eR16G16B16A16_UINT:
		case renderer::Format::eR16G16B16A16_SINT:
		case renderer::Format::eR16G16B16A16_SFLOAT:
		case renderer::Format::eR32G32B32A32_UINT:
		case renderer::Format::eR32G32B32A32_SINT:
		case renderer::Format::eR32G32B32A32_SFLOAT:
		case renderer::Format::eBC1_RGBA_UNORM_BLOCK:
		case renderer::Format::eBC1_RGBA_SRGB_BLOCK:
		case renderer::Format::eBC2_UNORM_BLOCK:
		case renderer::Format::eBC2_SRGB_BLOCK:
		case renderer::Format::eBC3_UNORM_BLOCK:
		case renderer::Format::eBC3_SRGB_BLOCK:
		case renderer::Format::eETC2_R8G8B8A1_UNORM_BLOCK:
		case renderer::Format::eETC2_R8G8B8A1_SRGB_BLOCK:
		case renderer::Format::eETC2_R8G8B8A8_UNORM_BLOCK:
		case renderer::Format::eETC2_R8G8B8A8_SRGB_BLOCK:
		case renderer::Format::eASTC_4x4_UNORM_BLOCK:
		case renderer::Format::eASTC_4x4_SRGB_BLOCK:
		case renderer::Format::eASTC_5x4_UNORM_BLOCK:
		case renderer::Format::eASTC_5x4_SRGB_BLOCK:
		case renderer::Format::eASTC_5x5_UNORM_BLOCK:
		case renderer::Format::eASTC_5x5_SRGB_BLOCK:
		case renderer::Format::eASTC_6x5_UNORM_BLOCK:
		case renderer::Format::eASTC_6x5_SRGB_BLOCK:
		case renderer::Format::eASTC_6x6_UNORM_BLOCK:
		case renderer::Format::eASTC_6x6_SRGB_BLOCK:
		case renderer::Format::eASTC_8x5_UNORM_BLOCK:
		case renderer::Format::eASTC_8x5_SRGB_BLOCK:
		case renderer::Format::eASTC_8x6_UNORM_BLOCK:
		case renderer::Format::eASTC_8x6_SRGB_BLOCK:
		case renderer::Format::eASTC_8x8_UNORM_BLOCK:
		case renderer::Format::eASTC_8x8_SRGB_BLOCK:
		case renderer::Format::eASTC_10x5_UNORM_BLOCK:
		case renderer::Format::eASTC_10x5_SRGB_BLOCK:
		case renderer::Format::eASTC_10x6_UNORM_BLOCK:
		case renderer::Format::eASTC_10x6_SRGB_BLOCK:
		case renderer::Format::eASTC_10x8_UNORM_BLOCK:
		case renderer::Format::eASTC_10x8_SRGB_BLOCK:
		case renderer::Format::eASTC_10x10_UNORM_BLOCK:
		case renderer::Format::eASTC_10x10_SRGB_BLOCK:
		case renderer::Format::eASTC_12x10_UNORM_BLOCK:
		case renderer::Format::eASTC_12x10_SRGB_BLOCK:
		case renderer::Format::eASTC_12x12_UNORM_BLOCK:
		case renderer::Format::eASTC_12x12_SRGB_BLOCK:
			return 4u;

		case renderer::Format::eD16_UNORM:
		case renderer::Format::eX8_D24_UNORM_PACK32:
		case renderer::Format::eD32_SFLOAT:
			return 1u;

		case renderer::Format::eD24_UNORM_S8_UINT:
		case renderer::Format::eD32_SFLOAT_S8_UINT:
			return 2u;

		case renderer::Format::eS8_UINT:
			return 1u;

		default:
			assert( false && "Unsupported pixel format." );
			return 4u;
		}
	}
}
