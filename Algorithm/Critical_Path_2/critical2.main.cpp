// ��������(Topology Sort)�� ��� �Ӱ���(All Critical Path)���ϴ� �˰���
// ��� �Ӱ� ��� ���ϱ� ���� ������ ����

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
vector<Edge> b[MAX]; // ������

void topologySort() {
	queue<int> q;
	// ������ ��� ť�� ����
	q.push(start);
	// ���̻� �湮 ��� ���� ������
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			Edge y = Edge(a[x][i].node, a[x][i].time);
			if (result[y.node] <= y.time + result[x]) {
				result[y.node] = y.time + result[x];
			}
			// ���Ӱ� ���������� 0�� �� ������ ť�� ����
			if (--inDegree[y.node] == 0) q.push(y.node);
		}
		
	}
	// ��� ������
	int count = 0;
	q.push(finish);
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		for (int i = 0; i < b[y].size(); i++) {
			Edge x = Edge(b[y][i].node, b[y][i].time);
			// �����ο� ���ԵǴ� �� Ȯ��
			if (result[y] - result[x.node] == x.time) {
				count++;
			
				// ť���� �� ������ ��� ����
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