// 기본적인 파일 입출력
// ASCII는 txt 확장자 많이 사용, 느림
// binary file은 문서로 읽어서 사람이 확인 불가
// 디버깅에 더욱 신경 써야 함
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> //exit()
#include <sstream>
using namespace std;

int main()
{
	// writing
	if (true)
	{
		ofstream ofs("my_first_file.dat", ios::binary); // ios::app, ios::binary
		//ofs.open("my_first_file.dat");

		if (!ofs)
		{
			cerr << "Couldn't open file" << endl;
			exit(1);
		}

		// ASCII
		/*ofs << "Line 1" << endl;
		ofs << "Line 2" << endl;*/

		// binary
		const unsigned num_data = 10;
		ofs.write(reinterpret_cast<const char*>(&num_data), sizeof(num_data));

		for (int i = 0; i < num_data; ++i)
			ofs.write(reinterpret_cast<const char*>(&i), sizeof(i));
	}

	// reading
	//if (true)
	{
		ifstream ifs("my_first_file.dat", ios::binary); 
		if (!ifs)
		{
			cerr << "Cannot open file" << endl;
			exit(1);
		}

		// ASCII
		/*while (ifs)
		{
			std::string str;
			getline(ifs, str);

			std::cout << str << endl
		}*/
		unsigned num_data = 0;
		ifs.read(reinterpret_cast<char*>(&num_data), sizeof(num_data));

		cout << "num_data: " << num_data << endl;

		for (int i = 0; i < num_data; ++i)
		{
			int num;
			ifs.read(reinterpret_cast<char*>(&num), sizeof(num));
			cout << num << endl;
		}

	}

	return 0;
}