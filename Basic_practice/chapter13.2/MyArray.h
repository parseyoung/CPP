#pragma once
#include <iostream>
#include <assert.h>

template<typename T> // typename 대신 class가 들어오기도 함
class MyArray
{
private:
	int m_length;
	T* m_data;
	
public:
	MyArray()
	{
		m_length = 0;
		m_data = nullptr;
	}

	MyArray(int length)
	{
		m_length = length;
		m_data = new T[length];
	}
	
	~MyArray()
	{
		reset();
	}

	void reset()
	{
		delete[] m_data;
		m_length = 0;
		m_data = nullptr;
	}

	T& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	int getLength()
	{
		return m_length;
	}
	void print();
};


