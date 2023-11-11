// 주소에 의한 인수 전달 (call by address)
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
	// foo(5); 포인터와 같은 주소의 전달 시 리터럴 불가
	// 함수 매개변수로 const 사용해도 불가

	return 0;
}