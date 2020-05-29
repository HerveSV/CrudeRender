//
//  CameraController.hpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/19/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef CameraController_hpp
#define CameraController_hpp

#include "Controller.hpp"
#include "Camera.hpp"


namespace Crude::Utils
{
    class CameraController : public Controller
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
