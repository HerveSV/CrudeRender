//
//  ImGuiLayer.cpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/10/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//


#include <glad/glad.h>
#include "ImGuiLayer.hpp"
#include "../Core/Application.hpp"
#include "../Core/KeyCodes.h"

#define IMGUI_IMPL_OPENGL_LOADER_GLAD
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"


/*#include "examples/imgui_impl_glfw.h"
#include "examples/imgui_impl_opengl3.h"*/
/*#include "../../../vendor/imgui/imgui.h"
#include "../../../vendor/imgui/examples/imgui_impl_opengl3.h"
#include "../../../vendor/imgui/examples/imgui_impl_glfw.h"*/

/*#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"*/
#include <GLFW/glfw3.h>





namespace Crude
{
    ImGuiLayer::ImGuiLayer()
    : Layer("ImGuiLayer")
    {
        
    }
    
    ImGuiLayer::~ImGuiLayer()
    {
        
    }
    
    void ImGuiLayer::onAttach()
    {
        //setup ImGui Context

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        
        // Setup back-end capabilities flags
        ImGuiIO& io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;         // We can honor GetMouseCursor() values (optional)
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;          // We can honor io.WantSetMousePos requests (optional, rarely used)
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
        
        // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
        ImGuiStyle& style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }
        
        
        
        io.KeyMap[ImGuiKey_Tab] = CRD_KEY_TAB;
        io.KeyMap[ImGuiKey_LeftArrow] = CRD_KEY_LEFT;
        io.KeyMap[ImGuiKey_RightArrow] = CRD_KEY_RIGHT;
        io.KeyMap[ImGuiKey_UpArrow] = CRD_KEY_UP;
        io.KeyMap[ImGuiKey_DownArrow] = CRD_KEY_DOWN;
        io.KeyMap[ImGuiKey_PageUp] = CRD_KEY_PAGE_UP;
        io.KeyMap[ImGuiKey_PageDown] = CRD_KEY_PAGE_DOWN;
        io.KeyMap[ImGuiKey_Home] = CRD_KEY_HOME;
        io.KeyMap[ImGuiKey_End] = CRD_KEY_END;
        io.KeyMap[ImGuiKey_Insert] = CRD_KEY_INSERT;
        io.KeyMap[ImGuiKey_Delete] = CRD_KEY_DELETE;
        io.KeyMap[ImGuiKey_Backspace] = CRD_KEY_BACKSPACE;
        io.KeyMap[ImGuiKey_Space] = CRD_KEY_SPACE;
        io.KeyMap[ImGuiKey_Enter] = CRD_KEY_ENTER;
        io.KeyMap[ImGuiKey_Escape] = CRD_KEY_ESCAPE;
        io.KeyMap[ImGuiKey_KeyPadEnter] = CRD_KEY_KP_ENTER;
        io.KeyMap[ImGuiKey_A] = CRD_KEY_A;
        io.KeyMap[ImGuiKey_C] = CRD_KEY_C;
        io.KeyMap[ImGuiKey_V] = CRD_KEY_V;
        io.KeyMap[ImGuiKey_X] = CRD_KEY_X;
        io.KeyMap[ImGuiKey_Y] = CRD_KEY_Y;
        io.KeyMap[ImGuiKey_Z] = CRD_KEY_Z;
        
        Application& app = Application::get();
        GLFWwindow* window = app.getWindow().getNativeWindow();
        
        // Setup Platform/Renderer bindings
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 410");

        
    }
    
    void ImGuiLayer::onDetach()
    {
        //destroy ImGui Context
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
        
    }
    
    void ImGuiLayer::onEvent(Event &event)
    {
        EventDispatcher dispatcher(event);
        dispatcher.dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(ImGuiLayer::onMouseButtonPressedEvent));
        dispatcher.dispatch<MouseButtonReleasedEvent>(BIND_EVENT_FN(ImGuiLayer::onMouseButtonReleasedEvent));
        dispatcher.dispatch<MouseScrolledEvent>(BIND_EVENT_FN(ImGuiLayer::onMouseScrolledEvent));
        
        dispatcher.dispatch<KeyPressedEvent>(BIND_EVENT_FN(ImGuiLayer::onKeyPressedEvent));
        dispatcher.dispatch<KeyReleasedEvent>(BIND_EVENT_FN(ImGuiLayer::onKeyReleasedEvent));
        dispatcher.dispatch<KeyTypedEvent>(BIND_EVENT_FN(ImGuiLayer::onKeyTypedEvent));
    }
    
    void ImGuiLayer::beginFrame()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        
    }
    
    void ImGuiLayer::endFrame()
    {
        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::get();
        io.DisplaySize = ImVec2((float)app.getWindow().getWidth(), (float)app.getWindow().getHeight());
        
        
        
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
        
    }
    
    bool ImGuiLayer::onMouseButtonPressedEvent(MouseButtonPressedEvent& event)
    {
        ImGuiIO io = ImGui::GetIO();
        return io.WantCaptureMouse;
    }
    
    bool ImGuiLayer::onMouseButtonReleasedEvent(MouseButtonReleasedEvent &event)
    {
        ImGuiIO io = ImGui::GetIO();
        return io.WantCaptureMouse;
    }
    
    bool ImGuiLayer::onMouseScrolledEvent(MouseScrolledEvent &event)
    {
        ImGuiIO io = ImGui::GetIO();
        return io.WantCaptureMouse;
    }
    
    bool ImGuiLayer::onKeyPressedEvent(KeyPressedEvent &event)
    {
        ImGuiIO io = ImGui::GetIO();
        return io.WantCaptureKeyboard;
    }
    
    bool ImGuiLayer::onKeyReleasedEvent(KeyReleasedEvent &event)
    {
        ImGuiIO io = ImGui::GetIO();
        return io.WantCaptureKeyboard;
    }
    
    bool ImGuiLayer::onKeyTypedEvent(KeyTypedEvent &event)
    {
        ImGuiIO io = ImGui::GetIO();
        return io.WantCaptureKeyboard;
    }
    
    bool ImGuiLayer::onWindowResizeEvent(WindowResizeEvent &event)
    {
        ImGuiIO io = ImGui::GetIO();
        io.DisplaySize = ImVec2(event.getWidth(), event.getHeight());
        io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
        glViewport(0, 0, event.getWidth(), event.getHeight());
        
        return false;
    }
}

