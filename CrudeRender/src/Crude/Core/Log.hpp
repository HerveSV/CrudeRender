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
        static void init();
        
        inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }
    private:
        inline static std::shared_ptr<spdlog::logger> s_CoreLogger;
        inline static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
    
}


// Core log macros
#define CORE_LOG_TRACE(...)         ::Crude::Log::getCoreLogger()->trace(__VA_ARGS__)
#define CORE_LOG_INFO(...)          ::Crude::Log::getCoreLogger()->info(__VA_ARGS__)
#define CORE_LOG_WARN(...)          ::Crude::Log::getCoreLogger()->warn(__VA_ARGS__)
#define CORE_LOG_ERROR(...)         ::Crude::Log::getCoreLogger()->error(__VA_ARGS__)
#define CORE_LOG_CRITICAL(...)      ::Crude::Log::getCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define LOG_TRACE(...)         ::Crude::Log::getClientLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)          ::Crude::Log::getClientLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)          ::Crude::Log::getClientLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)         ::Crude::Log::getClientLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...)      ::Crude::Log::getClientLogger()->critical(__VA_ARGS__)

#endif /* Log_hpp */
