
#include <cstdio>
#include <cstdarg>

namespace Logger
{
    void Log(const char* fmt, ...)
    {
        char msg[512];
        va_list lst;
        va_start(lst, fmt);
        int s = vsprintf(msg, fmt, lst);
        va_end(lst);
        printf("%s", msg);
    }
}