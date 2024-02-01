// 강한 결합 요소 (Strongly Connected Component, SCC)
// 방향 그래프 안에서 강하게 결합된 정점 집합 (사이클)
// 코사라주(Kosaraju's algorithm), 타잔 알고리즘(Tarjan's algorithm)이 있음
// 타잔 알고리즘이 구현은 어렵지만 적용이 더 쉬움
// 타잔 알고리즘 : 모든 정점에 대해 DFS 수행하여 SCC 찾는 알고리즘
// 시간복잡도는 O(V + E), 정점의 갯수 + 간선의 갯수 (위상정렬과 동일)

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 10001;

int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int>> SCC; // 한 그래프에서 여러개 나오기에 2차원 vec
stack<int> s;

// DFS는 총 정점의 갯수만큼 실행
int dfs(int x) {
	d[x] = ++id; // node마다 고유 번호 할당
	s.push(x); // 스택에 자기 자신 삽입

	int parent = d[x];
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		// 방문하지 않은 이웃
		if (d[y] == 0) parent = min(parent, dfs(y));
		// 처리 중인 이웃
		else if (!finished[y]) parent = min(parent, d[y]);
	}
	// 부모노드가 자기 자신인 경우
	if (parent == d[x]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == x) break;
		}
		SCC.push_back(scc);
	}
	// 자식의 부모 반환
	return parent;
}
int main(void) {
	int v = 11;
	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);
	a[4].push_back(2);
	a[4].push_back(5);
	a[5].push_back(7);
	a[6].push_back(5);
	a[7].push_back(6);
	a[8].push_back(5);
	a[8].push_back(9);
	a[9].push_back(10);
	a[10].push_back(11);
	a[11].push_back(3);
	a[11].push_back(8);
	for (int i = 1; i <= v; i++) {
		if (d[i] == 0) dfs(i);
	}
	cout << "SCC의 갯수 : " << SCC.size() << endl;
	for (int i = 0; i < SCC.size(); i++) {
		cout << i + 1 << "번 째 SCC : " << ' ';
		for (int j = 0; j < SCC[i].size(); j++) {
			cout << SCC[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
 }
