// ��������

#include <iostream>

using namespace std;

struct Something
{
	int v1;
	float v2;
};

struct Other
{
	Something st;
};

int main()
{
	Other ot;

	int &v1 = ot.st.v1; // �̷������� ���������� �����ϱ� �����ϰ� ����� ����
	v1 = 1;


	int value = 5;

	//int * ptr = nullptr;
	//ptr = &value;

	int &ref = value;
	// �ݵ�� �ʱ�ȭ�� ���Ѿ���, �� ���ͷ��� ���� �� ���� ���������� �޸� �ּҸ� ���� �ʱ� ������

	cout << ref << endl;

	ref = 10;

	const int y = 8;
	const int &ref = y;

	cout << &value << endl;
	cout << &ref << endl;
	//&value, &ref ���� ����, �ּҸ� �����Ѵٰ� �����ϸ� �ɵ�.
	return 0;

}