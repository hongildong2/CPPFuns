#include <iostream>
#include "Subone.h"
#include "Bar.h"

namespace POCU3200Midterm
{
    Subone::Subone(int x, int y) : mpSuboneX(new int(x)), mpSuboneY(new int(y)), mSuboneIntegers{ 0, }
    {
        // Testing polymorphism during multiple-inheritance construction
        // Baz Inherits Bar, Subone. What happens if we cast 'this' to Bar here?
        // 그냥 테스트할 필요도없이 코드 자체가 말이안됨

        std::cout << "Subone obejct, all the members are initialized, this is constructor." << std::endl;
    }

    Subone::~Subone()
    {
        delete mpSuboneX;
        delete mpSuboneY;
        // is array automatically destructed?
        // TEST : What happen if i access my members on destruction? -> subobject's destructor called first.

        std::cout << "Subone object is destructing, is this what and where did you exepected?" << std::endl;

        std::cout << "Accessing member array on destruction :: " << std::endl;

        for (int& m : mSuboneIntegers)
        {
            std::cout << m << std::endl;
        }
    }

    Subone& Subone::operator=(const Subone& other)
    {
        if (this == &other)
        {
            return *this;
        }

        delete mpSuboneX;
        mpSuboneX = new int(*other.mpSuboneX);
        delete mpSuboneY;
        mpSuboneY = new int(*other.mpSuboneY);

        mSuboneIntegers[0] = other.mSuboneIntegers[0];
        mSuboneIntegers[1] = other.mSuboneIntegers[1];

        return *this;
    }

    void Subone::Submethod()
    {
        std::cout << "Hello! this is just simple subobject! But is most base class!" << std::endl;
    }
}