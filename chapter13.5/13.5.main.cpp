// Class Template Specialization (Ŭ���� ���ø� Ư��ȭ)
#include <iostream>
#include <array>
#include "Storege8.h"
using namespace std;

template<typename T>
class A
{
public:
	A(const T& input)
	{}

	void doSomething()
	{
		cout << typeid(T).name() << endl;
	}

	void test()
	{}
};

// Specialization
template<>
class A<char>
{
public:
	A(const char& temp)
	{}

	void doSomething()
	{
		cout << "Char type specialization" << endl;
	}
};

int main()
{
	// �����ڿ� �ڷ����� �־���⿡, C++ 17������ 
	//  A  a_int(1);  �ڷ��� ���� ���� ����
	/*
	A<int> a_int(1);
	A<double> a_double(3.14);
	A<char> a_char('A');

	a_int.doSomething();
	a_double.doSomething();
	a_char.doSomething();
	*/

	// Define a Storage8 for integers
	Storage8<int> inStorage;

	for (int count = 0; count < 8; ++count)
		inStorage.set(count, count);

	for (int count = 0; count < 8; ++count)
		std::cout << inStorage.get(count) << '\n';

	cout << " Sizeof Storage8<int> " << sizeof(Storage8<int>) << endl;



	return 0;
}