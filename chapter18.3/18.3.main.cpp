// string stream 문자열 흐름 (버퍼)
// 빈칸으로 구분 하는 것이 특징

#include <iostream> // cout
#include <sstream> // string stream
using namespace std;

int main()
{
	stringstream os;
	// 버퍼에 계속 쌓임
	//os << "Hello, World!"; // << : insertion operator
	//os << "Hello, World2!" << endl;

	// 이전 내용 지우고 버퍼 내용 통째로 바꿔버림
	//os.str("Hello, World!\n"); 

	string str;

	//os >> str; // 공백까지만 출력 됨

	//str = os.str();
	//cout << str << endl;

	cout << os.str() << endl;

	// int, double
	// 공백으로 알아서 구분 함
	int i = 12345;
	double d = 3.15;
	os << i << " " << d;
	string str1; // 12345
	string str2; // 3.15

	// int, double을 string으로 넣기
	os << " 12345 67.89";
	string str3; // 12345
	string str4; // 67.89

	os >> str1 >> str2;
	os >> str3 >> str4;


	cout << str1 << " " << "|" << " " << str2 << endl;
	cout << str3 << " " << "|" << " " << str4 << endl;

	os.str(""); // 버퍼 비우기
	os.clear(); // state 비움
	cout << os.str() << endl; // 아무것도 안 나옴
	return 0;
}
