// std::array

#include <iostream>
#include <array>
#include <algorithm> // sorting ���� ����

using namespace std;

void printLength(const array<int, 5>& my_arr)
// const �Ű������̱� ������ printLength()���� my_arr�� ������ ����
// array�� ǥ�� ���̺귯�� ���� &(���۷���)�� ������ �����ͷ� �� �� ��� �غ�����
// ������ �ƴϰ� ���۷����� �ϸ� �߰��� �����ϴ� ������ �����Ǿ� ����

// ������ �迭�� ���ο� �� �Ҵ�, �����Ҵ� (��, ũ�⸦ �ʰ��ϸ� ������ ���� �߻�) //

{
	cout << "printLength" << " " << my_arr.size() << endl;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	// ũ�� ���� �� �ص� �����׷��� �˾Ƽ� ��

	array<int, 5> my_arr = { 1, 2, 3, 4, 5 };
	// std::array���� ũ�� ���� �ؾ���

	my_arr = { 0, 7, 2 };

	for (const auto& element : my_arr)
		cout << element << " "; // 0 7 2 0 0
	cout << endl;

	std::sort(my_arr.begin(), my_arr.end()); // �迭�� ó��(begin) ���� ��(end)���� �������� ����

	for (const auto& element : my_arr)
		cout << element << " "; //0 0 0 2 7
	cout << endl;

	std::sort(my_arr.rbegin(), my_arr.rend());  // �迭�� ó��(begin) ���� ��(end)���� ���� ����
	for (const auto& element : my_arr)
		cout << element << " "; // 7 2 0 0 0
	cout << endl;


	//cout << my_arr.at(1) << endl;
	// at�� ����ϸ� ����ó�� �ߵ���Ŵ, but �ӵ��� ����

	cout << my_arr.size() << endl;
	// �迭�� ���� ����� Ȯ��

	printLength(my_arr);


	return 0;
}

