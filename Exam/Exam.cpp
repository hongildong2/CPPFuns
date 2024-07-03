#include <iostream>
#include "Foo.h"
#include "Bar.h"
#include "Baz.h"
#include "IBar.h"
#include "AlgoHeader.h"

int main()
{

	// Algorithm
	{
		using namespace Algorithm;

		solve11052();
	}


	// POCUCOMP3200Midterm code snippets
	/*
	{


		using namespace POCU3200Midterm;

		Baz diastervirtual(1);


		{
			Baz* baz1 = new Baz(2);
			Baz baz2(5);
			*baz1 = baz2;


			baz1 = baz1;
		}

		{
			std::string a = "hello world";
			std::string a2 = "hello world";

			auto pp = a.c_str() == a2.c_str();

			std::string b = "hello world 512";

			std::string c;
			auto cc = a == b;

			c = a;

			auto ccc = a == c;

			b.pop_back();
			b.pop_back();
			b.pop_back();
			b.pop_back();

			auto cc2 = a == b;
			auto pp2 = a.c_str() == b.c_str();


		}

		{
			Foo foo1(1, 5);
			// consider foo1 to be invalidated
			Foo fooMoved = std::move(foo1); // move constructor called
		}

		// 최적화를 했는지 선언만하고 쓰지도않으면 생성자 호출도안함
		Bar barObject;
		Foo fooObject(1, 3);
		Baz bazObject(4);
		Baz bazObject2(66);

		bazObject = bazObject2;


		// Does not compile if we delete copy constructor of Foo
		// It compile when we declare Foo(const Bar& other); <- compiler found conversion
		Foo implicitConversionFoo = barObject;
		Foo implicitConversionFoo2 = Bar();
		// value downcasting is possible
		// Foo valueCastedToFooFromBar = static_cast<Foo>(barObject);


		bazObject.PureVirtualMethod();


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

		Bar obj4;
	}
	*/

}