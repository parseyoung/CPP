// �̺� ��Ī(Bipartite Matching) �˰��� ����Ǯ��
// ���� 11377 ������ȣ3 
// Ư�� ������ 2�� ����(k), ��� ���� 1���� ��Ī ���� ��, Ư�� ���� �� ��ŭ �߰� ��Ī
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1001;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int n, m, s, k;

// ��Ī�� ���� true, ���� flase
bool dfs(int x) {
	// x�� ����� ��� ��忡 ���ؼ� �� �� �ִ��� �õ�
	for (int i = 0; i < a[x].size(); i++) {
		int t = a[x][i];
		// �̹� ó���� ���� �� �̻� �� �ʿ� ����
		if (c[t]) continue;
		c[t] = true;
		// ����ų� ���� ��忡 �� ������ ���� ���
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
	// 2�� �۾��ϴ� ��� k �߰� ���
	int extra = 0;
	for (int i = 1; i <= n && extra < k; i++) {
		fill(c, c + MAX, false);
		if (dfs(i)) extra++;
	}

	
	cout << count + extra << endl;
	return 0;
}
