#include "GlContext.hpp"

#if _WIN32
#	include "Platform/GlMswContext.hpp"
#elif __linux__
#	include "Platform/GlWaylandContext.hpp"
#	include "Platform/GlXcbContext.hpp"
#	if ASHES_USE_XLIB_EGL
#		include "Platform/GlX11EglContext.hpp"
#	else
#		include "Platform/GlX11Context.hpp"
#	endif
#endif

namespace ashes::gl
{
#if __linux__

	ContextImplPtr ContextImpl::create( VkInstance instance
		, VkXcbSurfaceCreateInfoKHR createInfo
		, ContextImpl const * mainContext )
	{
		return std::make_unique< XcbContext >( instance
			, std::move( createInfo )
			, mainContext );
	}

	ContextImplPtr ContextImpl::create( VkInstance instance
		, VkXlibSurfaceCreateInfoKHR createInfo
		, ContextImpl const * mainContext )
	{
#	if ASHES_USE_XLIB_EGL
		return std::make_unique< X11EglContext >( instance
			, std::move( createInfo )
			, mainContext );
#	else
		return std::make_unique< X11Context >( instance
			, std::move( createInfo )
			, mainContext );
#	endif
	}

	ContextImplPtr ContextImpl::create( VkInstance instance
		, VkWaylandSurfaceCreateInfoKHR createInfo
		, ContextImpl const * mainContext )
	{
		return std::make_unique< WaylandContext >( instance
			, std::move( createInfo )
			, mainContext );
	}

#elif _WIN32

	ContextImplPtr ContextImpl::create( VkInstance instance
		, VkWin32SurfaceCreateInfoKHR createInfo
		, ContextImpl const * mainContext )
	{
		return std::make_unique< MswContext >( instance
			, std::move( createInfo )
			, mainContext );
	}

#endif
}
