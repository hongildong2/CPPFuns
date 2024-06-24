
#pragma once
#include "Subone.h"

namespace POCU3200Midterm
{
    class Foo
    {
    public:
        Foo(int x, int y);
        virtual ~Foo();
        virtual void Say() const;

    protected:
        // TEST : what happens below code? Bar is derived class from Foo
        // Bar mCircularSubobject; Compiler Error : unknown override specifier

        Subone mSubobject; // 32byte
        int* mpX;
        int* mpY;
        int* mpZ;
    };
}