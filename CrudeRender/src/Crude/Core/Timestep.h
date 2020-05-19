//
//  Timestep.h
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/19/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef Timestep_h
#define Timestep_h

namespace Crude
{
    class Timestep
    {
    public:
        Timestep(float time = 0.0f)
        : m_Time(time)
        {
        }
        
        operator float() const { return m_Time; }
        
        float GetSeconds() const { return m_Time; }
        float GetMilliseconds() const { return m_Time * 1000.0f; }
    private:
        float m_Time;
    };
}


#endif /* Timestep_h */
