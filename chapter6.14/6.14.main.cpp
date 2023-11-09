#include <iostream>

using namespace std;

int main()
{

	int value = 5;

	//int * ptr = nullptr;
	//ptr = &value;

	int &ref = value;

	cout << ref << endl;

	ref = 10;

	cout << &value << endl;
	cout << &ref << endl;
	//&value, &ref 값은 같음, 주소를 공유한다고 생각하면 될듯.
	return 0;

}