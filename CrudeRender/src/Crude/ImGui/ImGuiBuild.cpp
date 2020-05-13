//
//  ImGuiBuild.cpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/13/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

/*
 This .cpp file tells the compile to compile the following files.
 They are necessary for ImGui usage
 */


#define IMGUI_IMPL_OPENGL_LOADER_GLAD
#include "imgui.cpp"
#include "imgui_widgets.cpp"
#include "imgui_demo.cpp"
#include "imgui_draw.cpp"
#include "examples/imgui_impl_opengl3.cpp"
#include "examples/imgui_impl_glfw.cpp"
