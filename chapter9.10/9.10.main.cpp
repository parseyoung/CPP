// Converting constrictor (변환 생성자) explicit, delete
// 동적할당시 메모리 삭제하는 delete와 다른 의미임
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

	Fraction(const Fraction& fraction) // 복사 생성자
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << " copy constructor called" << endl;

	}

	friend std::ostream& operator << (std::ostream& out, const Fraction& f)
	{
		out << f.m_numerator << " / " << f.m_denominator << endl;
		return out;
	}
};

void doSomething(Fraction frac)
{
	cout << frac << endl;
}

int main()
{
	Fraction frac(7);
	doSomething(frac);
	doSomething(Fraction(9));
	doSomething(8);
	return 0;
}