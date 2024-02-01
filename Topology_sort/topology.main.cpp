// 위상 정렬 (Topology Sort) 
// 순서가 정해져 있는 작업 차례로 수행 할때 순서 결정 알고리즘
// 사이클이 발생하는 경우 위상정렬 사용 X
// 시작점이 존재해야지만 수행 가능한 알고리즘
// 두 가지의 해결책을 내는 특징이 있음
// 1. 현재 그래프는 위상 정렬이 가능한지
// 2. 가능하다면 그 결과는 무엇인지
// stack과 queue 사용해서 구현 가능, queue 선호 함
// 시간복잡도는 O(V + E) , 정점의 갯수 + 간선의 갯수, 매우 빠른 알고리즘
#include <iostream>
#include <vector>
#include <queue>
//#define MAX 10
const int MAX = 10;
using namespace std;

int n, inDegree[MAX];
vector<int> a[MAX];

void toplogySort() {
	int result[MAX];
	queue<int> q;
	// 진입 차수 0인 node queue에 삽입
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}
	// 위상 정렬이 완전히 수행되려면 정확히 N개의 노드 방문
	for (int i = 1; i <= n; i++) {
		// n개를 방문하기 전에 큐가 빈다면 사이클 발생
		if (q.empty()) {
			cout << "사이클이 발생했습니다." << endl;
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			// 새롭게 진입차수가 0이 된 정점을 큐에 삽입
			if (--inDegree[y] == 0) {
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << result[i] << ' ';
	}
	cout << endl;
}
int main(void) {

	n = 7;
	a[1].push_back(2);
	inDegree[2]++;
	a[1].push_back(5);
	inDegree[5]++;
	a[2].push_back(3);
	inDegree[3]++;
	a[3].push_back(4);
	inDegree[4]++;
	a[4].push_back(6);
	inDegree[6]++;
	a[5].push_back(6);
	inDegree[6]++;
	a[6].push_back(7);
	inDegree[7]++;
	toplogySort();

	return 0;
}