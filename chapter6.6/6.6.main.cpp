#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char source[] = "Copy this!";
	char dest[50];
	strcpy_s(dest, 50, source);
	//strcpy(dest, source)
	//strcat(dest, source) �� ���� ���� �ڿ� �ѹ� �� ������
	/*
	strcmp(source, dest)�� ������ 0, �ٸ��� - 1 ���
	�Ʒ�ó�� ����� ¥�� ��
	if (strcmp(source, dest) == 0)
	{

	}
	*/
	cout << source << endl;
	cout << dest << endl;

	return 0;
}