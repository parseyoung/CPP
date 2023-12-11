// Inherited Function �����
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
		// �ڽ� Ŭ���� print() ���� �Ұ�
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
	// ���������ڸ� ��ӹ���  Ŭ�������� ���� ����
private:
	using Base::print; // do not add ()
	// public ��� ������ ���� Ŭ���� �Լ� ��� ���ϰ� ���� ����

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