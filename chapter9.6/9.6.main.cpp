// [] subscript operator 첨자 연산자 오버로딩 하기
#include <iostream>
#include <cassert>
using namespace std;

class IntList
{
private:
	int m_list[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

public:
	/*void setItem(int index, int value)
	{
		m_list[index] = value;
	}

	int getItem(int index)
	{
		return m_list[index];
	}

	int* getlist()
	{
		return m_list;
	}*/
	// assert 사용 해 런타임 에러 방지
	int& operator [] (const int index)
	{
		assert(index >= 0);
		assert(index < 10);
		return m_list[index];
	}

	const int& operator [] (const int index) const
	{
		assert(index >= 0);
		assert(index < 10);
		return m_list[index];
	}
};

int main()
{
	IntList my_list;
	cout << my_list[3] << endl; // 정저 할당 시 접근

	IntList* list = new IntList; // 동적 할당 시 접근
	(*list)[3] = 10; 
	cout << (*list)[3] << endl;
	delete list;

	//my_list.setItem(3, 1);
	//cout << my_list.getItem(3) << endl;
	//my_list.getlist()[3] = 2;
	//cout << my_list.getlist()[3] << endl;
	return 0;
}