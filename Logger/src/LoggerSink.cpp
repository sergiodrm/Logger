#include "LoggerSink.h"

#include "LoggerMacros.h"
#include <cstdio>

#define COLOR_OUTPUT_BASE "\033[0;"
#define COLOR_OUTPUT_END "m"
#define COLOR_OUTPUT_DEFAULT    COLOR_OUTPUT_BASE COLOR_OUTPUT_END
#define COLOR_OUTPUT_BLACK      COLOR_OUTPUT_BASE "30" COLOR_OUTPUT_END
#define COLOR_OUTPUT_RED        COLOR_OUTPUT_BASE "31" COLOR_OUTPUT_END
#define COLOR_OUTPUT_GREEN      COLOR_OUTPUT_BASE "32" COLOR_OUTPUT_END
#define COLOR_OUTPUT_YELLOW     COLOR_OUTPUT_BASE "33" COLOR_OUTPUT_END
#define COLOR_OUTPUT_BLUE       COLOR_OUTPUT_BASE "34" COLOR_OUTPUT_END
#define COLOR_OUTPUT_MAGENTA    COLOR_OUTPUT_BASE "35" COLOR_OUTPUT_END
#define COLOR_OUTPUT_CYAN       COLOR_OUTPUT_BASE "36" COLOR_OUTPUT_END
#define COLOR_OUTPUT_WHITE      COLOR_OUTPUT_BASE "37" COLOR_OUTPUT_END

namespace Logger
{
    const char* GetOutputColor(LogColor::ELogColor color)
    {
        switch (color)
        {
        case LogColor::Black: return COLOR_OUTPUT_BLACK;
        case LogColor::Red: return COLOR_OUTPUT_RED;
        case LogColor::Green: return COLOR_OUTPUT_GREEN;
        case LogColor::Yellow: return COLOR_OUTPUT_YELLOW;
        case LogColor::Blue: return COLOR_OUTPUT_BLUE;
        case LogColor::White: return COLOR_OUTPUT_WHITE;
        case LogColor::Magenta: return COLOR_OUTPUT_MAGENTA;
        case LogColor::Cyan: return COLOR_OUTPUT_CYAN;
        default:
        break;
        }
        return COLOR_OUTPUT_DEFAULT;
    }

    void CSink::InitSink(ESinkType sinkType)
    {
        logger_check(m_type == ESinkType::None);
        m_type = sinkType;
        // TODO: file sink initialization.
    }

    void CSink::TerminateSink()
    {
        m_type = ESinkType::None;
        // TODO: file sink termination;
    }

    void CSink::PrintToOutput(LogColor::ELogColor color, const char* msg)
    {
        DispatchPrint(color, msg);
    }

    void CSink::DispatchPrint(LogColor::ELogColor color, const char* msg)
    {
        switch (m_type)
        {
        case ESinkType::Console:
        PrintToConsole(color, msg);
        break;
        case ESinkType::File:
        PrintToFile(color, msg);
        break;
        default:
        logger_check(false && "Invalid sink type at runtime.");
        }
    }

    void CSink::PrintToFile(LogColor::ELogColor, const char*)
    {
        // TODO
    }

    void CSink::PrintToConsole(LogColor::ELogColor color, const char* msg)
    {
        const char* colorStr = GetOutputColor(color);
        printf("%s%s" COLOR_OUTPUT_DEFAULT, colorStr, msg);
    }
}