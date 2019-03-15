/*
This file belongs to Ashes.
See LICENSE file in root folder
*/
#pragma once

#include "VkRenderer/Image/VkTexture.hpp"
#include "VkRenderer/Image/VkTextureView.hpp"

#include <Ashes/Core/BackBuffer.hpp>

namespace vk_renderer
{
	/**
	*\brief
	*	Classe encapsulant une image venant d'une swap chain.
	*/
	class BackBuffer
		: public ashes::BackBuffer
	{
	public:
		/**
		*\brief
		*	Constructeur.
		*\param[in] device
		*	La connexion logique au GPU.
		*\param[in] swapchain
		*	La swapchain.
		*\param[in] imageIndex
		*	L'index de l'image, parmi les images de la swap chain.
		*/
		BackBuffer( Device const & device
			, ashes::TexturePtr image
			, uint32_t imageIndex
			, ashes::Format format
			, Texture const & imageRef );
	};
}
