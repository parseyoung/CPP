// 다익스트라 알고리즘(Dijkstra Algorithm)
// 최단거리 알고리즘, 하나의 정점에서 다른 모든 정점의 최단 경로 
// 이전에 구한 정보를 사용하여 최단거리 구함

#include <iostream>
#include <vector>
#include <queue> // Heap과 같은 방식으로 동작
using namespace std;

int number = 6;
int INF = 10000000;

// 인접리스트 활용 방식으로, O(N * lohN)
vector<pair<int, int> > a[7]; // 간선 정보
int d[7]; // 최소 비용

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq; // Heap 구조
	// priority_queue : 큰 값을 기준으로 최상단 노드를 생성
	pq.push(make_pair(start, 0));
	// 가까운 순서대로 처리
	while (!pq.empty()) {
		int current = pq.top().first;
		// 큰 값이 먼저 오므로, 짧은 값이 먼저 오도록 음수화(-)
		int distance = -pq.top().second;
		pq.pop();
		// 최단거리 아닌 경우 Skip
		if (d[current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++) {
			// 선택된 노드의 인접 노드
			int next = a[current][i].first;
			// 선택된 노드 거쳐서 인접 노드로 가는 비용
			int nextDistance = distance + a[current][i].second;
			// 기존 최소 비용보다 저렴하면 교체
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

int main(void) {
	// 기본적으로 연결되지 않은 경우 비용은 무한
	for (int i = 1; i <= number; i++) {
		d[i] = INF;
	}
	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));

	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));

	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));

	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));

	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));

	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));

	dijkstra(1);

	// 결과 출력
	for (int i = 1; i <= number; i++) {
		cout << d[i] << ' ';
	}
	
	return 0;
}


/*  선형탐색 O(N^2), 비효율적
// 전체 그래프 초기화
int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0}

	bool v[6]; // 방문한 노드
	int d[6]; // 최단 거리

// 가장 최소거리 가지는 정점 반환
int getSmallIndex() {
	int min = INF;
	int index = 0;
	for (int i = 0; i < number; i++) {
		if (d[i] < min && !v[i]) {
			min = d[i];
			index = i;
		}
	}
	return index;
}
};
// 다익스트라 수행하는 함수
void dijkstra(int start) {
	for (int i = 0; i < number; i++) {
		d[i] = a[start][i];
	}
	v[start] = true;
	for (int i = 0; i < number - 2; i++) {
		int current = getSmallIndex();
		v[current] = true;
		for (int j = 0; j < 6; j++) {
			if (!v[j]) {
				if (d[current] + a[current][j] < d[j]) {
					d[j] = d[current] + a[current][j];
				}
			}
		}
	}
}
int main(void) {
	dijkstra(0);
	for (int i = 0; i < number; i++) {
		cout << d[i] << ' ';
	}

	return 0;
}

*/