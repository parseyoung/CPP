// ���� Ŭ�������� ��� ������ ����ϱ�
#include <iostream>
class Base
{
public:
	Base() {}


	friend std::ostream& operator << (std::ostream& out, const Base& b)
	{
		return b.print(out);
	}

	// friend ����� ���� ���� virtual �Լ� �����Ͽ� �ڽĿ��� override
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