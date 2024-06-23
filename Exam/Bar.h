#pragma once
#include "Foo.h"

class Bar :
    public Foo
{
public:
	Bar();
	~Bar(); // will destructor of Foo called? parent destructor is virtual but derived one is not.
	void Say() const override;
private:
	int mU;
	int mV;
	int mW;
	int mY;
};

