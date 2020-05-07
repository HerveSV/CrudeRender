//
//  Log.hpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/6/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#ifndef Log_hpp
#define Log_hpp

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Crude
{

    class Log
    {
    public:
        static void Init();
        
        inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }
    private:
        inline static std::shared_ptr<spdlog::logger> s_Logger;
    };
    
}

#endif /* Log_hpp */
