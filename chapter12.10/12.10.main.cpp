// Dynamic Casting (���� ����ȯ)
// casting�� �����ϸ� nullptr�� �ڵ����� ����
// static cast�� ��Ե� ���� ��Ŵ, ���� üũ �� ��, ����Ȯ �� ���� ����
// �����δ� ���� ����ȯ ���� ��� ����, functional, ���ٷ� ��ü �ϴ� ��� ����

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
	// base->m_j �Ұ���


	auto* base_to_d1 = dynamic_cast<Dervied2*>(base);

	if (base_to_d1 != nullptr)
		cout << base_to_d1->m_name << endl;
	else
		cout << "Failed" << endl; // Failed ���


	// static cast


	return 0;
}
