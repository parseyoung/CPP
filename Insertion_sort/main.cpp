// 삽입정렬 (insertion sort)
// 필요한 경우에만 위치 바꿈, 적절한 위치에 삽입
// 시간복잡도 O(N^2) (거의 정렬된 상태에서 제일 효율적)

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
