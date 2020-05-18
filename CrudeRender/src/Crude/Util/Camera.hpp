//
//  Camera.hpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/14/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include "../../crudestd.hpp"

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Crude
{
    
    class Camera
    {
    public:
        //virtual void setProjection() = 0;
        void setPosition(const glm::vec3& position) { m_Position = position; recalculateViewMatrix(); };
        const inline glm::vec3& getPosition() {return m_Position; };
        
        inline const glm::mat4& getViewMatrix() const { return m_ViewMatrix; }
        inline const glm::mat4& getProjectionMatrix() const { return m_ProjectionMatrix; }
        inline const glm::mat4& getViewProjectionMatrix() const { return m_ViewProjectionMatrix; }
        
    protected:
        glm::vec3 m_Position;
        glm::mat4 m_ViewMatrix;
        glm::mat4 m_ProjectionMatrix;
        glm::mat4 m_ViewProjectionMatrix;
        
    protected:
        Camera() : m_Position(0.0f), m_ViewMatrix(1.0f), m_ProjectionMatrix(1.0f), m_ViewProjectionMatrix(1.0f) {};
            
        inline void recalculateViewProjectionMatrix() { m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewProjectionMatrix; }
        
        void recalculateViewMatrix();
            
        virtual void recalculateProjectionMatrix() = 0;
            
        
        
        
        
        
    };
}

#endif /* Camera_hpp */
