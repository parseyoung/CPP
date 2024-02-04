// Delegating Constructors (위임 생성자)

#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	int		m_id;
	string	m_name;


public:
	// 문자열만 인자로 받는 생성자 추가, 생성자가 생성자를 가져와서 사용(위임 생성자)
	Student(const string& name_in)
		//: Student(0, name_in)
	{
		init(0, name_in);
	}
		//:m_id(0), m_name(name_in) 
		//이런식으로 초기화 하는건 아주 비추천, 초기화(기능)는 한 군데에서만 가능하도록 설계

	Student(const int& id_in, const string& name_in)
		//:m_id(id_in),  m_name(name_in)
	{
		init(id_in, name_in);
	}
	
	// 초기화 기능을 아예 분리하는 방법도 자주 사용 됨
	void init(const int& id_in, const string& name_in)
	{
		m_id = id_in;
		m_name = name_in;
	}
	void print()
	{
		cout << m_id << " " << m_name << " " << endl;
	}

};
int main()
{
	Student st1(0, "Jack Jack");
	st1.print();

	Student st2("se");
	st2.print();

	return 0;
}