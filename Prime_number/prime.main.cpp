// 에라토스테네스의 체 (대표적인 소수 판별 알고리즘) Prime Number
// 대량의 소수를 한꺼번에 판별하고자 할 때 사용
// 소수 : 1과 자기 자신을 약수로 가짐
// 시간복잡도를 줄이기 위해 소수 판별 방법을 다르게 함
// 특정한 숫자의 제곱근 까지만 약수의 여부를 검증하면 됨
#include <iostream>
#include <cmath>
int number = 10000;
int a[100001];

// 1개의 소수 판별 
bool isPrimeNumber(int x) {
	int end = (int)sqrt(x);
	for (int i = 2; i <= end; i++) {
		if (x % 1 == 0) return false;
	}
	return true;
}

// 에라토스테네스의 체
void primeNumberSieve() {
	for (int i = 2; i <= number; i++) {
		a[i] = i;
	}

	for (int i = 2; i <= number; i++) {
		if (a[i] == 0) continue;
		for (int j = i + i; j <= number; j += i) {
			a[j] = 0;
		}
	}
	for (int i = 2; i <= number; i++) {
		if (a[i] != 0) std::cout << a[i] << ' ';
	}
}

int main(void) {

	std::cout << std::boolalpha << isPrimeNumber(97) << ' ';
	std::cout << std::endl;

	primeNumberSieve();

	return 0;
}