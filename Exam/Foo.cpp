#include <iostream>
#include "Foo.h"
#include "Bar.h"

namespace POCU3200Midterm
{

    Foo::Foo(int x, int y)
        : mpX(new int(x)),
        mpY(new int(y)),
        mpZ(new int(x + y)),
        mSubobject(x, y)
    {

        // this does not call polymorphic virtual method of Bar
        // In constructor, polymorphism does not work
        Bar* pDerivedThis = static_cast<Bar*>(this);

        pDerivedThis->Say();

    }
    
    Foo::Foo(const Foo&& other) noexcept
    : mpX(other.mpX),
    mpY(other.mpY),
    mpZ(other.mpZ),
    mSubobject(other.mSubobject)
    {
        
    } 



    Foo::Foo(const Bar& other)
        : mpX(nullptr),
        mpY(nullptr),
        mpZ(nullptr),
        mSubobject(1, 3)
    {
    }

    Foo::~Foo()
    {

        delete mpX;
        delete mpY;
        delete mpZ;
        // TEST : are mSubobjects are automatically destructed?
        // yes, they are potentially invoked

        

    }

    void Foo::Say() const
    {
        std::cout << "Hello, i am parent class! has some subobjects!" << std::endl;
    }
}