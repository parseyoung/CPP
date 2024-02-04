//Inheritance (1. ����� �⺻)

#include <iostream>
using namespace std;

class Mother
{
// protected�� ��� �� �ڽĿ��� ���
// protected:
private:
	int m_i;
public:
	Mother(const int& i_in)
		: m_i(i_in)
	{
		std::cout << "Mother Constructour" << std::endl;
	}

	void setValue(const int& i_in)
	{
		m_i = i_in;
	}

	int getValue()
	{
		return m_i;
	}
};

class Child : public Mother 
{
private:
	double m_d;

public:
	Child(const int& i_in, const double& d_in)
		: Mother(i_in), m_d(d_in)
	{}

	void setValue(const int& i_in, const double& d_in)
	{
		// m_i = i_in; �� protected�� ��� ����
		Mother::setValue(i_in);
		m_d = d_in;
	}

	void setValue(const double& d_in)
	{
		m_d = d_in;
	}

	double getValue()
	{
		return m_d;
	}
};

int main()
{
	Mother mother(1024);
	mother.setValue(1024);
	cout << mother.getValue() << endl;

	Child child(1023, 128.0);
	//child.Mother::setValue(1023);
	//child.setValue(128);
	cout << child.Mother::getValue() << endl;
	cout << child.getValue() << endl;

	return 0;

}