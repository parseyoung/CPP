// ostream 으로 출력하기
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// std::setw 칸수 맞춰서 띄우기
	cout << -12345 << endl;
	cout.fill('*'); // 빈칸 띄울 때 *로 채우기 on
	cout << std::setw(10) << -12345 << endl;
	cout << std::setw(10) << std::left << -12345 << endl;
	cout << std::setw(10) << std::right << -12345 << endl;
	cout << std::setw(10) << std::internal << -12345 << endl;

	//cout << std::defaultfloat;
	cout << std::setprecision(3) << 123.456 << endl; // 123
	cout << std::setprecision(4) << 123.456 << endl; // 123.5
	cout << std::setprecision(5) << 123.456 << endl; // 123.46
	cout << std::setprecision(6) << 123.456 << endl; // 123.456

	//cout << std::fixed; // 소수점 뒷자리 고정 빈칸 0으로 채움
	cout << std::setprecision(3) << 123.456 << endl; // 123.456
	cout << std::setprecision(4) << 123.456 << endl; // 123.4560
	cout << std::setprecision(5) << 123.456 << endl; // 123.45600

	//cout << std::scientific << std::uppercase; // 소수점 뒷자리 고정 빈칸 0으로 채움
	cout << std::setprecision(6) << 123.456 << endl; // 1.234560E+02
	cout << std::setprecision(7) << 123.456 << endl; // 1.2345600E+02
	cout << std::setprecision(9) << 123.456 << endl; // 1.234560000E+02

	cout << std::showpoint; // 소수점 출력
	cout << std::setprecision(3) << 123.456 << endl; // 123.
	cout << std::setprecision(4) << 123.456 << endl; // 123.5
	cout << std::setprecision(5) << 123.456 << endl; // 123.46





	//cout.setf(std::ios::showpos); // + 기호 출력
	
	//cout.unsetf(std::ios::dec); // 10진수 모드 off
	//cout.setf(std::ios::hex); // 16진수로 출력
	// 위 두 줄 아래 한 줄로 해결, basefield의 flag set
	//cout.setf(std::ios::hex, std::ios::basefield);
	
	//cout << std::hex; // 16진수로 출력 
	// cout.setf(std::ios::uppercase); // 대문자 출력

	// <iomnip> include 해야 사용 가능
	cout << std::hex << std::uppercase; // 16진수 + 대문자

	cout << 108 << endl; // 6D

	//cout.unsetf(std::ios::showpos); // + 기호 unset(삭제)
	cout << 109 << endl; //6C

	cout << std::dec; // 10진수로 출력
	cout << 110 << endl; // 110

	cout << true << " " << false; // 1 0
	cout << std::boolalpha;
	cout << true << " " << false; // true false



	return 0;
}