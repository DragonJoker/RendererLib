/*
This file belongs to Ashes.
See LICENSE file in root folder
*/
#pragma once

#include "renderer/TestRenderer/Command/Commands/TestCommandBase.hpp"

namespace ashes::test
{
	class DrawIndirectCommand
		: public CommandBase
	{
	public:
		DrawIndirectCommand( VkDevice device
			, VkBuffer buffer
			, VkDeviceSize offset
			, uint32_t drawCount
			, uint32_t stride
			, VkPrimitiveTopology mode
			, VbosBindingArray const & vbos );

		void apply()const;
		CommandPtr clone()const;

	private:
		VkBuffer m_buffer;
		uint32_t m_offset;
		uint32_t m_drawCount;
		uint32_t m_stride;
		VbosBindingArray m_vbos;
	};
}
