//
//  RenderCommands.cpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/27/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#include "RenderCommands.hpp"
#include "../GLlibs.h"

namespace Crude::Utils
{
    
    void RenderCommands::setClearColour(glm::vec4 colour)
    {
        glClearColor(colour.r, colour.g, colour.b, colour.a);
    }
    
    void RenderCommands::setClearColour(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a);
    }
    
    void RenderCommands::clearColourBuffer()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }
    
    void RenderCommands::enableDepthTesting(bool flagTrueToEnable)
    {
        if(flagTrueToEnable)
        {
            glEnable(GL_DEPTH_TEST);
        }
        else
        {
            glDisable(GL_DEPTH_TEST);
        }
    }
    
    void RenderCommands::clearDepthBuffer()
    {
        glClear(GL_DEPTH_BUFFER_BIT);
    }
    
    void RenderCommands::enableWireframeMode(bool flagTrueToEnable)
    {
        if(flagTrueToEnable)
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        }
        else
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }
    }
    
    void RenderCommands::enableVSync(bool flagTrueToEnable)
    {
        glfwSwapInterval(flagTrueToEnable);
    }
    
    void RenderCommands::enableBlending(bool fragTrueToEnable)
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
    
}
