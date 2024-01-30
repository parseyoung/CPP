// �� ���� (Quick sort)
// ���� ���� �������� ū ���ڿ� ���� ���ڸ� ���� (���� ����)
// �ð� ���⵵ O(N*logN)
// ������ �־��� ��� O(N^2), ������ �� �̷���� �ִ� ��� ���� ������ ���� ��� �Ұ�
#include <iostream>
//#include <vector>
using namespace std;

void quickSort(int *data, int start, int end) {
	if (start >= end) {
		return;
	}
	int key = start;
	int i = start + 1, j = end, temp;

	while (i <= j) {
		while (i <= end && data[i] <= data[key]) { // ---- 1
			i++;
		}
		while (j > start && data[j] >= data[key]) { // ---- 2
			j--;
		}
		// 1, 2�� ������ �� �� �ε�ȣ ���� ��ü �� �������� ����

		if (i > j) {
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}
int main(void)
{
	int i;
	int number = 10;
	int data[] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	quickSort(data, 0, number - 1);
	for (i = 0; i < number; i++) cout << data[i] << " ";
	return 0;
}