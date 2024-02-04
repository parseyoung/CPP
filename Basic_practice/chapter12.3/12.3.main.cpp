// override, final, covariant(공변) 반환형
// 파라미터가 다르면 오버라이딩 불가, 오버로딩으로 인식
// 실수를 방지하기 위해 override 키워드 적용하면 컴파일러가 잘못을 잡아줌
// final 키워드를 사용하면 하위 클래스는 override 사용 막을 수 있음

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
	b.getThis()->print(); // B , virtual 키워드 때문에 B 출력
	ref.getThis()->print(); // A  , ref가 A&타입으로 선언 되었기에 A 반환

	cout << typeid(b.getThis()).name() << endl;
	cout << typeid(ref.getThis()).name() << endl; //class A* 출력
	// typied 연산자는 정적 타입(컴파일 타임 타입) 반영

	return 0;
}