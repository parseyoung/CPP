// class 와 const
// const로 막을 수 있는 부분은 다 막아 놓는게 좋음
// 그래야 디버깅에 유리함 + 실수를 줄일 수 있음
// const의 여부로 오버로딩 가능
#include <iostream>
#include <string>
using namespace std;

class Something
{
public:

	string m_value = "default";

	const string& getValue() const {
		cout << "const version" << endl;
		return m_value;
	}

	string& getValue() {
		cout << "non-const version" << endl;
		return m_value; 
	}

};


int main()
{
	Something something;
	something.getValue() = 10;

	const Something something2;
	something2.getValue();

	return 0;
}