/*
This file belongs to Ashes.
See LICENSE file in root folder
*/
#include "Platform/GlEglContext.hpp"

#ifndef _WIN32

#include <stdexcept>

namespace ashes::gl
{
	EglContext::EglContext( VkInstance instance
		, VkDisplaySurfaceCreateInfoKHR createInfo
		, ContextImpl const * mainContext )
		: ContextImpl{ instance }
		, createInfo{ createInfo }
	{
	}

	EglContext::~EglContext()
	{
		doCleanup();
	}

	void EglContext::preInitialise( int major, int minor )
	{
		try
		{
			EGLBoolean ok = eglBindAPI( EGL_OPENGL_API );

			if ( !ok )
			{
				throw std::runtime_error{ "Couldn't bind EGL API" };
			}

			m_display = eglGetDisplay( EGL_DEFAULT_DISPLAY );

			if ( m_display == EGL_NO_DISPLAY )
			{
				throw std::runtime_error{ "Couldn't get EGL display" };
			}

			EGLint major, minor;
			ok = eglInitialize( m_display, &major, &minor );

			if ( !ok )
			{
				throw std::runtime_error{ "Couldn't initialise EGL" };
			}

			const EGLint eglConfigAttribs[]
			{
				EGL_COLOR_BUFFER_TYPE, EGL_RGB_BUFFER,
				EGL_BUFFER_SIZE, 32,
				EGL_RED_SIZE, 8,
				EGL_GREEN_SIZE, 8,
				EGL_BLUE_SIZE, 8,
				EGL_ALPHA_SIZE, 8,

				EGL_DEPTH_SIZE, 24,
				EGL_STENCIL_SIZE, 8,

				EGL_SAMPLE_BUFFERS, 0,
				EGL_SAMPLES, 0,

				EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
				EGL_RENDERABLE_TYPE, EGL_OPENGL_BIT,

				EGL_NONE,
			};

			EGLint constexpr configsSize = 256;
			EGLConfig configs[configsSize]{};
			EGLint numConfigs{};
			ok = eglChooseConfig( m_display
				, eglConfigAttribs
				, configs
				, configsSize // num requested configs
				, &numConfigs ); // num returned configs

			if ( !ok )
			{
				throw std::runtime_error{ "Couldn't choose EGL config" };
			}

			if ( numConfigs == 0 )
			{
				throw std::runtime_error{ "Failed to find suitable EGLConfig" };
			}

			EGLConfig config{ nullptr };
			EGLint i = 0;
			const EGLint pbufferAttribs[]
			{
				EGL_WIDTH, EGLint( imageExtent.width ),
				EGL_HEIGHT, EGLint( imageExtent.height ),
				EGL_NONE,
			};

			while ( i < numConfigs && !m_surface )
			{
				config = configs[i];
				m_surface = eglCreatePbufferSurface( m_display
					, config
					, pbufferAttribs );
				++i;
			}

			if ( !m_surface )
			{
				throw std::runtime_error{ "EGL Surface creation failed" };
			}

			const EGLint eglContextAttribs[]
			{
				EGL_CONTEXT_MAJOR_VERSION, reqMajor,
				EGL_CONTEXT_MINOR_VERSION, reqMinor,
				EGL_NONE,
			};
			m_context = eglCreateContext( m_display
				, config
				, shared
				, eglContextAttribs );

			if ( !m_context )
			{
				throw std::runtime_error{ "EGL Context creation failed" };
			}

			ok = eglMakeCurrent( m_display, m_surface, m_surface, m_context );

			if ( !ok )
			{
				throw std::runtime_error{ "eglMakeCurrent() failed" };
			}

			eglSwapInterval( m_display, 0 );
			eglMakeCurrent( m_display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT );
		}
		catch ( std::exception & p_exc )
		{
			doCleanup();
			throw;
		}
	}

	void EglContext::postInitialise()
	{
	}

	void EglContext::enable()const
	{
		eglMakeCurrent( m_display, m_surface, m_surface, m_context );
	}

	void EglContext::disable()const
	{
		eglMakeCurrent( m_display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT );
	}

	void EglContext::swapBuffers()const
	{
		eglSwapBuffers( m_display, m_surface );
	}

	void EglContext::doCleanup()
	{
		if ( m_context )
		{
			eglDestroyContext( m_display, m_context );
			m_context = nullptr;
		}

		if ( m_surface )
		{
			eglDestroySurface( m_display, m_surface );
			m_surface = nullptr;
		}

		if ( m_display )
		{
			eglTerminate( m_display );
			m_display = nullptr;
		}
	}
}

#endif
