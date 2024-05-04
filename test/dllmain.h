#include <Windows.h>
#include <sonny/sonny.h>

void Fish();

class Test
{
public:
#define Test__Fun_ARGS 1
    DECLARE_METHOD_DETAIL("aa bb cc", void(Test *), Fun);

    void Fun();
};