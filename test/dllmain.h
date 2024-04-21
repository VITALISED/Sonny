#include <sonny/sonny.h>
#include <Windows.h>

void Fish();

class Test
{
    DECLARE_METHOD_DETAIL("aa bb cc", void(Test*), Fun);

    void Fun();
};