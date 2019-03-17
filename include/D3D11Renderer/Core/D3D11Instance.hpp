/**
*\file
*	Instance.h
*\author
*	Sylvain Doremus
*/
#pragma once

#include "D3D11Renderer/D3D11RendererPrerequisites.hpp"

#include <Ashes/Core/Instance.hpp>
#include <Utils/DynamicLibrary.hpp>

namespace d3d11_renderer
{
	class Instance
		: public ashes::Instance
	{
	public:
		/**
		*\brief
		*	Constructeur, initialise l'instance de Vulkan.
		*/
		Instance( Configuration const & configuration );
		/**
		*\brief
		*	Destructeur.
		*/
		~Instance();
		/**
		*\brief
		*	Crée le périphérique logique.
		*\param[in] connection
		*	La connection avec la fenêtre.
		*/
		ashes::DevicePtr createDevice( ashes::SurfacePtr surface
			, ashes::DeviceQueueCreateInfoArray queueCreateInfos
			, ashes::StringArray enabledLayers
			, ashes::StringArray enabledExtensions
			, ashes::PhysicalDeviceFeatures enabledFeatures )const override;
		/**
		*\brief
		*	Crée une connection.
		*\param[in] deviceIndex
		*	L'indice du périphérique physique.
		*\param[in] handle
		*	Le descripteur de la fenêtre.
		*/
		ashes::SurfacePtr createSurface( ashes::PhysicalDevice const & gpu
			, ashes::WindowHandle handle )const override;
		/**
		*\copydoc	ashes::Instance::frustum
		*/
		std::array< float, 16 > frustum( float left
			, float right
			, float bottom
			, float top
			, float zNear
			, float zFar )const override;
		/**
		*\copydoc	ashes::Instance::perspective
		*/
		std::array< float, 16 > perspective( float radiansFovY
			, float aspect
			, float zNear
			, float zFar )const override;
		/**
		*\copydoc	ashes::Instance::ortho
		*/
		std::array< float, 16 > ortho( float left
			, float right
			, float bottom
			, float top
			, float zNear
			, float zFar )const override;

		inline IDXGIFactory * getDXGIFactory()const
		{
			return m_factory;
		}

	private:
		void doCreateDXGIFactory();
		D3D_FEATURE_LEVEL doLoadAdapters();

	private:
		IDXGIFactory * m_factory;
	};
}
