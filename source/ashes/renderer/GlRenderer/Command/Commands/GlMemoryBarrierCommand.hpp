/*
This file belongs to Ashes.
See LICENSE file in root folder
*/
#pragma once

#include "renderer/GlRenderer/Command/Commands/GlCommandBase.hpp"

namespace ashes::gl
{
	//*************************************************************************

	template<>
	struct alignas( uint64_t ) CmdT< OpType::eMemoryBarrier >
	{
		inline CmdT( GlMemoryBarrierFlags flags )
			: cmd{ { OpType::eMemoryBarrier, sizeof( CmdT ) / sizeof( uint32_t ) } }
			, flags{ std::move( flags ) }
		{
		}

		Command cmd;
		GlMemoryBarrierFlags flags;
	};
	using CmdMemoryBarrier = CmdT< OpType::eMemoryBarrier >;

	void apply( ContextLock const & context
		, CmdMemoryBarrier const & cmd );
	
	//*************************************************************************

	void buildMemoryBarrierCommand( VkPipelineStageFlags after
		, VkPipelineStageFlags before
		, VkDependencyFlags dependencyFlags
		, ArrayView< VkMemoryBarrier const > memoryBarriers
		, ArrayView< VkBufferMemoryBarrier const > bufferMemoryBarriers
		, ArrayView< VkImageMemoryBarrier const > imageMemoryBarriers
		, VkDeviceMemorySet & downloads
		, VkDeviceMemorySet & uploads
		, CmdList & list );

	//*************************************************************************
}
