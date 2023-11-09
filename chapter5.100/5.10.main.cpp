#include <iostream>

using namespace std;

int getInt()
{
	while (true)
	{
		cout << "Enter an integer number : ";
		int x;
		cin >> x;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '/n'); // 버퍼 초기화
			cout << "Invalid number, please try agin" << endl;
		}
		else
		{
			std::cin.ignore(32367, '/n');
			return x;
		}
	}

}

char getOperator()
{
	while (true)
	{
		cout << "Enter an operator (+, -) : ";
		char op;
		std::cin >> op;
		std::cin.ignore(32767, '/n');

		if (op == '+' || op == '-')
			return op;
		else
			cout << "Invalid operator, please try agin" << endl;
	}

}

void printResult(int x, char op, int y)
{
	if (op == '+') cout << x + y << endl;
	else if (op == '-') cout << x - y << endl;
	else
	{
		cout << "Invaild operator" << endl;
	}
}

int main()
{
	int x = getInt();
	char op = getOperator();
	int y = getInt();
		
	printResult(x, op, y);

	return 0;
}

