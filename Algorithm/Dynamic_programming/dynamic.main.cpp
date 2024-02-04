// ���̳��� ���α׷���(Dynamic Programming)
// �ϳ��� ������ �� �� ���� Ǯ���� �ϴ� �˰���
// �� ������ ���� �Ͽ� ��� ����
// 1. ū ������ ���� ������ ���� �� �ִ� ���
// 2. ���� �������� ���� ������ �װ��� �����ϴ� ū���������� ����
// �ð����⵵ O(N)
#include <iostream>
using namespace std;
int d[100];

int fibodacci(int x) {
	// �Ϲ������� �Ǻ���ġ ������ 1,2��°�� 1�� ���� ��
	if (x == 1) return 1;
	if (x == 2) return 1;
	if (d[x] != 0) return d[x]; // momoization ��� ����ؼ� �ߺ� ��� X
 	return d[x] = fibodacci(x - 1) + fibodacci(x - 2);
}

int main(void) {
	cout << fibodacci(30) << endl;
}