//
//  Texture.hpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/27/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp

#include "../../crudestd.hpp"


namespace Crude::Utils
{
    class Texture
    {
    public:
        Texture(std::string filepath, /*unsigned int colourFormat,*/ bool verticalFlip = true);
        ~Texture();
        
        void bind(unsigned int slot = 0);
        void unbind();
        
        inline int getWidth() const {return m_Width;}
        inline int getHeight() const {return m_Height;}
        inline unsigned int getID() const {return m_ID;}
        
        
    private:
        unsigned int m_ID;
        std::string m_Filepath;
        //unsigned char* m_LocalBuffer;
        unsigned int m_InternalFormat, m_ExternalFormat;
        int m_Width, m_Height, m_Channels; //Bits Per Pixel
        unsigned int m_Slot;
        
        inline static const int s_MaxTextureSlots = 16;
    
    
    };
    
    class TextureLibrary
    {
    public:
        TextureLibrary();
        ~TextureLibrary();
        
        void add(const std::string& name, Texture& texture);
        void load(const std::string& name, const std::string& filepath);
        Texture* get(const std::string& name);
        bool exists(const std::string& name);
        
    private:
        std::unordered_map<std::string, Texture*> m_TextureCache;
    };
}



#endif /* Texture_hpp */
