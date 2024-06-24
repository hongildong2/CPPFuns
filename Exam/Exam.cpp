#include <iostream>
#include "Foo.h"
#include "Bar.h"
#include "Baz.h"
#include "IBar.h"

int main()
{
    // POCUCOMP3200Midterm code snippets
    {
        using namespace POCU3200Midterm;
        std::cout << "Hello World!\n";
        int count = 0;
    LABEL:
        {
            count++;
            // ����ȭ�� �ߴ��� �����ϰ� ������������ ������ ȣ�⵵����
            Bar barObject;
            Foo fooObject(1, 3);
            Baz bazObject(4);
            Baz bazObject2(66);

            bazObject.PureVirtualMethod();

            // value downcasting is possible
            Foo valueCastedToFooFromBar = static_cast<Foo>(barObject);

            // value upcasting is impossible
            // !! Bar valueUpcastedToBarFromDowncastedBar = static_cast<Bar>(valueCastedToFooFromBar);


            Bar* pRealBar = &barObject;
            Foo* pRealFoo = &fooObject;
            Foo* pCastedToFooFromBar = static_cast<Foo*>(pRealBar);

            Bar* pUpcastedToBarFromDowncastedBar = static_cast<Bar*>(pCastedToFooFromBar);
            Bar* pUpcastedToBarFromFoo = static_cast<Bar*>(pRealFoo);
          

            Bar& refRealBar = barObject;
            Foo& refRealFoo = fooObject;
            Foo& refCastedToFooFromBar = static_cast<Foo&>(refRealBar);

            Bar& refUpcastedToBarFromDowncastedBar = static_cast<Bar&>(refCastedToFooFromBar);
            Bar& refUpcastedToBarFromFoo = static_cast<Bar&>(refRealFoo);

            // ???
            // !! Bar& refUpcastingToBarFromFooValue static_cast<Bar&>(fObj1);

            pCastedToFooFromBar->Say(); // derived method has no virtual keyword
            pRealBar->Say(); // parent method has virtual keyword
            pRealFoo->Say();
           
           
            refCastedToFooFromBar.Say();
            refRealBar.Say();
            refRealFoo.Say();
            // derived method�� virtual keyword�� �ȳ־��൵, �������� �� �����Ѵ�.
            // TODO : Bar�� ����ص�, �ڽ��� �������� �����ұ�?
            // �������̺��� ��Ȯ�� ���??

            if (count != 10)
            {
                goto LABEL; // obj1,2,3 lifetime ends, destructors are called! compilers are smart.
            }

            Bar obj4;
        }
    }
}