// 다이나믹 프로그래밍(Dynamic Programming)
// 하나의 문제는 단 한 번만 풀도록 하는 알고리즘
// 두 가지의 가정 하에 사용 가능
// 1. 큰 문제를 작은 문제로 나눌 수 있는 경우
// 2. 작은 문제에서 구한 정답은 그것을 포함하는 큰문제에서도 동일
// 시간복잡도 O(N)
#include <iostream>
using namespace std;
int d[100];

int fibodacci(int x) {
	// 일반적으로 피보나치 수열의 1,2번째는 1로 시작 함
	if (x == 1) return 1;
	if (x == 2) return 1;
	if (d[x] != 0) return d[x]; // momoization 기법 사용해서 중복 계산 X
 	return d[x] = fibodacci(x - 1) + fibodacci(x - 2);
}

int main(void) {
	cout << fibodacci(30) << endl;
}