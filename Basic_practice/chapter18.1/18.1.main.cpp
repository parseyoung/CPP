// istream으로 입력 받기
// 아래 기능들을 filestream에 사용, 복잡한 file format에 적용 가능
#include <iostream>
#include <string>
#include <iomanip> // input/output manipulators
using namespace std;

int main()
{
	//char buf[5];
	////setw() buf size 보다 많이 담아도 런타임에러 X
	//cin >> setw(5) >> buf; // asdfghjkl

	//cout << buf << endl; // asdf

	//cin >> setw(5) >> buf; 

	//cout << buf << endl; //ghjk

	char buf2[7];
	char buf3[100];
	char buf5[1024];
	string buf4; // 동적

	//cin은 기본적으로 빈칸을 출력 X, get으로 받으면 해결 가능
	//Hello cin 입력
	//cin.get(buf2, 5);
	//cin.getline(buf3, 100);
	// getline(cin, buf4); // paramter로 cin

	//cin.ignore(2); // 입력 시 맨 앞 2글자 무시
	// peak() cat같은 느낌, buf에서 꺼내는 것은 아님
	//cout << (char)cin.peek() << endl; // H
	cin >> buf4;
	cout << buf4 << endl; // Hello
	cin.unget(); // 마지막 읽은 값 버퍼에 다시 삽입
	cin.putback('A');
	cin.putback('C');
	cin >> buf4;
	cout << buf4 << endl; // CAo = LIFO

	


	//cout << cin.gcount() << " " << buf2 << endl; // 5 Hello
	//cout << cin.gcount() << " " << buf3 << endl; // 6 Hello (+ 줄바꿈 char)
	//cout << cin.gcount() << " " << buf4 << endl; // 0 Hello
	/*cin.get(buf2, 5);
	cout << cin.gcount() << " " << buf2 << endl;*/

	return 0;
}