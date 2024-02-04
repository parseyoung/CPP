// member func one more Templeatize (멤버함수 한번 더 템플릿)
#include <iostream>
#include <typeinfo>
using namespace std;

template<class T> //template<typename T>
class A
{
private:
	T m_value;
public:
	A(const T& input)
		: m_value(input)
	{}

	// TT는 doSomething에서만 적용되는 parameter
	template<typename TT>
	void doSomething(const TT & input)
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
		cout << (TT)m_value << endl;
	}

	void print()
	{
		cout << m_value << endl;
	}
};

int main()
{
	A<int> a_int(123);
	A<char> a_char(65);

	a_int.print();
	a_char.print();
	 //a_int.doSomething<float>(); parameter 없을 경우
	a_int.doSomething(13.0f);
	a_char.doSomething(char());
	

	return 0;
}