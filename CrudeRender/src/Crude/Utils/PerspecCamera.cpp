//
//  PerspecCamera.cpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/19/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#include "PerspecCamera.hpp"

namespace Crude::Utils
{
    
    
    PerspecCamera::PerspecCamera(float fov, float aspectRatio, float near, float far)
    : Camera(), m_FrustrumData(fov, aspectRatio, near, far)
    {
        updateProjectionMatrix();
    }
    
    PerspecCamera::~PerspecCamera()
    {
        
    }
    
    void PerspecCamera::setProjection(float fov, float aspectRatio, float near, float far)
    {
        m_FrustrumData = PerspecFrustrumData(fov, aspectRatio, near, far);
        updateProjectionMatrix();
    }
    
    void PerspecCamera::setFOV(float fov)
    {
        m_FrustrumData.FOV = fov;
        updateProjectionMatrix();
    }
    
    void PerspecCamera::setAspectRatio(float aspectRatio)
    {
        m_FrustrumData.AspectRatio = aspectRatio;
        updateProjectionMatrix();
    }
    
    void PerspecCamera::setNearFarPlanes(float near, float far)
    {
        m_FrustrumData.Near = near;
        m_FrustrumData.Far = far;
        updateProjectionMatrix();
    }
    
    void PerspecCamera::updateProjectionMatrix()
    {
        m_ProjectionMatrix = glm::perspective(m_FrustrumData.FOV, m_FrustrumData.AspectRatio, m_FrustrumData.Near, m_FrustrumData.Far);
        updateViewProjectionMatrix();
    }
    
}
