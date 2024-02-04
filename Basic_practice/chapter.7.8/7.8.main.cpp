// 매개변수의 기본값
#include <iostream>

using namespace std;

void print(int x, int y = 10, int z = 30); 
// in header file에 들어가는 경우가 많은데 이때는 함수 생성시 기본값 넣으면 안됌, 재정의 에러 발생

void print(int x, int y, int z)
{
	cout << x << " " << y << " " << z << " " << endl;
}

int main()
{
	print(100); // 100 10 30
	print(100, 200); // 100 200 30

	return 0;
}