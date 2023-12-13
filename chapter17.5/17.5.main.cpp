// std::string 대입, 교환, appeng(덧붙히기), 삽입
#include <iostream>
#include <string>
using namespace std;

int main()
{
	std::string str1("one");
	string str2;
	str2 = str1;
	str2 = "two";
	str2.assign("three").append(" ").append("four");
	cout << str2 << endl; // three

	std::swap(str1, str2);
	cout << str1 << " " << str2 << endl;
	str1.swap(str2);
	cout << str1 << " " << str2 << endl;

	str1 += "seyoung";
	str2 = str1 + "jaehyun";
	cout << str1 << " " << str2 << endl;

	return 0;
}
