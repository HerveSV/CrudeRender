//
//  VertexBufferLayout.hpp
//  CrudeEngine
//
//  Created by Hervé Schmit-Veiler on 4/27/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef VertexBufferLayout_hpp
#define VertexBufferLayout_hpp

#include "../../crudestd.hpp"

namespace Crude::Utils
{
    
    class VertexBufferElement
    {
    public:
        unsigned int type;
        unsigned int count;
        unsigned int normalised;
        
        VertexBufferElement(unsigned int c_type, unsigned int c_count, unsigned int c_normalised)
        : type(c_type), count(c_count), normalised(c_normalised)
        {
            
        }
        
        static unsigned int getSizeOfType(unsigned int type);
    };

    class VertexBufferLayout
    {
    private:
        std::vector<VertexBufferElement> m_elements;
        unsigned int m_stride;
    public:
        
        VertexBufferLayout() : m_stride(0) {};
        //~VertexBufferLayout();
        
        template <typename T>
        void push(unsigned int count)
        {
            LOG_ERROR("Unspecified type for VertexBufferLayout::push(unsigned int)");
        }
        /*
        template<>
        void push<float>(unsigned int count);
        
        template<>
        void push<unsigned int>(unsigned int count);
        
        template<>
        void push<unsigned char>(unsigned int count);
        */
        
        void pushFloat(unsigned int count); //overloaded version of float pushing
        
        void pushUInt(unsigned int count); //overloaded version of unsigned int pushing
        
        void pushUChar(unsigned int count); //overloaded version of unsigned char/byte pushing
        
        inline const std::vector<VertexBufferElement> getElements() const {return m_elements;}
        inline unsigned int getStride() const {return m_stride;}
    };
    
    

}
#endif /* VertexBufferLayout_hpp */
