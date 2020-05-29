//
//  RenderCommands.hpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/27/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef RenderCommands_hpp
#define RenderCommands_hpp

#include "../../crudestd.hpp"
#include "../glmHeaders.h"

namespace Crude::Utils
{
    class RenderCommands
    {
    public:
        static void setClearColour(glm::vec4 colour);
        static void setClearColour(float r, float g, float b, float a);
        static void clearColourBuffer();
        
        static void enableBlending(bool fragTrueToEnable);
        
        static void enableDepthTesting(bool flagTrueToEnable);
        static void clearDepthBuffer();
        
        static void enableWireframeMode(bool flagTrueToEnable);
        
        static void enableVSync(bool flagTrueToEnable);
        
        
        
    };
}

#endif /* RenderCommands_hpp */
