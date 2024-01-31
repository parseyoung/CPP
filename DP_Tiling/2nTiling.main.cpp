// 다이나믹 프로그래밍 타일링 (Dynamic Programming Tailling)
// 2 * n 타일링하는 방법 수 10,007로 나눈 나머지 출력 (2*1, 2*2 크기 타일로 채우기)
// 경우의 수 : D[n] = D[n-1] + 2*D[n-2]

#include <iostream>
using namespace std;

int d[1001];

int dp(int x) {
	if (x == 1) return 1;
	if (x == 2) return 3; // n이 2일 경우 3가지 형태 반환 가능
	if (d[x] != 0) return d[x];
	return d[x] = dp(x - 1) + 2 * dp(x - 2) % 1007;
}

int main(void) {
	int x;
	cin >> x;
	cout << dp(x) << endl;

}
