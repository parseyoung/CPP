#include <iostream>

//()��ȣ �� void ���� ����, ��Ģ���� �ڵ� �ϴ� �е��� ���� ��.
//()��ȣ ���� : �Ķ���� �ڸ�, �Ķ���Ͱ� ������ (void)
//return�� ���� ��쿡�� �� �տ� void �־�� ��.
void my_function(void)

{

}

int main()
{
	//void my_void; void�� �޸𸮸� ���� ���� �ʱ� ������ �̷��� ���� �Ұ���
	//data type�� �ٸ��� data size�� �ٸ�����, data�� �ּҸ� ǥ���ϴ� data�� ���� ***
	int i = 123;
	float f = 123.456f;

	void* my_void; 
	
	//&�� �ּ�, i(������)�� �ּ�
	my_void = (void*)&i;
	my_void = (void*)&f;

	return 0;
}