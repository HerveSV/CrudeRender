//
//  Window.hpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/7/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include "../../crudestd.hpp"
#include "../Events/Event.h"

#include <GLFW/glfw3.h>




namespace Crude
{
    class WindowProps
    {
    public:
        std::string Title;
        uint32_t Width;
        uint32_t Height;
        
        WindowProps(const std::string& title = "cookie&dummy",
                    uint32_t width = 1280,
                    uint32_t height = 720)
        : Title(title), Width(width), Height(height)
        {
        }
    };
    
    // Interface representing a desktop system based Window
    class Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;
        
        Window(const WindowProps& props = WindowProps());
        ~Window();
        
        
        void onUpdate();
        
        
        
        uint32_t getWidth() const { return m_Data.Width; }
        uint32_t getHeight() const { return m_Data.Height; }
        std::pair<uint32_t, uint32_t> getDimensions() const { return {m_Data.Width, m_Data.Height}; };
        std::string getName() const { return m_Data.Title; }
        
        // Window attributes
        void setEventCallback(const EventCallbackFn& callback) { m_Data.EventCallback = callback; }
        void setVSync(bool enable);
        bool isVSync() const;
        
        void shutdown() const;
        
        GLFWwindow* getNativeWindow() const { return m_Window; }
        
        static Window* create(const WindowProps& props = WindowProps());
    private:
        void init(const WindowProps& props);
        void shutdown();
    private:
        struct WindowData
        {
            std::string Title;
            uint32_t Width, Height;
            bool VSync;
            
            EventCallbackFn EventCallback;
        };
        
        WindowData m_Data;
        
        GLFWwindow* m_Window;
    };
}

#endif /* Window_hpp */
