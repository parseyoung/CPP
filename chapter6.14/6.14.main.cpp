#include <iostream>

using namespace std;

int main()
{

	int value = 5;

	//int * ptr = nullptr;
	//ptr = &value;

	int &ref = value;

	cout << ref << endl;

	ref = 10;

	cout << &value << endl;
	cout << &ref << endl;
	//&value, &ref ���� ����, �ּҸ� �����Ѵٰ� �����ϸ� �ɵ�.
	return 0;

}