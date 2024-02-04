#include <iostream>

using namespace std;

int foo(int x, int y);

int foo(int x, int y)
{
	return x + y;

}

int main() 
{
	int x{ 1 }, y{ 2 };
	

	int result1 = foo(6, 10);
	cout << "result1 " << result1 << endl;

	int result2 = foo(x, y);
	cout << "result2 " << result2 << endl;

	return 0;
}