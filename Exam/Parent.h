#pragma once
class Parent
{
public:
	Parent(const int i) : m_p(i) {}
	void Change(int i)
	{
		m_p = i;
	}

	virtual Parent* GetThis()
	{
		return this;
	}
protected:
	int m_p;
};

class FirstChild : public Parent
{
public:
	FirstChild() : Parent(1), m_c(1) {}
private:
	int m_c;

};


class SecondChild : public Parent
{
public:
	SecondChild() : Parent(2), m_c(2) {}
private:
	int m_c;

};

class ThirdChild : public Parent
{
public:
	ThirdChild() : Parent(3), m_c(3) {}
private:
	int m_c;

};


class What : public Parent, FirstChild, SecondChild, ThirdChild
{
public:
	What()
		: Parent(-1)
		, FirstChild()
		, SecondChild()
		, ThirdChild()
		, what(10213)
	{

	}
	void Say()
	{
		Parent::Change(123);
		FirstChild::Change(456);
		auto* p = Parent::GetThis();
		p->Change(0);

		auto* c1 = FirstChild::GetThis();
		c1->Change(1);

		auto* c2 = SecondChild::GetThis();
		auto* c3 = ThirdChild::GetThis();
	}
private:
	int what;
};