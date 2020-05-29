//
//  Controller.hpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/27/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp


#include "../../crudestd.hpp"
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
    class Controller
    {
    public:
        virtual void onEvent(Event& event) = 0;
        virtual void onUpdate(Timestep deltaTime) = 0;
    
    protected:
        Controller() {};
        ~Controller() {};
    
    };
}

#endif /* Controller_hpp */
