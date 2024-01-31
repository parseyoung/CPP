// �����佺�׳׽��� ü (��ǥ���� �Ҽ� �Ǻ� �˰���) Prime Number
// �뷮�� �Ҽ��� �Ѳ����� �Ǻ��ϰ��� �� �� ���
// �Ҽ� : 1�� �ڱ� �ڽ��� ����� ����
// �ð����⵵�� ���̱� ���� �Ҽ� �Ǻ� ����� �ٸ��� ��
// Ư���� ������ ������ ������ ����� ���θ� �����ϸ� ��
#include <iostream>
#include <cmath>
int number = 10000;
int a[100001];

// 1���� �Ҽ� �Ǻ� 
bool isPrimeNumber(int x) {
	int end = (int)sqrt(x);
	for (int i = 2; i <= end; i++) {
		if (x % 1 == 0) return false;
	}
	return true;
}

// �����佺�׳׽��� ü
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