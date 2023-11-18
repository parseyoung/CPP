/*
* Object Oriented Programing (OOP) ��ü���� ���α׷��ְ� Ŭ���� 
* �Ϲ�������, �����͸� �ٷ궩 struct, �����Ϳ� ����� ���� �� Ŭ������ �ַ� ���
* Ÿ������ ���� �߻� �� ���� ���� �߻� Ȯ�� ����
* ������ ª�� �����ϰ� �ϴ� ���� �߿�
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Friend
{
public: // access specifier (publuc, private, protected)
	string _name; // ����������� ǥ���ϱ� ���� �տ� m_ Ȥ�� _ ǥ���ϴ� ��� �Ϲ���
	string _address;
	int		_age;
	double _height;
	double _weight;

	void print() const// �Լ��� �����
	{
		cout << _name << " " << _address << " " << _age << " " << _height << " "
			<< _weight << " " << endl;
	}
};

int main()
{
	Friend se{ "Se young", "Suwon", 25, 168, 57 }; //instanciation, instance
	Friend jj{ "Jack", "Seoul", 27, 180, 76 };
	//jj.print();

	vector<Friend> my_friends;
	my_friends.resize(2); // 10���� ģ�� ���� �� ����

	my_friends[0] = se;
	my_friends[1] = jj;
	
	/* emplace_back �Լ��� ����Ͽ� �ڵ带 �� �����ϰ� ��
	* emplace_back�� ���� ��ü�� �����ϰ� �ٷ� ���Ϳ� �߰��ϴ� �� ���
	* 
	my_friends.emplace_back("����", "����", 25, 168, 57);
    my_friends.emplace_back("��", "����", 27, 180, 76);
	*/
	for (const auto& ele : my_friends)
		ele.print();

	return 0;
}