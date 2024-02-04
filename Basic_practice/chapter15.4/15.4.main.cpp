// std::move
#include "AutoPtr.h"
#include "Resource.h"
#include <iostream>
using namespace std;

template<class T>
void MySwap(T& a, T& b)
{
	/*T temp = a;
	a = b;
	b = temp;*/

	T tmp{ std::move(a) };
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	/*
	AutoPtr<Resource> res1(new Resource(1000000));

	cout << res1.m_ptr << endl;

	//AutoPtr<Resource> res2 = res1; // copy constructor (L)
	AutoPtr<Resource> res2 = std::move(res1); // move constructor (R-value)

	cout << res1.m_ptr << endl;
	cout << res2.m_ptr << endl;
	*/

	AutoPtr<Resource> res1(new Resource(3));
	//res1->setAll(3);


	AutoPtr<Resource> res2(new Resource(5));
	//res2->setAll(5);

	res1->print();
	res2->print();

	MySwap(res1, res2);

	res1->print();
	res2->print();

	{
		std::string x{ "abc" };
		std::string y{ "de" };

		std::cout << " x : " << x << std::endl;
		std::cout << " y : " << y << std::endl;

		MySwap(x, y);
		std::cout << " x : " << x << std::endl;
		std::cout << " y : " << y << std::endl;
		
	}
	return 0;

}