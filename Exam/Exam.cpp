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
            // 최적화를 했는지 선언만하고 쓰지도않으면 생성자 호출도안함
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
            // derived method에 virtual keyword를 안넣어줘도, 다형성이 잘 동작한다.
            // TODO : Bar를 상속해도, 자식의 다형성이 동작할까?
            // 가상테이블이 정확히 어떻게??

            if (count != 10)
            {
                goto LABEL; // obj1,2,3 lifetime ends, destructors are called! compilers are smart.
            }

            Bar obj4;
        }
    }
}