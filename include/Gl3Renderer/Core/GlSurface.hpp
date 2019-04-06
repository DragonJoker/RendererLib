/*
This file belongs to Ashes.
See LICENSE file in root folder
*/
#pragma once

#include "Core/GlContext.hpp"

#include <Ashes/Core/Surface.hpp>

namespace gl_renderer
{
	class Surface
		: public ashes::Surface
	{
	public:
		Surface( Instance const & instance
			, PhysicalDevice const & gpu
			, ashes::WindowHandle handle );

		bool getSupport( uint32_t queueFamilyIndex )const override;

		ashes::SurfaceCapabilities getCapabilities()const override
		{
			return m_surfaceCapabilities;
		}

		std::vector < VkPresentModeKHR > getPresentModes()const override
		{
			return m_presentModes;
		}

		std::vector< VkSurfaceFormatKHR > getFormats()const override
		{
			return m_surfaceFormats;
		}

		inline ContextLock getContext()const
		{
			return { *m_context };
		}

	private:
		std::vector< VkSurfaceFormatKHR > m_surfaceFormats;
		ashes::SurfaceCapabilities m_surfaceCapabilities;
		std::vector< VkPresentModeKHR > m_presentModes;
		ContextPtr m_context;
	};
}
