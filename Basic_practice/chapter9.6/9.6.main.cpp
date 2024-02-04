// [] subscript operator ÷�� ������ �����ε� �ϱ�
#include <iostream>
#include <cassert>
using namespace std;

class IntList
{
private:
	int m_list[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

public:
	/*void setItem(int index, int value)
	{
		m_list[index] = value;
	}

	int getItem(int index)
	{
		return m_list[index];
	}

	int* getlist()
	{
		return m_list;
	}*/
	// assert ��� �� ��Ÿ�� ���� ����
	int& operator [] (const int index)
	{
		assert(index >= 0);
		assert(index < 10);
		return m_list[index];
	}

	const int& operator [] (const int index) const
	{
		assert(index >= 0);
		assert(index < 10);
		return m_list[index];
	}
};

int main()
{
	IntList my_list;
	cout << my_list[3] << endl; // ���� �Ҵ� �� ����

	IntList* list = new IntList; // ���� �Ҵ� �� ����
	(*list)[3] = 10; 
	cout << (*list)[3] << endl;
	delete list;

	//my_list.setItem(3, 1);
	//cout << my_list.getItem(3) << endl;
	//my_list.getlist()[3] = 2;
	//cout << my_list.getlist()[3] << endl;
	return 0;
}