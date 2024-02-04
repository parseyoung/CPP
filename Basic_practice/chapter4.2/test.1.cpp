#include <iostream>
#include "myconstent.h"

extern int a = 5;

void dosomething()
{
	using namespace std;

	cout << "Hello" << endl;

	cout << " in test cpp file " << Constants::pi << " " << &Constants::pi << endl;


}