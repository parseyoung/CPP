// std::string ���� �����ϱ�� �迭���� ��ȯ
// c_str(), data()�� ����� ����, �������� null char �߰� -> C-style
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string my_str("abcdefg");

	cout << my_str.c_str() << endl;
	//cout << my_str.data() << endl;
	const char* arr = my_str.c_str();

	cout << (int)arr[6] << endl; // 103 ('g')
	cout << (int)arr[7] << endl; // 0 (null char)

	char buf[20];
	my_str.copy(buf, 5, 0); // 0�� ofset
	buf[5] = '\0'; // null char ����, �� �����Ⱚ ����
	cout << buf << endl; 

	//try
	//{
	//	// my_str[100] = 'X';
	//	// �ӵ� �������� ����ó�� X
	//	my_str.at(100) = 'X';
	//	// �ӵ� �������� ����ó�� O
	//}
	//catch (std::exception& e)
	//{
	//	cout << e.what() << endl;
	//}

	return 0;
}