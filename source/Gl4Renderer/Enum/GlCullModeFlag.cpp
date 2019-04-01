#include "GlRendererPrerequisites.hpp"

namespace gl_renderer
{
	std::string getName( GlCullMode value )
	{
		switch ( value )
		{
		case gl_renderer::GL_CULL_MODE_NONE:
			return "GL_NONE";

		case gl_renderer::GL_CULL_MODE_FRONT:
			return "GL_FRONT";

		case gl_renderer::GL_CULL_MODE_BACK:
			return "GL_BACK";

		case gl_renderer::GL_CULL_MODE_FRONT_AND_BACK:
			return "GL_FRONT_AND_BACK";

		default:
			assert( false && "Unsupported GlCullMode" );
			return "GlCullMode_UNKNOWN";
		}
	}

	GlCullMode convert( ashes::CullModeFlags const & flags )
	{
		GlCullMode result{ GL_CULL_MODE_NONE };

		if ( checkFlag( flags, VkCullModeFlagBits::eFrontAndBack ) )
		{
			result = GL_CULL_MODE_FRONT_AND_BACK;
		}
		else if ( checkFlag( flags, VkCullModeFlagBits::eFront ) )
		{
			result = GL_CULL_MODE_FRONT;
		}
		else if ( checkFlag( flags, VkCullModeFlagBits::eBack ) )
		{
			result = GL_CULL_MODE_BACK;
		}

		return result;
	}
}
