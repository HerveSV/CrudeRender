//
//  ImGuiLayer.hpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/10/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef ImGuiLayer_hpp
#define ImGuiLayer_hpp



#include "../Core/Layer.hpp"
#include "../Events/Event.h"
#include "../Events/MouseEvent.h"
#include "../Events/KeyEvent.h"
#include "../Events/ApplicationEvent.h"

namespace Crude
{
    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();
        
        void onAttach() override;
        void onDetach() override;
        void onEvent(Event& event) override;
        
        void beginFrame();
        void endFrame();
        
    private:
        bool onMouseButtonPressedEvent(MouseButtonPressedEvent& event);
        bool onMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
        bool onMouseScrolledEvent(MouseScrolledEvent &event);
        
        bool onKeyPressedEvent(KeyPressedEvent& event);
        bool onKeyReleasedEvent(KeyReleasedEvent& event);
        bool onKeyTypedEvent(KeyTypedEvent& event);
        
        bool onWindowResizeEvent(WindowResizeEvent& event);
        
    };
}


#endif /* ImGuiLayer_hpp */
