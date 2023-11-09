#include <iostream>

void doSomething(double * ptr)
{
	std::cout << "address of pointer varaible in doSomething()" << &ptr << std::endl;

	if (ptr != nullptr)
	{
		std::cout << *ptr << std::endl;
	}

	else
	{
		std::cout << "Null ptr, do nothing" << std::endl;
	}

}
int main()
{
	double* ptr = nullptr; //modern C++

	doSomething(ptr);
	doSomething(nullptr);

	double d = 123.4;
	doSomething(&d);

	ptr = &d;
	doSomething(ptr);

	std::cout << "address of pointer varaible in main()" << &ptr << std::endl;
	return 0;

	
}