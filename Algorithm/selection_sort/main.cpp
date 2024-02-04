// 선택 정렬 (selection sort)
// 가장 작은 것을 비교해서 앞으로 보내는 기법
// 시간복잡도 : O(N^2) (비효율적)
#include <iostream>
using namespace std;

int main(void) {
    int i, j, min, index, temp;
    int array[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

    for (i = 0; i < 10; i++) {
        min = 9999;
        for (j = i; j < 10; j++) {
            if (min > array[j]) {
                min = array[j];
                index = j;
            }
        }
        temp = array[i];
        array[i] = array[index];
        array[index] = temp;
    }

    for (i = 0; i < 10; i++) {
        std::cout << array[i] << " ";
    }
    return 0;
}

