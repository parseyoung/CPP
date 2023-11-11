#include <iostream>

using namespace std;

int func(int x)
{
	return x;
}

int goo(int y)
{
	return y;
}

int main()
{
	cout << func << endl; // cout : 008111F9 -> 함수도 포인터임
	cout << func(2) << endl; // 2

	int(*fcnptr)(int) = func;
	cout << fcnptr(2) << endl; // 2

	fcnptr = goo;
	cout << fcnptr(7) << endl; // 7


	return 0;
}