// anonymous (익명 객체)
/*
	A a;
	a.print();

A().print();
이렇게 줄여서 사용 가능, 이때 A는 R-Value처럼 작동, 재사용 불가 */

#include <iostream>
using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; } // 생성자 (객체 초기화)

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