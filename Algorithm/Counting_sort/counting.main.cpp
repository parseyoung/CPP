// 계수 정렬 (Counting sort)
// 범위 조건이 있는 경우에 한해서 속도가 빠름 (크기 기준 counting)
// 단, 데이터의 크기가 한정된 경우에만 사용 가능
// 시간 복잡도 : O(N)
#include <iostream>
using namespace std;

int main(void) {

	int temp;
	int count[5];
	int array[30] = {
		1, 3, 2, 4, 3, 2, 5, 3, 1, 2,
		3, 4, 4, 3, 5, 1, 2, 3, 5, 2,
		3, 1, 4, 3, 5, 1, 2, 1, 1, 1
	};
	for (int i = 0; i < 5; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < 30; i++) {
		count[array[i] - 1] ++;
	}
	for (int i = 0; i < 5; i++) {
		cout << "Element" << i + 1 << ":";
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++) {
				cout << " " << i + 1 << " ";
			}
			cout << " ( " << count[i] << " ) " << endl;
		}
	}
	return 0;
}