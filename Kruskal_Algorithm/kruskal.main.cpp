// 크루스칼알고리즘 (Kruskal Algorithm) 
// 가장 적은 비용으로 모든 노드 연결 (최소 비용 신장 트리)
// 간선을 거리가 짧은 순서대로 그래프에 포함, 단 사이클 생성 X
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 간선 클래스 선언
class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool const operator < (Edge& edge) const {
		return this->distance < edge.distance;
	}
};

// 부모 노드 찾는 함수(재귀적)
int getParent(vector<int>& parent, int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

// 두 부모 노드 합침
int unionParent(vector<int>& parent, int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) return parent[b] = a;
	return parent[a] = b;
}

// 같은 부모를 가지는지 확인
bool findParent(vector<int>& parent, int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	return 0;
}

int main(void) {

	int n = 7;
	int m = 11;

	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));

	// 간선 비용 기준으로 오름차순 정렬
	sort(v.begin(), v.end());

	// 각 정점이 포함된 그래프 어디인지 저장
	vector<int> parent(n);
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		// 사이클 발생 않는 경우 그래프에 포함
		if (!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) {
			sum += v[i].distance;
			unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}

	cout << sum << ' ' << endl; // 123
	return 0;
}
