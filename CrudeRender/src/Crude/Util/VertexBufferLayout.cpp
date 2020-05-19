//
//  VertexBufferLayout.cpp
//  CrudeEngine
//
//  Created by Hervé Schmit-Veiler on 4/27/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#include "VertexBufferLayout.hpp"

#include "../GLlibs.h"


namespace Crude::Utils
{

    unsigned int VertexBufferElement::getSizeOfType(unsigned int type)
    {
        switch(type)
        {
            case GL_FLOAT:          return 4;
            case GL_UNSIGNED_INT:   return 4;
            case GL_UNSIGNED_BYTE:  return 1;
        }
        std::cout<< "Type " << type << "is/may not supported by Crude" <<std::endl;
        return 0;
    }

    void VertexBufferLayout::pushf(unsigned int count)
    {
        m_elements.push_back(VertexBufferElement(GL_FLOAT, count, GL_FALSE));
        m_stride += VertexBufferElement::getSizeOfType(GL_FLOAT) * count;
    }

    void VertexBufferLayout::pushui(unsigned int count)
    {
        m_elements.push_back(VertexBufferElement(GL_UNSIGNED_INT, count, GL_FALSE));
        m_stride += VertexBufferElement::getSizeOfType(GL_UNSIGNED_INT) * count;
    }

    void VertexBufferLayout::pushuc(unsigned int count)
    {
        m_elements.push_back(VertexBufferElement(GL_UNSIGNED_BYTE, count, GL_FALSE));
        m_stride += VertexBufferElement::getSizeOfType(GL_UNSIGNED_BYTE) * count;
    }

    template<> void VertexBufferLayout::push<float>(unsigned int count)
    {
        m_elements.push_back(VertexBufferElement(GL_FLOAT, count, GL_FALSE));
        m_stride += VertexBufferElement::getSizeOfType(GL_FLOAT) * count;
    }

    template<> void VertexBufferLayout::push<unsigned int>(unsigned int count)
    {
        m_elements.push_back(VertexBufferElement(GL_UNSIGNED_INT, count, GL_FALSE));
        m_stride += VertexBufferElement::getSizeOfType(GL_UNSIGNED_INT) * count;
    }

    template<> void VertexBufferLayout::push<unsigned char>(unsigned int count)
    {
        m_elements.push_back(VertexBufferElement(GL_UNSIGNED_BYTE, count, GL_FALSE));
        m_stride += VertexBufferElement::getSizeOfType(GL_UNSIGNED_BYTE) * count;
    }
    
}
