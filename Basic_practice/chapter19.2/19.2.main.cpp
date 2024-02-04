// 함수에서 여러 개의 리턴 값 반환 (C++ 17)
#include <iostream>
#include <tuple>
using namespace std;

//tuple<int, int> my_func()
//{
//	return tuple<int, int>(123, 456);
//}

auto my_func()
{
	return tuple(123, 456, 13.5);
}

int main()
{
	//tuple<int, int> result = my_func();

	/*auto result = my_func();
	cout << get<0>(result) << " " << get<1>(result) << " " << get<2>(result) << endl;*/

	auto [a, b, c] = my_func();
	cout << a << " " << b << " " << c << endl;

	//cout << "Hello, World" << endl;
	return 0;
}