// virtual Tables (���� �Լ� ǥ)
#include <iostream>
using namespace std;

class Base
{
public:
	//FunctionPointer *__vptr;
	void func1() {};
	void func2() {};
};

class Der : public Base
	//FunctionPointer *__vptr;
{
	void func1() {};
	virtual void func3() {};
};

int main()
{
	cout << sizeof(Base) << endl; // 1byte
	cout << sizeof(Der) << endl; // virtual�� 4byte , funcptr ��� ������

	return 0;
}