#include <iostream>
/*
*ptr = 6;
dereferencing(�������Ͽ� value�� ���� �ٲ���)
const�ÿ��� ���� �ٲ��� ����.
*/

using namespace std;

/* 
const�� �ٴ� ��ġ�� ���� �ٸ�  
����Ű�� �ּҿ� �ִ� ���� �ٲ��� �ʰڴ���, ptr�� �ּҸ� �ٲٴ� ���� ��� ����
1)
	int value1 = 5;
	const int *ptr = &value1;

	int value2 = 6;
	ptr = &value2;

*/

/*
const�� �ٴ� ��ġ�� ���� �ٸ�
�ּҴ� �ٲ��� ���ϰ�, �ּҰ� ����Ű�� ���� �ٲ� �� ����, ������ const pointer��
2)
	int value1 = 5;
	int * const ptr = &value1;

	int value2 = 6;
	*ptr = value2;

3) �� �� ������ �ּ�, �� �� �� �� �ٲ�!!
*/
int main()
{
	int value = 5;
	const int *const ptr1 = &value;
	int *const ptr2 = &value;
	const int* const ptr3 = &value;

	return 0;
}