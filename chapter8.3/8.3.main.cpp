// Constructors ������
#include <iostream>
using namespace std;

class Second
{
public:
	Second()
	{
		cout << "class second constructor()" << endl;
	}
};

class First
{
	Second sec;

public:
	First()
	{
		cout << "class First constructor()" << endl;
	}
};
class Fraction
{
private: // ĸ��ȭ
	int m_numerator; // ����
	int m_denominator; // �и�
	// �ʱ�ȭ�� �⺻���� ���� �� ����, �����ڸ� ����� ���� ����

public:
	
	Fraction(const int& num_in = 3, const int& den_in = 3)
		// Ŭ������ �̸��� �����ϸ� ������, �ڵ����� �ٷ� ���� ��
		// default �־��� �� ����
	{
		m_numerator = num_in;
		m_denominator = den_in;
		cout << "Faction() constructor" << endl;
	}

public:
	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

int main()
{
	First fir;

	Fraction frac(1); // �������� �Ķ���Ͱ� ���� ��� ��ȣ�� ������� �ʰ� ȣ����. �߿�!
	frac.print();

	Fraction one_thirds(1, 5);
	// ( ) �� warnning�� �߻������� Ÿ�� ��ȯ �ص� ������ ��.
	Fraction two_thirds(3);
	Fraction three_thirds{ 3, 4 }; 
	// { } �������ʱ�ȭ�� public�� ��쿡�� ����
	// { } �� Ÿ�� ��ȯ�� ��� �� ��.
	one_thirds.print();
	two_thirds.print();
	three_thirds.print();
}