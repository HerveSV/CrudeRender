//
//  VertexBuffer.cpp
//  CrudeEngine
//
//  Created by Hervé Schmit-Veiler on 4/26/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#include "VertexBuffer.hpp"

#include "../GLlibs.h"

namespace Crude::Utils
{

    VertexBuffer::VertexBuffer(const void* data, unsigned int size) //size is bytecount of data
    {
        glGenBuffers(1, &m_ID);
        bind();
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }

    VertexBuffer::~VertexBuffer()
    {
        LOG_TRACE("Vertex Buffer ID<{0}> deleted", m_ID);
        glDeleteBuffers(1, &m_ID);
    }

    void VertexBuffer::bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_ID);
    }

    void VertexBuffer::unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

}
