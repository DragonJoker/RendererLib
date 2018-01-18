/*
This file belongs to GlRenderer.
See LICENSE file in root folder.
*/
#include "GlBindGeometryBuffersCommand.hpp"

#include "GlGeometryBuffers.hpp"

namespace gl_renderer
{
	BindGeometryBuffersCommand::BindGeometryBuffersCommand( renderer::GeometryBuffers const & vao )
		: m_vao{ static_cast< GeometryBuffers const & >( vao ) }
	{
	}

	void BindGeometryBuffersCommand::apply()const
	{
		glBindVertexArray( m_vao.getVao() );
	}

	CommandPtr BindGeometryBuffersCommand::clone()const
	{
		return std::make_unique< BindGeometryBuffersCommand >( *this );
	}
}