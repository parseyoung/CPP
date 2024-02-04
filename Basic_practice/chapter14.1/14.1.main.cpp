// Exception Handling (예외처리의 기본)
// 예외처리는 형변환이 엄격함
// try catch throw 말고 퍼포먼스를 위해서는 (예측 불가능한 경우가 잦은 경우)
// 일반적인 프로그래밍 범위 내에서 예외처리를 해결함 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// findFirstChar에서 -1이 나오면 예외 발생임을 미리 알고 있어야 하는 예외처리 
int findFirstChar(const char* string, char ch)
{
	for (std::size_t index = 0; index < strlen(string); ++index)
		if (string[index] == ch)
			return index;
	
	return -1; //no match
} 

double divide(int x, int y, bool& success)
{
	if (y == 0)
	{
		success = false;
		// 이 외에는 true
		return 0.0;
	}

	success = false;
	return static_cast<double>(x) / y;
}
int main()
{

	bool success;
	double result = divide(5, 3, success);

	if (!success)
		std::cerr << "An error occurred" << std::endl;
	else
		std::cout << "Result is" << result << std::endl;

	std::ifstream input_file("temp.txt");
	if (!input_file)
		std::cerr << "Cannot open file" << endl;

	// try, catch, throw
	double x;
	cin >> x;

	try
	{
		if (x < 0.0) throw std::string("Negative input");

		cout << std::sqrt(x) << endl;
	}

	catch (std::string error_message)
	{
		cout << error_message << endl;
	}

	return 0;
}