/*
* 명령줄 인수 (Command Line Arguments)
* 명령줄 인수에 1024 넣음
* Boost library의 Program_options에 Command Line Arguments 처리 효율적으로 할 수 있음 참고!
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	for (int count = 0; count < argc; ++count)
	{
		std::string argv_single = argv[count]; // string으 로 바꾸고

		if (count == 1)
		{
			int input_number = std::stoi(argv_single); // 정수형으로 바꿈
			cout << input_number + 1 << endl;
		}
		else
			cout << argv_single << endl;
	}
	return 0;
}