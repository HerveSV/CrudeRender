//
//  MouseEvent.h
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/6/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef MouseEvent_h
#define MouseEvent_h

#include "Event.h"

namespace Crude
{
    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(float xPos, float yPos)
        : m_MouseX(xPos), m_MouseY(yPos)
        {
            
        }
        
        std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
            return ss.str();
        }
        
        inline float getX() const { return m_MouseX; }
        inline float getY() const { return m_MouseY; }
        
        DEFINE_CATEGORY_TYPE_METHODS(EventCategoryInput | EventCategoryMouse)
        DEFINE_EVENT_TYPE_METHODS(MouseMoved)
        
    private:
        float m_MouseX, m_MouseY;
        
    };
    
    class MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(float xOffset, float yOffset)
        : m_OffsetX(xOffset), m_OffsetY(yOffset)
        {
            
        }
        
        std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: "<< m_OffsetX << ", " << m_OffsetY;
            return ss.str();
        }
        
        inline float getX() const { return m_OffsetX; }
        inline float getY() const { return m_OffsetY; }
        
        DEFINE_CATEGORY_TYPE_METHODS(EventCategoryInput | EventCategoryMouse)
        DEFINE_EVENT_TYPE_METHODS(MouseScrolled)
        
    private:
        float m_OffsetX, m_OffsetY;
        
    };
    
    class MouseButtonEvent : public Event
    {
    public:
        inline int getButton() const { return m_Button; }
        
        DEFINE_CATEGORY_TYPE_METHODS(EventCategoryInput | EventCategoryMouse)
        
    protected:
        MouseButtonEvent(int button)
        : m_Button(button)
        {
            
        }
        
        int m_Button;
    };
    
    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(int button)
        : MouseButtonEvent(button)
        {
            
        }
        
        std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressed: " << m_Button;
            return ss.str();
        }
        
        DEFINE_EVENT_TYPE_METHODS(MouseButtonPressed)
    };
    
    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int button)
        : MouseButtonEvent(button)
        {
            
        }
        
        std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleased: " << m_Button;
            return ss.str();
        }
        
        DEFINE_EVENT_TYPE_METHODS(MouseButtonReleased)
    };
    
    
}

#endif /* MouseEvent_h */
