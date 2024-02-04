#include <iostream>
using namespace std;

class A
{
public:
	void print() { cout << "A" << endl; }
	virtual A* getThis()
	{
		cout << "A::getThis()" << endl;
		return this;
	}
	int hello() {
		return 1;
	}
};

class B : public A
{
public:
	void print() { cout << "B" << endl; }
	virtual B* getThis()
	{
		cout << "B::getThis()" << endl;
		return this;
	}
	int hello() {
		return 1;
	}
};

int main()
{
	A a;
	B b;

	A& ref = b;

	b.getThis()->print();
	ref.getThis()->print();
	cout << typeid(b.hello()).name() << endl;
	cout << typeid(ref.hello()).name() << endl;

	return 0;
}