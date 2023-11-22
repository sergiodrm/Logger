#pragma once

#include "LoggerTypes.h"

namespace Logger
{
    class CLogger
    {
    public:
        CLogger();
        ~CLogger();

        void ConsoleLog(ELogLevel level, const char* fmt, ...);

    private:
        int PutHeaderLog(ELogLevel level, char* outStr, int count) const;
    };

    extern CLogger DefaultLogger;
}

#define Log(level, msg) Logger::DefaultLogger.ConsoleLog(Logger::ELogLevel::level, msg)
#define LogFmt(level, msg, ...) Logger::DefaultLogger.ConsoleLog(Logger::ELogLevel::level, msg, __VA_ARGS__)
