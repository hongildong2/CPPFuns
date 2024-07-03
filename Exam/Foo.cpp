#include <iostream>
#include "Foo.h"
#include "Bar.h"

namespace POCU3200Midterm
{

	Foo::Foo(int x, int y)
		: mpX(new int(x)),
		mpY(new int(y)),
		mpZ(new int(x + y)),
		mSubobject(x, y)
	{

		// this does not call polymorphic virtual method of Bar
		// In constructor, polymorphism does not work
		Bar* pDerivedThis = static_cast<Bar*>(this);

		pDerivedThis->Say();

	}

	Foo::Foo(Foo&& other) noexcept
		: mpX(other.mpX),
		mpY(other.mpY),
		mpZ(other.mpZ),
		mSubobject(std::move(other.mSubobject))
		//mSubobject(other.mSubobject) You should not call simple  copy constructor, as this is resource handover
		// 만약 복사생성자 호출해버리면 동작은 되겠지만 약속을 지킨게 아니므로 누군가 속상해할수도 있음
	{
		// you should make other valid!!!! 안하면 소멸자 호출될때 개박살난다!!
		other.mpX = new int();
		other.mpY = new int();
		other.mpZ = new int();
	}



	Foo::Foo(const Bar& other)
		: mpX(nullptr),
		mpY(nullptr),
		mpZ(nullptr),
		mSubobject(1, 3)
	{
	}

	Foo::~Foo()
	{


		delete mpX;
		delete mpY;
		delete mpZ;
		// TEST : are mSubobjects are automatically destructed?
		// yes, they are potentially invoked



	}

	Subone&& Foo::HandoverMyResource()
	{
		return std::move(mSubobject);
	}

	void Foo::TrashReceiveResource(const Subone&& resource)
	{
		// need move assignment operator
		// mSubobject = resource; // all the hardwork about resource ownership will be handled in Subone class and it should be!
		// 개쓰래기 같은게 const qualifier 때문에 move assignment operator 호출 안하고 copy assignment operator로 resolve 돼서 이상한거호출함
		// 이거때문에라도 const도 방심하지말고 제대로 코드짜야한다.

		// 이게아님, rvalue reference를 그냥 expression으로 쓰면 lvalue인걸 까먹지 말것. 항상  std::move()를 붙여줘야한다.
		// mSubobject = std::move(resource); 다행히도 std::move는 const T&&을 거절한다
		std::cout << " Oops! You made wrong signature of resource handover method!! " << std::endl;
	}

	void Foo::ReceiveResource(Subone&& resource)
	{
		mSubobject = std::move(resource);
		// this properly calls move assignment operator
	}


	// reading rRef, using as lvalue should contain const qualifier, explicitly indicating that this is just simple read
	void Foo::ReadRRef(const Subone&& sub) const
	{
		std::cout << "I am reading subone, no resource handover happens here " << std::endl;
	}

	void Foo::CheckSubobjectValidity()
	{
		mSubobject.Submethod();
		std::cout << "SubObject is Alive!" << std::endl;
	}

	void Foo::Say() const
	{
		std::cout << "Hello, i am parent class! has some subobjects!" << std::endl;
	}
}