//chaining Member Function this 포인터와 연쇄 호출
#include <iostream>
using namespace std;

class Simple
{
private:
	int m_id;

public:
	Simple(int id)
	{
		setID(id);
		// this는 현재 객체의 포인터를 나타냄
		cout << "SetID address: " << this << endl;
	}

	void setID(int id) { m_id = id; }
	int getID() { return m_id; }
};

class Calc
{
private:
	int m_value;

public:
	Calc(int init_value)
		: m_value(init_value)
	{}
	// 아직 C++에서는 자주 사용 안 하는 기법이지만, 다른 언어에선 비교적 사용 함.
	Calc& add(int value) { m_value += value; return *this; }
	Calc& sub(int value) { m_value -= value; return *this; }
	Calc& mult(int value) { m_value *= value; return *this; }

	void print()
	{
		cout << m_value << endl;
	}
};

int main()
{
	Simple sim(1);

	//chaining Member Function
	Calc cal(0);
	Calc& temp1 = cal.add(10);
	Calc& temp2 = temp1.sub(1);
	Calc& temp3 = temp2.mult(2);
	temp3.print();

	cal.add(10).mult(1).sub(5).print();
	return 0;
}