// Derived 유도된 클래스의 생성과 초기화
// 상속 받은 경우 상위 클래스에서 선언된 변수까지
// 담을 수 있도록 큰 메모리 사이즈가 할당 됨
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
	// 생성자는 A, B, C 순서로 접근
	// 소멸자는 반대로 실행 됨 C, B, A
	return 0;
}