// �ּҿ� ���� �μ� ���� (call by address)
#include <iostream>

using namespace std;
void foo(int*ptr)
{
	cout << "foo function : " <<  *ptr << " " << ptr << " " << &ptr << endl;
}

void fuu(int* arr, int length)
{
	for (int i = 0; i < length; ++i)
		cout << arr[i] << endl;
}

int main()
{
	int value = 5;

	cout << "main : " << value << " " << & value << endl;

	int *ptr = &value;
	cout << value << " " << &value << endl;
	cout << ptr << " " << &ptr << endl;

	foo(&value);
	foo(ptr);
	// foo(5); �����Ϳ� ���� �ּ��� ���� �� ���ͷ� �Ұ�
	// �Լ� �Ű������� const ����ص� �Ұ�

	return 0;
}