#include <iostream>
#include "Foo.h"


Foo::Foo(int x, int y)
	: mX(new int(x)),
	mY(new int(y)),
	mSubobjects
	{
	// CHECK : 얘네 사실상 동일한 개체인데, Unique Object하나만 만들어놓고 재활용하려나? 재활용한다면, 재활용하지 못하도록 하는 조건은 무엇인가?
		Subone(0,0),
		Subone(0,0),
		Subone(0,0),
		Subone(0,0),
		Subone(0,0)
	}
{}

Foo::~Foo()
{
	delete mX;
	delete mY;
	// are mSubobjects are automatically destructed?
}

void Foo::Say() const
{
	std::cout << "Hello, i am parent class! has some subobjects!" << std::endl;
}