// Exception class 상속 (예외 클래스와 상속)
#include <iostream>
using namespace std;

class Exception
{
public:
	void report()
	{
		cerr << "Exception report" << endl;
	}
};

class ArrayException : public Exception
{
public:
	void report() 
	{
		cerr << "Array exception" << endl;
	}
};

class MyArray
{
private:
	int m_data[5];
public:
	int& operator [] (const int& index)
	{
		//if (index < 0 || index >= 5) throw - 1;
		if (index < 0 || index >= 5) throw ArrayException();
		return m_data[index];
	}
};

void doSomething()
{
	MyArray my_array;

	try
	{
		my_array[100]; //  operator overrode [] 
	}
	catch (const int& x)
	{
		cerr << "Excaption" << x << endl;
	}

	/*
	catch (ArrayException& e)
	{
		cout << "doSomething()" << endl;
		e.report();
		throw e; // rethrow -> arr
	}
	*/

	catch (Exception& e)
	{
		cout << "doSomething()" << endl;
		e.report();

		// MyArray class에서 ArrayException throw 했기에 
		// main e.report()시  ArrayException class 실행
		throw;

		// main e.report()시 Exception class 실행
		// throw e;
	}
}

int main()
{
	try 
	{
		doSomething();
	}

	catch (ArrayException& e)
	{
		cout << " main() " << endl;
		e.report();
	}

	catch (Exception& e)
	{
		cout << " main() " << endl;
		e.report();
	}

	return 0;
}