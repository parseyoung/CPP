//class와 header file
// 일반적으로 클래스 명을 헤더파일로 함

#include "Clac.h"

int main()
{

	Calc cal1(10);
	cal1.add(10).mult(1).sub(5).print();

	Calc cal2(20);
	cal2.add(10).mult(1).sub(5).print();

	return 0;
}
