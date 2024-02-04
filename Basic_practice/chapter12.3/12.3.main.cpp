// override, final, covariant(����) ��ȯ��
// �Ķ���Ͱ� �ٸ��� �������̵� �Ұ�, �����ε����� �ν�
// �Ǽ��� �����ϱ� ���� override Ű���� �����ϸ� �����Ϸ��� �߸��� �����
// final Ű���带 ����ϸ� ���� Ŭ������ override ��� ���� �� ����

#include <iostream>
using namespace std;

class A
{
public:
	void print() { cout << "A" << endl; }
	virtual A* getThis() { 
		cout << "A::getThis()" << endl;
		return this; }
};

class B : public A
{
public:
	virtual void print() { cout << "B" << endl; }
	virtual B* getThis() {
		cout << "B::getThis()" << endl;
		return this; }
};


class C : public B
{
public :
	virtual void print() final override { cout << "C" << endl; }
	virtual C* getThis() override { return this; }

};

class D 
{
public :
	void print(short x) { cout << "D" << endl; }
	D* getThis() { return this;  }
};

int main()
{
	A a;
	B b;
	C c;
	D d;

	A& ref = b;
	b.getThis()->print(); // B , virtual Ű���� ������ B ���
	ref.getThis()->print(); // A  , ref�� A&Ÿ������ ���� �Ǿ��⿡ A ��ȯ

	cout << typeid(b.getThis()).name() << endl;
	cout << typeid(ref.getThis()).name() << endl; //class A* ���
	// typied �����ڴ� ���� Ÿ��(������ Ÿ�� Ÿ��) �ݿ�

	return 0;
}