#include "GlRendererPrerequisites.hpp"

namespace ashes::gl3
{
	std::string getName( GlPrimitiveTopology value )
	{
		switch ( value )
		{
		case GL_PRIMITIVE_TOPOLOGY_POINT_LIST:
			return "GL_POINTS";

		case GL_PRIMITIVE_TOPOLOGY_LINE_LIST:
			return "GL_LINES";

		case GL_PRIMITIVE_TOPOLOGY_LINE_LOOP:
			return "GL_LINE_LOOP";

		case GL_PRIMITIVE_TOPOLOGY_LINE_STRIP:
			return "GL_LINE_STRIP";

		case GL_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST:
			return "GL_TRIANGLES";

		case GL_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP:
			return "GL_TRIANGLE_STRIP";

		case GL_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN:
			return "GL_TRIANGLE_FAN";

		case GL_PRIMITIVE_TOPOLOGY_LINE_LIST_ADJACENCY:
			return "GL_LINES_ADJACENCY";

		case GL_PRIMITIVE_TOPOLOGY_LINE_STRIP_ADJACENCY:
			return "GL_LINE_STRIP_ADJACENCY";

		case GL_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_ADJACENCY:
			return "GL_TRIANGLES_ADJACENCY";

		case GL_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_ADJACENCY:
			return " GL_TRIANGLE_STRIP_ADJACENCY";

		case GL_PRIMITIVE_TOPOLOGY_PATCH_LIST:
			return "GL_PATCHES";

		default:
			assert( false && "Unsupported GlPrimitiveTopology" );
			return "GlPrimitiveTopology_UNKNOWN";
		}
	}

	GlPrimitiveTopology convert( VkPrimitiveTopology const & topology )
	{
		switch ( topology )
		{
		case VK_PRIMITIVE_TOPOLOGY_POINT_LIST:
			return GL_PRIMITIVE_TOPOLOGY_POINT_LIST;

		case VK_PRIMITIVE_TOPOLOGY_LINE_LIST:
			return GL_PRIMITIVE_TOPOLOGY_LINE_LIST;

		case VK_PRIMITIVE_TOPOLOGY_LINE_STRIP:
			return GL_PRIMITIVE_TOPOLOGY_LINE_STRIP;

		case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST:
			return GL_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;

		case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP:
			return GL_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP;

		case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN:
			return GL_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN;

		case VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY:
			return GL_PRIMITIVE_TOPOLOGY_LINE_LIST_ADJACENCY;

		case VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY:
			return GL_PRIMITIVE_TOPOLOGY_LINE_STRIP_ADJACENCY;

		case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY:
			return GL_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_ADJACENCY;

		case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY:
			return GL_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_ADJACENCY;

		case VK_PRIMITIVE_TOPOLOGY_PATCH_LIST:
			return GL_PRIMITIVE_TOPOLOGY_PATCH_LIST;

		default:
			assert( false );
			return GL_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
		}
	}
}
