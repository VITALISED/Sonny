#include <sonny/sonny.h>
#include <Windows.h>

class Test
{
    DECLARE_METHOD_DETAIL("aa bb cc", void(), Fun);
    void Fun();
};