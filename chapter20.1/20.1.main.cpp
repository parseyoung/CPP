// �������Ϸ��� ���� ����ȭ�� �ʿ��� �κ� ã�� ����
// ����ȭ�� ���� �ʿ��� ���� 80% ����ȭ �ϴ� �� ��ǥ
// ������ ���α׷� �������ϸ� �� ���, �޸𸮿� CPU�� ���� �� 
// �Ϲ����� ���α׷��� ���� �ص� ū ������ ������, ���輺�� ���� �� ����
// ����ȭ �� ���α׷��� ��ų�� �ƴ�(�Ѱ谡 ����), �˰��� ���踦 ����ȭ�ϴ� ���� ȿ������
// Debug mode ���ܵ��� Ȱ�� �������ϸ�
// ����׸��� ����� ������ ��� �ڵ带 �ڼ��ϰ� �� ���� ������, 
// �����ս��� ���� ��������� ���� �߻�
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <numeric> // std::inner_product
using namespace std;

void func1()
{
	long long sum = 0;
	for (unsigned i = 0; i < 100'000; ++i)
		sum += i;

	cout << sum << endl;
}

void func2()
{
	long long sum = 0;
	for (unsigned i = 0; i < 1000'000'000; ++i)
		sum += i;

	cout << sum << endl;
}

void run()
{
	func1();
	func2();
}
int main()
{

	//run();

	int* d = new int[10000];
	float* f = new float[100];

	delete[] d;
	delete[] f;

	return 0;

}