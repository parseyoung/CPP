#pragma once
#include <iostream>

template <class T>
class Storage
{
private:
	T m_value;

public:
	Storage(T value)
	{
		m_value = value;
	}

	~Storage()
	{}

	void print()
	{
		std::cout << m_value << '\n';
	}

};

// �ش� ����� cpp�� �и��ϰ� �ʹٸ�, main���� Storage.cpp include! 
template <>
void Storage<double>::print()
{
	std::cout << "Double Type ";
	std::cout << std::scientific << m_value << '\n';
}
