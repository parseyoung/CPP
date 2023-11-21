/* 캡슐화(Encapsulation), 접근 지정자(Access Specifiers), 접근 함수(Access Funcrions)
복잡한 코드를 각각의 모듈별로 조립 및 분리를 잘 하는 것이 중요
최근 SW는 재활용과 Opensource 많이 사용함 그래서 더 중요
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Date
{
	// access specifier
private: // 생략 가능 기본은 private 
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

	const int& getDay() //직접 접근하는 함수 생성 시 const로 막는 경우 일반적
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