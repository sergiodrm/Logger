#pragma once

#include <cassert>

#define expand(x) (x)
#define logger_check(exp) assert(expand(exp))
#define logger_debug_break() __debugbreak()

