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
		// ���� ��������� ȣ���ع����� ������ �ǰ����� ����� ��Ų�� �ƴϹǷ� ������ �ӻ����Ҽ��� ����
	{
		// you should make other valid!!!! ���ϸ� �Ҹ��� ȣ��ɶ� ���ڻ쳭��!!
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
		// �������� ������ const qualifier ������ move assignment operator ȣ�� ���ϰ� copy assignment operator�� resolve �ż� �̻��Ѱ�ȣ����
		// �̰Ŷ������� const�� ����������� ����� �ڵ�¥���Ѵ�.

		// �̰Ծƴ�, rvalue reference�� �׳� expression���� ���� lvalue�ΰ� ����� ����. �׻�  std::move()�� �ٿ�����Ѵ�.
		// mSubobject = std::move(resource); �������� std::move�� const T&&�� �����Ѵ�
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