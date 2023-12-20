// 파일의 임의 위치 접근하기
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

		// 처음부터 5byte 이동 후 읽기
		ifs.seekg(5); // ifs.seekg(5, ios::beg);
		cout << (char)ifs.get() << endl;

		ifs.seekg(5, ios::cur); // 커서에서 5byte
		cout << (char)ifs.get() << endl;

		//ifs.seekg(-5, ios::end); // end에서 -5byte
		
		/*ifs.seekg(0, ios::end);
		cout << (char)ifs.tellg() << endl;*/

		string str;
		getline(ifs, str);

		cout << str << endl;
	}

	// file 임의 위치(5) 접근하여 A로 수정
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