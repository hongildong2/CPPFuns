#pragma once
#include <iostream>

template<typename T, typename U>
T add(T a, U b)
{
	std::cout << " i am T U two params template function " << std::endl;
	return a + b;
}

// function template's partial specialization is not allowed, only full specialization is allowed


// Fully Specialized template function is NOT "template". It is concrete function. Thus If you want to declare it in header, declare it as "inline"
// or separate template instantiation and its definition in other cpp file
template<>
inline unsigned int add<unsigned int, int>(unsigned int x, int y)
{
	std::cout << "Fully Specialized Function" << std::endl;
	return 0u;
}



/*
* Partial Specialization looks like this
template<typename X>
X add<X>(X a, X b) -> compiler disallows this
{
	std::cout << " i am X single param template function " << std::endl;
	return a + b;
}
*/


// template-head signature is different each other => Different function template Signature => overloading
// These are all different function template, results in overloading, not partial specialization.
template<typename X>
X add(X a, X b)
{
	std::cout << " i am X single param template function " << std::endl;
	return a + b;
}

// ����ȿ� Ÿ���� �־ ����� �κ� Ư��ȭ�� �Ǹ� ill-formed, ���踦 ������� ������ �׳� �ñ׳�ó�� �ٸ� ���ø� �����̴�.
template<typename Z>
Z add(Z a, double b)
{
	std::cout << " i am Z twisted template function " << std::endl;
	return a + b;
}

// no template instantiation, concrete function overloading
inline int add(double a, float c)
{
	return a + c;
}
// template overloading -> overloading is done when non-type template parameter is used. Above example is just function overloading



// template without <> is instantiation
template double add<double, double>(double a, double b);
template float add<float>(float a, double b); // instantiation of overloaded function template
template int add<int, double>(int a, double b);



template<int T>
class A
{
	int m = T;
};


// A is non-type template parameter
template<int I, int J>
A<I + J> f(A<I>, A<J>)
{
	return A();
}

//template<typename U>
//float add<float, U>(float a, U b)
//{
//	return a + b;
//}



/*
*
* Template Declaration coming first will be treated as prototype template
* => No Template Specialization can come before prototype, must be after
* ���� �������°� ���ø� �������� �����ȴ�.
* ���ø� ���� ���� -> ���ø� �Ķ���Ͱ� ���� ���� ��ġ�ϴ� ������ ���� instantiated�ȴ�.
template <typename U>
class TClass<U, double>
{
public:
	TClass<U, double>()
		: d(0)
	{
		std::cout << " I am twisted " << std::endl;
	}

	U d;
};
*/



template <typename T, typename U>
class TClass
{
public:
	TClass<T, U>()
		: a(0)
		, b(0)
	{
		std::cout << " I am not SPECIAL " << std::endl;
	}

	T a;
	U b;
};

// template specialization�� �� �� template parameter �̸��� ����� ����. ���� ���ø��� �Ķ���͸� �־��ִ� ��ġ�� ���� ��������.
template <typename U>
class TClass<U, double>
{
public:
	TClass<U, double>()
		: d(0)
	{
		std::cout << " I am twisted " << std::endl;
	}

	U d;
};


// specialization
template <typename T>
class TClass<T, T*>
{
public:
	TClass<T, T*>()
		: a(0)
		, b(NULL)
	{
		std::cout << " IAM SPECUIAL " << std::endl;
	}
	T a;
	T* b;
};



template class TClass<int, float>; // explicit instantiation
template class TClass<float, float*>; // which template will be instantiated? specialized one??
// template class TClass<float>; // Specialized Template instantiation need full parameter



