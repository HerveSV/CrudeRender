//
//  MainLayer.cpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/11/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#include "MainLayer.hpp"

MainLayer::MainLayer()
: Layer("Main0")
{
    
}

void MainLayer::onUpdate()
{
    glClearColor(1.0f, 0.4f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    if(Crude::Input::isKeyPressed(CRD_KEY_LEFT_CONTROL))
    {
        LOG_TRACE("0 is pressed!");
    }
    //CORE_LOG_TRACE("Yeet, it's updating");
}

void MainLayer::onImGuiRender()
{
    //ImGui::ShowUserGuide();
    //ImGui::ShowDemoWindow();
    ImGui::ShowCrudeDockSpace();
    ImGui::ShowDemoWindow();
    /*ImGui::Begin("Test1");
     ImGui::End();
     ImGui::Begin("Test2");
     ImGui::End();*/
    
}

void MainLayer::onEvent(Crude::Event& event)
{
    Crude::EventDispatcher dispatcher(event);
    dispatcher.dispatch<Crude::KeyTypedEvent>(BIND_EVENT_FN(MainLayer::onKeyTypedEvent));
}


bool MainLayer::onKeyTypedEvent(Crude::KeyTypedEvent& event)
{
    LOG_TRACE("Key not captured");
    return true;
}
