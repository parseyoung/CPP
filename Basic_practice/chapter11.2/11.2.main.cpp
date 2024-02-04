// Inheritance (2. 상속의 기본)

#include "Student.h"
#include "Teacher.h"

int main()
{
	std::string name;

	Student std("Jae Hyun");
	std.setName("Jae Hyun2");
	std.getName();
	std::cout << std.getName() << std::endl;

	Teacher teacher1("Dr. Se Young");
	teacher1.setName("Dr. Se Young2");
	std::cout << teacher1.getName() << std::endl;
	
	std::cout << std << std::endl;
	std::cout << teacher1 << std::endl;

	std.doNothing();
	teacher1.doNothing();

	std.study();
	teacher1.teach();

	Person person;
	person.setName("Mr. Incradible");
	person.getName();

	return 0;
}