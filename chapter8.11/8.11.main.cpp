// static member function
// ���� �������� ���� ����, 
#include <iostream>
using namespace std;

class Something
{
public:

	class _init
	{
	public:
		_init()
		{
			s_value = 999;
		}
	}; // �̳�Ŭ���� ����
	// static ��� ������ ���� �ʱ�ȭ �ϴ� �� ó�� ������ ���� ����

private:
	static int s_value;
	int m_value{ 5 };
	static _init s_initializer; // �̳�Ŭ������ static���� ����

public:
	Something()
		: m_value(123) // static ������ �ʱ�ȭ �Ұ� -> �̳� Ŭ������ �ذ�
	{}

	static int getValue() 
	{
		return s_value;
	
	}   // static function�� this Ű���� ��� �Ұ�

	int temp() 
	{
		return this->s_value + this->m_value;
	}
};

int Something::s_value;
Something::_init Something::s_initializer;

int main()
{
	cout << Something::getValue() << endl;

	Something s1, s2;

	cout << s1.getValue() << endl;
	cout << s1.temp() << endl;

	// non-static ��� �Լ� ������ ����
	// Ư�� �ν��Ͻ��� ������ ������ ������� ��
	int (Something:: * fptr1)() = &Something::temp;
	cout << (s2.*fptr1)() << endl;

	// static ��� �Լ� ������ ����
	// Ư�� �ν��Ͻ��� ���� X
	int (*fptr2)() = &Something::getValue;
	cout << fptr2() << endl;

	return 0;
}