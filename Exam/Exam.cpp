// Exam.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Foo.h"
#include "Bar.h"

int main()
{
    std::cout << "Hello World!\n";
	int count = 0;
LABEL:
	{
		count++;
		// ����ȭ�� �ߴ��� �̵������ϸ� ������ ȣ�⵵����
		Bar obj1;
		Bar obj2;
		Bar obj3;

		Bar* pObj1 = &obj1;
		Foo* pObj1Parent = static_cast<Foo*>(pObj1);

		pObj1->Say(); // derived method has no virtual keyword
		pObj1Parent->Say(); // parent method has virtual keyword
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
