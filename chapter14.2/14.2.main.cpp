// stack Unwinding (����ó���� ���� �ǰ���)
#include <iostream>
using namespace std;

void last() throw(int) // int type ���� ó�� �� ���� �ִ� ���� 
{
	cout << "last" << endl;
	cout << "Throws excaption" << endl;

	throw -1; // int type ��ȯ 
	// throw 'a';  catch (...) ����

	cout << "End last" << endl; // ��� x
}

// catch() ��� passz
void third()
{
	cout << "Third" << endl;

	last();

	cout << "End third" << endl;
}

// catch(double) �̶� pass
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

// catch(int) ����
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

	catch (...) // (ellipes, ��� Ÿ��) catch-all handlers
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