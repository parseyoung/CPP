// Dynamic binding (동적 바인딩)과, static binding(정적 바인딩)
// 유연하게 변화해야하는 프로그램에는 동적바인딩이 필수, 속도는 정적에 비해 느림
#include <iostream>
using namespace std;

int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multply(int x, int y)
{
	return x * y;
}

int main()
{
	int x, y;
	cin >> x >> y;

	int op;
	cout << " 0 : add, 1 : subtract, 2 : multiply" << endl;
	cin >> op;

	//static binding (early binding)

	/*int result = 0;

	switch (op)
	{
	case 0: result = add(x, y); break;
	case 1: result = subtract(x, y); break;
	case 2: result = multply(x, y); break;
	}

	cout << result << endl; */

	// Dynamic binding (late binding)
	int(*func_ptr)(int, int) = nullptr;
	switch (op)
	{
	case 0: func_ptr = add; break;
	case 1: func_ptr = subtract; break;
	case 2: func_ptr = multply; break;
	}

	if (func_ptr != nullptr)
	{
		cout << func_ptr(x, y) << endl;
	}

	return 0;
}
