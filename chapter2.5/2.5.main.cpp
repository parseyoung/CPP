//�ε��Ҽ����� (Floating Point Numbers)
#include <iostream>
#include <iomanip>// �Ҽ� ��° �ڸ� ���� ����� �� ���� �� ����
#include <limits>

int main()
{
	using namespace std;

	//cout << std::setprecision(4) << endl; //0.3333, iomanip�� setprecision
	//cout << 1.0 / 3.0 << endl;

	float	f(3.141592f); //3.14 = 31.4 * 0.1
	double	d(3.141592);
	long double	ld(3.141592);

	cout << 3.14 << endl;
	cout << 31.4e-1 << endl;
	cout << 31.4e-2 << endl;
	cout << 31.4e1 << endl;
	cout << 31.4e21 << endl;


	//cout << numeric_limits<float>::max() << endl;
	//cout << numeric_limits<double>::max() << endl;
	//cout << numeric_limits<long double>::max() << endl;

	//cout << numeric_limits<float>::min() << endl;
	//cout << numeric_limits<double>::min() << endl;
	//cout << numeric_limits<long double>::min() << endl;
	////lowest���� -��� max,min�� +, double�� long double�� ū ���� X ��� �Ǵ� ��� ������
	//cout << numeric_limits<float>::lowest() << endl;
	//cout << numeric_limits<double>::lowest() << endl;
	//cout << numeric_limits<long double>::lowest() << endl;

	/*cout << sizeof(float) << endl;
	cout << sizeof(d) << endl;
	cout << sizeof(ld) << endl;*/

	return 0;
}