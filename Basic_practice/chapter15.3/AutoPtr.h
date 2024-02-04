#pragma once
#include <iostream>

template<class T>
class AutoPtr
{
public:
	T* m_ptr = nullptr;

public:
	AutoPtr(T* ptr = nullptr)
		: m_ptr(ptr)
	{
		std::cout << "Auto default constructor" << std::endl;
	}

	~AutoPtr()
	{
		std::cout << "AutoPtr destructor" << std::endl;

		if (m_ptr != nullptr) delete m_ptr;
	}

	// Move constructor
	AutoPtr(AutoPtr&& a)
		:m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr;

		std::cout << "AutoPtr move constructuor" << std::endl;
	}

	//Move assignment
	AutoPtr& operator=(AutoPtr&& a)
	{
		std::cout << "AutoPtr move assignenment" << std::endl;
		if (&a == this)
			return *this;

		if (!m_ptr) delete m_ptr;

		// shallow copy
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;

		return *this;
	}


	// Resource.h  copy assignment 호출
	AutoPtr(AutoPtr& a)
	{
		std::cout << "Auto copy constructor" << std::endl;
		
		// deep copy
		m_ptr = new T;
		m_ptr = a.m_ptr;
	}

	AutoPtr& operator=(const AutoPtr& a) {
		std::cout << "Auto copy assignment" << std::endl;

		if (&a == this)
			return *this;

		delete m_ptr;  // 기존의 자원 해제

		// 깊은 복사
		m_ptr = new T(*(a.m_ptr));  // 새로운 자원 할당 및 복사

		return *this;
	}


	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }

};