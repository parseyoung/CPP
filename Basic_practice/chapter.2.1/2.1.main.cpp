#include <iostream>

int main()
{
	using namespace std;

	bool bValue = false;
	char chValue = 'A';
	float fValue = 3.14159f; // flot은 뒤에 'f'붙힘
	double dValue = 3.141592;

	auto aValue = 3.141592;
	auto aValue2 = 3.141592f; //auto 자동 결정 후 출력

	//변수 초기화의 3가지 방법
	int a = 123;
	// 직접 만든 데이터 초기화 하기 위해 아래 2개 사용
	int a(123); // direct initialization
	int b{ 123 }; // uniform initialization 

	// 같은 데이터만 여러개 동시 선언 가능
	int k, l, m = 123; // 맨 마지막만 초기화 권장 하지 않음
	int k = 0, l = 123, m = 456; //가급적 모두 초기화 권장


	cout << fValue << endl;
	cout << dValue << endl;

	cout << aValue << endl;
	cout << aValue2 << endl;

	//변수가 차지하는 메모리 공간 사이즈 출력 sizeof(변수 or 자료형)
	cout << sizeof(bool) << endl;
	cout << sizeof(bValue) << endl; 

	return 0;

}