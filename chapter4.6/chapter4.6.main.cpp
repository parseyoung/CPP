#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
	const char my_strs [] = "Hello, World";
	const string my_hello("Hello, World");
	// string�� ����� ���� �ڷ����̶�� ��������!

	cout << "Your name : ";
	string name;
	//cin >> name; // cin�� ���⸦ �ϸ� �Ѿ����
	std::getline(std::cin, name); // �� ���� ��ü(���ͱ���)�� �Է����� ��

	cout << "Your age : ";
	string age;
	std::getline(std::cin, age);


	/*
	���� age�� int������ �ް� �ʹٸ�,
	cout << "Your age : ";
	int age;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.ignore(32767, '\n') //32767�� magic number�̴� 
	����ϱ� ������ limits ������� ���� �� �� �� �ڵ� ����ϸ� ��.
	*/
	cout << name << " " << age << endl;

	// ���ڿ� ���ϱ� append ��� ��
	string a("Hello,"); // ���ڿ� ���̴� 7, �� �ڿ� ������ �ִ�.
	string b(" World");
	string hw = a + b; // append
	hw += " I'm good";

	cout << hw << endl;
	cout << a.length() << endl; // ���ڿ� ���̰� 6�� ����



	return 0;
}