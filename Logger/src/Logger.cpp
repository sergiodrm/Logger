#include "Logger.h"
#include "LoggerMacros.h"
#include <cstdio>
#include <cstdarg>
#include <string>

namespace Logger
{
    CLogger DefaultLogger;

    CLogger::CLogger() 
    {
        m_levelColors[LogLevel::Info] = LogColor::Default;
        m_levelColors[LogLevel::Ok] = LogColor::Green;
        m_levelColors[LogLevel::Warning] = LogColor::Yellow;
        m_levelColors[LogLevel::Error] = LogColor::Red;

        m_consoleSink.InitSink(ESinkType::Console);
    }

    CLogger::~CLogger() 
    {
        m_consoleSink.TerminateSink();
    }

    void CLogger::SetLevelColor(LogLevel::ELogLevel level, LogColor::ELogColor color)
    {
        logger_check(level < LogLevel::Count);
        m_levelColors[level] = color;
    }

    void CLogger::ConsoleLog(LogLevel::ELogLevel level, const char* fmt, ...)
    {
        static constexpr int MAX_MSG_LENGTH = 512;
        char msg[MAX_MSG_LENGTH];

        int headerLength = PutHeaderLog(level, msg, MAX_MSG_LENGTH);

        va_list lst;
        va_start(lst, fmt);
        int s = vsprintf(&msg[headerLength], fmt, lst);
        logger_check(s <= MAX_MSG_LENGTH);
        va_end(lst);
        logger_check(level < LogLevel::Count);
        m_consoleSink.PrintToOutput(m_levelColors[level], msg);
    }

    int CLogger::PutHeaderLog(LogLevel::ELogLevel level, char* outStr, int count) const
    {
        logger_check(count > 0);
        const char* levelStr = LogLevel::ToStr(level);
        int written = sprintf(outStr, "[%s] ", levelStr);
        logger_check(written < count);
        return written;
    }
}