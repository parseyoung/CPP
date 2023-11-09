#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
	const char my_strs [] = "Hello, World";
	const string my_hello("Hello, World");
	// string은 사용자 정의 자료형이라고 생각하자!

	cout << "Your name : ";
	string name;
	//cin >> name; // cin은 띄어쓰기를 하면 넘어가버림
	std::getline(std::cin, name); // 한 라인 전체(엔터까지)를 입력으로 봄

	cout << "Your age : ";
	string age;
	std::getline(std::cin, age);


	/*
	만약 age를 int형으로 받고 싶다면,
	cout << "Your age : ";
	int age;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.ignore(32767, '\n') //32767은 magic number이다 
	사용하기 싫으면 limits 헤더파일 선언 한 뒤 위 코드 사용하면 됨.
	*/
	cout << name << " " << age << endl;

	// 문자열 더하기 append 라고 함
	string a("Hello,"); // 문자열 길이는 7, 맨 뒤에 공백이 있다.
	string b(" World");
	string hw = a + b; // append
	hw += " I'm good";

	cout << hw << endl;
	cout << a.length() << endl; // 문자열 길이가 6이 나옴



	return 0;
}