#include "Core/GlContext.hpp"

#if RENDERLIB_WIN32
#	include "GlMswContext.hpp"
#elif RENDERLIB_XLIB
#	include "GlX11Context.hpp"
#endif

#include <gl/GL.h>

namespace gl_renderer
{
	Context::Context( PhysicalDevice const & gpu
		, renderer::ConnectionPtr && connection )
		: m_gpu{ gpu }
		, m_connection{ std::move( connection ) }
	{
	}

	ContextPtr Context::create( PhysicalDevice const & gpu
		, renderer::ConnectionPtr && connection )
	{
		ContextPtr result;

		try
		{
#if defined( _WIN32 )
			result = std::make_unique< MswContext >( gpu, std::move( connection ) );
#elif defined( __linux__ )
			result = std::make_unique< X11Context >( gpu, std::move( connection ) );
#endif
		}
		catch ( std::exception & error )
		{
			renderer::Logger::logError( error.what() );
		}

		return result;
	}
}
