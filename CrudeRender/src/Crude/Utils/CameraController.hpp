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
#include "../Events/ApplicationEvent.h"
#include "../Events/KeyEvent.h"
#include "../Events/MouseEvent.h"
#include "../Core/Input.hpp"
#include "../Core/KeyCodes.h"
#include "../Core/MouseButtonCodes.h"
#include "../Core/Timestep.h"

namespace Crude::Utils
{
    class CameraController
    {
    public:
        CameraController() {};
        ~CameraController() {};
        
        virtual void onEvent(Event& event) = 0;
        virtual void onUpdate(Timestep deltaTime) = 0;
        
    protected:
        
        
    };
}

#endif /* CameraController_hpp */
