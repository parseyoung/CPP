//chaining Member Function this �����Ϳ� ���� ȣ��
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
		// this�� ���� ��ü�� �����͸� ��Ÿ��
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
	// ���� C++������ ���� ��� �� �ϴ� ���������, �ٸ� ���� ���� ��� ��.
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