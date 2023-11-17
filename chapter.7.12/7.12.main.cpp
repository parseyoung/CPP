// 재귀적 함수 호출(Recursive Function Call)
// 아직 완강 x 11/18 이어서 진행

#include <iostream>
using namespace std;

void countDown(int count)
{
	cout << count << endl;
	countDown(count - 1);

}

int main()
{
	countDown(5);
	return 0;
}
