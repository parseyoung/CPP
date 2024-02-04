// 퀵 정렬 (Quick sort)
// 기준 값을 기준으로 큰 숫자와 작은 숫자를 나눔 (분할 정복)
// 시간 복잡도 O(N*logN)
// 하지만 최악의 경우 O(N^2), 정렬이 잘 이루어져 있는 경우 분할 정복의 이점 사용 불가
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
		// 1, 2의 오른쪽 비교 값 부등호 방향 교체 시 내림차순 정렬

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