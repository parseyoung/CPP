// Inherited Function 숨기기
#include <iostream>
using namespace std;

class Base
{
protected:
	int m_i;

public:
	Base(int value)
		:m_i(value)
	{}

	void print()
	{
		cout << " I'm base " << endl;
	}

private:
	void print() = delete;
		// 자식 클래스 print() 접근 불가
};

class Derived : public Base
{
private:
	double m_d;

public:
	Derived(int value)
		: Base(value)
	{}
	using Base::m_i; 
	// 접근제어자를 상속받은  클래스에서 변경 가능
private:
	using Base::print; // do not add ()
	// public 상속 이지만 상위 클래스 함수 사용 못하게 막기 가능

};

int main()
{
	Base base(5);
	base.print();

	Derived dervied(7);
	dervied.m_i = 1024;
	//dervied.print();

	return 0;
}