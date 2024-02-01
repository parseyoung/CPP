// ��������(Topology Sort)�� �Ӱ���(Critical Path)���ϴ� �˰���
// �� ������ ���������� 0�̸� ť�� �ְ� ������ ����� ť���� pop�ϴ� ������� ���
// ���� �ð����� �ð� �� �����ɸ��� ��� �߻��ϸ� ����ؼ� �����ϴ� ���
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