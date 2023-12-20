// ragular expressions (���� ǥ���� �Ұ�)
#include <iostream>
#include <regex>
using namespace std;

int main()
{
	// ���۷��� �޴��� ���鼭 �ٸ� ��Ģ �����Ͽ� ���� �ϸ� ��
	
	//regex re("\\d+"); // ���� �Ǵ�
	//regex re("[ab]"); // a, b �� match
	//regex re("[[:digit:]]{3}"); // digit 3���� ����
	//regex re("[A-Z]+");
	//regex re("[A-Z]{1,5}"); // A-Z �ּ� 1�� �ִ� 5��
	regex re("([0-9]{1})([-]?)([0-9]{1,4})"); // ([-]?) : - �־ ok, ��� ok

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