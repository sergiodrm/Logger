

#include "Logger.h"
#include <math.h>

int main(int, char**)
{
    Log(Warning, "Prueba sin fmt de warning.\n");
    LogFmt(Error, "Prueba con fmt de %s %.3f\n", 
        Logger::LogLevelToStr(Logger::ELogLevel::Error), sqrtf(2.f));

    #ifdef _DEBUG
    Log(Info, "Debug\n");
    #elif defined(_NDEBUG)
    Log(Info, "NDebug\n");
    #else
    #error Not config defined
    #endif

    char buff[1024];
    for (int i = 0; i < 500; ++i)
    {
        buff[i] = (char)(i % 27 + 65);
    }
    buff[500] = 0;
    LogFmt(Info, "pruebaaaaa de error %s", buff);
    return 0;
}