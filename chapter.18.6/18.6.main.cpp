// �⺻���� ���� �����
// ASCII�� txt Ȯ���� ���� ���, ����
// binary file�� ������ �о ����� Ȯ�� �Ұ�
// ����뿡 ���� �Ű� ��� ��
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