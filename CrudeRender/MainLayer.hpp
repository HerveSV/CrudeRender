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
#include "src/CrudeRenderUtils.h"




class MainLayer : public Crude::Layer
{
    
public:
    MainLayer();
    
    virtual void onAttach() override;
    
    virtual void onDetach() override;
    
    virtual void onUpdate(Crude::Timestep deltaTime) override;
    
    virtual void onImGuiRender() override;
    
    virtual void onEvent(Crude::Event& event) override;
    
private:
    bool onKeyTypedEvent(Crude::KeyTypedEvent& event);
    bool onWindowResizeEvent(Crude::WindowResizeEvent& event);
    
    
private:

    Crude::Utils::OrthoCameraController m_OCamController;
    Crude::Utils::PerspecCameraController m_PCamController;
    //Crude::Utils::OrthoCamera* m_OrthoCam;
    //Crude::Utils::PerspecCamera* m_PerspecCam;
    //Crude::Utils::VertexBuffer* m_vbo;
    
    glm::vec3 m_Pos = glm::vec3(0.0f);
    Crude::Utils::VertexArray m_vao;
    //std::unique_ptr<Crude::Utils::Shader> m_Shader;
    Crude::Utils::Shader m_FlatColourShader, m_TextureShader;
    
    Crude::Utils::TextureLibrary m_TextureLibrary;
    //Crude::Utils::Texture *m_ContainerTexture, *m_FaceTexture, *m_BlendTexture;
    
    bool m_showDemo = true;
};

#endif /* MainLayer_hpp */
