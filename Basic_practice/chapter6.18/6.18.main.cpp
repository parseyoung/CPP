//void pointer = generic pointer라고도 불림

#include <iostream>

using namespace std;

enum Type
{
	INT,
	FLOAT,
	CHAR
};

int main()
{
	int i = 5;
	float f = 3.0;
	char c = 'a';

	void* ptr = nullptr; 

	ptr = &i;
	ptr = &f;
	ptr = &c;

	int* ptr_i = &i;
	cout << ptr_i + 1 << endl; // int pointer는 이런식으로 4byte 연산 가능 

	// cout << ptr + 1 << endl; 와 같은 포인터 연산 불가
	// 어떤타입의 몇 바이트 인지 모르기때문에 불가

	Type type = FLOAT;


	if (type == FLOAT)
		cout << *static_cast<float*>(ptr) << endl; //void 포인터의 경우 강제 형 

	return 0;

}