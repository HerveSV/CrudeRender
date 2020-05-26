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
        static void addShader(Shader* shader, const std::string& name);
        static void useShader(std::string name);
        
        static void beginScene(Camera* camera);
        static void endScene();
        
        static void draw(VertexArray& vao, glm::mat4& modelMat);
        static void draw(VertexArray& vao, glm::vec4& colour, glm::mat4& modelMat);
        
    private:
        inline static bool m_SceneBegun = false;
        inline static bool m_ShaderActive = false;
        inline static Camera* m_CurrCamera;
        inline static Shader* m_CurrShader;
        inline static std::unordered_map<std::string, Shader*> m_ShaderCache;
    };
    
}

#endif /* Renderer_hpp */
