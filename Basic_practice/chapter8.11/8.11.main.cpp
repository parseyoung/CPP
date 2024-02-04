// static member function
// 정적 변수에만 접근 가능, 
#include <iostream>
using namespace std;

class Something
{
public:

	class _init
	{
	public:
		_init()
		{
			s_value = 999;
		}
	}; // 이너클래스 정의
	// static 멤버 변수의 값을 초기화 하는 것 처럼 간접적 구현 가능

private:
	static int s_value;
	int m_value{ 5 };
	static _init s_initializer; // 이너클래스를 static으로 생성

public:
	Something()
		: m_value(123) // static 생성자 초기화 불가 -> 이너 클래스로 해결
	{}

	static int getValue() 
	{
		return s_value;
	
	}   // static function은 this 키워드 사용 불가

	int temp() 
	{
		return this->s_value + this->m_value;
	}
};

int Something::s_value;
Something::_init Something::s_initializer;

int main()
{
	cout << Something::getValue() << endl;

	Something s1, s2;

	cout << s1.getValue() << endl;
	cout << s1.temp() << endl;

	// non-static 멤버 함수 포인터 선언
	// 특정 인스턴스와 연결을 무조건 시켜줘야 함
	int (Something:: * fptr1)() = &Something::temp;
	cout << (s2.*fptr1)() << endl;

	// static 멤버 함수 포인터 선언
	// 특정 인스턴스와 연결 X
	int (*fptr2)() = &Something::getValue;
	cout << fptr2() << endl;

	return 0;
}