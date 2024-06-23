#include <iostream>
#include "Foo.h"


Foo::Foo(int x, int y)
	: mX(new int(x)),
	mY(new int(y)),
	mSubobjects
	{
	// CHECK : ��� ��ǻ� ������ ��ü�ε�, Unique Object�ϳ��� �������� ��Ȱ���Ϸ���? ��Ȱ���Ѵٸ�, ��Ȱ������ ���ϵ��� �ϴ� ������ �����ΰ�?
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