#pragma once

#include <spdlog/common.h>
#include <spdlog/logger.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/spdlog.h>

#include <memory>

#include "spdlog/sinks/stdout_color_sinks.h"

#ifdef ENABLE_DEBUG_LOGGING
static constexpr auto LOG_LEVEL = spdlog::level::debug;
#else
static constexpr auto LOG_LEVEL = spdlog::level::info;
#endif

class Logger {
   public:
    template <typename... Args>
    static void Debug(const spdlog::format_string_t<Args...>& fmt, Args&&... args) {
        Get()->debug(fmt, std::forward<Args>(args)...);
    }

    template <typename... Args>
    static void Info(const spdlog::format_string_t<Args...>& fmt, Args&&... args) {
        Get()->info(fmt, std::forward<Args>(args)...);
    }

    template <typename... Args>
    static void Error(const spdlog::format_string_t<Args...>& fmt, Args&&... args) {
        Get()->error(fmt, std::forward<Args>(args)...);
    }

    template <typename... Args>
    static void Warn(const spdlog::format_string_t<Args...>& fmt, Args&&... args) {
        Get()->warn(fmt, std::forward<Args>(args)...);
    }

    static std::shared_ptr<spdlog::logger> Get() {
        static std::shared_ptr<spdlog::logger> instance = CreateLogger();
        return instance;
    }

   private:
    static std::shared_ptr<spdlog::logger> CreateLogger() {
        auto logger = spdlog::stdout_color_mt("yeenboy");
        logger->set_pattern("[%Y-%m-%d %H:%M:%S] [%^%l%$] %v");
        logger->set_level(LOG_LEVEL);
        logger->flush_on(LOG_LEVEL);

        return logger;
    }
};

#define LOG_DEBUG(msg, ...) Logger::Get()->debug(msg, __VA_ARGS__);