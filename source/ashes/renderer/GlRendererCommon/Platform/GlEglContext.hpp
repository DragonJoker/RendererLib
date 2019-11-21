/*
This file belongs to Ashes.
See LICENSE file in root folder
*/
#pragma once

#ifndef _WIN32
#include "renderer/GlRendererCommon/GlContext.hpp"

#include <EGL/egl.h>
#include <memory>

namespace ashes::gl
{
	class EglContext
		: public ContextImpl
	{
	public:
		EglContext( VkInstance instance
			, VkDisplaySurfaceCreateInfoKHR createInfo
			, ContextImpl const * mainContext );
		~EglContext();

		void preInitialise( int major, int minor )override;
		void postInitialise()override;
		void enable()const override;
		void disable()const override;
		void swapBuffers()const override;

		inline EGLContext getContext()const
		{
			return m_context;
		}

	private:
		void doCleanup();

	private:
		VkDisplaySurfaceCreateInfoKHR createInfo;
		EGLDisplay m_display{ nullptr };
		EGLContext m_context{ nullptr };
		EGLSurface m_surface{ nullptr };
	};
}

#endif
