#include <iostream>

using namespace std;


int main()
{
	int x = 5;
	double d = 123.0;

	int *ptr_x = &x;
	double *ptr_d = &d;

	// ������ �ּҸ� �����Ϳ� �־��ִ� ����
	// ��� : ������(*)�� ������ �Ǵ� ���� �ּ���

	cout << ptr_x << endl;
	cout << *ptr_x << endl;

	cout << ptr_d << endl;
	cout << *ptr_d << endl;

	cout << sizeof(x) << endl;
	cout << sizeof(d) << endl;

	// �������� �ּ� ���� ũ��� 4byte��
	// �������̾ �ּ��� ũ��� 4byte (x86����)
	cout << sizeof(&x) << " " << sizeof(ptr_x) << endl;
	cout << sizeof(&d) << " " << sizeof(ptr_d) << endl;




	return 0;
}