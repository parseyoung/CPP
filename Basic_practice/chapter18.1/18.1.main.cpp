// istream���� �Է� �ޱ�
// �Ʒ� ��ɵ��� filestream�� ���, ������ file format�� ���� ����
#include <iostream>
#include <string>
#include <iomanip> // input/output manipulators
using namespace std;

int main()
{
	//char buf[5];
	////setw() buf size ���� ���� ��Ƶ� ��Ÿ�ӿ��� X
	//cin >> setw(5) >> buf; // asdfghjkl

	//cout << buf << endl; // asdf

	//cin >> setw(5) >> buf; 

	//cout << buf << endl; //ghjk

	char buf2[7];
	char buf3[100];
	char buf5[1024];
	string buf4; // ����

	//cin�� �⺻������ ��ĭ�� ��� X, get���� ������ �ذ� ����
	//Hello cin �Է�
	//cin.get(buf2, 5);
	//cin.getline(buf3, 100);
	// getline(cin, buf4); // paramter�� cin

	//cin.ignore(2); // �Է� �� �� �� 2���� ����
	// peak() cat���� ����, buf���� ������ ���� �ƴ�
	//cout << (char)cin.peek() << endl; // H
	cin >> buf4;
	cout << buf4 << endl; // Hello
	cin.unget(); // ������ ���� �� ���ۿ� �ٽ� ����
	cin.putback('A');
	cin.putback('C');
	cin >> buf4;
	cout << buf4 << endl; // CAo = LIFO

	


	//cout << cin.gcount() << " " << buf2 << endl; // 5 Hello
	//cout << cin.gcount() << " " << buf3 << endl; // 6 Hello (+ �ٹٲ� char)
	//cout << cin.gcount() << " " << buf4 << endl; // 0 Hello
	/*cin.get(buf2, 5);
	cout << cin.gcount() << " " << buf2 << endl;*/

	return 0;
}