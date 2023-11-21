/*
std::vector�� stackó�� ����ϱ�
vector�� size�� capacity(�뷮)�� ����
capacity(�뷮)��ŭ �޸𸮸� ������ ������ ���߿� �� size�� ����Ѵ� �̷� ������
heap�� new, delete�� ���� �� ���°� ����
vector�� �� Ȱ���ϴ� ����� new�� delete�� �ִ��� �� ȣ���ϴ� ����
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
	// stack.reserve(1024); // �޸� �뷮 �̸� Ȯ��
	// reserve ����ϸ� �迭 �� ���� �߰� �� �ξ� �ӵ� ������ ���� ����
	// reserve�� �ʹ� ũ�� �ϸ� ������ �ٷ� �� �ٸ� ������ �� ������ ���� �� �����.

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