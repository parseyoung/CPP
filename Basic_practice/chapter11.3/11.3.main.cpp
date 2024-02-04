// Derived 유도된 클래스의 생성 순서
# include <iostream>

using namespace std;

class Mother
{
public:
	int m_i;

	Mother(const int & i_in = 0)
		: m_i(i_in)
	{
		cout << "Mother construction" << endl;
	}
};

class Child : public Mother
{
public:
	double m_d;

public:
	Child()
		: Mother(5), m_d(1.0)
	{
		cout << "Child construction" << endl;
	}
};

class A
{
public:
	A()
	{
		cout << "A constructur" << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "B constructur" << endl;
	}
};

class C : public B
{
public:
	C()
	{
		cout << "C constructur" << endl;
	}
};

int main()
{
	Child c1;

	C c;

	return 0;
}