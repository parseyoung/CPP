//�������� ������ �������ִ� ennum class
#include <iostream>

int main()
{
	using namespace std;

	enum class Color
	{
		YELLO,
		RED,
		GREAN,
	};

	enum class Fruit
	{
		BANANA,
		APPLE,
		KIWI,
	};

	Color color1 = Color::RED;
	Color color2 = Color::RED;
	
	if (color1 == color2)
		cout << "Same color " << endl;

	return 0;

}