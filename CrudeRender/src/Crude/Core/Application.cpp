//
//  Application.cpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/6/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#include "Application.hpp"
#include "../../crudestd.hpp"

#include "../Events/KeyEvent.h"
#include "../Events/MouseEvent.h"

#include "GLFW/glfw3.h"

namespace Crude
{

    Application::Application()
    :m_Running(true)
    {
        if(s_Instance == nullptr)
        {
            Log::init();
        }
        
        assert(!s_Instance && "Crude::Application class(or any of it's children) instanciated more than once");
        s_Instance = this;
        
        m_Window = std::unique_ptr<Window>(Window::create());
        m_Window->setEventCallback(BIND_EVENT_FN(Application::onEvent));
        
        m_ImGuiLayer = new ImGuiLayer();
        pushOverlay(m_ImGuiLayer);

    }
    
    Application::~Application()
    {
    
    }
    
    void Application::onEvent(Event &event)
    {
        EventDispatcher dispatcher(event);
        dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::onWindowCloseEvent));
        
        //CORE_LOG_TRACE(event);
        
        for(auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
        {
            if(event.isHandled())
            {
                break;
            }
            (*--it)->onEvent(event);
        }
    }
    
    void Application::Run()
    {
        while(m_Running)
        {
            for(Layer* layer : m_LayerStack)
            {
                layer->onUpdate();
            }
            
            m_ImGuiLayer->beginFrame();
            for(Layer* layer: m_LayerStack)
            {
                layer->onImGuiRender();
            }
            m_ImGuiLayer->endFrame();
        
            m_Window->onUpdate();
        }
        
    }
    
    void Application::pushLayer(Layer *layer)
    {
        m_LayerStack.pushLayer(layer);
        CORE_LOG_TRACE("Pushed layer: {0}", layer->getName());
    }
    
    void Application::pushOverlay(Layer *overlay)
    {
        m_LayerStack.pushOverlay(overlay);
        CORE_LOG_TRACE("Pushed overlay: {0}", overlay->getName());
    }
    
    
    
    
    bool Application::onWindowCloseEvent(WindowCloseEvent& event)
    {
        //CORE_LOG_TRACE("Arrives here");
        m_Running = false;
        return true;
    }
    
    
}
