//
//  IndexBuffer.cpp
//  CrudeEngine
//
//  Created by Hervé Schmit-Veiler on 4/26/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#include "IndexBuffer.hpp"

#include "../GLlibs.h"

namespace Crude::Utils
{
    
    IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count) //count is element count of data
    {
        glGenBuffers(1, &m_ID);
        bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
        
    }

    IndexBuffer::~IndexBuffer()
    {
        glDeleteBuffers(1, &m_ID);
    }

    void IndexBuffer::bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
    }

    void IndexBuffer::unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

}
