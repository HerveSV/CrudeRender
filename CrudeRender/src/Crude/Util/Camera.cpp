//
//  Camera.cpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/14/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#include "Camera.hpp"

namespace Crude::Utils
{

    Camera::Camera()
    : m_ViewMatrix(1.0f), m_ProjectionMatrix(1.0f), m_ViewProjectionMatrix(1.0f), m_WorldUp(0.0f, 1.0f, 0.0f), m_Front(0.0f, 0.0f, 1.0f)
    {
        
    }
    
    void Camera::setPosition(const glm::vec3 &position)
    {
        m_Position = position;
        updateViewMatrix();
    }
    
    void Camera::setWorldUp(const glm::vec3 &worldUp)
    {
        m_WorldUp = worldUp;
        updateCameraVectors();
        updateViewMatrix();
    }
    
    void Camera::setCamFront(const glm::vec3 &front)
    {
        m_Front = front;
        updateCameraVectors();
        updateViewMatrix();
    }
    
    
    void Camera::updateViewMatrix()
    {
        //glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_Position);
        //m_ViewMatrix = glm::inverse(transform);
        
        m_ViewMatrix = glm::lookAt(m_Position, m_Position + m_Front, m_Up);
        //glm::lookAt(m_Position, glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        updateViewProjectionMatrix();
    }
    
    void Camera::updateViewProjectionMatrix()
    {
        m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
    }
    
    void Camera::updateCameraVectors()
    {
        //m_Front = glm::vec3(0.0f, 0.0f, 1.0f);
        m_Right = glm::normalize(glm::cross(m_Front, m_WorldUp));
        m_Up = glm::normalize(glm::cross(m_Right, m_Front));
    }
    
}
