//Assocication(집합관계)
#include <iostream>
#include <vector>
#include <string>
#include "Lecture.h"

int main()
{
	using namespace std;

	Student *std1 = new Student("Jae hyun", 0);
	Student *std2 = new Student("Se young", 1);
	Student *std3 = new Student("Jack Jack", 2);

	Teacher *teacher1 = new Teacher("prof. Hong");
	Teacher *teacher2 = new Teacher("prof. Good");

	Lecture lec1("Introduction to Computer Programing");
	lec1.assignTeacher(teacher1);
	lec1.registerStudent(std1);
	lec1.registerStudent(std2);
	lec1.registerStudent(std3);

	Lecture lec2("Computer Thinking");
	lec2.assignTeacher(teacher2);
	lec2.registerStudent(std1);

	//test
	{
		cout << lec1 << endl;
		cout << lec2 << endl;

		lec2.study();

		cout << lec1 << endl;
		cout << lec2 << endl;
	}
	// TODO : class HobbyClub
	// delete memory
	delete std1;
	delete std2;
	delete std3;

	delete teacher1;
	delete teacher2;

	return 0;
}