// ������ ���� ���� 
#include <iostream>
#include <cmath> //sin(), cos()
#include <vector>
using namespace std;

void getSinCos(const double &degrees, double &sin_out, double &cos_out)
{
	static const double pi = 3.141592 / 180.0;
	//static�� ��������ν� �Ź� �������� �ʰ� ������ ��

	const double radians = degrees * pi;
	sin_out = std::sin(radians);
	cos_out = std::cos(radians);
}

typedef int* pint;  
//pint�� ���������� ����ó�� ���̰� Ȱ���ϴ� ���, ���������ͽ� ����ϸ� ��

//void foo(pint &ptr)
void foo(int *&ptr)
{
	cout << ptr << " " << &ptr << endl;
}

void printElement(const vector<int>& arr)
{
	// ...
}
int main()
{
	double sin{ 0.0 }, cos{ 0.0 };
	getSinCos(30.0, sin, cos);
	cout << sin << " " << cos << endl;


	int x = 5;
	int *ptr = &x;
	//pint ptr = &x; 
	cout << ptr << " " << &ptr << endl;
	foo(ptr);

	vector<int> arr{ 1, 3, 8, 15 };
	printElement(arr);

	return 0;
}