// Destructor (�Ҹ���) 
// <-> �������� �ݴ���. ������ ������ ����� ����� �� ȣ��Ǵ� ���� �ǹ�

#include <iostream>	
using namespace std;

class Simple
{
private:
	int m_id;

public:
	Simple(const int& id_in)
		: m_id(id_in)
	{
		cout << "constructor" << m_id << endl;
	}

	~Simple()
	{
		cout << "Destructor" << m_id << endl;
	}
};

class IntArray
{
private:
	int* m_arr = nullptr;
	int m_length = 0;

public:
// ���� �Ҵ� �� �޸� ���� ���� �ϱ� ���� ���� Ŭ���� �ȿ� new, delete ��� ��.
// vector�� ���������� new, delete�� ������ �Ǿ�����
// �̰Ÿ� �����ϱ� ���� size�� capacity(�뷮)�� ����
// capacity(�뷮)��ŭ �޸𸮸� ������ ������ ���߿� �� size�� ����Ѵ� �̷� ����

	IntArray(const int length_in)
	{
		m_length = length_in;
		m_arr = new int[m_length];

		cout << "Constructor" << endl;
	}
	~IntArray() // �Ҹ��ڴ� �Ű������� ����
	{
		if( m_arr != nullptr)
			delete[] m_arr;
	}

	int size() { return m_length; }
};
int main()
{
	while (true)
	{
		IntArray my_int_arr(10000);
		// delete[] my_int_arr.m_arr �̷������� ���� �Ұ���
		// new ��� �� delete�� �ʼ�, �޸� ����! �̷� ��� �Ҹ� �� ���

	Simple s1(0);
	Simple s2(1);

	return 0;
}