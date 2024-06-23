#pragma once
class Subone
{
public:
	Subone(int x, int y);
	virtual ~Subone();
	void Submethod();

private:
	int* mSubX;
	int* mSubY;
	int mSubIntegers[10]; // member array elements are also subobject. need initialization action.
};

