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


		// Below 2 disaster factory has same problem! Dangling references
		static Bar& BarDisasterFactory2()
		{
			Bar temp;
			return temp; // returning reference to dead object, not valid reference
		}

		static Bar&& BarDisasterFactory() // disaster, returning reference to dead object
		{
			return Bar();
			// as soon as Bar is evaluated, its lifetime is over, evaluated object will begin destruction sequence.
			// Does even returning rValue reference makes sense? => ���� �����ϰ��ִ� ��ü�� ���ҽ� �������� �ѱ�� ���� ��
		}

		//static Bar&& BarRRefFactory()
		//{
		//	Bar&& temp = Bar();
		//	// when rvalue reference is used as expression, it is lvalue
		//	// thus, what you are doing here is just returning lvalue.
		//	return temp; 
		//}

		// will destructor of Foo called? parent destructor is virtual but derived one is not.
		// = Yes. base class Foo is defined as polymorphic, any derived class from it is also polymorphic class. Compiler handles that behavior automaticallly
		// virtual Ű����� ���� base object�� �ѹ��� �ٿ��൵ �ǳ�? -> �Ҹ��ڴ� ������ ������������ �ƴ϶� ������� �� �����ϹǷ� �ƴ�����?
		~Bar();

		void Say() const override;
		virtual void BarVirtualMethod();

		// returning rValue reference means "i am handing over my resource ownership who calls this!"
		// You can utilize argument for access guard

	private:
		int mU;
		int mV;
		int mW;
		int mY;
	};
}
