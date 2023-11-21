// 재귀적 함수 호출(Recursive Function Call)
// 퍼포먼스가 중요한 프로그램일 경우 재귀를 사용 안 하는것이 나음(스택때문), 그래서 반복을 사용 함.
// 재귀호출은 자기 자신을 부르기에 스택오버플로우 가능성 높음 아니면 vector을 스택처럼 사용해서 구현 가능* /
//*메모이제이션(Memoization)**은 동적 계획법(Dynamic Programming)의 한 기법으로, 
//이전에 계산한 값을 저장해 두었다가 나중에 동일한 계산을 반복하지 않고 빠르게 결과를 얻을 수 있도록 하는 것입니다. 
//주로 재귀적인 알고리즘에서 중복 계산을 피하기 위해 사용됩니다.

#include <iostream>
#include <vector>

using namespace std;

vector<int> memo; //메모이제이션 위한 벡터

// 재귀함수 사용해서 피보나치수열 계산
int fibonacci(int n)
{
	if (n <= 1)
		return n;

	if (memo[n] != -1) //이미 계산한 값 있는지 확인
		return memo[n];

	// 계산한 값 없으면 계산하고 메모이제이션 
	memo[n] = fibonacci(n - 1) + fibonacci(n - 2);

	return memo[n];
}
int main()
{
	int n = 10;

	memo.resize(n + 1, -1); // memo 벡터 초기화

	cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;

	return 0;
}
