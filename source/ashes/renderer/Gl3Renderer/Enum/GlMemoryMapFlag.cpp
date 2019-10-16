#include "GlRendererPrerequisites.hpp"

namespace gl_renderer
{
	std::string getName( GlMemoryMapFlags value )
	{
		std::string result;
		std::string sep;

		if ( checkFlag( value, gl_renderer::GlMemoryMapFlag::GL_MEMORY_MAP_READ_BIT ) )
		{
			result += sep + "GL_MAP_READ_BIT";
			sep = " | ";
		}

		if ( checkFlag( value, gl_renderer::GlMemoryMapFlag::GL_MEMORY_MAP_WRITE_BIT ) )
		{
			result += sep + "GL_MAP_WRITE_BIT";
			sep = " | ";
		}

		if ( checkFlag( value, gl_renderer::GlMemoryMapFlag::GL_MEMORY_MAP_PERSISTENT_BIT ) )
		{
			result += sep + "GL_MAP_PERSISTENT_BIT";
			sep = " | ";
		}

		if ( checkFlag( value, gl_renderer::GlMemoryMapFlag::GL_MEMORY_MAP_COHERENT_BIT ) )
		{
			result += sep + "GL_MAP_COHERENT_BIT";
			sep = " | ";
		}

		if ( checkFlag( value, gl_renderer::GlMemoryMapFlag::GL_MEMORY_MAP_INVALIDATE_RANGE_BIT ) )
		{
			result += sep + "GL_MAP_INVALIDATE_RANGE_BIT";
			sep = " | ";
		}

		if ( checkFlag( value, gl_renderer::GlMemoryMapFlag::GL_MEMORY_MAP_INVALIDATE_BUFFER_BIT ) )
		{
			result += sep + "GL_MAP_INVALIDATE_BUFFER_BIT";
			sep = " | ";
		}

		if ( checkFlag( value, gl_renderer::GlMemoryMapFlag::GL_MEMORY_MAP_FLUSH_EXPLICIT_BIT ) )
		{
			result += sep + "GL_MAP_FLUSH_EXPLICIT_BIT";
			sep = " | ";
		}

		if ( checkFlag( value, gl_renderer::GlMemoryMapFlag::GL_MEMORY_MAP_UNSYNCHRONIZED_BIT ) )
		{
			result += sep + "GL_MAP_UNSYNCHRONIZED_BIT";
		}

		return result;
	}

	GlMemoryMapFlags getMapFlags( VkMemoryPropertyFlags const & flags )
	{
		GlMemoryMapFlags result{ 0 };

		if ( checkFlag( flags, VkMemoryPropertyFlagBits::VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT ) )
		{
			result |= GL_MEMORY_MAP_READ_BIT;
			result |= GL_MEMORY_MAP_WRITE_BIT;
		}

		if ( !checkFlag( flags, VkMemoryPropertyFlagBits::VK_MEMORY_PROPERTY_HOST_COHERENT_BIT ) )
		{
			result |= GL_MEMORY_MAP_INVALIDATE_RANGE_BIT;
			result |= GL_MEMORY_MAP_UNSYNCHRONIZED_BIT;
			result |= GL_MEMORY_MAP_FLUSH_EXPLICIT_BIT;
		}

		return result;
	}
}