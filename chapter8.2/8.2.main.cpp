/* ĸ��ȭ(Encapsulation), ���� ������(Access Specifiers), ���� �Լ�(Access Funcrions)
������ �ڵ带 ������ ��⺰�� ���� �� �и��� �� �ϴ� ���� �߿�
�ֱ� SW�� ��Ȱ��� Opensource ���� ����� �׷��� �� �߿�
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Date
{
	// access specifier
private: // ���� ���� �⺻�� private 
	int _month;
	int _day;
	int _year;

public:
	void setDate(const int& month_input, const int& day_input, const int& year_input)
	{
		_month = month_input;
		_day = day_input;
		_year = year_input;

	}

	void setMonth(const int& month_input)
	{
		_month = month_input;
	};

	void setDay(const int& day_input)
	{
		_day = day_input;
	};

	void setYear(const int& year_input)
	{
		_year = year_input;
	};

	// getMonth, getYear ...

	const int& getDay() //���� �����ϴ� �Լ� ���� �� const�� ���� ��� �Ϲ���
	{
		return _day;
	};

	void copyFrom(const Date& original)
	{
		_month = original._month;
		_day = original._day;
		_year = original._year;

	};
};
	int main()
	{
		Date today;
		today.setDate(8, 4, 2025);
		today.setMonth(10);

		cout << today.getDay() << endl;

		Date copy;
		copy.copyFrom(today);

		return 0;
	}