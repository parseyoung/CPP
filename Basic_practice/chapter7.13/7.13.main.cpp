/* 
����� ���α׷����� ����

*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int x;
	cin >> x;

	// semantic error (�� ����) : 5�� �Է� �� ��� = ��ȣ�� �������� ũ�ٰ� �����
	if (x >= 5)
		cout << "x is better than 5" << endl;

	// violated assumption (���� ����) : ����ڰ� �ٸ� �ǹ̷� �����
	// ����ڸ� ����Ͽ� �����ġ�� �� ����� ������

	string hello = "Hello, my name is Jack jack";

	int ix;
	cin >> ix;
	while (true)
	{
		if (ix >= 0 && hello.size() - 1)
		{
			cout << hello[ix] << endl;
			break;
		}
		else cout << "Please try again" << endl;
	}
	return 0;
}


