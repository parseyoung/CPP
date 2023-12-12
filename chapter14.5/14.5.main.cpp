// function try (�Լ� try)
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
	// �����ڿ��� func try ����ϸ� main������ ����
	// �⺻�����δ� �� ����
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
