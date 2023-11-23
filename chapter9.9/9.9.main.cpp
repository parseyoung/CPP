// 복사 생성자, 복사 초기화,
// RVO(Return Value Optimization)
//디버그 모드와 릴리즈 모드의 차이는 최적화 수준 때문에 발생하며, RVO와 같은 최적화 기법이 사용될 때 복사 생성자 호출을 피할 수 있습니다. 
// 따라서 릴리즈 모드에서는 "Copy constructor called"가 출력되지 않는다.
#include <iostream>
#include <cassert>
using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int num = 0, int den = 1)
		: m_numerator(num), m_denominator(den)
	{
		assert(den != 0);
	}

	Fraction(const Fraction& fraction) // copy constructor 복사 생성자
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "Copy constructor called" << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Fraction& f)
	{
		out << f.m_numerator << " / " << f.m_denominator << endl;
		return out;
	}
};

Fraction doSomething()
{
	Fraction temp(1, 2);
	cout << &temp << endl;
	return temp;
}

int main()
{
	/*Fraction frac(3, 5);

	Fraction fr_copy(frac);

	cout << frac << " " << fr_copy << endl;*/
	
	Fraction result = doSomething();
	cout << &result << endl;
	cout << result << endl;
	return 0;
}
