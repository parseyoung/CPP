#include <iostream>

using namespace std;

/* 
정적 메모리 할당은 stack에 들어감, stack은 용량이 작음
동적 메모리 할당은 hip에 들어감, hip은 용량이 큼
*/

/*
new, delete은 os에서 받아와서 사용하는 거라 좀 느리게 프로그램이 돌아감
최대한 적게 사용하는 것이 효율적암
new로 메모리 할당 후 delete해주지 않으면 메모리 누수가 발생함 위험함 주의!!
할당 받은 메모리를 다시 컴퓨터에게 작업이 끝난 뒤 돌려주는 작업이 매우 중요함
*/

int main()
{

	//int *ptr = new int;
	//*ptr = 7;
	int *ptr = new (std::nothrow) int{ 7 }; 
	//(std::nothrow)를 넣으면 할당받을 메모리가 없어도 어떻게든 버텨서 실행 함, 오류를 발생시키지 않음(예외처리)


	delete ptr; // 프로그램 종료 전에 os에게 먼저 반납하는 작업임.
	ptr = nullptr; // 반납한 뒤, 보통 이 작업부터 아래 과정까지 진행을 많이 함.

	cout << "After delete" << endl;
	if (ptr != nullptr)
	{
		cout << ptr << endl;
		cout << *ptr << endl;
	}
	else
	{
		cout << "Could not allocate memory" << endl;
	}

	return 0;
}