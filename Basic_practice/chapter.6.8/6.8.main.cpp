#include <iostream>

using namespace std;

struct Mystruct
{
	int array[5]{ 9, 7, 5, 3, 1 };
};

void doSomething(Mystruct* ms)
// array�� struct�� class�ȿ� ������ ������ �����ͷ� �� ��ȯ �Ͼ�� ����
{
	cout << sizeof((*ms).array) << endl; //20

}
int main()
{
	Mystruct ms;
	cout << ms.array[0] << endl;
	cout << sizeof(ms.array) << endl;

	doSomething(&ms);

	//int * ptr = array;
	//cout << *ptr << " " << *(ptr + 1) << endl; 
	// ptr + 1 �ϸ� 7�� �ҷ���

	//cout << array << endl;
	//cout << &array[0] << endl;
	// ù��° ���� �ּҰ��� ����
	// ���� array�� �ᱹ�� pointer��.
	

	return 0;

}