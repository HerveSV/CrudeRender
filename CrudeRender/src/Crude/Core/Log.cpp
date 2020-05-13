//
//  Log.cpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/6/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#include "Log.hpp"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Crude
{
    
    void Log::init()
    {
        //spdlog::set_pattern("%^[%T] %n: %v%$");
        //spdlog::set_pattern("[%T] [%n] [%l] %v <Thread: %t>");
        spdlog::set_pattern("[%T] [%n] [%l] %v");
        s_CoreLogger = spdlog::stdout_color_mt("CRUDE");
        s_CoreLogger->set_level(spdlog::level::trace);
        
        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace);
    }
    

    
    
}

