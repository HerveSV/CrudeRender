//
//  OrthoCameraController.cpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/20/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#include "OrthoCameraController.hpp"

#include "../Core/Application.hpp"

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
        
        LOG_TRACE("Cam pos: {0}, {1}, {2}", m_CameraPosition.x, m_CameraPosition.y, m_CameraPosition.x);
        
        
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
        
        static bool doneOnce = false;
        
        if(!doneOnce)
        {
            auto[x1, y1] = Input::getMousePosition();
            LOG_TRACE("Mouse pos: {0}, {1}", x1, y1);
            auto[x2, y2] = Application::get().getWindow().getDimensions();
            LOG_TRACE("Window dim: {0}, {1}", x2, y2);
        
            float xRatio = x1/x2;
            float yRatio = y1/y2;
            
            float camWidth = glm::abs(m_Camera.getRightPlane() - m_Camera.getLeftPlane());
            float camHeight = glm::abs(m_Camera.getTopPlane() - m_Camera.getBottomPlane());
            
            float xIncrement = camWidth * xRatio;
            float yIncrement = camHeight * yRatio;
            
            m_CameraPosition.x = xIncrement;
            m_CameraPosition.y = yIncrement;
            //float ratio[2] = {x1/x2, y1/y2};
            doneOnce = true;
        }
        //float newX = m_CameraPosition.x + (x1 - x2);
        //float newY = m_CameraPosition.y + (y1 - y2);
        //m_CameraPosition.x = x;
        //m_CameraPosition.y = y;
        //m_CameraPosition.z = m_CameraPosition.z;*/
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
