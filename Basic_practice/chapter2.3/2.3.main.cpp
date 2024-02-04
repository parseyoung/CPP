// 고정너비정수-멀티플랫폼 프로그래밍시 중요하다.
#include <iostream>
//#include <cstdint>

int main()
{
	using namespace std;

	std::int16_t i(5);
	std::int8_t myint = 65; // char type

	cout << myint << endl; // A출력

	std::int_fast8_t fi(5); // int 8bits중 가장 빠른 것
	std::int_least64_t fl(5); //64bits (8byte)를 갖는 데이터 타입

	return 0;
}