#include <iostream>
#include<string>

using namespace std;

struct Person // ����ü ���� �������� ������ ��.
{
	double height;
	float weight;
	int age;
	string name;

	void printPerson()
	{
		cout << height << " " << weight << " " << age << " " << name;
		cout << endl;
	}
};

Person getMe()
{
	Person me{ 2.0, 100.0, 20, "Jack Jack" };
	return me;
}

struct Family
{
	Person me, mom, dad;
};

int main()
{
	Person me_from_func = getMe();
	me_from_func.printPerson();

	return 0;
}