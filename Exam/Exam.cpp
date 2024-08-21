#include <iostream>
#include "Foo.h"
#include "Bar.h"
#include "Baz.h"
#include "IBar.h"
#include "AlgoHeader.h"
#include "TClass.h"
#include "CompileTime.h"
#include "Parent.h"

#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

int main()
{

	// Algorithm
	{
		using namespace Algorithm;

		solve1202();
		std::cout << std::endl << "### algo done ###" << std::endl;
	}



	// Final
	{
		unsigned int fullSpecial = add<unsigned int, int>(1u, -1);

		// Specialize해도 사용할떄, instantiate 할때는 항상 템플릿인자를 다 넣어주어야한다. 추론할때 말고는
		// TClass<int, int> a; // template instantiation
		TClass<double, double*> cc; // specialized?? yes => 최대한 맞는 모양으로 알아서 찾아간다.
		TClass<double, double> twisted; //ttwiste?


		std::vector<int> v;
		//std::vector<int> v(200, 10); count 200 만큼 value 10 으로 초기화
		v.reserve(123123);
		v.resize(100); // Only DefaultInsertable T allowed to use, int's default is 0, size becomes 100
		v.assign(200, 10); // v size becomes 200, all elements become 10
		v.assign(50, 3); // v size becomes 50, all elements become 3
		v.resize(40); // v size becomes 40
		v.resize(100); // 40 ~ 100 elements is DefaultInserted
		v.resize(200, -1); // size becomes 200, 100 ~ elements copy initialized with -1, T must be CopyInsertable

		v.reserve(10);


		std::map<int, int> m{ {1,1}, {2,2} }; // intializer

		// auto& val = m.at(0); // exception is thrown! 뭔생각으로 만든거야?


		 // In operator[], if key does not exist, value is value_type object inserted
		constexpr int I_AM_NOT_EXISTS = 0;
		auto& wtf = m[I_AM_NOT_EXISTS];
		assert(wtf == 0); // default constructed
		// equivalent to ` return this->try_emplace(key).first->second;
		// key is copy constructed, value is default constructed and their definition must satisfy those

		auto& val = m[1]; // existing 1 is returned


		// since 1 is already exists, this does not do anything
		const std::pair<std::map<int, int>::iterator, bool> result = m.insert({ 1, 2 });
		assert(result.second == false);
		assert(result.first->first == 1); // key
		assert(result.first->second == 1); // val

		const auto shitType = m.insert({ 100, 100 });
		assert(shitType.second == true);
		assert(shitType.first->first == 100);
		assert(shitType.first->second == 100);

		auto why = m.find(100); // iterator를 반환한다.
		assert(why->first == 100);

		auto no = m.find(123123); // 없으면 end를
		assert(no == m.end());



		// std::replace(m.begin(), m.end(), std::pair<int, int>{100, 100}, std::pair<int, int>{-1, -1});
		std::replace(v.begin(), v.end(), -1, 123);



		Black<1> a;
		// a.Disaster(); // static assert triggered, compile time failure
		Black<20> b;
		b.Disaster(); // passes



	}


	// iterator
	{
		std::vector<int> v1;
		std::vector<int> v2;

		v1.push_back(1);
		v1.push_back(1);
		v1.push_back(1);
		v1.push_back(1);
		v1.push_back(1);

		v2.push_back(2);
		v2.resize(100);
		std::copy(v1.begin(), v1.end(), v2.begin());
	}

	What what;

	what.Say();

}