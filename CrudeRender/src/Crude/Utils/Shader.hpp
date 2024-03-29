//
//  Shader.hpp
//  CrudeEngine
//
//  Created by Hervé Schmit-Veiler on 4/26/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp

#include "../../crudestd.hpp"

#include "../glmHeaders.h"

namespace Crude::Utils
{
    
    class Shader
    {
    private:
        bool m_Initialised = false;
        
        unsigned int m_ID;
        
        std::unordered_map<std::string, int> m_UniformLocationCache;
        
    public:
        // constructor generates the shader on the fly
        // ------------------------------------------------------------------------
        Shader(const std::string& vertexPath, const std::string& fragmentPath);
        // If the user prefers to generate shader later on
        Shader();
        ~Shader();
        
        // Contructs shader from file
        void loadFromFile(const std::string& vertexPath, const std::string& fragmentPath);
        // Constructs shader from source string
        void loadFromSource(const std::string& vertexSrc, const std::string& fragmentSrc);
        
        // activate the shader
        // ------------------------------------------------------------------------
        void bind() const;
        
        void unbind() const;
        // utility uniform functions
        // ------------------------------------------------------------------------
        int getUniformLocation(const std::string &name);
        
        void setBool(const std::string& name, bool value, bool bindShader = false);
     
        void setInt(const std::string& name, int value, bool bindShader = false);
        
        void setFloat(const std::string& name, float value, bool bindShader = false);
        
        void setVec2f(const std::string& name, float x, float y, bool bindShader = false);
        
        void setVec3f(const std::string& name, float x, float y, float z, bool bindShader = false);
        
        void setVec4f(const std::string& name, float x, float y, float z, float w, bool bindShader = false);
        
        void setMat4(const std::string& name, const glm::mat4 &mat, bool bindShader = false);
        
        unsigned int getID() const {return m_ID;}
        
    private:
        // utility function for checking shader compilation/linking errors.
        // ------------------------------------------------------------------------
        void checkCompileErrors(unsigned int shader, std::string type);
    };
    
    
    class ShaderLibrary
    {
    public:
        
    };
    
}


#endif /* Shader_hpp */
