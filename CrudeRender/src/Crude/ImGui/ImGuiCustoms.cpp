//
//  ImGuiCustoms.cpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/13/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#include "ImGuiCustoms.hpp"
#include "imgui.h"

namespace ImGui
{
    void ShowCrudeDockSpace()
    {
        
        static ImGuiDockNodeFlags dockspaceFlags = ImGuiDockNodeFlags_None;
        //It would be confusing to have two docking targets within each other
        ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoDocking;
        
        {
            ImGuiViewport* viewport = ImGui::GetMainViewport();
            ImGui::SetNextWindowPos(viewport->GetWorkPos());
            ImGui::SetNextWindowSize(viewport->GetWorkSize());
            ImGui::SetNextWindowViewport(viewport->ID);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        }
        
        windowFlags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
        windowFlags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
        
        windowFlags |= ImGuiWindowFlags_NoBackground;
        dockspaceFlags |= ImGuiDockNodeFlags_PassthruCentralNode | ImGuiDockNodeFlags_NoDockingInCentralNode;
        
        
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
        ImGui::Begin("Crude DockSpace", NULL, windowFlags);
        ImGui::PopStyleVar();
        ImGui::PopStyleVar(2);
        
        ImGuiIO& io = ImGui::GetIO();
        //if(!io.ConfigDockingWithShift) { io.ConfigDockingWithShift = true; }
        if(io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
        {
            ImGuiID dockspaceID = ImGui::GetID("MyDockSpace");
            ImGui::DockSpace(dockspaceID, ImVec2(0.0f, 0.0f), dockspaceFlags);
        }
        else
        {
            CORE_LOG_WARN("Docking disabled - enable using ImGuiConfigFlags_DockingEnable bitflag");
        }
        ImGui::End();
    }
}
