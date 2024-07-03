
#pragma once
#include "Subone.h"


namespace POCU3200Midterm
{    
    // Forward declaration for compiler to know. Naively including Bar.h distrupts preprocessor
    class Bar;
    class Foo
    {
    public:
        Foo(int x, int y);
        Foo(const Foo& other) = delete;
        Foo(const Foo&& other) noexcept;
        Foo(const Bar& other);
        // Foo(const Bar&& other);
        virtual ~Foo();

        virtual void Say() const;

    

    protected:
        // TEST : what happens below code? Bar is derived class from Foo
        // Bar mCircularSubobject; Compiler Error : unknown override specifier
        // In this way, there is no way for compiler to know how memory layout should be arranged for Foo and Bar since the have circular dependency for deciding layout


        // Referencing by pointer, since this pointer size is known and deterministic, compiler can decide how it should construct object memory
        // Bar& mHandlingCircularReference; !You cannot have vertically circularly dependent object as member!

        Subone mSubobject; // 32byte
        int* mpX;
        int* mpY;
        int* mpZ;
    };
    
}