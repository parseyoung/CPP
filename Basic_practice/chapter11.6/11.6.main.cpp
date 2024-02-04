// Derived(유도된)클래스에 새로운 기능 추가
// 상위 클래스 public 으로 getvalue() 만들어서 
// value 접근 해도 되지만, 퍼포먼스가 떨어질 경우도 있음
// 상황 봐서 protected로 하위 클래스 접근 가능 하도록 하는 것도 방법임.

#include <iostream>
using namespace std;

class Base
{
protected:
	int m_value;
public:
	Base(int value)
		: m_value(value)
	{

	}
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base(value)
	{

	}
	void setValue(int value)
	{
		Base::m_value = value;
	}
};

int main()
{
	return 0;
}