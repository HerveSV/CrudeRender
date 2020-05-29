//
//  OrthoCameraController.cpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/20/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#include "OrthoCameraController.hpp"

namespace Crude::Utils
{
    OrthoCameraController::OrthoCameraController(float aspectRatio)
    : m_AspectRatio(aspectRatio), m_ZoomLevel(1.0f), m_Camera(-aspectRatio / 1.0f, aspectRatio / 1.0f, -1.0f, 1.0f)
    {
        
    }
    
    void OrthoCameraController::onEvent(Event &event)
    {
        EventDispatcher dispatcher(event);
        
        dispatcher.dispatch<WindowResizeEvent>(BIND_EVENT_FN(OrthoCameraController::onWindowResizeEvent));
        dispatcher.dispatch<MouseScrolledEvent>(BIND_EVENT_FN(OrthoCameraController::onMouseScrolledEvent));
    }
    
    void OrthoCameraController::onUpdate(Timestep deltaTime)
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
                m_CameraPosition.y += (m_CameraTranslationSpeed/m_ZoomLevel) * deltaTime;
            }
            if(Input::isKeyPressed(CRD_KEY_DOWN))
            {
                m_CameraPosition.y -= (m_CameraTranslationSpeed/m_ZoomLevel) * deltaTime;
            }
            
        }
        else
        {
            if(Input::isKeyPressed(CRD_KEY_RIGHT))
            {
                m_CameraPosition.x -= m_CameraTranslationSpeed * deltaTime; //the x-axis seems to be inverted
            }
            if(Input::isKeyPressed(CRD_KEY_LEFT))
            {
                m_CameraPosition.x += m_CameraTranslationSpeed * deltaTime;
            }
            
            if(Input::isKeyPressed(CRD_KEY_UP))
            {
                m_CameraPosition.y += m_CameraTranslationSpeed * deltaTime;
            }
            if(Input::isKeyPressed(CRD_KEY_DOWN))
            {
                m_CameraPosition.y -= m_CameraTranslationSpeed * deltaTime;
            }
        }
        
        m_Camera.setPosition(m_CameraPosition);
        
        
    }
    
    bool OrthoCameraController::onWindowResizeEvent(WindowResizeEvent &event)
    {
        //LOG_TRACE("WindowResizeEvent received by OrthoCameraController");
        
        m_AspectRatio = (float)event.getWidth() / (float)event.getHeight();
        m_Camera.setProjection(-m_AspectRatio / m_ZoomLevel, m_AspectRatio / m_ZoomLevel, -1.0f/m_ZoomLevel, 1.0f/m_ZoomLevel);
        return false;
    }
    
    bool OrthoCameraController::onMouseScrolledEvent(MouseScrolledEvent &event)
    {
        //LOG_TRACE("MouseScrolledEvent received by OrthoCameraController");
        
        /*auto[x, y]  = Input::getMousePosition();
        m_CameraPosition.x = x;
        m_CameraPosition.y = y;
        m_CameraPosition.z = m_CameraPosition.z;*/
        //m_Camera.setPosition({x, y, m_Camera.getPosition().z});
        
        
        m_ZoomLevel += event.getYOffset() * m_CameraZoomSpeed;
        m_ZoomLevel = std::min(m_ZoomLevel, m_CameraMaxZoom);
        m_ZoomLevel = std::max(m_ZoomLevel, m_CameraMinZoom);
        m_Camera.setProjection(-m_AspectRatio / m_ZoomLevel, m_AspectRatio / m_ZoomLevel, -1.0f/m_ZoomLevel, 1.0f/m_ZoomLevel);
        return false;
    }
    
    void OrthoCameraController::setZoom(float zoom)
    {
        m_ZoomLevel = std::min(zoom, m_CameraMaxZoom);
        m_ZoomLevel = std::min(m_ZoomLevel, m_CameraMinZoom);
        m_Camera.setProjection(-m_AspectRatio / m_ZoomLevel, m_AspectRatio / m_ZoomLevel, -1.0f/m_ZoomLevel, 1.0f/m_ZoomLevel);
    }
}
