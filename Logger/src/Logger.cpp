#include "Logger.h"
#include "LoggerMacros.h"
#include <cstdio>
#include <cstdarg>
#include <string>

#define COLOR_OUTPUT_DEFAULT "\033[0m"
#define COLOR_OUTPUT_BLACK "\033[0;30m"
#define COLOR_OUTPUT_RED "\033[0;30m"
#define COLOR_OUTPUT_GREEN "\033[0;30m"
#define COLOR_OUTPUT_YELLOW "\033[0;30m"

namespace Logger
{
    CLogger DefaultLogger;

    CLogger::CLogger() {}
    CLogger::~CLogger() {}

    void CLogger::ConsoleLog(ELogLevel level, const char* fmt, ...)
    {
        static constexpr int MAX_MSG_LENGTH = 512;
        char msg[MAX_MSG_LENGTH];

        int headerLength = PutHeaderLog(level, msg, MAX_MSG_LENGTH);

        va_list lst;
        va_start(lst, fmt);
        int s = vsprintf(&msg[headerLength], fmt, lst);
        logger_check(s <= MAX_MSG_LENGTH);
        va_end(lst);
        printf("%s", msg);
    }

    int CLogger::PutHeaderLog(ELogLevel level, char* outStr, int count) const
    {
        logger_check(count > 0);
        const char* levelStr = LogLevelToStr(level);
        int written = sprintf(outStr, "[%s] ", levelStr);
        logger_check(written < count);
        return written;
    }
}