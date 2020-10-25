/*
This file belongs to Ashes.
See LICENSE file in root folder.
*/
#include "ashespp/Sync/Fence.hpp"

#include "ashespp/Core/Device.hpp"
#include "ashespp/Sync/SyncException.hpp"

namespace ashes
{
	Fence::Fence( Device const & device
		, VkFenceCreateFlags flags )
		: Fence{ device, "Fence", flags }
	{
	}

	Fence::Fence( Device const & device
		, std::string const & debugName
		, VkFenceCreateFlags flags )
		: m_device{ device }
	{
		VkFenceCreateInfo createInfo
		{
			VK_STRUCTURE_TYPE_FENCE_CREATE_INFO,
			nullptr,
			flags
		};
		DEBUG_DUMP( createInfo );
		auto res = m_device.vkCreateFence( device
			, &createInfo
			, m_device.getAllocationCallbacks()
			, &m_internal );
		checkError( res, "Fence creation" );
		registerObject( m_device, debugName, *this );
	}

	Fence::~Fence()
	{
		unregisterObject( m_device, *this );
		m_device.vkDestroyFence( m_device
			, m_internal
			, m_device.getAllocationCallbacks() );
	}

	WaitResult Fence::wait( uint64_t timeout )const
	{
		auto res = m_device.vkWaitForFences( m_device
			, 1
			, &m_internal
			, VK_TRUE
			, timeout );
		auto result = res == VK_SUCCESS
			? WaitResult::eSuccess
			: ( res == VK_TIMEOUT
				? WaitResult::eTimeOut
				: WaitResult::eError );
		onWaitEnd( *this, result );
		return result;
	}

	void Fence::reset()const
	{
		auto res = m_device.vkResetFences( m_device
			, 1
			, &m_internal );
		checkError( res, "Fence reset" );
	}
}
