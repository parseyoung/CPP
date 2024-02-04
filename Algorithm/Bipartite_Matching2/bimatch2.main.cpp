// 이분 매칭(Bipartite Matching) 알고리즘 문제풀이
// 백준 11377 열혈강호3 
// 특정 직원만 2번 일함(k), 모든 직원 1번씩 매칭 수행 후, 특정 직원 수 만큼 추가 매칭
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1001;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int n, m, s, k;

// 매칭에 성공 true, 실패 flase
bool dfs(int x) {
	// x와 연결된 모든 노드에 대해서 들어갈 수 있는지 시도
	for (int i = 0; i < a[x].size(); i++) {
		int t = a[x][i];
		// 이미 처리한 노드는 더 이상 볼 필요 없음
		if (c[t]) continue;
		c[t] = true;
		// 비었거나 점유 노드에 들어갈 공간이 없는 경우
		if (d[t] == 0 || dfs(d[t])) {
			d[t] = x;
			return true;
		}
	}
	return false;
}

int main(void) {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= s; j++) {
			int t;
			cin >> t;
			a[i].push_back(t);
		}
	}
	int count = 0;

	for (int i = 1; i <= n; i++) {
		fill(c, c + MAX, false);
		if (dfs(i)) count++;
	}
	// 2번 작업하는 사람 k 추가 계산
	int extra = 0;
	for (int i = 1; i <= n && extra < k; i++) {
		fill(c, c + MAX, false);
		if (dfs(i)) extra++;
	}

	
	cout << count + extra << endl;
	return 0;
}
