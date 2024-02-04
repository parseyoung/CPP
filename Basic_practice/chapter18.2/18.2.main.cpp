// ostream ���� ����ϱ�
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// std::setw ĭ�� ���缭 ����
	cout << -12345 << endl;
	cout.fill('*'); // ��ĭ ��� �� *�� ä��� on
	cout << std::setw(10) << -12345 << endl;
	cout << std::setw(10) << std::left << -12345 << endl;
	cout << std::setw(10) << std::right << -12345 << endl;
	cout << std::setw(10) << std::internal << -12345 << endl;

	//cout << std::defaultfloat;
	cout << std::setprecision(3) << 123.456 << endl; // 123
	cout << std::setprecision(4) << 123.456 << endl; // 123.5
	cout << std::setprecision(5) << 123.456 << endl; // 123.46
	cout << std::setprecision(6) << 123.456 << endl; // 123.456

	//cout << std::fixed; // �Ҽ��� ���ڸ� ���� ��ĭ 0���� ä��
	cout << std::setprecision(3) << 123.456 << endl; // 123.456
	cout << std::setprecision(4) << 123.456 << endl; // 123.4560
	cout << std::setprecision(5) << 123.456 << endl; // 123.45600

	//cout << std::scientific << std::uppercase; // �Ҽ��� ���ڸ� ���� ��ĭ 0���� ä��
	cout << std::setprecision(6) << 123.456 << endl; // 1.234560E+02
	cout << std::setprecision(7) << 123.456 << endl; // 1.2345600E+02
	cout << std::setprecision(9) << 123.456 << endl; // 1.234560000E+02

	cout << std::showpoint; // �Ҽ��� ���
	cout << std::setprecision(3) << 123.456 << endl; // 123.
	cout << std::setprecision(4) << 123.456 << endl; // 123.5
	cout << std::setprecision(5) << 123.456 << endl; // 123.46





	//cout.setf(std::ios::showpos); // + ��ȣ ���
	
	//cout.unsetf(std::ios::dec); // 10���� ��� off
	//cout.setf(std::ios::hex); // 16������ ���
	// �� �� �� �Ʒ� �� �ٷ� �ذ�, basefield�� flag set
	//cout.setf(std::ios::hex, std::ios::basefield);
	
	//cout << std::hex; // 16������ ��� 
	// cout.setf(std::ios::uppercase); // �빮�� ���

	// <iomnip> include �ؾ� ��� ����
	cout << std::hex << std::uppercase; // 16���� + �빮��

	cout << 108 << endl; // 6D

	//cout.unsetf(std::ios::showpos); // + ��ȣ unset(����)
	cout << 109 << endl; //6C

	cout << std::dec; // 10������ ���
	cout << 110 << endl; // 110

	cout << true << " " << false; // 1 0
	cout << std::boolalpha;
	cout << true << " " << false; // true false



	return 0;
}