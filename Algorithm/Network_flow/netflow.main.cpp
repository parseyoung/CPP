// 네트워크 플로우 (Network flow) = 최대 유량 문제
// 특정 지점에서 다른 지점으로 데이터가 얼마나 많이 흐르고 있는지 측정
// 에드몬드 카프(Edmonds-Karp) 알고리즘 : BFS(너비우선탐색) 사용
// 가능한 모든 경로로 찾기 위해 음의 유량 까지 파악
// 표현 방식 : 유랑(Flow) / 용량(Capacity)
// 시간복잡도 O(VE^2) (정점*간선^2)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX{ 100 };
const int INF{ 100000000 };

int n{ 6 }, result;
int c[MAX][MAX], f[MAX][MAX], d[MAX];
vector<int> a[MAX];

void maxFlow(int start, int end) {
	while (1) {
		fill(d, d + MAX, -1);
		queue<int> q;
		q.push(start);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < a[x].size(); i++) {
				int y = a[x][i];
				// 방문하지 않은 노드 중에서 용량이 남은 경우
				if (c[x][y] - f[x][y] > 0 && d[y] == -1) {
					q.push(y);
					d[y] = x; // 경로 기억
					if (y == end) break; // 도착지 도달
				}
			}
		}
		// 모든경로 다 찾은 경우
		if (d[end] == -1) break;
		int flow = INF;
		// 거꾸로 최소 유량(음의 유량) 탐색
		for (int i = end; i != start; i = d[i]) {
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}
		// 최소 유량 만큼 추가
		for (int i = end; i != start; i = d[i]) {
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}
		result += flow;
	}
}
int main(void) {
	a[1].push_back(2);
	a[2].push_back(1);
	c[1][2] = 12;

	a[1].push_back(4);
	a[4].push_back(1);
	c[1][4] = 11;

	a[2].push_back(3);
	a[3].push_back(2);
	c[2][3] = 6;

	a[2].push_back(4);
	a[4].push_back(2);
	c[2][4] = 3;

	a[2].push_back(5);
	a[5].push_back(2);
	c[2][5] = 5;

	a[2].push_back(6);
	a[6].push_back(2);
	c[2][6] = 9;

	a[3].push_back(6);
	a[6].push_back(3);
	c[3][6] = 8;

	a[4].push_back(5);
	a[5].push_back(4);
	c[4][5] = 9;

	a[5].push_back(3);
	a[3].push_back(5);
	c[5][3] = 3;

	a[5].push_back(6);
	a[6].push_back(5);
	c[5][6] = 4;

	maxFlow(1, 6);
	cout << result << ' ';
	cout << endl;

	return 0;
}
