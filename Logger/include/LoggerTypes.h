#pragma once

namespace Logger
{
    namespace LogLevel
    {
        enum ELogLevel
        {
            Info,
            Ok,
            Warning,
            Error,

            // Don't use externally
            Count
        };
        const char* ToStr(ELogLevel level);
    }

    namespace LogColor
    {
        enum ELogColor
        {
            Default,
            Black,
            Red,
            Blue,
            Green,
            Yellow,
            White,
            Magenta,
            Cyan
        };
        const char* ToStr(ELogColor color);
    }
}