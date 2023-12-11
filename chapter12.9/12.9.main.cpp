// object slicing(객체 잘림)과 reference_wrapper
// 다형성 유지 하면서 vector사용하기(ref, ptr)
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Base
{
public:
	int m_i = 0;

	virtual void print()
	{
		cout << "I'm base" << endl;
	}
};

class Derived : public Base
{
public:
	int m_j = 1;

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}
};

void doSomething(Base& b)
{
	b.print();
}

int main()
{
	Base b;
	Derived d;

	/* pointer ver.
	std::vector<Base*> my_vec;
	my_vec.push_back(&b);
	my_vec.push_back(&d);

	for (auto& ele : my_vec)
		ele->print();
	*/

	// reference ver.
	// vector은 & 이렇게 사용 해야 함.
	std::vector<std::reference_wrapper<Base>> my_vec;
	my_vec.push_back(b);
	my_vec.push_back(d);

	for (auto& ele : my_vec)
		ele.get().print();

	return 0;
}