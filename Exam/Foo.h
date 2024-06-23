#pragma once
#include "Subone.h"

class Foo
{
public:
	Foo(int x, int y);
	virtual ~Foo();
	virtual void Say() const;

protected:
	Subone mSubobjects[5];
	int* mX;
	int* mY;
};

