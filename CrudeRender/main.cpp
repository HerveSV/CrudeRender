//
//  main.cpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/6/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//


#include "src/crudestd.hpp"
#include "src/CrudeRender.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"




class MainLayer : public Crude::Layer
{
public:
    MainLayer()
    : Layer("Main0") {}
    
    virtual void onUpdate() override
    {
        glClearColor(1.0f, 0.4f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        //CORE_LOG_TRACE("Yeet, it's updating");
    }
    
    virtual void onImGuiRender() override
    {
        //ImGui::ShowUserGuide();
        static int great;
        ImGui::Begin("Hello there");
        ImGui::InputInt("Great int", &great);
        ImGui::End();
        if(m_showDemo)
        {
            ImGui::ShowDemoWindow(&m_showDemo);
        }
        
    }
    
    virtual void onEvent(Crude::Event& event) override
    {
        Crude::EventDispatcher dispatcher(event);
        dispatcher.dispatch<Crude::KeyTypedEvent>(BIND_EVENT_FN(MainLayer::windowClose));
    }
    
private:
    bool windowClose(Crude::KeyTypedEvent& event)
    {
        LOG_TRACE("Key not captured");
        return true;
    }
    
    bool m_showDemo = true;
};

class LolLayer : public Crude::Layer
{
public:
    LolLayer()
    : Layer("Lol0") {}
    
    virtual void onUpdate() override
    {
        //CORE_LOG_TRACE("Yeet, it's permeating the first layer");
    }
    
    virtual void onEvent(Crude::Event& event) override
    {
        Crude::EventDispatcher dispatcher(event);
        dispatcher.dispatch<Crude::WindowCloseEvent>(BIND_EVENT_FN(LolLayer::windowClose));
    }
    
private:
    bool windowClose(Crude::WindowCloseEvent& event)
    {
        LOG_TRACE("Passed through Once");
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Crude::Application app;
    
    app.pushLayer(new MainLayer);
    app.pushLayer(new LolLayer);
    
    
    /*std::shared_ptr<spdlog::logger> logger = spdlog::stdout_color_mt("CRUDE");
    logger->set_level(spdlog::level::trace);
    logger->trace("Hey {0}", "bruh");*/
    //Crude::Log::init();
    //Crude::Log::getClientLogger()->trace("hey {0}", "bruh");
    app.Run();
    return 0;
}
