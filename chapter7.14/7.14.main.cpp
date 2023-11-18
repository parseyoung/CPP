/*
* �ܾ��ϱ� assert
* release ��忡���� assert ���� ����, debug ��忡���� �۵� �� ���� ã����
* assert�� ��Ÿ�ӿ� üũ��
* static assert�� ������ Ÿ�ӿ� ���� �߻�
* �����Ϸ��� �̿��ؼ� ���߿� ������ ���� �� �ִ� �κ��� �̸� ���� ����!!
*/
#include <iostream>
#include <cassert> //assert.h
#include <array>

void printValue(const std::array<int, 5>& my_ar, const int& ix)
{
	assert(ix >= 0);
	assert(ix <= my_ar.size() - 1);
	// && �����ڷ� �� �ٷ� ��ĥ �� ������ ���� �ľ��� ���� ������ �ϴ� ��찡 ����

	std::cout << my_ar[ix] << std::endl;
}
int main()
{
	std::array<int, 5> my_ar{ 1, 2, 3, 4, 5 };

	printValue(my_ar, 100);

	// static assert�� const ����϶� ��밡��, ������ ���� �� ����
	const int x = 5;
	static_assert(x == 10, "x should be 10(sy) ");;

	return 0;
}