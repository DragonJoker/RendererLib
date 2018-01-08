/*
This file belongs to Renderer.
See LICENSE file in root folder.
*/
#pragma once

#include "VkShaderModule.hpp"

#include <Renderer/ShaderProgram.hpp>

namespace vk_renderer
{
	/**
	*\brief
	*	Gère les différents ShaderModules qu'un programme shader peut utiliser.
	*/
	class ShaderProgram
		: public renderer::ShaderProgram
	{
	public:
		/**
		*\brief
		*	Constructeur.
		*\param[in] device
		*	Le périphérique logique.
		*/
		ShaderProgram( Device const & device );
		/**
		*\brief
		*	Crée un module de shader et l'ajoute à la liste.
		*\param[in] shader
		*	Le code GLSL du shader.
		*\param[in] stage
		*	Le niveau de shader utilisé pour le module.
		*/
		void createModule( std::string const & shader
			, renderer::ShaderStageFlag stage )override;
		/**
		*\brief
		*	Crée un module de shader et l'ajoute à la liste.
		*\param[in] shader
		*	Le code SPIR-V du shader.
		*\param[in] stage
		*	Le niveau de shader utilisé pour le module.
		*/
		void createModule( renderer::ByteArray const & shader
			, renderer::ShaderStageFlag stage )override;
		/**
		*\brief
		*	Lie les modules du programme.
		*/
		void link()override
		{
		}
		/**
		*\~french
		*\brief
		*	Le début du tableau de modules.
		*\~english
		*\brief
		*	The beginning of the modules array.
		*/
		inline auto begin()const
		{
			return m_modules.begin();
		}
		/**
		*\~french
		*\brief
		*	La fin du tableau de modules.
		*\~english
		*\brief
		*	The end of the modules array.
		*/
		inline auto end()const
		{
			return m_modules.end();
		}

	private:
		Device const & m_device;
		std::vector< ShaderModule > m_modules;
	};
}