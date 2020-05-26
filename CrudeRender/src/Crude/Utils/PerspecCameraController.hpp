//
//  PerspecCameraController.hpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/21/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef PerspecCameraController_hpp
#define PerspecCameraController_hpp

#include "CameraController.hpp"
#include "PerspecCamera.hpp"

namespace Crude::Utils
{
    
    //All angles here are handled in radians
    class PerspecCameraController : public CameraController
    {
    public:
        PerspecCameraController(float aspectRatio, float fov);
        ~PerspecCameraController();
        
        virtual void onEvent(Event& event) override;
        virtual void onUpdate(Timestep deltaTime) override;
        
        void setTranslationSpeed(float speed) { m_CameraTranslationSpeed = speed; };
        inline float getTranslationSpeed() const { return m_CameraTranslationSpeed; }
        
        void setBaseFOV(float fov);
        inline float getBaseFOV() const { return m_BaseFOV; }
        
        //Using this is PREFERRED to using the zoom bounding functions
        void setFOVBounds(float minFOV, float maxFOV);
        
        inline std::pair<float, float> getFovBounds() const { return {m_BaseFOV/m_CameraMinZoom, m_BaseFOV/m_CameraMaxZoom}; }
        
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
        
        inline PerspecCamera& getCamera() { return m_Camera; }
    protected:
        bool onWindowResizeEvent(WindowResizeEvent& event);
        bool onMouseScrolledEvent(MouseScrolledEvent& event);
        
       
        
    protected:
        PerspecCamera m_Camera;
        
        glm::vec3 m_CameraPosition = {0.0f, 0.0f, 0.0f};
        
        float m_ZoomLevel = 1.0f;
        float m_AspectRatio;
        float m_BaseFOV; //This is the default fov when zoom is set to 0, since our zoom system uses fov
        
       
        float m_CameraMaxZoom = 4.5f;
        float m_CameraMinZoom = 0.5f;
        float m_CameraZoomSpeed = 0.15f;
        float m_CameraTranslationSpeed = 5.0f;
        
    private:
        bool m_ScaleTranslationSpeedWithZoom = false;
        
        /* WARNING:
         
         The members and methods below were for the linear zoom system and will not work with the current implementation of the camera zoom. They will be left here in case I decide to invest more time into the using the perspective camera zoom.
         *//*
        float m_BaseFOV; //The default FOV for when zoom is 1.0, this is primarily used for calculations
        float m_ScaledFOV; //actual FOV with zoom calculations taken into account
        float m_DistToTarget;
        float m_BaseViewSize;
        void updateZoomFactors();
            /**/
    };
}

#endif /* PerspecCameraController_hpp */
