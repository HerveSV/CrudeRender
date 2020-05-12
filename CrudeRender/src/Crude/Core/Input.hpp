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
    };
}

#endif /* Input_hpp */
