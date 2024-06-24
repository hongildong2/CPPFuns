#include <iostream>
#include "Subone.h"
namespace POCU3200Midterm
{
    Subone::Subone(int x, int y) : mpSuboneX(new int(x)), mpSuboneY(new int(y)), mSuboneIntegers{ 0, }
    {
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

    void Subone::Submethod()
    {
        std::cout << "Hello! this is just simple subobject! But is most base class!" << std::endl;
    }
}