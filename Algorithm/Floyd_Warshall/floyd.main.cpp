// 플로이드 와샬 알고리즘 (Floyd Warshall)
// 모든 정점에서 모든 정점으로의 최단 경로 구하기
// 거처가는 정점을 기준으로 알고리즘을 수행 함
// X -> Y 최소비용 VS X에서 node 1 + node1에서 Y 비용
// D[2, 3] vs (D[2,1] + D[1,3])

#include <iostream>
using namespace std;

const int number = 4;
int INF = 100000000;

// 자료 배열 초기화
int a[4][4] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};

void floydWarshall() {
	// 결과 그래프 초기화 
	int d[number][number];

	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			d[i][j] = a[i][j];
		}
	}

	// K : 거쳐가는 노드, i : 출발 노드, j : 도착 노드
	for (int k = 0; k < number; k++) {
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < number; j++) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	// result print
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			cout << d[i][j] << ' ';;
		}
		cout << endl;

	}
}

int main(void) {
	floydWarshall();
	return 0;
}