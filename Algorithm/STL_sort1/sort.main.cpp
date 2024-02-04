#include <iostream>
#include <algorithm>
using namespace std;

class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}
	bool operator < (Student& student) {
		return this->score > student.score; // 내림차순
	}
};

int main(void) {
	Student students[] = {
		Student("박세영", 90),
		Student("나동빈", 93),
		Student("박한울", 97),
		Student("김종구", 87),
		Student("이태일", 81),
	};
	sort(students, students + 5);
	for (int i = 0; i < 5; i++) {
		cout << students[i].name << " " << students[i].score << " ";
	}
}


//bool compare(int a, int b) {
//	return a > b;
//}
//
//int main(void) {
//	int a[10] = { 9, 3, 5, 4, 1, 10, 8, 6, 7, 2 };
//	sort(a, a + 10, compare);
//	for (int i = 0; i < 10; i++) cout << a[i] << " ";
//	return 0;
//}