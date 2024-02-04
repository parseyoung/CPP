// anonymous (�͸� ��ü)
/*
	A a;
	a.print();

A().print();
�̷��� �ٿ��� ��� ����, �̶� A�� R-Valueó�� �۵�, ���� �Ұ� */

#include <iostream>
using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; } // ������ (��ü �ʱ�ȭ)

	int getCents() const { return m_cents; }
};

Cents add(const Cents& c1, const Cents &c2)
{
	return Cents(c1.getCents() + c2.getCents());
}
int main()
{
	cout << add(Cents(6), Cents(8)).getCents() << endl;

	return 0;
}