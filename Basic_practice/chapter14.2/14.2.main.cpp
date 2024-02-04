// stack Unwinding (예외처리와 스택 되감기)
#include <iostream>
using namespace std;

void last() throw(int) // int type 예외 처리 할 수도 있다 정도 
{
	cout << "last" << endl;
	cout << "Throws excaption" << endl;

	throw -1; // int type 반환 
	// throw 'a';  catch (...) 실행

	cout << "End last" << endl; // 출력 x
}

// catch() 없어서 passz
void third()
{
	cout << "Third" << endl;

	last();

	cout << "End third" << endl;
}

// catch(double) 이라 pass
void second()
{
	cout << "Second" << endl;

	try
	{
		third();
	}
	catch (double)
	{
		cerr << "Second caught double excaption" << endl;
	}

	cout << "End second" << endl;
}

// catch(int) 실행
void first()
{
	cout << "first" << endl;

	try
	{
		second();
	}
	catch (int)
	{
		cerr << "first caught int excaption" << endl;
	}

	catch (...) // (ellipes, 모든 타입) catch-all handlers
	{
		cerr << "main caught ellipes exception" << endl;
	}

	cout << "End first" << endl;
}
int main()
{
	cout << "Start" << endl;

	try
	{
		first();
	}
	catch (int)
	{
		cerr << "main caught int excaption" << endl;
	}

}