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
    
    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_Logger = spdlog::stdout_color_mt("Crude");
        s_Logger->set_level(spdlog::level::trace);
    }
    
    
}
