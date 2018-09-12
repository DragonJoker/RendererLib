/*
This file belongs to RendererLib.
See LICENSE file in root folder.
*/
#include "Core/GlDevice.hpp"

#include <Buffer/PushConstantsBuffer.hpp>

#include <algorithm>

namespace renderer
{
	renderer::PushConstantArray convert( renderer::ShaderStageFlag stage
		, renderer::SpecialisationMapEntryArray::const_iterator const & begin
		, renderer::SpecialisationMapEntryArray::const_iterator const & end )
	{
		renderer::PushConstantArray result;

		for ( auto it = begin; it != end; ++it )
		{
			result.push_back( {
				it->constantID,
				it->offset,
				it->format,
				it->arraySize
			} );
		}

		return result;
	}

	renderer::PushConstantsBufferPtr convert( renderer::Device const & device
		, uint32_t location
		, renderer::ShaderStageFlag stage
		, renderer::SpecialisationInfoBase const & specialisationInfo )
	{
		auto result = device.createPushConstantsBuffer( location
			, stage
			, convert( stage, specialisationInfo.begin(), specialisationInfo.end() ) );
		assert( result->getSize() == specialisationInfo.getSize() );
		std::memcpy( result->getData()
			, specialisationInfo.getData()
			, specialisationInfo.getSize() );
		return std::move( result );
	}
}
