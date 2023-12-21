// Perfect Fowarding(완벽한 전달)과 std::forward
#include <iostream>
#include <vector>
#include <utility> // std::forward
using namespace std;

struct MyStruct
{};

void func(MyStruct& s)
{
	cout << "Pass by L-ref" << endl;
}

void func(MyStruct&& s)
{
	cout << "Pass by R-ref" << endl;
}

// 이렇게 구현하면 L, R ref 구분 못 함
//template<typename T>
//void func_wrapper(T t)
//{
//	func(t);
//}

template<typename T>
void func_wrapper(T&& t)
{
	func(std::forward<T>(t));
}

int main()
{
	MyStruct s;

	//func(s); // L-ref
	//func(MyStruct()); // R-ref

	func_wrapper(s); // L ref
	func_wrapper(MyStruct()); // R- ref
}