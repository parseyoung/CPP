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
		return this->score > student.score; // ��������
	}
};

int main(void) {
	Student students[] = {
		Student("�ڼ���", 90),
		Student("������", 93),
		Student("���ѿ�", 97),
		Student("������", 87),
		Student("������", 81),
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