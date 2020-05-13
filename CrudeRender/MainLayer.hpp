//
//  MainLayer.hpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/11/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef MainLayer_hpp
#define MainLayer_hpp

#include "src/CrudeRender.h"
#include "src/CrudeUtil.h"

class MainLayer : public Crude::Layer
{
    
public:
    MainLayer();
    
    virtual void onUpdate() override;
    
    virtual void onImGuiRender() override;
    
    virtual void onEvent(Crude::Event& event) override;
    
private:
    bool onKeyTypedEvent(Crude::KeyTypedEvent& event);
    
    bool m_showDemo = true;
};

#endif /* MainLayer_hpp */
