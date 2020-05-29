//
//  Renderer.hpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/25/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include "../../crudestd.hpp"
#include "../glmHeaders.h"
#include "Camera.hpp"
#include "Shader.hpp"
#include "VertexArray.hpp"


namespace Crude::Utils
{
    class Renderer
    {
    public:
        
        enum class ShaderViewProjectionConfig
        {
            PreMultiplied,
            Separate,
            PreMultipliedAndSeparate,
        };
        
        //static void addShader(Shader* shader, const std::string& name);
        //static void useShader(std::string name);
        static void useShader(Shader& shader);
        
        static void beginScene(Camera& camera);
        static void endScene();
        
        static void submit(const VertexArray& vao, const glm::mat4& modelMat);
        
        //static void draw(const VertexArray& vao, const glm::mat4& modelMat);
        //static void draw(const VertexArray& vao, const glm::vec4& colour, const glm::mat4& modelMat);
        
        //inline static Shader& getShader(const std::string& name) { return *m_ShaderCache[name]; };
        //inline static Shader& getCurrShader() { return *m_CurrShader; };
        
    private:
        inline static bool m_SceneBegun = false;
        inline static bool m_ShaderActive = false;

        inline static Camera* m_CurrCamera;
        inline static Shader* m_CurrShader;
        //inline static std::unordered_map<std::string, Shader*> m_ShaderCache;
        
        
        
        
        
    public:
        static void setViewMatrixName(const std::string& name);
        static void setProjectionMatrixName(const std::string& name);
        static void setViewProjectionMatrixName(const std::string& name);
        static void setModelMatrixName(const std::string& name);
    private:
        
        inline static std::string m_ViewMatrixName = "u_View";
        inline static std::string m_ProjectionMatrixName = "u_Projection";
        inline static std::string m_ViewProjectionMatrixName = "u_ViewProjection";
        inline static std::string m_ModelMatrixName = "u_Model";
        
    };
    
}

#endif /* Renderer_hpp */
