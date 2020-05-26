//
//  PerspecCamera.hpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/19/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef PerspecCamera_hpp
#define PerspecCamera_hpp

#include "Camera.hpp"

namespace Crude::Utils
{
    class PerspecCamera : public Camera
    {
    public:
        PerspecCamera();
        PerspecCamera(float fov, float aspectRatio, float near = 0.0f, float far = 100.f);
        ~PerspecCamera();
        
        void setProjection(float fov, float aspectRatio, float near, float far);
        void setFOV(float fov);
        void setAspectRatio(float aspectRatio);
        void setNearFarPlanes(float near, float far);
        
        inline float getFOV() const { return m_FrustrumData.FOV; }
        inline float getAspectRatio() const { return m_FrustrumData.AspectRatio; }
        inline std::pair<float, float> getNearFarPlanes() const { return {m_FrustrumData.Near, m_FrustrumData.Far}; };
        inline float getNearPlane() const { return m_FrustrumData.Near; }
        inline float getFarPlane() const { return m_FrustrumData.Far; }
        
        class PerspecFrustrumData
        {
        public:
            float FOV;
            float AspectRatio;
            float Near;
            float Far;
            
            PerspecFrustrumData(float fov, float aspectRatio, float near, float far)
            : FOV(fov), AspectRatio(aspectRatio), Near(near), Far(far)
            {
                
            }
        };
        
    protected:
        PerspecFrustrumData m_FrustrumData;
        
    protected:
        
        virtual void updateProjectionMatrix() override;
        
    };
}

#endif /* PerspecCamera_hpp */
