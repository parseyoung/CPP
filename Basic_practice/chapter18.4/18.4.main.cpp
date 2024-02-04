// stream states(흐름 상태)와 input validation(입력 유효성) 검증
#include <iostream>
#include <cctype>
#include <string>
#include <bitset>
using namespace std;

// stream의 상태 검증
void printCharacterClassification(const int& i)
{
	cout << boolalpha;
	cout << "isalnum" << bool(std::isalnum(i)) << " " << endl;
	cout << "isblank" << bool(std::isblank(i)) << " " << endl;
	cout << "isdigit" << bool(std::isdigit(i)) << " " << endl;
	cout << "islower" << bool(std::islower(i)) << " " << endl;
	cout << "isupper" << bool(std::isupper(i)) << " " << endl;
}

// state(int, char) 분류 검증
void printStates(const std::ios& stream)
{
	cout << boolalpha;
	cout << "good()=" << stream.good() << endl;
	cout << "eof()=" << stream.eof() << endl;
	cout << "fail()=" << stream.fail() << endl;
	cout << "bad()=" << stream.bad() << endl;
}

// 한 글자씩 모두 isdigit인지 확인 하는 func, 형식 검증
bool isAllDigit(const string& str)
{
	bool ok_flag = true;

	for (auto e : str)
		if (!std::isdigit(e))
		{
			ok_flag = false;
			break;
		}

	return ok_flag;
}

int main()
{
	while (true)
	{
		char i;
		cin >> i;

		// printStates(cin);

		/*cout << boolalpha;
		cout << std::bitset<8>(cin.rdstate()) << endl;
		cout << std::bitset<8>(std::istream::goodbit) << endl;
		cout << std::bitset<8>(std::istream::failbit) << endl;
		cout << !bool(cin.rdstate() & std::istream::failbit) != 0) << endl;*/

		// printCharacterClassification(i);

		//cin.clear();
		//cin.ignore(1024, '\n');
		//cout << endl;

		cout << boolalpha;
		cout << isAllDigit("1234") << endl; // true
		cout << isAllDigit("a1234") << endl; // false

		// regular expression 은 다음 강의
	}
}