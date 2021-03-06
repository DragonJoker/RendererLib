#include "GlRendererPrerequisites.hpp"

namespace ashes::gl
{
	std::string getName( GlTweak value )
	{
		switch ( value )
		{
		case GL_CULL_FACE:
			return "GL_CULL_FACE";

		case GL_DEPTH_RANGE:
			return "GL_DEPTH_RANGE";

		case GL_DEPTH_TEST:
			return "GL_DEPTH_TEST";

		case GL_DEPTH_WRITEMASK:
			return "GL_DEPTH_WRITEMASK";

		case GL_DEPTH_FUNC:
			return "GL_DEPTH_FUNC";

		case GL_STENCIL_TEST:
			return "GL_STENCIL_TEST";

		case GL_STENCIL_FRONT_FUNC:
			return "GL_STENCIL_FRONT_FUNC";

		case GL_STENCIL_FRONT_VALUE_MASK:
			return "GL_STENCIL_FRONT_VALUE_MASK";

		case GL_STENCIL_FRONT_FAIL:
			return "GL_STENCIL_FRONT_FAIL";

		case GL_STENCIL_FRONT_PASS_DEPTH_FAIL:
			return "GL_STENCIL_FRONT_PASS_DEPTH_FAIL";

		case GL_STENCIL_FRONT_PASS_DEPTH_PASS:
			return "GL_STENCIL_FRONT_PASS_DEPTH_PASS";

		case GL_STENCIL_FRONT_REF:
			return "GL_STENCIL_FRONT_REF";

		case GL_STENCIL_FRONT_WRITEMASK:
			return "GL_STENCIL_FRONT_WRITEMASK";

		case GL_BLEND:
			return "GL_BLEND";
			
		case GL_SCISSOR_TEST:
			return "GL_SCISSOR_TEST";

		case GL_POLYGON_OFFSET_POINT:
			return "GL_POLYGON_OFFSET_POINT";

		case GL_POLYGON_OFFSET_LINE:
			return "GL_POLYGON_OFFSET_LINE";

		case GL_MULTISAMPLE:
			return "GL_MULTISAMPLE";

		case GL_SAMPLE_ALPHA_TO_COVERAGE:
			return "GL_SAMPLE_ALPHA_TO_COVERAGE";

		case GL_SAMPLE_ALPHA_TO_ONE:
			return "GL_SAMPLE_ALPHA_TO_ONE";

		case GL_POLYGON_OFFSET_FILL:
			return "GL_POLYGON_OFFSET_FILL";

		case GL_PROGRAM_POINT_SIZE:
			return "GL_PROGRAM_POINT_SIZE";

		case GL_DEPTH_CLAMP:
			return "GL_DEPTH_CLAMP";

		case GL_STENCIL_BACK_FUNC:
			return "GL_STENCIL_BACK_FUNC";

		case GL_STENCIL_BACK_FAIL:
			return "GL_STENCIL_BACK_FAIL";

		case GL_STENCIL_BACK_PASS_DEPTH_FAIL:
			return "GL_STENCIL_BACK_PASS_DEPTH_FAIL";

		case GL_STENCIL_BACK_PASS_DEPTH_PASS:
			return "GL_STENCIL_BACK_PASS_DEPTH_PASS";
			
		case GL_TEXTURE_CUBE_MAP_SEAMLESS:
			return "GL_TEXTURE_CUBE_MAP_SEAMLESS";

		case GL_RASTERIZER_DISCARD:
			return "GL_RASTERIZER_DISCARD";

		case GL_STENCIL_BACK_REF:
			return "GL_STENCIL_BACK_REF";

		case GL_STENCIL_BACK_VALUE_MASK:
			return "GL_STENCIL_BACK_VALUE_MASK";

		case GL_STENCIL_BACK_WRITEMASK:
			return "GL_STENCIL_BACK_WRITEMASK";

		case GL_PRIMITIVE_RESTART:
			return "GL_PRIMITIVE_RESTART";

		case GL_SAMPLE_SHADING:
			return "GL_SAMPLE_SHADING";

		case GL_FRAMEBUFFER_SRGB:
			return "GL_FRAMEBUFFER_SRGB";

		case GL_DEBUG_OUTPUT_SYNC:
			return "GL_DEBUG_OUTPUT_SYNCHRONOUS";

		default:
			assert( false && "Unsupported GlTweak" );
			return "GlTweak_UNKNOWN";
		}
	}
}
