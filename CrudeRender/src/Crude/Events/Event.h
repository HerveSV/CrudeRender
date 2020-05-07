//
//  Event.h
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/6/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef Event_h
#define Event_h

#include "crudestd.hpp"
#include "../Core/Core.h"

namespace Crude
{
    
    enum class EventType
    {
        None = 0,
        WindowClosed, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased,
        MouseButtonPresses, MouseButtonReleased, MouseMoved, MouseScrolled
    };
    
    enum EventCategory
    {
        None = 0,
        EventCategoryApplication = BIT(0), //shift 1 by 0 leftwards bits
        EventCategoryInput = BIT(1),
        EventCategoryKeyboard = BIT(2),
        EventCategoryMouse = BIT(3),
        EvenCategoryMouseButton = BIT(4)
    };
    
//This macro defines standard methods related to EventType, that need overloading in all Event derived classes
#define DEFINE_EVENT_TYPE_METHODS(type) static EventType getStaticType() { return EventType::type; }\
virtual EventType getEventType() const override { return getStaticType(); }\
virtual const char* getName() const override { return #type; }
    
//This macro defines standard methods related to EventCategory, that need overloading in all Event derived classes
#define DEFINE_CATEGORY_TYPE_METHODS(category) virtual int getCategoryFlag() const override { return category; }
    
    class Event
    {
        friend class EventDispatcher;
        
    public:
        virtual EventType getEventType() const = 0;
        virtual const char* getName() const = 0;
        
        virtual int getCategoryFlag() const = 0;
        
        virtual std::string toString() const { return getName(); }
        inline bool isInCategory(EventCategory category)
        {
            return getCategoryFlag() & category;
        }
        
        inline bool isHanded() const { return m_Handled; }
        
    protected:
        bool m_Handled = false;
    };
    
    
    class EventDispatcher
    {
    private:
    public:
        EventDispatcher(Event& event)
        : m_Event(event)
        {
            
        }
        
        //FUNC will be deduced by the compiler
        template<typename T, typename FUNC>
        bool dispatch(const FUNC& func)
        {
            if (m_Event.getEventType() == T::GetStaticType())
            {
                m_Event.m_Handled = func(static_cast<T&>(m_Event));
                return true;
            }
            return false;
        }
        
    private:
        Event& m_Event;
    };
    
    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.toString();
    }
    
}


#endif /* Event_h */
