#pragma once
#include "Foo.h"
namespace POCU3200Midterm
{
    class Bar :
        public Foo
    {
    public:
        Bar();
        Bar(const Bar& other) = default;

        // will destructor of Foo called? parent destructor is virtual but derived one is not.
        // = Yes. base class Foo is defined as polymorphic, any derived class from it is also polymorphic class. Compiler handles that behavior automaticallly
        // virtual 키워드는 가장 base object에 한번만 붙여줘도 되나? -> 소멸자는 어차피 다형적동작이 아니라 순차대로 다 동작하므로 아닐지도?
        ~Bar();
        
        void Say() const override;
        virtual void BarVirtualMethod();
    private:
        int mU;
        int mV;
        int mW;
        int mY;
    };
}
