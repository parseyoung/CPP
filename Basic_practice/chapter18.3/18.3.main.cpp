// string stream ���ڿ� �帧 (����)
// ��ĭ���� ���� �ϴ� ���� Ư¡

#include <iostream> // cout
#include <sstream> // string stream
using namespace std;

int main()
{
	stringstream os;
	// ���ۿ� ��� ����
	//os << "Hello, World!"; // << : insertion operator
	//os << "Hello, World2!" << endl;

	// ���� ���� ����� ���� ���� ��°�� �ٲ����
	//os.str("Hello, World!\n"); 

	string str;

	//os >> str; // ��������� ��� ��

	//str = os.str();
	//cout << str << endl;

	cout << os.str() << endl;

	// int, double
	// �������� �˾Ƽ� ���� ��
	int i = 12345;
	double d = 3.15;
	os << i << " " << d;
	string str1; // 12345
	string str2; // 3.15

	// int, double�� string���� �ֱ�
	os << " 12345 67.89";
	string str3; // 12345
	string str4; // 67.89

	os >> str1 >> str2;
	os >> str3 >> str4;


	cout << str1 << " " << "|" << " " << str2 << endl;
	cout << str3 << " " << "|" << " " << str4 << endl;

	os.str(""); // ���� ����
	os.clear(); // state ���
	cout << os.str() << endl; // �ƹ��͵� �� ����
	return 0;
}
