//
//  Layer.hpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/6/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef Layer_hpp
#define Layer_hpp

#include "../../crudestd.hpp"
#include "Core.h"
#include "../Events/Event.h"
#include <string>

namespace Crude
{
    class Layer
    {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer();
        
    
        virtual void onAttach() {};
        virtual void onDetach() {};
        virtual void onUpdate() {};
        virtual void onImGuiRender() {};
        virtual void onEvent(Event& event) {};
        
        inline const std::string& getName() const { return m_DebugName; }
    private:
        const std::string m_DebugName;
    };
}

#endif /* Layer_hpp */
