/*
* Object Oriented Programing (OOP) 객체지향 프로그래밍과 클래스 
* 일반적으로, 데이터만 다룰땐 struct, 데이터와 기능을 묶을 땐 클래스를 주로 사용
* 타이핑이 많이 발생 할 수록 오류 발생 확률 높음
* 가급적 짧고 간결하게 하는 것이 중요
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Friend
{
public: // access specifier (publuc, private, protected)
	string _name; // 멤버변수임을 표현하기 위해 앞에 m_ 혹은 _ 표시하는 경우 일반적
	string _address;
	int		_age;
	double _height;
	double _weight;

	void print() const// 함수도 멤버임
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
	my_friends.resize(2); // 10명의 친구 담을 수 있음

	my_friends[0] = se;
	my_friends[1] = jj;
	
	/* emplace_back 함수를 사용하여 코드를 더 간결하게 함
	* emplace_back은 보통 객체를 생성하고 바로 벡터에 추가하는 데 사용
	* 
	my_friends.emplace_back("세영", "수원", 25, 168, 57);
    my_friends.emplace_back("잭", "서울", 27, 180, 76);
	*/
	for (const auto& ele : my_friends)
		ele.print();

	return 0;
}