// virtual function 와 polymorphism
// 하위 클래스에 오버라이딩 된 함수가 있으면 그걸 호출 함
// virtual 키워드는 상위 클래스에 붙히면 하위 클래스에도 자동으로 적용
// 하지만 가독성을 위해 추가로 적어주는게 좋음
// 단 실시간 반응, 게임엔진에 virtual 키워드 자주 사용하면 느려짐 주의

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
	
	// 레퍼런스ver.
	A &ref = c;
	ref.print(); // A

	B& ref1 = c;
	ref1.print(); // C , virtual 키워드 적용 해서 B ref지만 C 출력

	C& ref2 = d;
	ref2.print(); // D  , virtual 키워드 타이핑 안 했지만, 상위 클래스 B에서
				 // 적용되어 하위 클래스 C에도 적용

	// 포인터ver.
	/*A* ptr = &c;
	ptr->print();*/
	

}