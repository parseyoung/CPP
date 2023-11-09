#include <iostream>

using namespace std;

struct Mystruct
{
	int array[5]{ 9, 7, 5, 3, 1 };
};

void doSomething(Mystruct* ms)
// array가 struct나 class안에 있으면 강제로 포인터로 형 변환 일어나지 않음
{
	cout << sizeof((*ms).array) << endl; //20

}
int main()
{
	Mystruct ms;
	cout << ms.array[0] << endl;
	cout << sizeof(ms.array) << endl;

	doSomething(&ms);

	//int * ptr = array;
	//cout << *ptr << " " << *(ptr + 1) << endl; 
	// ptr + 1 하면 7을 불러옴

	//cout << array << endl;
	//cout << &array[0] << endl;
	// 첫번째 값의 주소값을 가짐
	// 정적 array도 결국엔 pointer임.
	

	return 0;

}