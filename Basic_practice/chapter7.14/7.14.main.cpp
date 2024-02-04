/*
* 단언하기 assert
* release 모드에서는 assert 뺴고 실행, debug 모드에서는 작동 및 오류 찾아줌
* assert는 런타임에 체크함
* static assert는 컴파일 타임에 오류 발생
* 컴파일러를 이용해서 나중에 문제가 생길 수 있는 부분을 미리 차단 가능!!
*/
#include <iostream>
#include <cassert> //assert.h
#include <array>

void printValue(const std::array<int, 5>& my_ar, const int& ix)
{
	assert(ix >= 0);
	assert(ix <= my_ar.size() - 1);
	// && 연산자로 한 줄로 합칠 수 있지만 문제 파악을 위해 나눠서 하는 경우가 많음

	std::cout << my_ar[ix] << std::endl;
}
int main()
{
	std::array<int, 5> my_ar{ 1, 2, 3, 4, 5 };

	printValue(my_ar, 100);

	// static assert는 const 상수일때 사용가능, 문구를 남길 수 있음
	const int x = 5;
	static_assert(x == 10, "x should be 10(sy) ");;

	return 0;
}