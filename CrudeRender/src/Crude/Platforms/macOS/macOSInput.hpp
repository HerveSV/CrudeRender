//
//  macOSInput.hpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 6/13/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef macOSInput_hpp
#define macOSInput_hpp

#include "../../Core/Input.hpp"

namespace Crude
{
    class macOSInput : public Input
    {
    protected:
        virtual bool isKeyPressedImpl(int keyCode) override;
        virtual bool isMouseButtonPressedImpl(int button) override;
        virtual std::pair<float, float> getMousePositionImpl() override;
        virtual float getMouseXImpl() override;
        virtual float getMouseYImpl() override;
    };
}

#endif /* macOSInput_hpp */
