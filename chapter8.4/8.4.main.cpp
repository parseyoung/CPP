// Member Initializer List �������� ��� �ʱ�ȭ ����Ʈ
#include <iostream>
using namespace std;

class B
{
private:
	int		m_b;

public:
	B(const int& m_b_in)
		:m_b(m_b_in)
	{}
};

class Somethig
{
private:
	int		m_i = 100 ;
	double	m_d{ 100.0 };
	char	m_c{ 'a' };
	int		m_arr[5] = { 1, 2, 3, 4, 5 };
	B		m_b;
// ��� �� �����ڰ� �켱������ ���Ƽ� �����ڰ� ��� ��
public:
	Somethig()
		: m_i{ 2 }, m_d{ 3.14 }, m_c{ 'a' }, m_arr{1, 5, 10, 3, 2}
		, m_b{ m_i - 1 }
	{}
	void print()
	{
		cout << m_i << " " << m_d << " " << m_c << " " << endl;
		for (auto& e : m_arr)
			cout << e << " ";
		cout << endl; 
	
	}
};


int main()
{
	Somethig som;
	som.print();

	return 0;
}