//
//  ApplicationEvent.h
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/6/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef ApplicationEvent_h
#define ApplicationEvent_h

#include "Event.h"

namespace Crude
{
    
    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(uint32_t width, uint32_t height)
        : m_Width(width), m_Height(height)
        {
            
        }
        
        virtual std::string toString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: "<< m_Width << "(width) " << m_Height << "(height)";
            return ss.str();
        }
        
        inline uint32_t getWidth() const { return m_Width; }
        inline uint32_t getHeight() const { return m_Height; }
        
        DEFINE_CATEGORY_TYPE_METHODS(EventCategoryApplication)
        DEFINE_EVENT_TYPE_METHODS(WindowResize)
        
    private:
        uint32_t m_Width, m_Height;
    };
    
    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent()
        {
            
        }
        
        DEFINE_CATEGORY_TYPE_METHODS(EventCategoryApplication)
        DEFINE_EVENT_TYPE_METHODS(WindowClose)
    };
    
    class AppTickEvent : public Event
    {
    public:
        AppTickEvent()
        {
            
        }
        
        DEFINE_CATEGORY_TYPE_METHODS(EventCategoryApplication)
        DEFINE_EVENT_TYPE_METHODS(AppTick)
    };
    
    class AppUpdateEvent : public Event
    {
    public:
        AppUpdateEvent()
        {
            
        }
        
        DEFINE_CATEGORY_TYPE_METHODS(EventCategoryApplication)
        DEFINE_EVENT_TYPE_METHODS(AppUpdate)
    };
    
    class AppRenderEvent : public Event
    {
    public:
        AppRenderEvent()
        {
            
        }
        
        DEFINE_CATEGORY_TYPE_METHODS(EventCategoryApplication)
        DEFINE_EVENT_TYPE_METHODS(AppRender)
    };
    
}

#endif /* ApplicationEvent_h */
