//  ���� ��� ����(Static Member Variables) :
//	Ŭ���� ���ο��� ����� static ��� ������ �ش� Ŭ������ ��� ��ü�� �����ϴ� �����Դϴ�.
//	��ü�� ���� �� �����Ǵ��� �� ������ �ϳ��� �޸� ������ �����ϸ� ��� ��ü�� �����մϴ�.
//	Ŭ������ ���� ��� ������ Ŭ������ �ϳ��� ���纻�� �����Ǹ�, ��� ��ü�� �̸� ������ �� �ֽ��ϴ�.

#include <iostream>
using namespace std;

class Something
{
public:
	static int s_value;
	static const int cs_value = 5;
	static constexpr int cse_value = 1;
	//�̱��� ���Ͽ��� ���� ���
	// ���� ������ ���⼭ �ʱ�ȭ �Ұ�, const�� ���� ���⼭ �ݵ�� �ʱ�ȭ
};

int Something::s_value = 1; // define in cpp, no header file

int main()
{
	cout << &Something::s_value << " " << Something::s_value << endl;
	// static�� ���� �Ǳ� ������ �ּ� �� �� ���� 

	Something st1;
	Something st2;

	st1.s_value = 2;

	cout << &st1.s_value << " " << st1.s_value << endl;
	cout << &st2.s_value << " " << st2.s_value << endl;
	// st1.s_value�� st2.s_value�� ���� �ּ� ��� ��.
	return 0;
}

