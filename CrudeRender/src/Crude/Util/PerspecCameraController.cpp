//
//  PerspecCameraController.cpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/21/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#include "PerspecCameraController.hpp"

namespace Crude::Utils
{
    PerspecCameraController::PerspecCameraController(float aspectRatio, float fov)
    : m_Camera(fov, aspectRatio), m_BaseFOV(fov), m_AspectRatio(aspectRatio), m_ZoomLevel(1.0f)
    {
       
    }
    
    PerspecCameraController::~PerspecCameraController()
    {
        
    }
    
    void PerspecCameraController::onEvent(Event& event)
    {
        EventDispatcher dispatcher(event);
        
        dispatcher.dispatch<WindowResizeEvent>(BIND_EVENT_FN(PerspecCameraController::onWindowResizeEvent));
        dispatcher.dispatch<MouseScrolledEvent>(BIND_EVENT_FN(PerspecCameraController::onMouseScrolledEvent));
    }
    
    void PerspecCameraController::onUpdate(Timestep deltaTime)
    {
        if(m_ScaleTranslationSpeedWithZoom)
        {
            if(Input::isKeyPressed(CRD_KEY_RIGHT))
            {
                m_CameraPosition.x -= (m_CameraTranslationSpeed/m_ZoomLevel) * deltaTime; //the x-axis seems to be inverted
            }
            if(Input::isKeyPressed(CRD_KEY_LEFT))
            {
                m_CameraPosition.x += (m_CameraTranslationSpeed/m_ZoomLevel) * deltaTime;
            }
            
            if(Input::isKeyPressed(CRD_KEY_UP))
            {
                m_CameraPosition.z += (m_CameraTranslationSpeed/m_ZoomLevel) * deltaTime;
            }
            if(Input::isKeyPressed(CRD_KEY_DOWN))
            {
                m_CameraPosition.z -= (m_CameraTranslationSpeed/m_ZoomLevel) * deltaTime;
            }
            
            if(Input::isKeyPressed(CRD_KEY_SPACE))
            {
                m_CameraPosition.y += (m_CameraTranslationSpeed/m_ZoomLevel) * deltaTime;
            }
            if(Input::isKeyPressed(CRD_KEY_LEFT_CONTROL) || Input::isKeyPressed(CRD_KEY_RIGHT_CONTROL))
            {
                m_CameraPosition.y -= (m_CameraTranslationSpeed/m_ZoomLevel) * deltaTime;
            }
            
        }
        else
        {
            if(Input::isKeyPressed(CRD_KEY_RIGHT))
            {
                m_CameraPosition.x -= (m_CameraTranslationSpeed) * deltaTime; //the x-axis seems to be inverted
            }
            if(Input::isKeyPressed(CRD_KEY_LEFT))
            {
                m_CameraPosition.x += (m_CameraTranslationSpeed) * deltaTime;
            }
            
            if(Input::isKeyPressed(CRD_KEY_UP))
            {
                m_CameraPosition.z += (m_CameraTranslationSpeed) * deltaTime;
            }
            if(Input::isKeyPressed(CRD_KEY_DOWN))
            {
                m_CameraPosition.z -= (m_CameraTranslationSpeed) * deltaTime;
            }
            
            if(Input::isKeyPressed(CRD_KEY_SPACE))
            {
                m_CameraPosition.y += (m_CameraTranslationSpeed) * deltaTime;
            }
            if(Input::isKeyPressed(CRD_KEY_LEFT_CONTROL) || Input::isKeyPressed(CRD_KEY_RIGHT_CONTROL))
            {
                m_CameraPosition.y -= (m_CameraTranslationSpeed) * deltaTime;
            }
        }
        
        /*LOG_INFO("Aspect Ratio: {0}", m_AspectRatio);
        LOG_INFO("Zoom: {0}", m_ZoomLevel);
        LOG_INFO("Base FOV: {0}", glm::degrees(m_BaseFOV));
        LOG_INFO("Real FOV: {0}", glm::degrees(m_BaseFOV/m_ZoomLevel));*/
        
        m_Camera.setPosition(m_CameraPosition);
    }
    
    bool PerspecCameraController::onWindowResizeEvent(WindowResizeEvent &event)
    {
        m_AspectRatio = (float)event.getWidth() / (float)event.getHeight();
        m_Camera.setAspectRatio(m_AspectRatio);
        return false;
    }
    
    bool PerspecCameraController::onMouseScrolledEvent(MouseScrolledEvent &event)
    {
        m_ZoomLevel += event.getYOffset() * m_CameraZoomSpeed;
        setZoom(m_ZoomLevel);
        return false;
    }
    
    void PerspecCameraController::setBaseFOV(float fov)
    {
        float tempFOV = m_BaseFOV;
        m_BaseFOV = fov;
        setFOVBounds(tempFOV/m_CameraMinZoom, tempFOV/m_CameraMaxZoom); //to recalibrate the min and max FOV scalars so that the FOV bounds stay the same.
    }
    
    void PerspecCameraController::setFOVBounds(float minFOV, float maxFOV)
    {
        m_CameraMaxZoom = m_BaseFOV/minFOV; //this may sound confusing, but the smallest FOV will lead to the greatest zoom effect
        m_CameraMinZoom = m_BaseFOV/maxFOV; //think of it, it makes complete logical sense!
        
        setZoom(m_ZoomLevel); //to fit m_ZoomLevel into the new bounds we just defined
        
    }
    
    void PerspecCameraController::setZoom(float zoom)
    {
        m_ZoomLevel = std::min(zoom, m_CameraMaxZoom);
        m_ZoomLevel = std::max(m_ZoomLevel, m_CameraMinZoom);
        
        m_Camera.setFOV(m_BaseFOV/m_ZoomLevel);
    }
    
  
    
    
    
    
    
    
    
    /*
    void PerspecCameraController::updateZoomFactors()
    {
        m_DistToTarget = m_Camera.getNearPlane();
        m_BaseViewSize = glm::tan(m_BaseFOV) * m_DistToTarget;
        m_ScaledFOV = glm::atan(m_BaseViewSize * m_ZoomLevel, m_DistToTarget) * 2;
    }
     /**/
}
