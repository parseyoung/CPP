// class 와 const
// const로 막을 수 있는 부분은 다 막아 놓는게 좋음
// 그래야 디버깅에 유리함 + 실수를 줄일 수 있음
// 11/21에 이어서 하겠슴!!!!!
#include <iostream>
using namespace std;

class Something
{
public:
	int m_value = 0;

	void setValue(int value) 
	{ 
		m_value = value; 
	}

	int getValue() const // 멤버변수의 값을 바꾸지 않겠다(const)
	{ 
		return m_value;
	}
};

void print(Something st)
{
	cout << &st << endl;

	cout << st.m_value << endl;
}

int main()
{
	Something something;
	//something.setValue(2);
	something.getValue();

	print(something);

	cout << &something << endl;

	return 0;
}