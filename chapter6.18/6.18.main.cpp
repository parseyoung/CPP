//void pointer = generic pointer��� �Ҹ�

#include <iostream>

using namespace std;

enum Type
{
	INT,
	FLOAT,
	CHAR
};

int main()
{
	int i = 5;
	float f = 3.0;
	char c = 'a';

	void* ptr = nullptr; 

	ptr = &i;
	ptr = &f;
	ptr = &c;

	int* ptr_i = &i;
	cout << ptr_i + 1 << endl; // int pointer�� �̷������� 4byte ���� ���� 

	// cout << ptr + 1 << endl; �� ���� ������ ���� �Ұ�
	// �Ÿ���� �� ����Ʈ ���� �𸣱⶧���� �Ұ�

	Type type = FLOAT;


	if (type == FLOAT)
		cout << *static_cast<float*>(ptr) << endl; //void �������� ��� ���� �� 

	return 0;

}