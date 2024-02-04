#include <iostream>

using namespace std;


int main()
{
	int x = 5;
	double d = 123.0;

	int *ptr_x = &x;
	double *ptr_d = &d;

	// 변수의 주소를 포인터에 넣어주는 과정
	// 결론 : 포인터(*)에 저장이 되는 것은 주소임

	cout << ptr_x << endl;
	cout << *ptr_x << endl;

	cout << ptr_d << endl;
	cout << *ptr_d << endl;

	cout << sizeof(x) << endl;
	cout << sizeof(d) << endl;

	// 포인터의 주소 값의 크기는 4byte임
	// 더블형이어도 주소의 크기는 4byte (x86기준)
	cout << sizeof(&x) << " " << sizeof(ptr_x) << endl;
	cout << sizeof(&d) << " " << sizeof(ptr_d) << endl;




	return 0;
}