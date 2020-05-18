//
//  Camera.cpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/14/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#include "Camera.hpp"

namespace Crude
{
    
    void Camera::recalculateViewMatrix()
    {
        //glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_Position);
        //m_ViewMatrix = glm::inverse(transform);
        
        m_ViewMatrix = glm::lookAt(m_Position, glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        recalculateViewProjectionMatrix();
    }
}
