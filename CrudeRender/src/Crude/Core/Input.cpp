//
//  Input.cpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/12/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#include "Input.hpp"
#include "Application.hpp"
#include "GLFW/glfw3.h"

#ifdef CRD_PLATFORM_MACOS
    #include "../Platforms/macOS/macOSInput.hpp"
#endif

namespace Crude
{
    bool Input::isKeyPressed(int keycode)
    {
        GLFWwindow* window = Application::get().getWindow().getNativeWindow();
        auto state = glfwGetKey(window, keycode);
        return (state == GLFW_PRESS || state == GLFW_REPEAT);
    }
    
    bool Input::isMouseButtonPressed(int button)
    {
        GLFWwindow* window = Application::get().getWindow().getNativeWindow();
        auto state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
    }
    
    std::pair<float, float> Input::getMousePosition()
    {
        GLFWwindow* window = Application::get().getWindow().getNativeWindow();
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        return { (float)xpos, (float)ypos }; //returning as a pair
    }
    
    float Input::getMouseX()
    {
        auto[x, y] = getMousePosition(); //C++17 feature, allows you to name the individual vars in the array
        return x;
    }
    
    float Input::getMouseY()
    {
        auto[x, y] = getMousePosition();
        return y;
    }
}
