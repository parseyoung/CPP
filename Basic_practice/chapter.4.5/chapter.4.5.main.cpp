// 암시적 형변환과 명시적 형변환

#include <iostream>
#include <typeinfo>

int main()
{
	using namespace std;

	int a = 123.0;

	cout << typeid(a).name() << endl;

	//int a = static_cast<int>(4.0);
	cout << static_cast<int>(a) << endl;

	return 0;
}