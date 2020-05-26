//
//  Shader.cpp
//  CrudeEngine
//
//  Created by Hervé Schmit-Veiler on 4/26/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#include "Shader.hpp"

#include "../GLlibs.h"

namespace Crude::Utils
{

    Shader::Shader(const char* vertexPath, const char* fragmentPath)
    {
        // 1. retrieve the vertex/fragment source code from filePath
        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;
        // ensure ifstream objects can throw exceptions:
        vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            // open files
            vShaderFile.open(vertexPath);
            fShaderFile.open(fragmentPath);
            std::stringstream vShaderStream, fShaderStream;
            // read file's buffer contents into streams
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();
            // close file handlers
            vShaderFile.close();
            fShaderFile.close();
            // convert stream into string
            vertexCode   = vShaderStream.str();
            fragmentCode = fShaderStream.str();
        }
        catch (std::ifstream::failure& e)
        {
            LOG_ERROR("SHADER::FILE_NOT_SUCCESFULLY_READ");
            //std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        }
        const char* vShaderCode = vertexCode.c_str();
        const char * fShaderCode = fragmentCode.c_str();
        // 2. compile shaders
        unsigned int vertex, fragment;
        // vertex shader
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShaderCode, NULL);
        glCompileShader(vertex);
        checkCompileErrors(vertex, "VERTEX");
        // fragment Shader
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, NULL);
        glCompileShader(fragment);
        checkCompileErrors(fragment, "FRAGMENT");
        // shader Program
        m_ID = glCreateProgram();
        glAttachShader(m_ID, vertex);
        glAttachShader(m_ID, fragment);
        glLinkProgram(m_ID);
        checkCompileErrors(m_ID, "PROGRAM");
        // delete the shaders as they're linked into our program now and no longer necessary
        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }

    Shader::~Shader()
    {
        glDeleteProgram(m_ID);
    }

    void Shader::bind() const
    {
        glUseProgram(m_ID);
    }

    void Shader::unbind() const
    {
        glUseProgram(0);
    }

    int Shader::getUniformLocation(const std::string &name)
    {
        if(m_uniformLocationCache.find(name) != m_uniformLocationCache.end())
        {
            return m_uniformLocationCache[name];
        }
        
        int location = glGetUniformLocation(m_ID, name.c_str());
        if(location == -1)
        {
            LOG_WARN("Uniform {0} does not exist!", name);
            //std::cout<<"Warning: uniform "<<name<<" does not exist!"<<std::endl;
        }
        m_uniformLocationCache[name] = location;
        return location;
    }

    void Shader::setBool(const std::string &name, bool value, bool bindShader)
    {
        if(bindShader)
        {
            bind();
            glUniform1i(getUniformLocation(name), (int)value);
            unbind();
        }
        else
        {
            glUniform1i(getUniformLocation(name), (int)value);
        }
        
    }

    void Shader::setInt(const std::string &name, int value, bool bindShader)
    {
        if(bindShader)
        {
            bind();
            glUniform1i(getUniformLocation(name), value);
            unbind();
        }
        else
        {
            glUniform1i(getUniformLocation(name), value);
        }
    }

    void Shader::setFloat(const std::string &name, float value, bool bindShader)
    {
        if(bindShader)
        {
            bind();
            glUniform1f(getUniformLocation(name), value);
            unbind();
        }
        else
        {
            glUniform1f(getUniformLocation(name), value);
        }
       
    }

    void Shader::setVec2f(const std::string &name, float x, float y, bool bindShader)
    {
        if(bindShader)
        {
            bind();
            glUniform2f(getUniformLocation(name), x, y);
            unbind();
        }
        else
        {
            glUniform2f(getUniformLocation(name), x, y);
        }
    }

    void Shader::setVec3f(const std::string &name, float x, float y, float z, bool bindShader)
    {
        if(bindShader)
        {
            bind();
            glUniform3f(getUniformLocation(name), x, y, z);
            unbind();
        }
        else
        {
            glUniform3f(getUniformLocation(name), x, y, z);
        }
    }

    void Shader::setVec4f(const std::string &name, float x, float y, float z, float w, bool bindShader)
    {
        if(bindShader)
        {
            bind();
            glUniform4f(getUniformLocation(name), x, y, z, w);
            unbind();
        }
        else
        {
            glUniform4f(getUniformLocation(name), x, y, z, w);
        }
    }

    void Shader::setMat4(const std::string &name, const glm::mat4 &mat, bool bindShader)
    {
        if(bindShader)
        {
            bind();
            glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(mat));
            unbind();
        }
        else
        {
            glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(mat));
        }
    }

    void Shader::checkCompileErrors(unsigned int shader, std::string type)
    {
        int success;
        char infoLog[1024];
        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                LOG_ERROR("SHADER_COMPILATION_ERROR of type: {0}\n{1}\n -- ----------------------------------------------------- ", type, infoLog);
                //std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
        else
        {
            
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                LOG_ERROR("PROGRAM_LINKING_ERROR of type: {0}\n{1}\n ------------------------------------------------------- ", type, infoLog);
                //std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
    }

}
