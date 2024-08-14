#pragma once


template<typename T, typename U>
T add(T a, U b)
{
	return a + b;
}

template double add<double, double>(double a, double b);
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




template <typename T, typename U>
class TClass
{
	T a;
	U b;
};



// specialization
//template <typename T>
//class TClass<T, T*>
//{
//	T a;
//	T* b;
//};

template class TClass<int, float>; // explicit instantiation
template class TClass<float, float*>; // which template will be instantiated? specialized one??
// template class TClass<float>; // Specialized Template not instantiable??

// TClass<int, int> a; // implicit instantiation

