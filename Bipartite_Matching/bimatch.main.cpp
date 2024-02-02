// �̺� ��Ī (Bipartite Matching) 
// ���� ȿ�������� ��Ī������ �� �ִ� ��츦 �׷����� ǥ�� = �ִ��Ī(Max Matching)
// ���̿켱Ž��(DFS)���� �̺� ��Ī �ذ��ϸ� �ð����⵵ O(V*E)
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 101;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int n = 3, m, s;

// ��Ī�� �����Ѱ�� True, ���� False
bool dfs(int x) {
	// ����� ��� ��忡 ��ehd�ؼ� �� �� �ִ��� �õ�
	for (int i = 0; i < a[x].size(); i++) {
		int t = a[x][i];
		// �̹� ó���� ���� �� �ʿ� ����
		if (c[t]) continue;
		c[t] = true;
		// ����ְų� ���� ��忡 �� �� ���� �ִ� ���
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
	cout << count << " ���� ��Ī�� �̷�� �����ϴ�." << endl;
	for (int i = 1; i <= 100; i++) {
		if (d[i] != 0) {
			cout << d[i] << "->" << i << endl;
		}
	}
	return 0;
}