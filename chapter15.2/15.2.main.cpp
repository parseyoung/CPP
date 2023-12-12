// R-value References (오른쪽-값 참조)

#include <iostream>
using namespace std;

// L-value는 move semantics 사용하면 충돌 발생
void doSomething(const int& lref)
{
	cout << " const L-value " << endl;
}

// R-value ref로 가져온 경우에는, move semantics 사용가능
void doSomething(int&& ref)
{
	cout << " R-value " << endl;
}

int getResult()
{
	return 100 * 100;
}

int main()
{
	int x = 5;
	int y = getResult();
	const int cx = 6;
	const int cy = getResult();

	// L-value reference
	int &lr1 = x; // Modifiable l-value

	const int& lr4 = x; // Modifiable l-value
	const int& lr5 = cx; // Non-Modifiable l-value
	const int& lr6 = 5; // R-value

	// R-value reference
	int&& rr3 = 5; // R-value
	const int&& rr6 = 5; // R-value
	// int&& rr4 = p; 불가능

	doSomething(x); // L-value
	doSomething(cx);

	doSomething(5); // R-value
	doSomething(getResult()); 

	return 0;
}