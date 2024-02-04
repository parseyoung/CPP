// Non-type Parameters (자료형이 아닌 템플릿 매개변수)

#include "MyArray.h"

int main()
{
	MyArray<int, 100> my_array; 

	for (int i = 0; i < my_array.getLength(); ++i)
		my_array[i] = i + 65;

	my_array.print();

	return 0;
}