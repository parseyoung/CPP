// 가상소멸자 (virtual 소멸자)
// 소멸자 호출 순서는 생성자의 반대, 자식 부터 호출임
// virtual 키워드를 사용하면 자식 클래스 소멸자 삭제 할때 부모 클래스 소멸자
// 같이 삭제 가능. 메모리 동적 할당 시 누수 방지
#include <iostream>
using namespace std;

class Base
{
public:
	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
private:
	int* m_array;
public:
	Derived(int length)
	{
		m_array = new int[length];
	}

	virtual ~Derived() override // ~Base override
	{
		cout << "~Derived()" << endl;
		delete[] m_array;
	}
};

int main()
{
	//Derived dervied(5);

	Derived* dervied = new Derived(5);
	Base *base = dervied;
	delete base;
	// virtual 키워드 사용 안 하면 ~base()만 소멸
	// derived() 메모리 누수 발생

	return 0;
}