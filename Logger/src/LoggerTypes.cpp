
#include "LoggerTypes.h"
#include "LoggerMacros.h"

namespace Logger
{
    const char* LogLevelToStr(ELogLevel level)
    {
        switch (level)
        {
            case ELogLevel::Info: return "Info";
            case ELogLevel::Ok: return "Ok";
            case ELogLevel::Warning: return "Warning";
            case ELogLevel::Error: return "Error";
        }
        return "";
    }
}