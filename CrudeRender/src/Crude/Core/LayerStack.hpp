//
//  LayerStack.hpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/6/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef LayerStack_hpp
#define LayerStack_hpp

#include "../../crudestd.hpp"
#include "Layer.hpp"
#include <vector>

namespace Crude
{
    class LayerStack
    {
    public:
        LayerStack();
        ~LayerStack();
        
        void pushLayer(Layer* layer);
        void popLayer(Layer* layer);
        
        void pushOverlay(Layer* overlay);
        void popOverlay(Layer* overlay);
        
        std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
        std::vector<Layer*>::iterator end() { return m_Layers.end(); }
        
    private:
        std::vector<Layer*> m_Layers;
        uint32_t m_InsertLayerIndex = 0;
        
    };
}

#endif /* LayerStack_hpp */
