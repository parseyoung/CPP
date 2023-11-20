// 헤더파일에서는 using namespace std; 선언 안 하는 것이 일반적.
// include하는 것들이 전부 영향을 받기 때문임.
#pragma once
#include <iostream>

class Calc
{
private:
	int m_value;

public:
	Calc(int init_value);

	Calc& add(int value);
	Calc& sub(int value);
	Calc& mult(int value);
	void print();
};
