// 유도 클래스에서 출력 연산자 사용하기
#include <iostream>
class Base
{
public:
	Base() {}


	friend std::ostream& operator << (std::ostream& out, const Base& b)
	{
		return b.print(out);
	}

	// friend 기능을 위임 받은 virtual 함수 생성하여 자식에게 override
	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Base";
		return out;
	}
};

class Dervied : public Base
{
public:
	Dervied() {}

	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Derived";
		return out;
	}
};

int main()
{
	Base b;
	std::cout << b << '\n';

	Dervied d;
	std::cout << d << '\n';

	Base& bref = d;
	std::cout << bref << '\n';

	return 0;
}