#include "Core/GlRenderer.hpp"

#include "Core/GlConnection.hpp"
#include "Core/GlContext.hpp"
#include "Core/GlDevice.hpp"

#include <Miscellaneous/PhysicalDeviceInfo.hpp>

#include <iostream>

namespace gl_renderer
{
	Renderer::Renderer( Configuration const & configuration )
		: renderer::Renderer{ renderer::ClipDirection::eBottomUp, "gl", configuration }
	{
		m_gpuInfos.push_back( renderer::PhysicalDeviceInfo{} );
	}

	renderer::DevicePtr Renderer::createDevice( renderer::ConnectionPtr && connection )const
	{
		renderer::DevicePtr result;

		try
		{
			result = std::make_unique< Device >( *this, std::move( connection ) );
		}
		catch ( std::exception & exc )
		{
			std::cerr << "Could not initialise logical device:\n" << exc.what() << std::endl;
		}

		return result;
	}

	renderer::ConnectionPtr Renderer::createConnection( uint32_t deviceIndex
		, renderer::WindowHandle && handle )const
	{
		return std::make_unique< Connection >( *this
			, deviceIndex
			, std::move( handle ) );
	}
}
