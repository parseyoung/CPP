// 단순비교문자열부터 구현
// 시간복잡도 O(N*M) 효율적이지 X, 단순하고, 직관적인 알고리즘

#include <iostream>
using namespace std;

int findString(string parent, string pattern) {
	int parentSize = parent.size();
	int patternSize = pattern.size();
	for (int i = 0; i <= parentSize - patternSize; i++) {
		bool finded = true;
		for (int j = 0; j < patternSize; j++) {
			if (parent[i + j] != pattern[j]) {
				finded = false;
				break;
			}
		}
		if (finded) return i;
	}
	return -1;
}

int main(void) {
	string parent = "Hello World";
	string pattern = "llo";
	int result = findString(parent, pattern);
	if (result == -1) cout << "찾을 수 없습니다";
	else cout << result + 1 << " 번 째에서 찾았습니다" << endl;
	return 0;
}