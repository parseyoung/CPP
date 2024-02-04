//값에 의한 전달

#include <iostream>

using namespace std;

void doSomething(int y)
{
	y = y +10;
	cout << "In func " << y << " " << &y << endl;

}

int main()
{	
	doSomething(5);

	int x = 6;
	cout << "In  main " << x << " " << &x << endl;

	doSomething(x); 
	doSomething(x + 100);
	return 0;
}