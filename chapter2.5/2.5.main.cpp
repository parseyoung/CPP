//부동소수점수 (Floating Point Numbers)
#include <iostream>
#include <iomanip>// 소수 몇째 자리 까지 출력할 지 정할 수 있음
#include <limits>

int main()
{
	using namespace std;

	//cout << std::setprecision(4) << endl; //0.3333, iomanip의 setprecision
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
	////lowest에서 -출력 max,min은 +, double과 long double은 큰 차이 X 출력 되는 모습 보여줌
	//cout << numeric_limits<float>::lowest() << endl;
	//cout << numeric_limits<double>::lowest() << endl;
	//cout << numeric_limits<long double>::lowest() << endl;

	/*cout << sizeof(float) << endl;
	cout << sizeof(d) << endl;
	cout << sizeof(ld) << endl;*/

	return 0;
}