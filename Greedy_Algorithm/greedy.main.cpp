// 그리디 알고리즘 (Greedy), 갈망법, 탐욕적기법
// 당장 눈 앞에 보이는 최적의 상황만을 쫓는 알고리즘
// 거스름돈(최적의 해) 알고리즘, sort기법 활용, Kruskall 알고리즘
#include <iostream>
using namespace std;

int main(void) {
	int n, result = 0;
	cin >> n;
	result += n / 500;
	n %= 500;
	result += n / 100;
	n %= 100;
	result += n / 50;
	n %= 50;
	result += n / 10;
	n %= 10;
	cout << result << endl;
	return 0;
}