// �Ű������� �⺻��
#include <iostream>

using namespace std;

void print(int x, int y = 10, int z = 30); 
// in header file�� ���� ��찡 ������ �̶��� �Լ� ������ �⺻�� ������ �ȉ�, ������ ���� �߻�

void print(int x, int y, int z)
{
	cout << x << " " << y << " " << z << " " << endl;
}

int main()
{
	print(100); // 100 10 30
	print(100, 200); // 100 200 30

	return 0;
}