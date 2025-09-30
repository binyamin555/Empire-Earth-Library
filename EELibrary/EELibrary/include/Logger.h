#pragma once

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

namespace eelib {
// LoggerManager Class
// We need to don't expose spdlog to the user, so we create a wrapper class.


class Logger {
private:
#ifdef EE_COMPILE_EE_LIBRARY
    static __declspec(dllexport) std::shared_ptr<spdlog::logger> _libLogger;
#else
    static __declspec(dllimport) std::shared_ptr<spdlog::logger> _libLogger;
#endif // EE_COMPILE_EE_LIBRARY


public:
    static void Init(const char* name);
    static void Uninit();

    template <typename... Args>
    static inline void Trace(const char* fmt, const Args&... args)
    {
        if (_libLogger == nullptr) return;
        _libLogger->trace(fmt, args...);
    }

    template <typename... Args>
    static inline void Debug(const char* fmt, const Args&... args)
    {
        if (_libLogger == nullptr) return;
        _libLogger->debug(fmt, args...);
    }

    template <typename... Args>
    static inline void Info(const char* fmt, const Args&... args)
    {
        if (_libLogger == nullptr) return;
        _libLogger->info(fmt, args...);
    }

    template <typename... Args>
    static inline void Warn(const char* fmt, const Args&... args)
    {
        if (_libLogger == nullptr) return;
        _libLogger->warn(fmt, args...);
    }

    template <typename... Args>
    static inline void Error(const char* fmt, const Args&... args)
    {
        if (_libLogger == nullptr) return;
        _libLogger->error(fmt, args...);
    }

    template <typename... Args>
    static inline void Critical(const char* fmt, const Args&... args)
    {
        if (_libLogger == nullptr) return;
        _libLogger->critical(fmt, args...);
    }
};
}