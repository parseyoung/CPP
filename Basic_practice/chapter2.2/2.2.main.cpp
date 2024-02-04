#include <iostream>
#include <cmath> //제곱계산 : pow
#include <limits> //가장 큰 숫자 컴파일러에게 확인 함수

int main()
{
	using namespace std;

	short	s = 1; //2 bytes = 2 * b bits = 16bits , 65536

	//첫번째 -1은 부호결정, 두번째 -1은 0표현하기 위해 , 32767
	//pow : cmath 선언하여 제곱 계산 가능
	cout << std::pow(2, sizeof(short) * 8 - 1) - 1 << endl; 

	cout << std::numeric_limits<short>::max() << endl;
	cout << std::numeric_limits<short>::min() << endl; //-32768
	cout << std::numeric_limits<short>::lowest() << endl; //-32768

	s = 32767;
	s += 1; //32768

	//32768 출력이 아닌 가장 작은 숫자만 -32768이 출력 됨. overflow
	cout << s << endl; 

	/*int		i = 1;
	long	l = 1;
	long long ll = 1;
	
	cout << sizeof(int) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(long long) << endl;*/

	//unsigned는 -표현 안 하지만 -를 넣으면 overflow발생, 4294967
	unsigned int i = -1;
	cout << i << endl; 

	int i = 22 / 4;
	cout << 22 / 4 << endl; //5.5지만 정수형 5로 출력 됨
	cout << float(22) / 4 << endl; // 둘 중 하나만 float하면 float으로 출력

	return 0;
}