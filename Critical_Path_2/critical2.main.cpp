// 위상정렬(Topology Sort)의 모든 임계경로(All Critical Path)구하는 알고리즘
// 모든 임계 경로 구하기 위해 역추적 수행

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1001;

class Edge {
public:
	int node;
	int time;
	Edge(int node, int time) {
		this->node = node;
		this->time = time;
	}
};

int n, start, finish;
int inDegree[MAX], result[MAX], c[MAX];
vector<Edge> a[MAX];
vector<Edge> b[MAX]; // 역추적

void topologySort() {
	queue<int> q;
	// 시작점 노드 큐에 삽입
	q.push(start);
	// 더이상 방문 노드 없을 때까지
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			Edge y = Edge(a[x][i].node, a[x][i].time);
			if (result[y.node] <= y.time + result[x]) {
				result[y.node] = y.time + result[x];
			}
			// 새롭게 진입차수가 0이 된 정점을 큐에 삽입
			if (--inDegree[y.node] == 0) q.push(y.node);
		}
		
	}
	// 결과 역추적
	int count = 0;
	q.push(finish);
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		for (int i = 0; i < b[y].size(); i++) {
			Edge x = Edge(b[y][i].node, b[y][i].time);
			// 최장경로에 포함되는 지 확인
			if (result[y] - result[x.node] == x.time) {
				count++;
			
				// 큐에는 한 번씩만 담아 추적
				if (c[x.node] == 0) {
					q.push(x.node);
					c[x.node] = 1;
				}
			}
		}
	}
	cout << result[finish] << ' ';
	cout << count << ' ';
}

int main(void) {
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, node, time;
		cin >> x >> node >> time;
		a[x].push_back(Edge(node, time));
		b[node].push_back(Edge(node, time));
		inDegree[node]++;
	}
	cin >> start >> finish;
	topologySort();
	return 0;
}