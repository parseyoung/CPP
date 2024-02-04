// 깊이 우선 탐색 (Depth First Search, DFS)
// 맹목적으로 노드 탐색시 사용, Stack or 재귀함수로 구현

#include <iostream>
#include <vector>
using namespace std;
int number = 7;
int c[7];
vector<int> a[8];

// 재귀함수로 구현
void dfs(int x) {
	if (c[x]) return;
	c[x] = true;
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		dfs(y);
	}
}

int main(void) {
	// 1과 2연결
	a[1].push_back(2);
	a[2].push_back(1);
	// 1과 3연결
	a[1].push_back(3);
	a[3].push_back(1);
	// ...
	a[2].push_back(3);
	a[3].push_back(2);

	a[2].push_back(4);
	a[4].push_back(2);

	a[2].push_back(5);
	a[5].push_back(2);

	a[3].push_back(6);
	a[6].push_back(3);

	a[3].push_back(7);
	a[7].push_back(3);

	a[4].push_back(5);
	a[5].push_back(4);

	a[6].push_back(7);
	a[7].push_back(6);

	dfs(1); // 1 2 3 6 7 4 5

	return 0;
}