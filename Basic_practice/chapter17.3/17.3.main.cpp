//std::string�� ���̿� �뷮
// c-style�� ���ڿ� �������� null char ����������
// C++�� �߰� ���� ���� C++���� string�� class��
// 0 = false 
// ȿ������ ������ ���� �̸� �뷮�� �˰�, 
// reserve�� ��� �����ϸ� ȿ������

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string my_str("01234567");
	my_str.reserve(1000); // capacity �ּ� 1000 ��ƴ޶�

	cout << std::boolalpha;
	cout << my_str.empty() << endl;
	cout << my_str.size() << endl;
	cout << my_str.length() << endl;
	cout << my_str.capacity() << endl;
	cout << my_str.max_size() << endl;

	return 0;
}