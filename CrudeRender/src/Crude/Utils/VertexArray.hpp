//
//  VertexArray.hpp
//  CrudeEngine
//
//  Created by Hervé Schmit-Veiler on 4/27/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef VertexArray_hpp
#define VertexArray_hpp

#include "../../crudestd.hpp"

#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include "VertexBufferLayout.hpp"

namespace Crude::Utils
{
    class VertexArray
    {
    private:
        
        VertexBuffer* m_VBO;
        IndexBuffer* m_IBO;
        unsigned int m_ID;
        
    public:
        
        VertexArray();
        
        ~VertexArray();
        
        void bind() const;
        
        void unbind() const;
        
        void addVertexBuffer(VertexBuffer &vbo, VertexBufferLayout &layout);
        void addIndexBuffer(IndexBuffer &ibo);
        
        inline VertexBuffer& getVertexBuffer() const { return *m_VBO; }
        inline IndexBuffer& getIndexBuffer() const { return *m_IBO; }
        
        inline unsigned int getID() const { return m_ID; }
        
    };
}

#endif /* VertexArray_hpp */
