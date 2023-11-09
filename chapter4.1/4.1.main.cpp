/*���� ������ ����(Scope)�� ���ӱⰣ(Duration)
���(���չ�), ��Ī����, �̸��浹, �̸������*/

#include <iostream>

//main���� ��� �Լ��� �����Լ�

namespace work1
{
	int a = 1;
	void dosomething()
	{
		a += 3;
	}
}

namespace work2
{
	int a = 5;
	void dosomething()
	{
		a *= 3;
	}
}



int main()
{
	using namespace std;

	work1::a;
	cout << "Work1 a " << auto(work1::a) << endl;
	work1::dosomething();
	cout << "Work1 doSomething " << (work1::dosomething) << endl;

	work2::a;
	cout << "Work2 a " << int(work2::a) << endl;
	work2::dosomething();
	cout << "Work2 doSomething " << (work2::dosomething) << endl;

	return 0;

}