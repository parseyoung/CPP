// Derived ������ Ŭ������ ������ �ʱ�ȭ
// ��� ���� ��� ���� Ŭ�������� ����� ��������
// ���� �� �ֵ��� ū �޸� ����� �Ҵ� ��
# include <iostream>

using namespace std;

class A
{
public:
	A(int a)
	{
		cout << "A : " << a << endl;
	}

	~A()
	{
		cout << "Destructur A" << endl;
	}
};



class B : public A
{
public:
	B(int a, double b)
		: A(a)
	{
		cout << "B : " << b << endl;
	}

	~B()
	{
		cout << "Destructur B" << endl;
	}
};

class C : public B
{
public:
	C(int a, double b, char c)
		: B(a, b)
	{
		cout << "C : " << c << endl;
	}

	~C()
	{
		cout << "Destructur C" << endl;
	}
};
int main()
{
	C c(1024, 3.14, 'a');
	// �����ڴ� A, B, C ������ ����
	// �Ҹ��ڴ� �ݴ�� ���� �� C, B, A
	return 0;
}