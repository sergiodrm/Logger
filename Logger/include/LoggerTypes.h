#pragma once

namespace Logger
{
    enum class ELogLevel
    {
        Info,
        Ok,
        Warning,
        Error
    };
    const char* LogLevelToStr(ELogLevel level);
}