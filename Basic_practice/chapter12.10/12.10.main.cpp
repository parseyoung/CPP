// Dynamic Casting (동적 형변환)
// casting에 실패하면 nullptr을 자동으로 넣음
// static cast는 어떻게든 실행 시킴, 에러 체크 안 함, 비정확 할 수도 있음
// 실제로는 동적 형변환 자주 사용 안함, functional, 람다로 대체 하는 경우 많음

#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
	int m_i = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}
};

class Derived1 : public Base
{
public:
	int m_j = 2048;

	virtual void print() override
	{
		cout << "I'm Dervied" << endl;
	}
};

class Dervied2 : public Base
{
public:
	string m_name = "Dr. Jae Hyun";

	virtual void print() override
	{
		cout << "I'm dervied" << endl;
	}
};

int main()
{
	Derived1 d1;
	d1.m_j = 3000;

	Base* base = &d1;
	// base->m_j 불가능


	auto* base_to_d1 = dynamic_cast<Dervied2*>(base);

	if (base_to_d1 != nullptr)
		cout << base_to_d1->m_name << endl;
	else
		cout << "Failed" << endl; // Failed 출력


	// static cast


	return 0;
}
