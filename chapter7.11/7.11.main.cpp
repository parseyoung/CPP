/*
std::vector를 stack처럼 사용하기
vector은 size와 capacity(용량)이 있음
capacity(용량)만큼 메모리를 가지고 있지만 그중에 몇 size를 사용한다 이런 느낌임
heap의 new, delete은 느림 안 쓰는게 좋음
vector을 잘 활용하는 방법은 new와 delete를 최대한 덜 호출하는 거임
*/

#include <iostream>
#include <vector>

using namespace std;

void printStack(const std::vector<int> &stack)
{
	for (auto& e : stack)
		cout << e << " ";
	cout << endl;
}

int main()
{
	std::vector<int> stack;

	// stack.resize(2);
	// stack.reserve(1024); // 메모리 용량 미리 확보
	// reserve 사용하면 배열 뒤 원소 추가 시 훨씬 속도 빠르게 구성 가능
	// reserve를 너무 크게 하면 빅데이터 다룰 때 다른 데이터 들어갈 공간이 없어 잘 써야함.

	stack.push_back(3);
	printStack(stack);

	stack.push_back(5);
	printStack(stack);

	stack.push_back(7);
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	return 0;
}