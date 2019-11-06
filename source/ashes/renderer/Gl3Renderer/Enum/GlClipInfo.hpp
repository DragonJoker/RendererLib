/*
This file belongs to Ashes.
See LICENSE file in root folder
*/
#pragma once

namespace ashes::gl3
{
	enum GlClipOrigin
	{
		GL_LOWER_LEFT = 0x8CA1,
		GL_UPPER_LEFT = 0x8CA2,
	};

	enum GlClipDepth
	{
		GL_NEGATIVE_ONE_TO_ONE = 0x935E,
		GL_ZERO_TO_ONE = 0x935F,
	};
	std::string getName( GlClipOrigin value );
	std::string getName( GlClipDepth value );
}
