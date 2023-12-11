// virtual function �� polymorphism
// ���� Ŭ������ �������̵� �� �Լ��� ������ �װ� ȣ�� ��
// virtual Ű����� ���� Ŭ������ ������ ���� Ŭ�������� �ڵ����� ����
// ������ �������� ���� �߰��� �����ִ°� ����
// �� �ǽð� ����, ���ӿ����� virtual Ű���� ���� ����ϸ� ������ ����

#include <iostream>
using namespace std;

class A
{
public:
	void print() { cout << "A" << endl; }
};

class B : public A
{
public:
	virtual void print() { cout << "B" << endl; }
};

class C : public B
{
public: 
	void print() { cout << "C" << endl; }
};

class D : public C
{
public: 
	void print() { cout << "D" << endl; }
};

int main()
{
	A a;
	B b;
	C c;
	D d;
	
	// ���۷���ver.
	A &ref = c;
	ref.print(); // A

	B& ref1 = c;
	ref1.print(); // C , virtual Ű���� ���� �ؼ� B ref���� C ���

	C& ref2 = d;
	ref2.print(); // D  , virtual Ű���� Ÿ���� �� ������, ���� Ŭ���� B����
				 // ����Ǿ� ���� Ŭ���� C���� ����

	// ������ver.
	/*A* ptr = &c;
	ptr->print();*/
	

}