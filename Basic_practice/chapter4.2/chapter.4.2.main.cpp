//전역변수, 정적변수, 내부연결, 외부연결

#include <iostream>
#include "myconstent.h"
using namespace std;

//forward declartion (전방선언)
extern void dosomething(); //extern은 생략 가능
extern int a;

/*
	int g_x; //externel linkage
	static int g_x; //internal linkage
	const int g_x(0) // const는 값 변하지 않겠다는 의미, 값 초기화 해줘야함

	extern int g_z;
	extern const int g_z;

	extern int g_w(1); //초기화 한 번 하면 다른 곳에서는 하면 안됌.
	extern const int g_w(1); //외부에서 접근 가능 한 정의 된 상수

*/
int main()
{

	dosomething();

	cout << a << endl;

	cout << " in main cpp file " << Constants::pi << " " << & Constants::pi << endl;

	return 0;
}