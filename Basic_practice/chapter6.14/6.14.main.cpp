// 참조변수

#include <iostream>

using namespace std;

struct Something
{
	int v1;
	float v2;
};

struct Other
{
	Something st;
};

int main()
{
	Other ot;

	int &v1 = ot.st.v1; // 이런식으로 참조변수로 접근하기 수원하게 만들기 가능
	v1 = 1;


	int value = 5;

	//int * ptr = nullptr;
	//ptr = &value;

	int &ref = value;
	// 반드시 초기화를 시켜야함, 단 리터럴은 넣을 수 없음 공식적으로 메모리 주소를 갖지 않기 때문임

	cout << ref << endl;

	ref = 10;

	const int y = 8;
	const int &ref = y;

	cout << &value << endl;
	cout << &ref << endl;
	//&value, &ref 값은 같음, 주소를 공유한다고 생각하면 될듯.
	return 0;

}