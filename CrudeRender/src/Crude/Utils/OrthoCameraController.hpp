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
        OrthoCameraController(float aspectRatio);
        
        virtual void onEvent(Event& event) override;
        virtual void onUpdate(Timestep deltaTime) override;
        
        void setTranslationSpeed(float speed) { m_CameraTranslationSpeed = speed; };
        inline float getTranslationSpeed() const { return m_CameraTranslationSpeed; }
        
        //Zoom works as a multiplier where 1.0f will signify NO zoom, and for anything greater or smaller to scale the view up or down respectively
        void setZoom(float zoom);
        inline float getZoom() const { return m_ZoomLevel; }
        
        void setMaxZoom(float maxZoom) { m_CameraMaxZoom = maxZoom; }
        inline float getMaxZoom() const { return m_CameraMaxZoom; }
        
        void setMinZoom(float minZoom) { m_CameraMinZoom = minZoom; }
        inline float getMinZoom() const { return m_CameraMinZoom; }
        
        void setZoomSpeed(float zoomSpeed) { m_CameraZoomSpeed = zoomSpeed; }
        inline float getZoomSpeed() const { return m_CameraZoomSpeed; }
        
        //if true, translation speed will lower when zoomed in and vice versa
        void setScaleTranslationSpeedWithZoom(float flagTrueIfScale) { m_ScaleTranslationSpeedWithZoom = flagTrueIfScale; }
        
        inline OrthoCamera& getCamera() { return m_Camera; }
    protected:
        bool onWindowResizeEvent(WindowResizeEvent& event);
        bool onMouseScrolledEvent(MouseScrolledEvent& event);
        
    protected:
        OrthoCamera m_Camera;
        
    public://temporary
        glm::vec3 m_CameraPosition = {0.0f, 0.0f, 0.0f};
    protected:
        float m_ZoomLevel = 1.0f;
        float m_AspectRatio;
        
        float m_CameraMaxZoom = 3.0f;
        float m_CameraMinZoom = 0.15f;
        float m_CameraZoomSpeed = 0.15f;
        float m_CameraTranslationSpeed = 3.0f;
        
    private:
        bool m_ScaleTranslationSpeedWithZoom = false;
        
    };
}

#endif /* OrthoCameraController_hpp */
