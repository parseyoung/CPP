// Auto Ű����� �ڷ��� �߷�

#include <iostream>

auto add(int x, int y) //auto�� �Ķ���Ϳ��� ���Ұ�
{
	return x + y;
}

int main()
{
	using namespace std;

	auto a = 123; // ��, �ʱ�ȭ ���� ������ autoŰ���� ���Ұ�
	auto d = 123.0;
	auto c = 1 + 2.0;
	auto result = add(1, 2);

	cout << result << endl;

	return 0;

}