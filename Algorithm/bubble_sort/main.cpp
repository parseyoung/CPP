// 버블정렬 (bubble sort)
// 옆에 있는 것과 비교하여 앞으로 보냄
// 시간복잡도 O(N^2) (내부적 연산 가장 비효율)

#include <iostream>
using namespace std;
int main(void)
{
	int i, j, temp;
	int array[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 9 - i; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < 10; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}
