// 열거형

#include <iostream>
#include <typeinfo>

enum Color // user define data type , 열거형
{
	COLOR_BLACK, // = -3 으로 부분적 수동할당도 가능 함
	COLOR_RED,
	COLOR_BLUE,
	COLOR_GREAN, //마지막이지만 ,가 있어도 상관없음
};

enum Feeling
{
	HAPPY,
	JOY,
	TIRED,
};

// 위 두개의 enum은 전역처럼 작동해서 동일한 값을 넣을 수 없음.

int main()
{
	using namespace std;

	Color paint = COLOR_BLACK;
	Color house(COLOR_BLUE);
	Color apple{ COLOR_RED };

	cout << paint << " " << COLOR_BLACK << endl;
	cout << apple << " " << COLOR_RED << endl;
	cout << house << " " << COLOR_BLUE << endl;

	return 0;
}

