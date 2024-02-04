#include <iostream>

struct Person
{
	int age;
	float weight;
};

int main()
{
	Person ps;

	Person &ref = ps; //reference (.)
	ref.age = 5; 

	Person *ptr = &ps; //pointer (->)
	ptr->age = 30;
	//(*ptr).age = 20;
	

	Person &ref2 = *ptr;
	ref2.age = 45;

	std::cout << &ps << std::endl;
	std::cout << &ref2 << std::endl;
	//동일한 주소로 출력 됨

	return 0;

}