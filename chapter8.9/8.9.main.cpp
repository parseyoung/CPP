// class �� const
// const�� ���� �� �ִ� �κ��� �� ���� ���°� ����
// �׷��� ����뿡 ������ + �Ǽ��� ���� �� ����
// 11/21�� �̾ �ϰڽ�!!!!!
#include <iostream>
using namespace std;

class Something
{
public:
	int m_value = 0;

	void setValue(int value) 
	{ 
		m_value = value; 
	}

	int getValue() const // ��������� ���� �ٲ��� �ʰڴ�(const)
	{ 
		return m_value;
	}
};

void print(Something st)
{
	cout << &st << endl;

	cout << st.m_value << endl;
}

int main()
{
	Something something;
	//something.setValue(2);
	something.getValue();

	print(something);

	cout << &something << endl;

	return 0;
}