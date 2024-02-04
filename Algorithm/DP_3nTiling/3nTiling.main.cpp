// 2 * N 벽을 2*1, 1*2, 1*1 크기의 타일로 채우는 경우의 수, 결과를 1000000007로 나눔
// D[n] = D[n-1]*2 + D[n-2]*3 + (D[n-3]*2 + D[n-4]*2 + D[n-5]*2 + ... D[0]*2)
#include <iostream>



/* 1차원 DP, O(N^2)

long long int d[1000001];

long long int dp(int x) {
	if (x == 0) return 1;
	if (x == 1) return 2;
	if (x == 2) return 7;
	if (d[x] != 0) return d[x];
	int result = 3 * dp(x - 2) + 2 * dp(x - 1);
	for (int i = 3; i <= x; i++) {
		result += (2 * dp(x - i)) % 1000000007;
	}
	return d[x] = result % 1000000007;
}
*/

// 시간 줄이고자 2차원 DP로 변경, O(N)
// overflow 발생 안 하도록 long long int 사용
long long int d[1000001][2];
const long long int slice = 1000000007;
long long int dp(int x) {
	d[0][0] = 0;
	d[1][0] = 2;
	d[2][0] = 7;
	d[2][1] = 1;
	for (int i = 3; i <= x; i++) {
		d[i][1] = (d[i - 1][1] + d[i - 3][0]) % slice;
		d[i][0] = (3 * d[i - 2][0] + 2 * d[i - 1][0] + 2 * d[i][1]) % slice;
	}
	return d[x][0];
}


int main(void) {
	long long int x;
	std::cin >> x;
	std::cout << dp(x) << std::endl;

	return 0;
}