// ragular expressions (정규 표현식 소개)
#include <iostream>
#include <regex>
using namespace std;

int main()
{
	// 레퍼런스 메뉴얼 보면서 다른 규칙 조합하여 적용 하면 됨
	
	//regex re("\\d+"); // 숫자 판단
	//regex re("[ab]"); // a, b 만 match
	//regex re("[[:digit:]]{3}"); // digit 3개만 가능
	//regex re("[A-Z]+");
	//regex re("[A-Z]{1,5}"); // A-Z 최소 1개 최대 5개
	regex re("([0-9]{1})([-]?)([0-9]{1,4})"); // ([-]?) : - 있어도 ok, 없어도 ok

	string str;

	while (true)
	{
		getline(cin, str);

		if (std::regex_match(str, re))
			cout << "Match" << endl;
		else
			cout << "No match" << endl;

		// print matches
		{
			auto begin = std::sregex_iterator(str.begin(), str.end(), re);
			auto end = std::sregex_iterator();
			for (auto itr = begin; itr != end; ++itr)
			{
				std::smatch match = *itr;
				cout << match.str() << " ";
			}
			cout << endl;
		}

		cout << endl;
	}

	return 0;
}