// Destructor (소멸자) 
// <-> 생성자의 반대임. 변수가 영역을 벗어나서 사라질 때 호출되는 것을 의미

#include <iostream>	
using namespace std;

class Simple
{
private:
	int m_id;

public:
	Simple(const int& id_in)
		: m_id(id_in)
	{
		cout << "constructor" << m_id << endl;
	}

	~Simple()
	{
		cout << "Destructor" << m_id << endl;
	}
};

class IntArray
{
private:
	int* m_arr = nullptr;
	int m_length = 0;

public:
// 동적 할당 시 메모리 누수 방지 하기 위해 같은 클래스 안에 new, delete 사용 함.
// vector은 내부적으로 new, delete가 구현이 되어있음
// 이거를 구분하기 위해 size와 capacity(용량)이 있음
// capacity(용량)만큼 메모리를 가지고 있지만 그중에 몇 size를 사용한다 이런 느낌

	IntArray(const int length_in)
	{
		m_length = length_in;
		m_arr = new int[m_length];

		cout << "Constructor" << endl;
	}
	~IntArray() // 소멸자는 매개변수가 없음
	{
		if( m_arr != nullptr)
			delete[] m_arr;
	}

	int size() { return m_length; }
};
int main()
{
	while (true)
	{
		IntArray my_int_arr(10000);
		// delete[] my_int_arr.m_arr 이런식으로 접근 불가능
		// new 사용 뒤 delete은 필수, 메모리 누수! 이럴 경우 소멸 자 사용

	Simple s1(0);
	Simple s2(1);

	return 0;
}