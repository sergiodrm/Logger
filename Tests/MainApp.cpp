
#include "Logger.h"
#include <math.h>
#include <string.h>

/**
 * TESTS
*/

bool TestLevels()
{
    Log(Info, "Hola\n");
    Log(Warning, "Hola\n");
    Log(Error, "Hola\n");
    Log(Ok, "Hola\n");
    return true;
}

bool TestChannels()
{
    return true;
}

bool TestMaxBufferSize()
{
    return true;
}

void HandleTestError()
{
    // todo
    Log(Error, "No input test found.\n");
}

bool DispatchTest(const char* testName)
{
    if (!strcmp(testName, "TestLevels"))
        return TestLevels();
    if (!strcmp(testName, "TestChannels"))
        return TestChannels();
    if (!strcmp(testName, "TestMaxBufferSize"))
        return TestMaxBufferSize();
    return false;
}


int main(int argc, char** argv)
{
    int result = 0;
    if (argc >= 2)
    {
        for (int i = 1; i < argc; ++i)
        {
            if (!DispatchTest(argv[i]))
            {
                HandleTestError();
                result = -1;   
                break;
            }
        }
    }
    else
    {
        Log(Error, "Empty input arguments.\n");
        result = -1;
    }

    return result;
}