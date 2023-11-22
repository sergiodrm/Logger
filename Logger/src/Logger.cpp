#include "Logger.h"
#include "LoggerMacros.h"
#include <cstdio>
#include <cstdarg>

namespace Logger
{
    CLogger DefaultLogger;

    CLogger::CLogger() {}
    CLogger::~CLogger() {}

    void CLogger::ConsoleLog(ELogLevel, const char* fmt, ...)
    {
        static constexpr int MAX_MSG_LENGTH = 512;
        char msg[MAX_MSG_LENGTH];
        va_list lst;
        va_start(lst, fmt);
        int s = vsprintf(msg, fmt, lst);
        logger_check(s <= MAX_MSG_LENGTH);
        va_end(lst);
        printf("%s", msg);
    }
}