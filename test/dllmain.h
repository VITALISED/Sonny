#include <sonny/sonny.h>
#include <Windows.h>

class Test
{
    //DECLARE_METHOD_DETAIL("aa bb cc", void(), Fun);


    struct Fun_ : public Sonny::MethodDetail<void()> 
    {
        static constexpr const char *mpacSignature = "aa bb cc";
        static constexpr const char *mpacName = "Fun";
    };


    void Fun();
};