#include <iostream>

using namespace std;

int main()
{
	int one_student_score;
	int student_score[5];

	one_student_score = 100;
	student_score[0] = 100; // 1st element
	student_score[1] = 80;
	student_score[2] = 90;
	student_score[3] = 50;
	student_score[4] = 0; // 5th element

	cout << student_score[0] << endl;
	cout << student_score[1] << endl;
	cout << student_score[2] << endl;
	cout << student_score[3] << endl;
	cout << student_score[4] << endl;

	cout << (student_score[0] + student_score[1]) / 2.0 << endl;
	return 0;
}
