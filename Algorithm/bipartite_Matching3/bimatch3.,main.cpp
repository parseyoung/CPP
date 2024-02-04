// 이분 매칭(Bipartite Matching) 알고리즘 문제풀이
// 백준 1671 상어의 저녁식사
// 2번씩 매칭, 단 상어의 능력 수치에 따라서 매칭 지시, 능력 수치 비굘하는 부분이 중요
// 02.02 디버깅 에러 발생 해결 해야함
#include <iostream>
#include <vector>
const int MAX = 1001;
using namespace std;


vector<int> a[MAX];
int stat[MAX][3];
int d[MAX];
bool c[MAX];
int n;

bool dfs(int x) {
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (c[y]) continue;
		c[y] = true;
		if (d[y] == 0 || dfs(d[y])) {
			d[y] = x;
			return true;
		}
	}
	return false;

}

int main(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> stat[i][0] >> stat[i][1] >> stat[i][2];
    }
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (stat[i][0] == stat[j][0] && stat[i][1] == stat[j][1] && stat[i][2] == stat[j][2])
                a[i].push_back(j);
            else if (stat[i][0] >= stat[j][0] && stat[i][1] >= stat[j][1] && stat[i][2] >= stat[j][2])
                a[i].push_back(j);
            else if (stat[i][0] <= stat[j][0] && stat[i][1] <= stat[j][1] && stat[i][2] <= stat[j][2])
                a[j].push_back(i);
        }
    }
    int count = 0;
    for (int k = 0; k < 2; k++) {
        for (int i = 1; i <= n; i++) {
            // 배열을 반복문으로 초기화
            for (int idx = 1; idx <= n; idx++) {
                c[idx] = false;
            }
            if (dfs(i)) count++;
        }
    }
    cout << n - count << endl;
    return 0;
}
