// �Ͻ��� ����ȯ�� ����� ����ȯ

#include <iostream>
#include <typeinfo>

int main()
{
	using namespace std;

	int a = 123.0;

	cout << typeid(a).name() << endl;

	//int a = static_cast<int>(4.0);
	cout << static_cast<int>(a) << endl;

	return 0;
}