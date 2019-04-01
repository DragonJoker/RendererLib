/*
This file belongs to Ashes.
See LICENSE file in root folder
*/
#pragma once

#include <Ashes/Enum/PolygonMode.hpp>

namespace gl_renderer
{
	enum GlPolygonMode
		: GLenum
	{
		GL_POLYGON_MODE_POINT = 0x1B00,
		GL_POLYGON_MODE_LINE = 0x1B01,
		GL_POLYGON_MODE_FILL = 0x1B02,
	};
	std::string getName( GlPolygonMode value );
	/**
	*\brief
	*	Convertit un VkPolygonMode en GlPolygonMode.
	*\param[in] value
	*	Le VkPolygonMode.
	*\return
	*	Le GlPolygonMode.
	*/
	GlPolygonMode convert( VkPolygonMode const & value );
}
