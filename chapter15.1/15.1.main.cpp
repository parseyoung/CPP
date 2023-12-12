// Move semantics(�̵��� �ǹ�)�� smart pointers(����Ʈ ������)
// ���� autopointer�� ����� ���� ��
#include <iostream>
#include "Resource.h"
#include "AutoPtr.h"
using namespace std;

// RAII : resource acquisition is initialzation

void doSomething()
{
	// Resource* res = new Resource;  // dull pointer

	AutoPtr<Resource> res(new Resource); // smart pointer
	
	return; //early return

	//work with res
	if (true)
	{
		throw - 1; // exception
	}
	// delete res;

	return;
}

int main()
{
	//doSomething();

	{
		AutoPtr<Resource> res1(new Resource);
		AutoPtr<Resource> res2;

		cout << std::boolalpha;
	
		cout << res1.m_ptr << endl; // 00E8B2E8
		cout << res2.m_ptr << endl; // 00000000

		res2 = res1; // move semantics ������ ����

		cout << res1.m_ptr << endl; // 00000000
		cout << res2.m_ptr << endl; // 00E8B2E8

	}

	return 0;
}