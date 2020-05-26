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
    void Renderer::addShader(Shader* shader, const std::string& name)
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
            LOG_WARN("useShader(std::string) should only be called when a scene is active. Make sure it's after the beginScene(Camera*) call and before the endScene() call, and check for any errors from those method calls.");
            return;
        }
        m_CurrShader = m_ShaderCache[name];
        m_CurrShader->bind();
        m_CurrShader->setMat4("u_ViewProjection", m_CurrCamera->getViewProjectionMatrix());
        
        m_ShaderActive = true;
    }
    
    void Renderer::beginScene(Camera* camera)
    {
        if(camera == nullptr)
        {
            LOG_CRITICAL("Camera passed into beginScene(Camera*) cannot be a nullptr!");
            return;
        }
        m_CurrCamera = camera;
        m_SceneBegun = true;
        
        glClearColor(1.0f, 0.4f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
    
    void Renderer::endScene()
    {
        m_SceneBegun = false;
        m_CurrCamera = nullptr;
    }
    
    void Renderer::draw(VertexArray& vao, glm::mat4& modelMat)
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
        
        m_CurrShader->setMat4("u_Model", modelMat);
        glDrawElements(GL_TRIANGLES, vao.getIndexBuffer().getCount(), GL_UNSIGNED_INT, nullptr);
    }
    
    void Renderer::draw(VertexArray& vao, glm::vec4& colour, glm::mat4& modelMat)
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
        m_CurrShader->setMat4("u_Model", modelMat);
        m_CurrShader->setVec4f("u_Colour", colour.r, colour.g, colour.b, colour.a);
        glDrawElements(GL_TRIANGLES, vao.getIndexBuffer().getCount(), GL_UNSIGNED_INT, nullptr);
    }
    
}
