// �������� (insertion sort)
// �ʿ��� ��쿡�� ��ġ �ٲ�, ������ ��ġ�� ����
// �ð����⵵ O(N^2) (���� ���ĵ� ���¿��� ���� ȿ����)

#include <iostream>
using namespace std;

int main(void) {

	int i, j, temp;
	int array[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	for (i = 0; i < 10; i++) {
		j = i;
		while (j > 0 && array[j - 1] > array[j]) {
			temp = array[j - 1];
			array[j - 1] = array[j];
			array[j] = temp;
			j--;
		}

	}
	for (i = 0; i < 10; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

	return 0;
}
