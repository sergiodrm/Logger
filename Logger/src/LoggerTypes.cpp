
#include "LoggerTypes.h"
#include "LoggerMacros.h"

namespace Logger
{
    const char* LogLevel::ToStr(ELogLevel level)
    {
        switch (level)
        {
            case Info: return "Info";
            case Ok: return "Ok";
            case Warning: return "Warning";
            case Error: return "Error";
            case Count: return "Count";
        }
        return "";
    }

    const char* LogColor::ToStr(ELogColor color)
    {
        switch (color)
        {
            case Black: return "Black";
            case Red: return "Red";
            case Green: return "Green";
            case Blue: return "Blue";
            case Yellow: return "Yellow";
            case White: return "White";
            case Magenta: return "Magenta";
            case Cyan: return "Cyan";
            case Default: return "Default";
            default: break;
        }
        return "";
    }
}