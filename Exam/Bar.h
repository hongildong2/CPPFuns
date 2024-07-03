#pragma once
#include "Foo.h"
namespace POCU3200Midterm
{
    class Bar :
        public Foo
    {
    public:
        Bar();
        Bar(const Bar& other) = default;

        // will destructor of Foo called? parent destructor is virtual but derived one is not.
        // = Yes. base class Foo is defined as polymorphic, any derived class from it is also polymorphic class. Compiler handles that behavior automaticallly
        // virtual Ű����� ���� base object�� �ѹ��� �ٿ��൵ �ǳ�? -> �Ҹ��ڴ� ������ ������������ �ƴ϶� ������� �� �����ϹǷ� �ƴ�����?
        ~Bar();
        
        void Say() const override;
        virtual void BarVirtualMethod();
    private:
        int mU;
        int mV;
        int mW;
        int mY;
    };
}
