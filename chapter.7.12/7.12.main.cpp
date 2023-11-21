// ����� �Լ� ȣ��(Recursive Function Call)
// �����ս��� �߿��� ���α׷��� ��� ��͸� ��� �� �ϴ°��� ����(���ö���), �׷��� �ݺ��� ��� ��.
// ���ȣ���� �ڱ� �ڽ��� �θ��⿡ ���ÿ����÷ο� ���ɼ� ���� �ƴϸ� vector�� ����ó�� ����ؼ� ���� ����* /
//*�޸������̼�(Memoization)**�� ���� ��ȹ��(Dynamic Programming)�� �� �������, 
//������ ����� ���� ������ �ξ��ٰ� ���߿� ������ ����� �ݺ����� �ʰ� ������ ����� ���� �� �ֵ��� �ϴ� ���Դϴ�. 
//�ַ� ������� �˰��򿡼� �ߺ� ����� ���ϱ� ���� ���˴ϴ�.

#include <iostream>
#include <vector>

using namespace std;

vector<int> memo; //�޸������̼� ���� ����

// ����Լ� ����ؼ� �Ǻ���ġ���� ���
int fibonacci(int n)
{
	if (n <= 1)
		return n;

	if (memo[n] != -1) //�̹� ����� �� �ִ��� Ȯ��
		return memo[n];

	// ����� �� ������ ����ϰ� �޸������̼� 
	memo[n] = fibonacci(n - 1) + fibonacci(n - 2);

	return memo[n];
}
int main()
{
	int n = 10;

	memo.resize(n + 1, -1); // memo ���� �ʱ�ȭ

	cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;

	return 0;
}
