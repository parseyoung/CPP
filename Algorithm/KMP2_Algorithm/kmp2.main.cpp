// 문자열 매칭 알고리즘 (Knuth-Morris-Pratts, KMP)
// 접두사와 접미사가 일치하는 최대 길이를 활용 해 빠르게 점프
#include <iostream>
#include <vector>
using namespace std;

// 접두사와 접미사의 최대 길이 table
vector<int> makeTable(string pattern) {
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	int j = 0;
	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			table[i] == ++j;
		}
	}
	return table;
}

void KMP(string parent, string pattern) {
	vector<int> table = makeTable(pattern);
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int j = 0;
	for (int i = 0; i < parentSize; i++) {
		while (j > 0 && parent[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (parent[i] == pattern[j]) {
			if (j == patternSize - 1) {
				cout << i - patternSize + 2 << " 번 째에서 찾았습니다" << endl;
				j = table[j];
			}
			else j++;
		}
	}
}

int main(void) {
	string parent = "ababacabacaabacaabaabacaaba";
	string pattern = "abacaaba";
	KMP(parent, pattern);
	return 0;
}
