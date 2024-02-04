#include <iostream>

using namespace std;

/* 
���� �޸� �Ҵ��� stack�� ��, stack�� �뷮�� ����
���� �޸� �Ҵ��� hip�� ��, hip�� �뷮�� ŭ
*/

/*
new, delete�� os���� �޾ƿͼ� ����ϴ� �Ŷ� �� ������ ���α׷��� ���ư�
�ִ��� ���� ����ϴ� ���� ȿ������
new�� �޸� �Ҵ� �� delete������ ������ �޸� ������ �߻��� ������ ����!!
�Ҵ� ���� �޸𸮸� �ٽ� ��ǻ�Ϳ��� �۾��� ���� �� �����ִ� �۾��� �ſ� �߿���
*/

int main()
{

	//int *ptr = new int;
	//*ptr = 7;
	int *ptr = new (std::nothrow) int{ 7 }; 
	//(std::nothrow)�� ������ �Ҵ���� �޸𸮰� ��� ��Ե� ���߼� ���� ��, ������ �߻���Ű�� ����(����ó��)


	delete ptr; // ���α׷� ���� ���� os���� ���� �ݳ��ϴ� �۾���.
	ptr = nullptr; // �ݳ��� ��, ���� �� �۾����� �Ʒ� �������� ������ ���� ��.

	cout << "After delete" << endl;
	if (ptr != nullptr)
	{
		cout << ptr << endl;
		cout << *ptr << endl;
	}
	else
	{
		cout << "Could not allocate memory" << endl;
	}

	return 0;
}