#pragma once

#include "LoggerTypes.h"

namespace Logger
{

    enum class ESinkType
    {
        None,
        Console,
        File
    };

    class CSink
    {
    public:
        CSink() = default;

        void InitSink(ESinkType sinkType);
        void TerminateSink();

        inline ESinkType GetType() const { return m_type; }

        void PrintToOutput(LogColor::ELogColor color, const char* msg);
    protected:
        void DispatchPrint(LogColor::ELogColor color, const char* msg);

        void PrintToFile(LogColor::ELogColor color, const char* msg);
        void PrintToConsole(LogColor::ELogColor color, const char* msg);

    private:
        ESinkType m_type = ESinkType::None;
    };
}