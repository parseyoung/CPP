/*
생략부호 Ellipsis
함수 구현시 매개변수를 제한 없이 사용하고 싶을 떄 사용
*/

#include <iostream>
#include <cstdarg> //for ellipsis

using namespace std;

//갯수 입력받고, 입력받은 개수만큼의 숫자 평균 계산
double findAverage(int count, ...) 
{
	double sum = 0;

	va_list list;

	va_start(list, count);

	for (int arg = 0; arg < count; ++arg)
		sum += va_arg(list, int);

	va_end(list);

	return sum / count;

}

int main()
{
	cout << findAverage(1, 1, 2, 3, "Hello", 'c') << endl;
	cout << findAverage(3, 1, 2, 3) << endl;
	cout << findAverage(5, 1, 2, 3, 4, 5) << endl;
}