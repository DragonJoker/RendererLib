/*
This file belongs to Ashes.
See LICENSE file in root folder
*/
#pragma once

#include "renderer/TestRenderer/Command/Commands/TestCommandBase.hpp"

namespace ashes::test
{
	class DrawCommand
		: public CommandBase
	{
	public:
		DrawCommand( VkDevice device
			, uint32_t vtxCount
			, uint32_t instCount
			, uint32_t firstVertex
			, uint32_t firstInstance
			, VkPrimitiveTopology mode
			, VbosBindingArray const & vbos );

		void apply()const;
		CommandPtr clone()const;

	private:
		uint32_t m_vtxCount;
		uint32_t m_instCount;
		uint32_t m_firstVertex;
		uint32_t m_firstInstance;
		VbosBindingArray m_vbos;
	};
}
