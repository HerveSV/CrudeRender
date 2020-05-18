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
    
    virtual void onAttach() override;
    
    virtual void onUpdate() override;
    
    virtual void onImGuiRender() override;
    
    virtual void onEvent(Crude::Event& event) override;
    
private:
    bool onKeyTypedEvent(Crude::KeyTypedEvent& event);
    
    
private:
    
    
    Crude::OrthoCamera cam;
    //Crude::VertexBuffer* m_vbo;
    
    glm::vec3 m_Pos = glm::vec3(0.0f);
    Crude::VertexArray m_vao;
    std::unique_ptr<Crude::Shader> m_Shader;
    
    bool m_showDemo = true;
};

#endif /* MainLayer_hpp */
