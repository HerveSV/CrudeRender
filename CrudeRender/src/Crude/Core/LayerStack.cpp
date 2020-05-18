//
//  LayerStack.cpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/6/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#include "LayerStack.hpp"


namespace Crude
{
    LayerStack::LayerStack()
    {
        
    }
    
    LayerStack::~LayerStack()
    {
        for(Layer* layer : m_Layers)
        {
            delete layer;
        }
    }
    
    void LayerStack::pushLayer(Layer *layer)
    {
        m_Layers.emplace(begin() + m_InsertLayerIndex, layer);
        ++m_InsertLayerIndex;
        layer->onAttach();
    }
    
    void LayerStack::popLayer(Layer *layer)
    {
        auto it = std::find(begin(), begin() + m_InsertLayerIndex, layer);
        if(it != begin() + m_InsertLayerIndex) //to find out if layer exists, within the bounds we set
        {
            layer->onDetach();
            m_Layers.erase(it);
            --m_InsertLayerIndex;
        }
    }
    
    
    
    void LayerStack::pushOverlay(Layer *overlay)
    {
        m_Layers.emplace_back(overlay);
        overlay->onAttach();
    }
    
    void LayerStack::popOverlay(Layer *overlay)
    {
        auto it = std::find(begin() + m_InsertLayerIndex, end(), overlay);
        if(it != end()) //to find if the overlay layer exists, within the bounds we set
        {
            overlay->onDetach();
            m_Layers.erase(it);
        }
    }
}
