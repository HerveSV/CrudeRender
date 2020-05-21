//
//  OrthoCameraController.hpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/20/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef OrthoCameraController_hpp
#define OrthoCameraController_hpp

#include "CameraController.hpp"
#include "OrthoCamera.hpp"

namespace Crude::Utils
{
    class OrthoCameraController : public CameraController
    {
    public:
        OrthoCameraController(float aspectRatio, float zoom = 1.0f);
        
        virtual void onEvent(Event& event) override;
        virtual void onUpdate(Timestep deltaTime) override;
        
        void setTranslationSpeed(float speed) { m_CameraTranslationSpeed = speed; };
        inline float getTranslationSpeed() const { return m_CameraTranslationSpeed; }
        
        void setMaxZoom(float maxZoom) { m_CameraMaxZoom = maxZoom; } //zoom works truer to how it's implemented, 1/ZoomLevel will give you the intuitive zoom approach
        inline float getMaxZoom() const { return m_CameraMaxZoom; }
        
        void setZoomSpeed(float zoomSpeed) { m_CameraZoomSpeed = zoomSpeed; }
        inline float getZoomSpeed() const { return m_CameraZoomSpeed; }
        
        inline OrthoCamera& getCamera() { return m_Camera; }
    protected:
        bool onWindowResizeEvent(WindowResizeEvent& event);
        bool onMouseScrolledEvent(MouseScrolledEvent& event);
        
    protected:
        OrthoCamera m_Camera;
        
        glm::vec3 m_CameraPosition = {0.0f, 0.0f, 0.0f};
        float m_ZoomLevel = 1.0f;
        float m_AspectRatio;
        
        float m_CameraMaxZoom = 0.25f;
        float m_CameraZoomSpeed = 0.15f;
        float m_CameraTranslationSpeed = 5.0f;
        
    private:
        bool m_FixTranslationSpeedToZoom = true;
        
    };
}

#endif /* OrthoCameraController_hpp */
