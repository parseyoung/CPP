// Class Templats (클래스 템플릿)
#include "MyArray.h"

int main()
{

	MyArray<double> my_array(10);

	for (int i = 0; i < my_array.getLength(); ++i)
		my_array[i] = i * 0.5;
	my_array.print();

	MyArray<char> my_array2(10);

	for (int i = 0; i < my_array2.getLength(); ++i)
		my_array2[i] = i + 65;
	my_array2.print();

	return 0;
}