#include <iostream>
#include "Foo.h"

namespace POCU3200Midterm
{

    Foo::Foo(int x, int y)
        : mpX(new int(x)),
        mpY(new int(y)),
        mpZ(new int(x + y)),
        mSubobject(x, y)
    {
    }

    Foo::~Foo()
    {
        delete mpX;
        delete mpY;
        delete mpZ;
        // TEST : are mSubobjects are automatically destructed?
    }

    void Foo::Say() const
    {
        std::cout << "Hello, i am parent class! has some subobjects!" << std::endl;
    }
}