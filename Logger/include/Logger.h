#pragma once

#include "LoggerTypes.h"
#include "LoggerSink.h"

namespace Logger
{
    class CLogger
    {
    public:
        CLogger();
        ~CLogger();

        void ConsoleLog(LogLevel::ELogLevel level, const char* fmt, ...);

        void SetLevelColor(LogLevel::ELogLevel level, LogColor::ELogColor color);

    private:
        int PutHeaderLog(LogLevel::ELogLevel level, char* outStr, int count) const;

        LogColor::ELogColor m_levelColors[LogLevel::Count];
        CSink m_consoleSink;
    };

    extern CLogger DefaultLogger;
}

#define Log(level, msg) Logger::DefaultLogger.ConsoleLog(Logger::LogLevel::level, msg)
#define LogFmt(level, msg, ...) Logger::DefaultLogger.ConsoleLog(Logger::LogLevel::level, msg, __VA_ARGS__)
