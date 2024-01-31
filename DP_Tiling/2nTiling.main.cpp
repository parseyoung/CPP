// ���̳��� ���α׷��� Ÿ�ϸ� (Dynamic Programming Tailling)
// 2 * n Ÿ�ϸ��ϴ� ��� �� 10,007�� ���� ������ ��� (2*1, 2*2 ũ�� Ÿ�Ϸ� ä���)
// ����� �� : D[n] = D[n-1] + 2*D[n-2]

#include <iostream>
using namespace std;

int d[1001];

int dp(int x) {
	if (x == 1) return 1;
	if (x == 2) return 3; // n�� 2�� ��� 3���� ���� ��ȯ ����
	if (d[x] != 0) return d[x];
	return d[x] = dp(x - 1) + 2 * dp(x - 2) % 1007;
}

int main(void) {
	int x;
	cin >> x;
	cout << dp(x) << endl;

}
