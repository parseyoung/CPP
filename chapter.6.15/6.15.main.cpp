#include <iostream>

using namespace std;

void doSomething(const int &x)
// reference�� ������ �ּ� ���簡 �Ͼ�� ����, �����ͷ� ������ �ּ� ������
// reference�� �Լ� �Ķ���ͷ� ����ϸ� ���� ����
{
	cout << x << endl;
}


int main()
{
	/*
	int x = 5;
	int &ref_x = x;

	const int &ref_2 = 3 + 4; 
	= const reference(����)������ ���ͷ� ���� �� ����
	*/

	int a = 1;
	doSomething(a);
	doSomething(5); //const�̱⿡ �ٷ� ���ͷ� ���� �� ����
	doSomething(a + 3);
	doSomething(3 * 4);



	
	 
	

	


	return 0;
}