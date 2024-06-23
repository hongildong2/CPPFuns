#include <iostream>
#include "Subone.h"

Subone::Subone(int x, int y) : mSubX(new int(x)), mSubY(new int(y)), mSubIntegers{0, }
{
	std::cout << "Subone obejct, all the members are initialized, this is constructor." << std::endl;
}

Subone::~Subone()
{
	delete mSubX;
	delete mSubY;
	// is array automatically destructed?
	// TEST : What happen if i access my members on destruction? -> subobject's destructor called first.

	std::cout << "Subone object is destructing, is this what and where did you exepected?" << std::endl;
}

void Subone::Submethod()
{
	std::cout << "Hello! this is just simple subobject! But is most base class!" << std::endl;
}