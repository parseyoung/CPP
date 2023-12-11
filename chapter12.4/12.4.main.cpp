// ����Ҹ��� (virtual �Ҹ���)
// �Ҹ��� ȣ�� ������ �������� �ݴ�, �ڽ� ���� ȣ����
// virtual Ű���带 ����ϸ� �ڽ� Ŭ���� �Ҹ��� ���� �Ҷ� �θ� Ŭ���� �Ҹ���
// ���� ���� ����. �޸� ���� �Ҵ� �� ���� ����
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
	// virtual Ű���� ��� �� �ϸ� ~base()�� �Ҹ�
	// derived() �޸� ���� �߻�

	return 0;
}