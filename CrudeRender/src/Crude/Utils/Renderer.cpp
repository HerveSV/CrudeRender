//
//  Renderer.cpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/25/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#include "Renderer.hpp"

#include "../GLlibs.h"

namespace Crude::Utils
{
    /*void Renderer::addShader(Shader* shader, const std::string& name)
    {
        if(m_ShaderCache.find(name) != m_ShaderCache.end())
        {
            LOG_WARN("Shader <{name}> has already been added to Renderer!");
            return;
        }
        m_ShaderCache[name] = shader;
    }
    
    void Renderer::useShader(std::string name)
    {
        if(!m_SceneBegun)
        {
            LOG_WARN("useShader(std::string) should only be called when a scene is active. Make sure it's after the beginScene(Camera*) call and before the endScene() call, and check for any errors coming from those method.");
            return;
        }
        m_CurrShader = m_ShaderCache[name];
        m_CurrShader->bind();
        m_CurrShader->setMat4(m_ViewProjectionMatrixName, m_CurrCamera->getViewProjectionMatrix());
        //m_CurrShader->setMat4("u_View", m_CurrCamera->getViewMatrix());
        //m_CurrShader->setMat4("u_Projection", m_CurrCamera->getProjectionMatrix());
        m_ShaderActive = true;
    }*/
    
    void Renderer::useShader(Shader& shader)
    {
        if(!m_SceneBegun)
        {
            LOG_WARN("useShader(std::string) should only be called when a scene is active. Make sure it's after the beginScene(Camera*) call and before the endScene() call, and check for any errors coming from those method.");
            return;
        }
        m_CurrShader = &shader;
        m_CurrShader->bind();
        m_CurrShader->setMat4(m_ViewProjectionMatrixName, m_CurrCamera->getViewProjectionMatrix());
        m_ShaderActive = true;
    }
    
    void Renderer::beginScene(Camera& camera)
    {
        /*if(camera == nullptr)
        {
            LOG_CRITICAL("Camera passed into beginScene(Camera*) cannot be a nullptr!");
            return;
        }*/
        m_CurrCamera = &camera;
        m_SceneBegun = true;
        
        //glClearColor(1.0f, 0.4f, 0.2f, 1.0f);
        //glClear(GL_COLOR_BUFFER_BIT);
    }
    
    void Renderer::endScene()
    {
        m_SceneBegun = false;
        m_CurrCamera = nullptr;
    }
    
    
    void Renderer::submit(const VertexArray& vao, const glm::mat4& modelMat)
    {
        if(!m_SceneBegun)
        {
            LOG_WARN("Submit calls cannot be called if the scene isn't active!");
            return;
        }
        if(!m_ShaderActive)
        {
            LOG_WARN("Define a shader to use before sumbitting any geometry!");
            return;
        }
        //glm::vec4 pos;
        //pos = m_CurrCamera->getViewProjectionMatrix() * modelMat * pos;
        //LOG_TRACE("{0}, {1}, {2}", pos.x, pos.y, pos.z);
        
        m_CurrShader->bind();
        m_CurrShader->setMat4(m_ModelMatrixName, modelMat);
        glDrawElements(GL_TRIANGLES, vao.getIndexBuffer().getCount(), GL_UNSIGNED_INT, nullptr);
    }
    
    /*void Renderer::draw(const VertexArray& vao, const glm::mat4& modelMat)
    {
        if(!m_SceneBegun)
        {
            LOG_WARN("Draw calls cannot be called if the scene isn't active!");
            return;
        }
        if(!m_ShaderActive)
        {
            LOG_WARN("Draw calls cannot be called without first calling the useShader(std::string) method!");
            return;
        }
        
        m_CurrShader->setMat4(m_ModelMatrixName, modelMat);
        glDrawElements(GL_TRIANGLES, vao.getIndexBuffer().getCount(), GL_UNSIGNED_INT, nullptr);
    }
    
    void Renderer::draw(const VertexArray& vao, const glm::vec4& colour, const glm::mat4& modelMat)
    {
        if(!m_SceneBegun)
        {
            LOG_WARN("Draw calls cannot be called if the scene isn't active!");
            return;
        }
        if(!m_ShaderActive)
        {
            LOG_WARN("Draw calls cannot be called without first calling the useShader(std::string) method!");
            return;
        }
        m_CurrShader->setMat4(m_ModelMatrixName, modelMat);
        m_CurrShader->setVec4f("u_Colour", colour.r, colour.g, colour.b, colour.a);
        glDrawElements(GL_TRIANGLES, vao.getIndexBuffer().getCount(), GL_UNSIGNED_INT, nullptr);
    }*/
    

    
    
    void Renderer::setViewMatrixName(const std::string &name)
    {
        if(name != "")
        {
            m_ViewMatrixName = name;
        }
        else
        {
            LOG_WARN("ViewMatrix cannot be given empty name");
        }
        
    }
    
    void Renderer::setProjectionMatrixName(const std::string &name)
    {
        if(name != "")
        {
            m_ProjectionMatrixName = name;
        }
        else
        {
            LOG_WARN("ProjectionMatrix cannot be given empty name");
        }
    }
    
    void Renderer::setViewProjectionMatrixName(const std::string &name)
    {
        if(name != "")
        {
            m_ViewProjectionMatrixName = name;
        }
        else
        {
            LOG_WARN("ViewProjectionMatrix cannot be given empty name");
        }
    }

    void Renderer::setModelMatrixName(const std::string &name)
    {
        if(name != "")
        {
            m_ModelMatrixName = name;
        }
        else
        {
            LOG_WARN("ModelMatrix cannot be given empty name");
        }
        
    }
    
    /*void Renderer::setColourUniformName(const std::string &name)
    {
        if(name != "")
        {
            m_ColourUniformName = name;
        }
        else
        {
            LOG_WARN("Uniforms cannot have empty names");
        }
        
    }*/




}




