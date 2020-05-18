//
//  OrthoCamera.cpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/14/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#include "OrthoCamera.hpp"

namespace Crude
{
    OrthoCamera::OrthoCamera()
    : m_FrustrumData(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
    {
        
    }
    
    OrthoCamera::OrthoCamera(float left, float right, float bottom, float top, float near, float far)
    : m_FrustrumData(left, right, bottom, top, near, far)
    {
        recalculateProjectionMatrix();
    }
    
    OrthoCamera::~OrthoCamera()
    {
        
    }
    
    void OrthoCamera::setProjection(float left, float right, float bottom, float top, float near, float far)
    {
        m_FrustrumData = OrthoFrustrumData(left, right, bottom, top, near, far);
        recalculateProjectionMatrix();
    }
    
    void OrthoCamera::recalculateProjectionMatrix()
    {
        m_ProjectionMatrix = glm::ortho(m_FrustrumData.Left, m_FrustrumData.Right, m_FrustrumData.Bottom, m_FrustrumData.Top, m_FrustrumData.Near, m_FrustrumData.Far);
        
        recalculateViewProjectionMatrix();
    }
    
    
}
