/*
���� �Ҵ��� ������ ���� �̸� ���� ���־�� �� (const�� ����) const int leg = 5;
���� �Ҵ��� ��Ÿ�Ӷ� �迭�� ������ �����ϰ� os�κ��� �޸� �׶� �׋� �޾ƿ�
*/

#include <iostream>

using namespace std;

int main()
{
	int length;
	cin >> length;

	int* array = new int[length] {}; //{} �ȿ� �� ������ array[2]���� 0���� ä��

	array[0] = 1;
	array[1] = 2;

	for (int i = 0; i < length; ++i)
	{
		cout << (uintptr_t)&array[i] << endl;
		cout << array[i] << endl;

	}

	delete [] array; //new�� ����߱⿡ delete�� ���������� ���ִ� ���� ����
	return 0;


}
