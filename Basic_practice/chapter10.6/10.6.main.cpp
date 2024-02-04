// container classes (컨테이너 클래스)
// array new 동적할당

#include <iostream>	
#include <string>
#include <array>

using namespace std;

class IntArray
{
private:
	int m_size = 0;
	int* m_data = nullptr;

public:
	IntArray(int size = 0)
		: m_size(size)
	{
		m_data = new int[m_size];
		for (int i = 0; i < m_size; ++i)
		{
			m_data[i] = i * 2;
		}
	}

	~IntArray()
	{
		delete[] m_data;
	}

	int getSize() const
	{
		return m_size;
	}

	int& operator[](int index)
	{
		if (index >= 0 && index < m_size)
		{
			return m_data[index];
		}
		else
		{
			throw std::out_of_range("Index out of range");
		}
	}

	friend std::ostream& operator << (std::ostream& out, const IntArray& arr)
	{
		out << "[";
		for (int i = 0; i < arr.m_size; ++i)
		{
			out << arr.m_data[i];
			if (i < arr.m_size - 1)
			{
				out << " , ";
			}
		}
		out << "]";
		return out;
	}
};

int main()
{
	IntArray arr(5);

	cout << "Array size : " << arr.getSize() << endl;
	cout << "Array : " << arr << endl;
	

	return 0;

}