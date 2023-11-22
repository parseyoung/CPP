//Nested types (클래스 안에 포함 된 자료형)

#include <iostream>

class Fruit
{
public:
	enum class FruitType
	{
		APPLE, BANANA, CHERRY
	};

	class InnerClass
	{
		// ...
	};

	struct InnerStruct
	{
		// ...
	};

private:
	FruitType m_type; //Member Variable

public:
	Fruit(FruitType type)
		: m_type(type)
	{}

	FruitType getType() { return m_type; }
};

int main()
{
	Fruit apple(Fruit::FruitType::APPLE);

	if (apple.getType() == Fruit::FruitType::APPLE)
	{
		std::cout << "APPLE" << std::endl;
	}

	return 0;
}
