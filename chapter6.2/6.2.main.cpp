#include <iostream>

using namespace std;

void doSomething(int student_scores[]) // ()안에 들어있는건 배열이 아니라 포인터 !! 중요!!
{
	cout << (int)&student_scores << endl;
	cout << student_scores[0] << endl;
	cout << student_scores[1] << endl;
	cout << student_scores[2] << endl;
	cout << "do something size" << sizeof(student_scores) << endl;
	cout << "do something size" << sizeof(student_scores[1]) << endl;

}
int main()
{
	const int num_students = 20;

	int student_scores[num_students]{ 1, 2, 3, 4, 5 }; // 배열

	cout << (int)&student_scores << endl;
	cout << student_scores[0] << endl;
	cout << student_scores[1] << endl;
	cout << student_scores[2] << endl;
	doSomething(student_scores);
	cout << "main something size" << sizeof(student_scores) << endl;
	cout << "main something size" << sizeof(student_scores[1]) << endl;

	return 0;

}