// ������

#include <iostream>
#include <typeinfo>

enum Color // user define data type , ������
{
	COLOR_BLACK, // = -3 ���� �κ��� �����Ҵ絵 ���� ��
	COLOR_RED,
	COLOR_BLUE,
	COLOR_GREAN, //������������ ,�� �־ �������
};

enum Feeling
{
	HAPPY,
	JOY,
	TIRED,
};

// �� �ΰ��� enum�� ����ó�� �۵��ؼ� ������ ���� ���� �� ����.

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

