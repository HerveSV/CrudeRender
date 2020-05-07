//
//  KeyEvent.h
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/6/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef KeyEvent_h
#define KeyEvent_h

#include "Event.h"

namespace Crude
{
    class KeyEvent : public Event
    {
    public:
        inline int getKeyCode() const { return m_KeyCode; }
        
        DEFINE_CATEGORY_TYPE_METHODS(EventCategoryInput | EventCategoryKeyboard)

    protected:
        KeyEvent(int keycode)
        : m_KeyCode(keycode)
        {
            
        }
        int m_KeyCode;
    };

    class KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int keycode, int repeatCount)
        : KeyEvent(keycode), m_RepeatCount(repeatCount)
        {
            
        }
        
        std::string toString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << "(" << m_RepeatCount<< ")";
            return ss.str();
        }
        
        inline int getRepeatCount() const {return m_RepeatCount;}
        
        DEFINE_EVENT_TYPE_METHODS(KeyPressed)
        
    private:
        int m_RepeatCount;
    };
    
    class KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(int keycode)
        : KeyEvent(keycode)
        {
            
        }
        
        std::string toString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }
        
        DEFINE_EVENT_TYPE_METHODS(KeyReleased)
        
    };
};




#endif /* KeyEvent_h */
