#include <iostream>
#include <array>

using namespace std;

void printLength(const array<int, 5>& my_arr)
// const �Ű������̱� ������ printLength()���� my_arr�� ������ ����
// array�� ǥ�� ���̺귯�� ���� &(���۷���)�� ������ �����ͷ� �� �� ��� �غ�����
// ������ �ƴϰ� ���۷����� �ϸ� �߰��� �����ϴ� ������ �����Ǿ� ����
{
	cout << "printLength" << " " << my_arr.size() << endl;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	// ũ�� ���� �� �ص� �����׷��� �˾Ƽ� ��

	array<int, 5> my_arr = { 1, 2, 3, 4, 5 };
	// std::array���� ũ�� ���� �ؾ���
	my_arr = { 0, 1, 3, 5, 6 };
	my_arr = { 0, 1, 2 };

	cout << my_arr[1] << endl;
	// 10���� �迭�� ��� ������ ����, �ӵ��� �߿��� ��� ���

	cout << my_arr.at(1) << endl;
	// at�� ����ϸ� ����ó�� �ߵ���Ŵ, but �ӵ��� ����

	cout << my_arr.size() << endl;
	// �迭�� ���� ����� Ȯ��

	printLength(my_arr);


	return 0;
}

