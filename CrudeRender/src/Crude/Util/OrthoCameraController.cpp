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
    OrthoCameraController::OrthoCameraController(float aspectRatio, float zoom)
    : m_AspectRatio(aspectRatio), m_ZoomLevel(zoom), m_Camera(-aspectRatio * zoom, aspectRatio * zoom, -zoom, zoom)
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
        
        m_Camera.setPosition(m_CameraPosition);
        
        if(m_FixTranslationSpeedToZoom)
        {
            m_CameraTranslationSpeed = m_ZoomLevel;
        }
    }
    
    bool OrthoCameraController::onWindowResizeEvent(WindowResizeEvent &event)
    {
        //LOG_TRACE("WindowResizeEvent received by OrthoCameraController");
        
        m_AspectRatio = (float)event.getWidth() / (float)event.getHeight();
        m_Camera.setProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
        return false;
    }
    
    bool OrthoCameraController::onMouseScrolledEvent(MouseScrolledEvent &event)
    {
        //LOG_TRACE("MouseScrolledEvent received by OrthoCameraController");
        
        m_ZoomLevel -= event.getYOffset() * m_CameraZoomSpeed;
        m_ZoomLevel = std::max(m_ZoomLevel, m_CameraMaxZoom);
        m_Camera.setProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
        return false;
    }
}
