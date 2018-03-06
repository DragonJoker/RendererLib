/*
This file belongs to RendererLib.
See LICENSE file in root folder.
*/
#ifndef ___Renderer_Texture_HPP___
#define ___Renderer_Texture_HPP___
#pragma once

#include "ComponentMapping.hpp"
#include "ImageCreateInfo.hpp"
#include "ImageViewCreateInfo.hpp"

namespace renderer
{
	/**
	*\~english
	*\brief
	*	A texture image.
	*\~french
	*\brief
	*	L'image d'une texture.
	*/
	class Texture
	{
	public:
		/**
		*\~french
		*\brief
		*	Contient les informations d'une image mappée en RAM.
		*\~english
		*\brief
		*	Contains an image mapped in RAM informations.
		*/
		struct Mapped
		{
			uint8_t * data;
			uint64_t size;
			uint64_t rowPitch;
			uint64_t arrayPitch;
			uint64_t depthPitch;
		};

	protected:
		Texture( Texture const & ) = delete;
		Texture( Texture && rhs );
		/**
		*\~french
		*\brief
		*	Constructeur.
		*\param[in] device
		*	Le périphérique logique.
		*\~english
		*\brief
		*	Constructor.
		*\param[in] device
		*	The logical device.
		*/
		Texture( Device const & device
			, TextureType type
			, PixelFormat format
			, Extent3D dimensions
			, uint32_t mipLevels
			, uint32_t arrayLayers );

	public:
		Texture & operator=( Texture const & ) = delete;
		Texture & operator=( Texture && rhs );
		/**
		*\~english
		*\brief
		*	Destructor.
		*\~french
		*\brief
		*	Destructeur.
		*/
		virtual ~Texture() = default;
		/**
		*\~french
		*\brief
		*	Crée une vue sur la texture.
		*\param[in] createInfo
		*	Les informations de création de la vue.
		*\~english
		*\brief
		*	Creates a view to the texture.
		*\param[in] createInfo
		*	The view creation informations.
		*/
		virtual TextureViewPtr createView( ImageViewCreateInfo const & createInfo )const = 0;
		/**
		*\~french
		*\brief
		*	Crée une vue sur la texture.
		*\param[in] type
		*	Le type de texture de la vue.
		*\param[in] format
		*	Le format des pixels de la vue.
		*\param[in] baseMipLevel
		*	Le premier niveau de mipmap accessible à la vue.
		*\param[in] levelCount
		*	Le nombre de niveaux de mipmap (à partir de \p baseMipLevel) accessibles à la vue.
		*\param[in] baseArrayLayer
		*	La première couche de tableau accessible à la vue.
		*\param[in] layerCount
		*	Le nombre de couches de tableau (à partir de \p baseArrayLayer) accessibles à la vue.
		*\param[in] mapping
		*	Le mapping des composantes de couleur.
		*\~english
		*\brief
		*	Creates a view to the texture.
		*\param[in] type
		*	The view's texture type.
		*\param[in] format
		*	The view's pixels format.
		*\param[in] baseMipLevel
		*	The first mipmap level accessible to the view.
		*\param[in] levelCount
		*	The number of mipmap levels (starting from \p baseMipLevel) accessible to the view.
		*\param[in] baseArrayLayer
		*	The first array layer accessible to the view.
		*\param[in] layerCount
		*	The number of array layers (starting from \p baseArrayLayer) accessible to the view.
		*\param[in] mapping
		*	The colours component mapping.
		*/
		TextureViewPtr createView( TextureViewType type
			, PixelFormat format
			, uint32_t baseMipLevel = 0u
			, uint32_t levelCount = 1u
			, uint32_t baseArrayLayer = 0u
			, uint32_t layerCount = 1u
			, ComponentMapping const & mapping = ComponentMapping{} )const;
		/**
		*\~french
		*\brief
		*	Génère les mipmaps de la texture.
		*\~english
		*\brief
		*	Generates the texture mipmaps.
		*/
		virtual void generateMipmaps()const = 0;
		/**
		*\~french
		*\return
		*	Le format des pixels de la texture.
		*\~english
		*\return
		*	The texture pixel format.
		*/
		inline PixelFormat getFormat()const noexcept
		{
			return m_format;
		}
		/**
		*\~french
		*\return
		*	Le nombre de couches.
		*\~english
		*\return
		*	The layers count.
		*/
		inline uint32_t getLayerCount()const noexcept
		{
			return m_arrayLayers;
		}
		/**
		*\~french
		*\return
		*	Le nombre de niveaux de mipmaps.
		*\~english
		*\return
		*	The mipmap levels count.
		*/
		inline uint32_t getMipmapLevels()const noexcept
		{
			return m_mipLevels;
		}
		/**
		*\~french
		*\return
		*	Les dimensions de la texture.
		*\~english
		*\return
		*	The texture dimensions.
		*/
		inline Extent3D const & getDimensions()const noexcept
		{
			return m_dimensions;
		}
		/**
		*\~french
		*\return
		*	Le type de texture.
		*\~english
		*\return
		*	The texture type.
		*/
		inline TextureType getType()const
		{
			return m_imageType;
		}

	protected:
		Device const & m_device;
		TextureType m_imageType;
		PixelFormat m_format;
		Extent3D m_dimensions;
		uint32_t m_mipLevels;
		uint32_t m_arrayLayers;
	};
}

#endif
