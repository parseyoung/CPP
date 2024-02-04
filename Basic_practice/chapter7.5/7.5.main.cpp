#include <iostream>
#include <array>
#include <tuple>

using namespace std;

int& getarr(std::array<int, 100> &my_arr, int ix)
{
	return my_arr[ix];
}

// tuple 사용해서 두 개의 반환 값 받기 
std::tuple<int, double> gettuple() 
{
	int a{ 10 };
	double d{ 2.14 };
	return std::make_tuple(a, d);

}

int main()
{
	std::array<int, 100> my_arr;

	my_arr[30] = 10;
	getarr(my_arr, 30) = 1024;
	// 위 두 코드가 같은 기능을 함 
	cout << my_arr[30] << endl;


	// tupple 두개 인자 받기 
	std::tuple<int, double> my_tp = gettuple();
	std::get<0>(my_tp); //a
	std::get<1>(my_tp); //d

	cout << std::get<0>(my_tp) << endl;
	cout << std::get<1>(my_tp) << endl;

	// C++ 17 ver. tupple 두개 인자 받기 
	// 위와 같은 기능을 하지만 코드는 간결함
	auto [a, d] = gettuple();
	cout << a << endl;
	cout << d << endl;


	return 0;
}