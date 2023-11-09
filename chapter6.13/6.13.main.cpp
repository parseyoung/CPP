#include <iostream>
/*
*ptr = 6;
dereferencing(역참조하여 value의 값을 바꿔줌)
const시에는 값을 바꾸지 못함.
*/

using namespace std;

/* 
const가 붙는 위치에 따라 다름  
가르키는 주소에 있는 값을 바꾸지 않겠다임, ptr의 주소를 바꾸는 것은 상관 없음
1)
	int value1 = 5;
	const int *ptr = &value1;

	int value2 = 6;
	ptr = &value2;

*/

/*
const가 붙는 위치에 따라 다름
주소는 바꾸지 못하고, 주소가 가르키는 값은 바꿀 수 있음, 진정한 const pointer임
2)
	int value1 = 5;
	int * const ptr = &value1;

	int value2 = 6;
	*ptr = value2;

3) 둘 다 붙으면 주소, 값 둘 다 못 바꿈!!
*/
int main()
{
	int value = 5;
	const int *const ptr1 = &value;
	int *const ptr2 = &value;
	const int* const ptr3 = &value;

	return 0;
}