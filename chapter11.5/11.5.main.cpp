// 상속과 접근 지정자

#include <iostream>
using namespace std;

class Base
{
public:
	int m_public;
protected:
	int m_protected;
private:
	int m_private;
};

class Derived : protected Base
{
public: 
	Derived()
	{
		m_protected = 124;
		Base::m_public = 100;

		m_public = 100;
	}
};
class GrandChild : public Derived
{
public:
	GrandChild()
	{
		Derived::m_public;
	}
};

int main()
{
	Derived dervied;
	// m_protected = 124; 자식 클래스에서만 가능

	Base base;

	return 0;
}