/*
* ����� �μ� (Command Line Arguments)
* ����� �μ��� 1024 ����
* Boost library�� Program_options�� Command Line Arguments ó�� ȿ�������� �� �� ���� ����!
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	for (int count = 0; count < argc; ++count)
	{
		std::string argv_single = argv[count]; // string�� �� �ٲٰ�

		if (count == 1)
		{
			int input_number = std::stoi(argv_single); // ���������� �ٲ�
			cout << input_number + 1 << endl;
		}
		else
			cout << argv_single << endl;
	}
	return 0;
}