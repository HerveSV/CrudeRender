//
//  Application.hpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/6/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef Application_hpp
#define Application_hpp
#include "../../crudestd.hpp"

#include "Core.h"
#include "../Events/Event.h"
#include "../Events/ApplicationEvent.h"
#include "LayerStack.hpp"
#include "../ImGui/ImGuiLayer.hpp"
#include "Window.hpp"

namespace Crude
{
    class Application
    {
    public:
        Application();
        ~Application();
        
        void Run();
        
        void onEvent(Event& event);
        
        void pushLayer(Layer* layer);
        void pushOverlay(Layer* overlay);
        
        inline Window& getWindow() const { return *m_Window; }
        inline static Application& get() { return *s_Instance; }
    private:
        bool onWindowCloseEvent(WindowCloseEvent& event);
        
        LayerStack m_LayerStack;
        
        ImGuiLayer* m_ImGuiLayer;
        
        bool m_Running;
        std::unique_ptr<Window> m_Window;
        
        inline static Application* s_Instance = nullptr;
    };
}

#endif /* Application_hpp */
