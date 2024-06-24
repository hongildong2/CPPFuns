#include <iostream>
#include "Baz.h"

namespace POCU3200Midterm
{
    Baz::Baz(int x)
    : Bar(),
    mBazX(x)
    {}

    Baz::~Baz()
    {
        // TEST: When does destructor of members are called? after this or before this?
        int hereBreak = 0 ;
    }

    void Baz::Say() const
    {
        Bar::Say();
    }
    
    void Baz::BarVirtualMethod()
    {
        std::cout << "I am Baz, overrided Bar's virtual method" << std::endl;
    }

    void Baz::PureVirtualMethod()
    {
        std::cout << "I implemented pure virtual method of interface!" << std::endl;
    }

}