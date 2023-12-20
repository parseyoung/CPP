// ������ ���� ��ġ �����ϱ�
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

int main()
{
	const string filename = "my_file.txt";

	// make a flie
	{
		ofstream ofs(filename);

		for (char i = 'a'; i <= 'z'; ++i)
			ofs << i;
		ofs << endl;
	}
	if (false)
	// read a file
	{
		ifstream ifs(filename);

		// ó������ 5byte �̵� �� �б�
		ifs.seekg(5); // ifs.seekg(5, ios::beg);
		cout << (char)ifs.get() << endl;

		ifs.seekg(5, ios::cur); // Ŀ������ 5byte
		cout << (char)ifs.get() << endl;

		//ifs.seekg(-5, ios::end); // end���� -5byte
		
		/*ifs.seekg(0, ios::end);
		cout << (char)ifs.tellg() << endl;*/

		string str;
		getline(ifs, str);

		cout << str << endl;
	}

	// file ���� ��ġ(5) �����Ͽ� A�� ����
	if (true)
	{
		// fstream iofs(filename, ios::in | ios::out);
		fstream iofs(filename);

		iofs.seekg(5);
		cout << (char)iofs.get() << endl; // read

		iofs.seekg(5);
		iofs.put('A'); // write

	}
	return 0;
}