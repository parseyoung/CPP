//��������, ��������, ���ο���, �ܺο���

#include <iostream>
#include "myconstent.h"
using namespace std;

//forward declartion (���漱��)
extern void dosomething(); //extern�� ���� ����
extern int a;

/*
	int g_x; //externel linkage
	static int g_x; //internal linkage
	const int g_x(0) // const�� �� ������ �ʰڴٴ� �ǹ�, �� �ʱ�ȭ �������

	extern int g_z;
	extern const int g_z;

	extern int g_w(1); //�ʱ�ȭ �� �� �ϸ� �ٸ� �������� �ϸ� �ȉ�.
	extern const int g_w(1); //�ܺο��� ���� ���� �� ���� �� ���

*/
int main()
{

	dosomething();

	cout << a << endl;

	cout << " in main cpp file " << Constants::pi << " " << & Constants::pi << endl;

	return 0;
}