//
//  Window.cpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/7/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#include <glad/glad.h>
#include "Window.hpp"

#include "../Events/ApplicationEvent.h"
#include "../Events/MouseEvent.h"
#include "../Events/KeyEvent.h"



namespace Crude
{
    static bool GLFWinitialised = false;
    
    static void GLFWErrorCallback(int error, const char* description)
    {
        CORE_LOG_ERROR("GLFW Error ({0}): {1}", error, description);
    }
    
    Window::Window(const WindowProps& props)
    {
        init(props);
    }
    
    Window::~Window()
    {
        shutdown();
    }
    
    void Window::init(const WindowProps &props)
    {
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;
        m_Data.Title = props.Title;
        
        if(!GLFWinitialised)
        {
            int success = glfwInit();
            assert(success && "Failed to initialise GLFW!");
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
            glfwSetErrorCallback(GLFWErrorCallback);
            GLFWinitialised = true;
        }
        
        m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        
        
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        assert(status && "Failed to initialise Glad!");
        
        glfwSetWindowUserPointer(m_Window, &m_Data);
        glViewport(0, 0, m_Data.Width, m_Data.Height);
        
        CORE_LOG_INFO("OpenGL Info:");
        
        CORE_LOG_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
        CORE_LOG_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
        CORE_LOG_INFO("  Version: {0}", glGetString(GL_VERSION));
        
        //Setting glfw callbacks
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            data.Width = width;
            data.Height = height;
            
            WindowResizeEvent event(width, height);
            data.EventCallback(event);
        });
    
        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            
            WindowCloseEvent event;
            data.EventCallback(event);
        });
        
        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            
            switch(action)
            {
                case GLFW_PRESS:
                {
                    KeyPressedEvent event(key, 0);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(key);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key, 1);
                    data.EventCallback(event);
                    break;
                }
            }
                               
        });
        
        glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            KeyTypedEvent event(keycode);
            data.EventCallback(event);
            
        });
        
        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            
            switch(action)
            {
                case GLFW_PRESS:
                {
                    MouseButtonPressedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonReleasedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
            }
                                       
        });
        
        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
        {
             WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
             
             MouseMovedEvent event(xpos, ypos);
             data.EventCallback(event);
             
        });
        
        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            
            MouseScrolledEvent event(xoffset, yoffset);
            data.EventCallback(event);
        });
                           
                           
                           
        
    }
    
    void Window::shutdown()
    {
        glfwDestroyWindow(m_Window);
    }
    
    void Window::onUpdate()
    {
        glfwSwapBuffers(m_Window);
        glfwPollEvents();
    }
    
    void Window::setVSync(bool enable)
    {
        glfwSwapInterval(enable);
        m_Data.VSync = enable;
    }
    
    
    Window* Window::create(const WindowProps& props)
    {
        return new Window(props);
    }
}
