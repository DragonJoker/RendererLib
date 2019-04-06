#include "RenderPanel.hpp"

#include "Application.hpp"
#include "MainFrame.hpp"

#include <AshesPP/Core/Surface.hpp>
#include <AshesPP/Core/Device.hpp>
#include <AshesRenderer/Util/Exception.hpp>

#include <Utils/Transform.hpp>

#include <chrono>

namespace vkapp
{
	RenderPanel::RenderPanel( wxWindow * parent
		, wxSize const & size
		, utils::Instance const & instance )
		: wxPanel{ parent, wxID_ANY, wxDefaultPosition, size }
	{
		try
		{
			doCreateSurface( instance );
			std::cout << "Surface created." << std::endl;
			doCreateDevice( instance );
			std::cout << "Logical device created." << std::endl;
		}
		catch ( std::exception & )
		{
			doCleanup();
			throw;
		}
	}

	RenderPanel::~RenderPanel()
	{
		doCleanup();
	}

	void RenderPanel::doCleanup()
	{
		if ( m_device )
		{
			m_device->waitIdle();
			m_device.reset();
		}
	}

	void RenderPanel::doCreateSurface( utils::Instance const & instance )
	{
		auto handle = common::makeWindowHandle( *this );
		auto & gpu = instance.getPhysicalDevice( 0u );
		m_surface = instance.getInstance().createSurface( gpu
			, std::move( handle ) );
	}

	void RenderPanel::doCreateDevice( utils::Instance const & instance )
	{
		auto & gpu = m_surface->getGpu();
		ashes::DeviceQueueCreateInfoArray queueCreateInfos;
		queueCreateInfos.emplace_back( 0u, 0u, ashes::FloatArray{ 1.0f } );
		ashes::DeviceCreateInfo createInfo
		{
			0u,
			std::move( queueCreateInfos ),
			instance.getLayerNames(),
			{},//instance.getExtensionNames(),
			gpu.getFeatures(),
		};
		m_device = instance.getInstance().createDevice( gpu
			, std::move( createInfo ) );

		if ( m_device )
		{
			std::cout << m_device->getPhysicalDevice().dumpProperties() << std::endl;
		}
	}
}
