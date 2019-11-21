#include "GlRendererPrerequisites.hpp"

#include "ashesgl3_api.hpp"

namespace ashes::gl3
{
	uint32_t deduceMemoryType( uint32_t typeBits
		, VkMemoryPropertyFlags requirements )
	{
		return ashes::deduceMemoryType( typeBits
			, requirements
			, Instance::getMemoryProperties() );
	}
}

namespace ashes::gl
{
	char const * const getDisplayName( VkDisplayModeKHR displayMode )
	{
		return gl3::get( gl3::get( displayMode )->getDisplay() )->getName();
	}

	uint32_t getRefreshRate( VkDisplayModeKHR displayMode )
	{
		return gl3::get( displayMode )->getRefreshRate();
	}
}