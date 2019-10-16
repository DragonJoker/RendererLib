/*
This file belongs to Ashes.
See LICENSE file in root folder
*/
#pragma once

namespace ashes::gl4
{
	enum GlAccessType
		: GLenum
	{
		GL_ACCESS_TYPE_READ_ONLY = 0x88B8,
		GL_ACCESS_TYPE_WRITE_ONLY = 0x88B9,
		GL_ACCESS_TYPE_READ_WRITE = 0x88BA,
	};
	std::string getName( GlAccessType value );
	/**
	*\brief
	*	Convertit un AccessFlags en VkAccessFlags.
	*\param[in] flags
	*	Le AccessFlags.
	*\return
	*	Le VkAccessFlags.
	*/
	GLenum convertAccessFlags( VkAccessFlags const & flags );
	/**
	*\brief
	*	Convertit un VkAccessFlags en AccessFlags.
	*\param[in] flags
	*	Le VkAccessFlags.
	*\return
	*	Le AccessFlags.
	*/
	VkAccessFlags convertAccessFlags( GLenum flags );
}