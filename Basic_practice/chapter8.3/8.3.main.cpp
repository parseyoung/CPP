// Constructors 생성자
#include <iostream>
using namespace std;

class Second
{
public:
	Second()
	{
		cout << "class second constructor()" << endl;
	}
};

class First
{
	Second sec;

public:
	First()
	{
		cout << "class First constructor()" << endl;
	}
};
class Fraction
{
private: // 캡슐화
	int m_numerator; // 분자
	int m_denominator; // 분모
	// 초기화시 기본값을 넣을 수 있음, 생성자를 사용할 수도 있음

public:
	
	Fraction(const int& num_in = 3, const int& den_in = 3)
		// 클래스의 이름과 동일하면 생성자, 자동으로 바로 실행 됨
		// default 넣어줄 수 있음
	{
		m_numerator = num_in;
		m_denominator = den_in;
		cout << "Faction() constructor" << endl;
	}

public:
	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

int main()
{
	First fir;

	Fraction frac(1); // 생성자의 파라미터가 없을 경우 괄호를 사용하지 않고 호출함. 중요!
	frac.print();

	Fraction one_thirds(1, 5);
	// ( ) 는 warnning이 발생하지만 타입 변환 해도 컴파일 됨.
	Fraction two_thirds(3);
	Fraction three_thirds{ 3, 4 }; 
	// { } 유니폼초기화는 public일 경우에만 가능
	// { } 는 타입 변환을 허용 안 함.
	one_thirds.print();
	two_thirds.print();
	three_thirds.print();
}