/* 
방어적 프로그래밍의 개념

*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int x;
	cin >> x;

	// semantic error (논리 오류) : 5가 입력 된 경우 = 등호가 있음에도 크다고 출력함
	if (x >= 5)
		cout << "x is better than 5" << endl;

	// violated assumption (가정 위반) : 사용자가 다른 의미로 사용함
	// 사용자를 고려하여 방어장치를 잘 만들어 놔야함

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


