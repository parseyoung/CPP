// 합집합 찾기 (Union-Find) or 서로소 집합 알고리즘(Disjoint-Set)
// 대표적 그래프 알고리즘
// 부모를 합칠 때는 일반적으로 더 작은 값 쪽으로 합침(Union)
// 연결을 확인하기 위해 부모노드만 보고 파악 불가, *재귀함수 사용
// 크루스칼 알고리즘(Kruskal Algorithm)에 응용하여 적용 가능
#include <iostream>
// 부모 노드 찾는 함수(재귀적)
int getParent(int parent[], int x)
{
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

// 두 부모 노드 합침
int unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) return parent[b] = a;
	return parent[a] = b;
}

// 같은 부모를 가지는지 확인
bool findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	return 0;
}

int main(void) {

	int parent[11];
	for (int i = 1; i <= 10; i++) {
		parent[i] = i;
	}
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);
	std::cout << " 1과 5는 연결 되어 있나요?" << std::boolalpha << findParent(parent, 1, 5) << ' ' << std::endl;
	unionParent(parent, 1, 5);
	std::cout << " 1과 5는 연결 되어 있나요?" << std::boolalpha << findParent(parent, 1, 5) << ' ' << std::endl;


	return 0;
}