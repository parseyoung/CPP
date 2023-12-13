// std::string 문자 접근하기와 배열로의 변환
// c_str(), data()의 기능은 동일, 마지막에 null char 추가 -> C-style
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string my_str("abcdefg");

	cout << my_str.c_str() << endl;
	//cout << my_str.data() << endl;
	const char* arr = my_str.c_str();

	cout << (int)arr[6] << endl; // 103 ('g')
	cout << (int)arr[7] << endl; // 0 (null char)

	char buf[20];
	my_str.copy(buf, 5, 0); // 0은 ofset
	buf[5] = '\0'; // null char 삽입, 뒤 쓰레기값 때문
	cout << buf << endl; 

	//try
	//{
	//	// my_str[100] = 'X';
	//	// 속도 빠르지만 오류처리 X
	//	my_str.at(100) = 'X';
	//	// 속도 느리지만 오류처리 O
	//}
	//catch (std::exception& e)
	//{
	//	cout << e.what() << endl;
	//}

	return 0;
}