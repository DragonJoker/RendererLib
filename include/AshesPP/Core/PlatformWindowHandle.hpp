/*
This file belongs to Ashes.
See LICENSE file in root folder.
*/
#ifndef ___AshesPP_PlatformWindowHandle_HPP___
#define ___AshesPP_PlatformWindowHandle_HPP___

#include "AshesPP/Core/WindowHandle.hpp"

//*************************************************************************************************
//
// INCLUDE THIS FILE ONLY WHERE YOU NEED IT (for instance not in precompiled header file)
//
//*************************************************************************************************

#if ASHES_WIN32
#	include <windows.h>
#elif ASHES_XLIB
#	include <GL/glx.h>
#elif ASHES_ANDROID
#	include <native_window.h>
#elif ASHES_XCB
#	include <xcbint.h>
#	include <xcb/xproto.h>
#elif ASHES_MIR
#	include <mir_toolkit/mir_connection.h>
#	include <mir_toolkit/mir_surface.h>
#elif ASHES_WAYLAND
#	include <wayland-client-core.h>
#else
#	error "Yet unsupported OS"
#endif

namespace ashespp
{
	class IWindowlessHandle
		: public IWindowHandle
	{
	public:
		explicit IWindowlessHandle()
		{
		}

		~IWindowlessHandle()
		{
		}

		operator bool()
		{
			return true;
		}
	};


#if ASHES_WIN32

	class IMswWindowHandle
		: public IWindowHandle
	{
	public:
		explicit IMswWindowHandle( HINSTANCE hInstance
			, HWND hWnd )
			: m_hInstance{ hInstance }
			, m_hWnd{ hWnd }
		{
		}

		~IMswWindowHandle()
		{
		}

		operator bool()
		{
			return m_hWnd != nullptr
				&& m_hInstance != nullptr;
		}

		inline HINSTANCE getHinstance()const
		{
			return m_hInstance;
		}

		inline HWND getHwnd()const
		{
			return m_hWnd;
		}

	private:
		HINSTANCE m_hInstance;
		HWND m_hWnd;
	};

#elif ASHES_XLIB

	class IXWindowHandle
		: public IWindowHandle
	{
	public:
		IXWindowHandle( GLXDrawable drawable
			, Display * display )
			: m_drawable{ drawable }
			, m_display{ display }
		{
		}

		~IXWindowHandle()
		{
		}

		operator bool()
		{
			return m_drawable != 0 && m_display != nullptr;
		}

		inline GLXDrawable getDrawable()const
		{
			return m_drawable;
		}

		inline Display * getDisplay()const
		{
			return m_display;
		}

	private:
		GLXDrawable m_drawable;
		Display * m_display;
	};

#elif ASHES_XCB

	class IXcbWindowHandle
		: public IWindowHandle
	{
	public:
		IXcbWindowHandle( xcb_connection_t * connection
			, xcb_window_t window )
			: m_connection{ connection }
			, m_window{ window }
		{
		}

		~IXcbWindowHandle()
		{
		}

		operator bool()
		{
			return m_connection != nullptr && m_window != 0;
		}

		inline xcb_connection_t * getConnection()const
		{
			return m_connection;
		}

		inline xcb_window_t getWindow()const
		{
			return m_window;
		}

	private:
		xcb_connection_t * m_connection;
		xcb_window_t m_window;
	};

#elif ASHES_ANDROID

	class IAndroidWindowHandle
		: public IWindowHandle
	{
	public:
		IAndroidWindowHandle( ANativeWindow * window )
			: m_window{ window }
		{
		}

		~IAndroidWindowHandle()
		{
		}

		operator bool()
		{
			return m_window != nullptr;
		}

		inline ANativeWindow * getWindow()const
		{
			return m_window;
		}

	private:
		ANativeWindow * m_window;
	};

#elif ASHES_MIR

	class IMirWindowHandle
		: public IWindowHandle
	{
	public:
		IMirWindowHandle( MirConnection * connection
			, MirSurface * surface )
			: m_connection{ connection }
			, m_surface{ surface }
		{
		}

		~IMirWindowHandle()
		{
		}

		operator bool()
		{
			return m_connection != nullptr && m_surface != nullptr;
		}

		inline MirConnection * getConnection()const
		{
			return m_connection;
		}

		inline MirSurface * getSurface()const
		{
			return m_surface;
		}

	private:
		MirConnection * m_connection;
		MirSurface * m_surface;
	};

#elif ASHES_WAYLAND

	class IWaylandWindowHandle
		: public IWindowHandle
	{
	public:
		IWaylandWindowHandle( wl_display * display
			, wl_surface * surface )
			: m_display{ display }
			, m_surface{ surface }
		{
		}

		~IWaylandWindowHandle()
		{
		}

		operator bool()
		{
			return m_display != nullptr && m_surface != nullptr;
		}

		inline wl_display * getDisplay()const
		{
			return m_display;
		}

		inline wl_surface * getSurface()const
		{
			return m_window;
		}

	private:
		wl_display * m_display;
		wl_surface * m_surface;
	};

#endif
}

#endif
