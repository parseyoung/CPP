// 라빈카프(Rabin-Karp) 알고리즘
// 항상 빠르지는 않지만 일반적인 경우 빠르게 작동
// Hash(해시)기법 사용, 긴데이터를 짧은 데이터로 change
// 긴 글 해시 값 = 2 * (긴 글 해시 값 - 가장 앞에 있는 문자의 수치) + 새롭게 들어온 문자의 수치
// 시간복잡도 O(N)
#include <iostream>
using namespace std;

void findString(string parent, string pattern) {
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int parentHash = 0, patternHash = 0, power = 1;
	for (int i = 0; i <= parentSize - patternSize; i++) {
		if (i == 0) {
			for (int j = 0; j < patternSize; j++) {
				parentHash += parent[patternSize - 1 - j] * power;
				patternHash += pattern[patternSize - 1 - j] * power;
				if (j < patternSize - 1) power *= 2;
			}
		}
		else {
			parentHash = 2 * (parentHash - parent[i - 1] * power) +
				parent[patternSize - 1 + i];
		}
		if (parentHash == patternHash) {
			bool finded = true;
			for (int j = 0; j < patternSize; j++) {
				if (parent[i + j] != pattern[j]) {
					finded = false;
					break;
				}
			}
			if (finded) cout << i + 1 << " 번째에서 발견했습니다." << endl;
		}
	}
}
int main(void) {
	string parent = "ababacabacaabacaaba";
	string pattern = "abacaaba";
	findString(parent, pattern);
	return 0;
}