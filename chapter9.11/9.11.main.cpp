// 대입 연산자, 오버로딩, 깊은 복사, 얕은 복사
#include <cassert>	
#include <iostream>
using namespace std;

class Mystring
{
//private:
public:
	char* m_data = nullptr;
	int m_length = 0;

	std::string data;

public:
	Mystring(const char* source = "")
	{
		assert(source);

		m_length = std::strlen(source) + 1;
		m_data = new char[m_length];

		for (int i = 0; i < m_length; ++i)
			m_data[i] = source[i];

		m_data[m_length - 1] = '\0';
	}
	
	Mystring(const Mystring &source) // copy constructor
	{
		cout << "Copy constructor" << endl;
		m_length = source.m_length;
		
		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];

			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
		else
			m_data = nullptr;
	}

	Mystring& operator = (const Mystring& source)
	{
		/* shallow sopy
		this->m_data = source.m_data;
		this->m_length = source.m_length;
		*/
		cout << "Assignment operator" << endl;

		if (this == &source) //prevent self-assignment
			return *this;
		
		delete[] m_data;

		m_length = source.m_length;

		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];

			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
		else
			m_data = nullptr;

		return *this;
	}

	~Mystring()
	{
		delete[] m_data;
	}

	char* getString() { return m_data; }
	int getlength() { return m_length; }
};

int main()
{
	Mystring hello("hello");

	Mystring str1(hello); //copy constructor

	Mystring str2; 
	str2 = hello; // Assignment operator

	cout << (int*)hello.m_data << endl;
	cout << hello.getString() << endl;

	{
		Mystring copy = hello;
		cout << (int*)copy.m_data << endl;
		cout << copy.getString() << endl;
	}

	cout << hello.getString() << endl;
}