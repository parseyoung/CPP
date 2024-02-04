// function try (함수 try)
#include <iostream>
using namespace std;

class A
{
private:
	int m_x;
public:
	A(int x)
		: m_x(x)
	{
		if (x <= 0)
			throw 1;
	}
};

class B : public A
{
public:
	// 생성자에서 func try 사용하면 main에서도 잡음
	// 기본적으로는 안 잡음
	B(int x) try 
		: A(x)
	{
		// do initialization
	}
	catch (...)
	{
		cout << "Catch in B constructor" << endl; // output1
	}
};

int main()
{
	try
	{
		B b(0);
	}

	catch (...)
	{
		cout << "Catch in main()" << endl; //output2
	}

	return 0;
}
