//
//  OrthoCamera.hpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/14/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef OrthoCamera_hpp
#define OrthoCamera_hpp

#include "../../crudestd.hpp"
#include "Camera.hpp"

namespace Crude
{
    
    class OrthoCamera : public Camera
    {
    public:
        
        OrthoCamera(); //default constructor
        OrthoCamera(float left, float right, float bottom, float top, float near = 0.0f, float far = 0.0f);
        ~OrthoCamera();
        
        void setProjection(float left, float right, float bottom, float top, float near = 0.0f, float far = 0.0f);
        
        class OrthoFrustrumData
        {
        public:
            float Left;
            float Right;
            float Bottom;
            float Top;
            float Near;
            float Far;
            
            OrthoFrustrumData(float left, float right, float bottom, float top, float near, float far)
            : Left(left), Right(right), Bottom(bottom), Top(top), Near(near), Far(far) {};
        };
        
    protected:
        OrthoFrustrumData m_FrustrumData;
        
    protected: //just in case we want to further inherit from this class again
        
        virtual void recalculateProjectionMatrix() override;
        
        
    };
}

#endif /* OrthoCamera_hpp */
