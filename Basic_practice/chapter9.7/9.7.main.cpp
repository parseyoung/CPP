//() parenthesis ��ȣ ������ �����ε��� Function object(Funcor) �Լ���ü
// �Լ� ��ü�� �Ϲ� �Լ��ʹ� �޸� ���¸� ���� �� �־ 
// �Լ� ȣ�� ���� ������ �����ϰų� ������ �� ����
#include <iostream>
using namespace std;

class Accmualtor
{
private:
	int m_counter = 0;
public:
	int operator()(int i) { return (m_counter += i); }
};

int main()
{
	Accmualtor acc;
	cout << acc(10) << endl;
	cout << acc(20) << endl;

	return 0;
}