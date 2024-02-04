// std::string�� �����ڵ�� ����ȯ
// string�� int, double ������ ��������
// int double�� string���� ������ ����

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

template <typename T>
std::string ToString(T x)
{
	std::ostreamstream osstream;

	osstream << x;
	// osstream input �� string���� return
	return osstream.str();
}

template <typename T>
bool FromString(const std::string& str, T& x)
{
	std::istringstream isstream(str);
	return (isstream >> x) ? true : flase;
}

int main()
{
	std::string my_str(ToString(3.14));
	double d;
	if (FromString(my_str, d))
		cout << d << endl;
	else
		cout << "cannot convert string to double";

	std::cout << my_str << std::endl;

	std::string allstring(ToString(3.145));
	cout << allstring << endl; // 3.1415 (string)

	// int�� string�� �ֱ� std::to_string()
	// 1004124 ��� ������ ��������
	std::string inttostring(std::to_string(1004));
	inttostring += std::to_string(124);

	// return type ���� 
	int i = std::stoi(inttostring); 
	int f = std::stof(inttostring);


	cout << inttostring << endl; // 1024124 (string)
	cout << i << endl; // 1024124 (int)
	cout << f << endl; // 1024124 (float)




	std::vector<char> vec;
	for (auto& e : "Today is good day")
		vec.push_back(e);
	std::string v_string(vec.begin(), std::find(vec.begin(), vec.end(), 'y'));
	std::cout << v_string << std::endl; // Toda


	std::string my_string("my string");
	//const char* my_string = "my string";

	std::string second_string(my_string, 3, 5);

	std::cout << my_string << std::endl;
	std::cout << second_string << std::endl; // strin

	std::string third_string(3, 'A'); 
	std::cout << third_string << std::endl; // AAA

	return 0;
}