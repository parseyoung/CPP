// ��Ӱ� ���� ������

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
	// m_protected = 124; �ڽ� Ŭ���������� ����

	Base base;

	return 0;
}