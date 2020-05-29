//
//  Texture.cpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/27/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#include "Texture.hpp"

#include "../GLlibs.h"
#include "stb_image.h"

namespace Crude::Utils
{
    Texture::Texture(std::string filepath, bool verticalFlip) //colourFormat is the external format
    : m_ID(0), m_Filepath(filepath), m_Width(0), m_Height(0), m_Channels(0), m_Slot(0)
    {
        glGenTextures(1, &m_ID);
        glBindTexture(GL_TEXTURE_2D, m_ID);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);    // set texture wrapping to GL_REPEAT (default wrapping method)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
        stbi_set_flip_vertically_on_load(verticalFlip);
        stbi_uc* data = nullptr;
        data = stbi_load(m_Filepath.c_str(), &m_Width, &m_Height, &m_Channels, 0);//colourFormat == GL_RGBA ? 4 : 0);
        if (m_Channels == 4)
        {
            m_InternalFormat = GL_RGBA8;
            m_ExternalFormat = GL_RGBA;
        }
        else if (m_Channels == 3)
        {
            m_InternalFormat = GL_RGB8;
            m_ExternalFormat = GL_RGB;
        }
        if(data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, m_InternalFormat, m_Width, m_Height, 0, m_ExternalFormat, GL_UNSIGNED_BYTE, data);
            
            glGenerateMipmap(GL_TEXTURE_2D);
            stbi_image_free(data);
        }
        else
        {
            LOG_ERROR("Failed to load texture: {0}", m_Filepath);
        }
        
        glBindTexture(GL_TEXTURE_2D, 0);
        
    
    }
    
    Texture::~Texture()
    {
        LOG_TRACE("Texture ID<{0}> deleted", m_ID);
        glDeleteTextures(1, &m_ID);
    }
    
    void Texture::bind(unsigned int slot)
    {
        
        assert(slot <= s_MaxTextureSlots && "slot exceed maximum texture units available!");
        m_Slot = slot;
        
        glActiveTexture(GL_TEXTURE0 + m_Slot);
        glBindTexture(GL_TEXTURE_2D, m_ID);
    }
    
    void Texture::unbind()
    {
        glActiveTexture(GL_TEXTURE0 + m_Slot);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    
    
    
    
    
    
    
    TextureLibrary::TextureLibrary()
    {
        
    }
    
    TextureLibrary::~TextureLibrary()
    {
        /*std::unordered_map<std::string, Texture*>::iterator it = m_TextureCache.begin();
        while(it != m_TextureCache.end())
        {
            delete it->second;
        }*/
        for(std::pair<std::string, Texture*> element : m_TextureCache)
        {
            delete element.second;
        }
    
    }
    
    void TextureLibrary::add(const std::string &name, Texture& texture)
    {
        if(name == "")
        {
            LOG_WARN("Your giving your texture an empty name");
        }
        if(exists(name))
        {
            LOG_WARN("Texture <{0}> already exists!", name);
            return;
        }
        
        m_TextureCache[name] = &texture;
        
    }
    
    void TextureLibrary::load(const std::string& name, const std::string& filepath)
    {
        if(name == "")
        {
            LOG_WARN("Your giving your texture an empty name");
        }
        if(exists(name))
        {
            LOG_WARN("Texture <{0}> already exists!", name);
            return;
        }
        
        Texture* tex = new Texture(filepath, true);
        m_TextureCache[name] = tex;
    }
    
    Texture* TextureLibrary::get(const std::string& name)
    {
        if(exists(name))
        {
            return m_TextureCache[name];
        }
        LOG_WARN("Texture <{0}> does not exist!", name);
        return nullptr;
    }
    
    bool TextureLibrary::exists(const std::string& name)
    {
        if(m_TextureCache.find(name) != m_TextureCache.end())
        {
            return true;
        }
        return false;
    }
}
