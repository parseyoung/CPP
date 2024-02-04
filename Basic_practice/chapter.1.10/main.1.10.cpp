#include <iostream>

using namespace std;

//컴파일러는 위에서부터 시작하기에 한 눈에 보기 편하게 한다.
// main을 위로 올리면, main 내부 사용 함수들이 더 위에 상주해야 함.
//이를 해결하기 위해 프로토타입을 선언함

//프로토타입
//foward declaration (전방선언)
int add(int a, int b); 
int multiply(int a, int b);
int subtract(int a, int b);

int main()
{
	cout << add(1, 2) << endl;
	cout << subtract(1, 2) << endl;
	cout << multiply(1, 2) << endl;
	return 0;
}

// 프로토타입 : 함수의 최소한의 정보를 포함하고 있는 것
// definition
int add(int a, int b) 
{
	return a + b;

}

int multiply(int a, int b)
{
	return a * b;
}
int subtract(int a, int b)
{
	return a - b;
}