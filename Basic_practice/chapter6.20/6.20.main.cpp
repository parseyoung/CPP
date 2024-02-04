// std::array

#include <iostream>
#include <array>
#include <algorithm> // sorting 위해 선언

using namespace std;

void printLength(const array<int, 5>& my_arr)
// const 매개변수이기 때문에 printLength()에서 my_arr은 변하지 않음
// array나 표준 라이브러리 사용시 &(레퍼런스)로 넣을지 포인터로 할 지 고민 해봐야함
// 포인터 아니고 레퍼런스로 하면 중간에 복사하는 과정이 생략되어 좋음

// 고정된 배열에 새로운 값 할당, 정적할당 (단, 크기를 초과하면 컴파일 오류 발생) //

{
	cout << "printLength" << " " << my_arr.size() << endl;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	// 크기 지정 안 해도 컴파잉러가 알아서 함

	array<int, 5> my_arr = { 1, 2, 3, 4, 5 };
	// std::array사용시 크기 지정 해야함

	my_arr = { 0, 7, 2 };

	for (const auto& element : my_arr)
		cout << element << " "; // 0 7 2 0 0
	cout << endl;

	std::sort(my_arr.begin(), my_arr.end()); // 배열의 처음(begin) 부터 끝(end)까지 오름차순 정렬

	for (const auto& element : my_arr)
		cout << element << " "; //0 0 0 2 7
	cout << endl;

	std::sort(my_arr.rbegin(), my_arr.rend());  // 배열의 처음(begin) 부터 끝(end)까지 역순 정렬
	for (const auto& element : my_arr)
		cout << element << " "; // 7 2 0 0 0
	cout << endl;


	//cout << my_arr.at(1) << endl;
	// at을 사용하면 예외처리 발동시킴, but 속도가 느림

	cout << my_arr.size() << endl;
	// 배열의 원소 몇개인지 확인

	printLength(my_arr);


	return 0;
}

