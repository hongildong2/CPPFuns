#include <iostream>
#include "Bar.h"

// if there is no default constructor for base class exists, you should explicitly call one of the constructor to intialize base class.
Bar::Bar()
	: Foo(3, 4),
	mU(0),
	mV(1),
	mW(2),
	mY(3)
{ }

Bar::~Bar()
{
	std::cout << "derived class Bar based on Foo is now desctructing" << std::endl;
	
	// TEST : what if we call base class part members or method? even virtua one? what happens?
	// Foo::Say();
	std::cout << "Now printing destructed base class member in derived class destructor : " << *Foo::mX << std::endl;
}

void Bar::Say() const
{
	// What action do i expect to happen?
	std::cout << "I didn't put virtual keyword in class definition." << std::endl;
}

