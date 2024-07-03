#include <cassert>
#include <iostream>
#include "Subone.h"
#include "Bar.h"

namespace POCU3200Midterm
{
    Subone::Subone(int x, int y) : mpSuboneX(new int(x)), mpSuboneY(new int(y)), mSuboneIntegers{ 0, }
    {
        // Testing polymorphism during multiple-inheritance construction
        // Baz Inherits Bar, Subone. What happens if we cast 'this' to Bar here?
        // �׳� �׽�Ʈ�� �ʿ䵵���� �ڵ� ��ü�� ���̾ȵ�

        std::cout << "Subone obejct, all the members are initialized, this is constructor." << std::endl;
    }

	Subone::Subone(const Subone& other) : mpSuboneX(new int(*other.mpSuboneX)) , mpSuboneY(new int(*other.mpSuboneY)), mSuboneIntegers {other.mSuboneIntegers[0], other.mSuboneIntegers[1]}
	{

	}

	Subone::Subone(Subone&& other) noexcept
	: mpSuboneX(other.mpSuboneX),
	mpSuboneY(other.mpSuboneY),
	mSuboneIntegers {other.mSuboneIntegers[0], other.mSuboneIntegers[1]}
	{
		// resource hand over
		// make sure that you do not acquire invalid resource!
		assert(mpSuboneX != nullptr && mpSuboneY != nullptr);

		// You should make "other" to be valid since you just handed over its resource
		// ��Ģ�� �־���Ѵ�. �ٵ� �������� ���ҽ� �Ѱܹ޴����� �Ѱ��ִ��� valid�ϰ� ������ִ°� �´°� ����.
		// �ϴ� ��üũ�ؼ� ��Ȱ���ϰų� ���� �̷��� �����ϰų�
		// �Ѱܹ޴����� �ƴ϶�, ���� Ŭ���� �ڵ�ϱ� ĸ��ȭ�� �ȴ�.. ��� �̻��� �޼��常�� ������ �������� move constructor, move assignment operator�� �Ἥ ���� ��Ѹ��� �ϸ� �ȵȴ�.
		other.mpSuboneX = new int();
		other.mpSuboneY = new int();
		for (auto& el : other.mSuboneIntegers)
		{
			el = 0;
		}
	}

    Subone::~Subone()
    {
		if (mpSuboneX != nullptr)
		{
			delete mpSuboneX;
		}

		if (mpSuboneY != nullptr)
		{
			delete mpSuboneY;
		}
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

	void Subone::operator=(Subone&& other) noexcept
	{
		if (this == &other)
		{
			return; // is this possible?
		}

		// release my resource first
		delete mpSuboneX;
		delete mpSuboneY;

		// shallow copy (acquisition resource ownership) of resource
		assert (other.mpSuboneX != nullptr && other.mpSuboneY != nullptr);
		mpSuboneX = other.mpSuboneX;
		mpSuboneY = other.mpSuboneY;
		mSuboneIntegers[0] = other.mSuboneIntegers[0];
		mSuboneIntegers[1] = other.mSuboneIntegers[1];

		// make "other" valid
		other.mpSuboneX = new int();
		other.mpSuboneY = new int();
		for (auto& el : other.mSuboneIntegers)
		{
			el = 0;
		}
	}

    void Subone::Submethod()
    {
        std::cout << "Hello! this is just simple subobject! But is most base class!" << std::endl;
    }
}