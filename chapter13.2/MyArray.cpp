#include "MyArray.h"

template<typename T>
void MyArray<T>::print()
{
	for (int i = 0; i < m_length; i++)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}

//explicit instantiation
// 이 과정 안 거치면 링킹에러 발생
/*
template void MyArray<char>::print();
template void MyArray<double>::print();
*/
template class MyArray<char>;
template class MyArray<double>;