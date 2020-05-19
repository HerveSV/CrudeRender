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

namespace Crude::Utils
{
    
    class Camera
    {
    public:
        //virtual void setProjection() = 0;
        void setPosition(const glm::vec3& position);
        const inline glm::vec3& getPosition() {return m_Position; };
        
        void setWorldUp(const glm::vec3& worldUp);
        void setCamFront(const glm::vec3& front);
        
        inline const glm::mat4& getViewMatrix() const { return m_ViewMatrix; }
        inline const glm::mat4& getProjectionMatrix() const { return m_ProjectionMatrix; }
        inline const glm::mat4& getViewProjectionMatrix() const { return m_ViewProjectionMatrix; }
        
    protected:
        glm::vec3 m_WorldUp = {0.0f, 0.0f, 0.0f};
        glm::vec3 m_Right   = {0.0f, 0.0f, 0.0f};
        glm::vec3 m_Front   = {0.0f, 0.0f, 0.0f};
        glm::vec3 m_Up      = {0.0f, 0.0f, 0.0f};
        
        glm::vec3 m_Position = {0.0f, 0.0f, 0.0f};
        glm::mat4 m_ViewMatrix;
        glm::mat4 m_ProjectionMatrix;
        glm::mat4 m_ViewProjectionMatrix;
        
    protected:
        Camera();
        
        void updateViewMatrix();
        void updateViewProjectionMatrix();
        
        virtual void updateProjectionMatrix() = 0;
        virtual void updateCameraVectors();
        
        
    };
}

#endif /* Camera_hpp */
