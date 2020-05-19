//
//  CameraController.hpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/19/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef CameraController_hpp
#define CameraController_hpp

#include "Camera.hpp"
#include "../Events/Event.h"
#include "../Core/Timestep.h"

namespace Crude::Utils
{
    class CameraController
    {
    public:
        void onEvent(Event& event);
        void onUpdate(Timestep deltaTime);
        
    protected:
        
        
    };
}

#endif /* CameraController_hpp */
