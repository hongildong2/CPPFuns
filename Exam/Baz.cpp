#include <iostream>
#include "Baz.h"

namespace POCU3200Midterm
{
    Baz::Baz(int x)
    : Bar(),
    Subone(5, 6),
    mBazX(x)
    {}

    Baz::~Baz()
    {
        // TEST: When does destructor of members are called? after this or before this?
        int hereBreak = 0 ;
    }

    int Baz::ChangeObject()
    {
        mBazX = 1;
        return mBazX;
    }

    void Baz::operator=(const Baz& rhs)
    {
        // ���ҽ� ���� ��å�� ���α׷��Ӱ� �˾Ƽ� �ؾ��Ѵ�.
        // ������
        // lhs�� this�� ������ �ִ� ���ҽ��� ��� ����
        // rhs�� ���ҽ��� ���� ����

        mBazX = rhs.mBazX;

        delete mpX;
        delete mpY;
        delete mpZ;

        mpX = new int(*rhs.mpX);
        mpY = new int(*rhs.mpY);
        mpZ = new int(*rhs.mpZ);

        mSubobject = rhs.mSubobject;

        return;
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