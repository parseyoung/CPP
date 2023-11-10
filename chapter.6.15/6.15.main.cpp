#include <iostream>

using namespace std;

void doSomething(const int &x)
// reference로 넣으면 주소 복사가 일어나지 않음, 포인터로 넣으면 주소 복사임
// reference를 함수 파라미터로 사용하면 아주 편함
{
	cout << x << endl;
}


int main()
{
	/*
	int x = 5;
	int &ref_x = x;

	const int &ref_2 = 3 + 4; 
	= const reference(참조)변수는 리터럴 넣을 수 있음
	*/

	int a = 1;
	doSomething(a);
	doSomething(5); //const이기에 바로 리터럴 넣을 수 있음
	doSomething(a + 3);
	doSomething(3 * 4);



	
	 
	

	


	return 0;
}