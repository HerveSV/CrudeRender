//
//  Input.hpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/12/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef Input_hpp
#define Input_hpp

#include "../../crudestd.hpp"

namespace Crude
{
    class Input
    {
    public:
        static bool isKeyPressed(int keycode);
        static bool isMouseButtonPressed(int button);
        static std::pair<float, float> getMousePosition();
        static float getMouseX();
        static float getMouseY();
        
    protected:
        virtual bool isKeyPressedImpl(int keycode) = 0;
        virtual bool isMouseButtonPressedImpl(int button) = 0;
        virtual std::pair<float, float> getMousePositionImpl() = 0;
        virtual float getMouseXImpl() = 0;
        virtual float getMouseYImpl() = 0;
        
    };
}

#endif /* Input_hpp */
