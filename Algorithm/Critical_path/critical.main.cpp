// 위상정렬(Topology Sort)의 임계경로(Critical Path)구하는 알고리즘
// 각 정점의 진입차수가 0이면 큐에 넣고 간선을 지우고 큐에서 pop하는 방식으로 계산
// 현재 시간보다 시간 더 오래걸리는 경우 발생하면 계속해서 갱신하는 방식
#include <iostream>
#include <vector>
#include <queue>

#define MAX 501

using namespace std;

int n, inDegree[MAX], ttime[MAX], result[MAX];
vector<int> a[MAX];

void topology() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            result[i] = ttime[i];
            q.push(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (q.empty()) {
            return;
        }
        int x = q.front();
        q.pop();
        for (int i = 0; i < a[x].size(); i++) {
            int y = a[x][i];
            if (--inDegree[y] == 0) {
                q.push(y);
            }
            result[y] = max(result[y], result[x] + ttime[y]);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << result[i] << ' ';
    }
    cout << endl;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ttime[i];
        while (1) {
            int x;
            cin >> x;
            if (x == -1) break;
            inDegree[i]++;
            a[x].push_back(i);
        }
    }
    topology();
}