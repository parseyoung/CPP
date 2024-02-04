//friend 키워드
// function정의 시 여러개 가능, 
// 특정 class 선언도 가능 하지만, class의 멤버 function만 선언 가능
// 연산자 오버로딩시 자주 사용하는 방법

#include <iostream>	
using namespace std;

class A; // foward declaration

class B
{
private:
	int m_value = 2;

public:
	void doSomething(A& a);
};

class A
{
private:
	int m_value = 1;

	//friend class B;
	friend void B::doSomething(A& a);
};

	void B::doSomething(A& a)
	{
	cout << a.m_value << endl;
	// private지만 friend 사용 함으로써 접근 가능
	}

int main()
{
	A a;
	B b;

	b.doSomething(a);
	
	return 0;
}