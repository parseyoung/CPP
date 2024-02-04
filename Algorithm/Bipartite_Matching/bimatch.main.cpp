// 이분 매칭 (Bipartite Matching) 
// 가장 효과적으로 매칭시켜줄 수 있는 경우를 그래프로 표현 = 최대매칭(Max Matching)
// 깊이우선탐색(DFS)으로 이분 매칭 해결하면 시간복잡도 O(V*E)
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 101;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int n = 3, m, s;

// 매칭에 성공한경우 True, 실패 False
bool dfs(int x) {
	// 연결된 모든 노드에 대ehd해서 들어갈 수 있는지 시도
	for (int i = 0; i < a[x].size(); i++) {
		int t = a[x][i];
		// 이미 처리한 노드는 볼 필요 없음
		if (c[t]) continue;
		c[t] = true;
		// 비어있거나 점유 노드에 더 들어갈 공간 있는 경우
		if (d[t] == 0 || dfs(d[t])) {
			d[t] = x;
			return true;
		}
	}
	return false;
}
int main(void) {
	a[1].push_back(1);
	a[1].push_back(2);
	a[1].push_back(3);
	a[2].push_back(1);
	a[3].push_back(2);
	int count = 0;
	for (int i = 1; i <= n; i++) {
		fill(c, c + MAX, false);
		if (dfs(i)) count++;
	}
	cout << count << " 개의 매칭이 이루어 졌습니다." << endl;
	for (int i = 1; i <= 100; i++) {
		if (d[i] != 0) {
			cout << d[i] << "->" << i << endl;
		}
	}
	return 0;
}