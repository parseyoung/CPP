// 힙정렬 (Heap sort)
// 시간복잡도 : O(N * log N)
// Heap Tree Structure : 최소값이나 최대값을 빠르게 찾기 위해 완전 이진트리 기반으로 함
// 최대 힙 : 부모노드가 자식노드보다 큰 힙
// 힙 생성 알고리즘(Heapify Algorithm)을 활용해 부모와 자식의 위치를 바꿔 힙 구조 유지 가능
// 힙 정렬은 병합 정렬과 다르게 추가적 배열이 필요하지 않아 메모리 측면에서 효율적
// 항상 N * log N 보장, 속도만 비교하면 퀵 정렬이 평균적으로 더 빠음 
#include <iostream>

int number = 9;
int heap [9]= { 7, 6, 5, 8, 3, 9, 1, 6};

int main(void) {
	// 전체 트리 구조를 최대 힙 구조로 바꿈
	for (int i = 1; i < number; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;
			if (heap[root] < heap[c]) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while (c != 0);
	}

	// 크기를 줄여가며 반복적으로 힙 구성(정렬)
	for (int i = number - 1; i >= 0; i--) {
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c = 1;
		do {
			c = 2 * root + 1;
			// 자식 중 더 큰 값 찾기
			if (heap[c] < heap[c + 1] && c < i - 1) {
				c++;
			}
			// root 보다 자식이 더 크면 교환
			if (heap[root] < heap[c] && c < i) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		} while (c < i);
	}
	for (int i = 0; i < number; i++) std::cout << heap[i] << " ";


	return 0;
}