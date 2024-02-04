// 이중포인터와 동적 다차원 배열
//new로 동적으로 만들었으니 delete 꼭 해줘야함
#include <iostream>

using namespace std;

int main()
{
	const int row = 3;
	const int col = 5;

	const int s2da[][5] =
	{
	{1, 2, 3, 4, 5},
	{6, 7, 8, 9, 10},
	{12, 13, 15, 16, 17}
	};

	int* matrix = new int[row * col];

	for (int r = 0; r < row; ++r)
		for (int c = 0; c < col; ++c)
			matrix[c + col * r] = s2da[r][c];

	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
			cout << matrix[c + col * r] << " ";
		cout << endl;
	}

	delete[] matrix;

	/*
	이중포인터 동적할당 2차원 배열 만들기

	int **matrix = new int *[row];
	// 이중포인터 matrix 선언하고 행 개수만큼 동적 메모리 할당
	// matrix는 포인터 배열로, 각 포인터는 열에 대한 배열을 가르킴

	for (int r = 0; r < row; ++r)
		matrix[r] = new int[col]; 
	// 반복문을 통해 각 행에 동적 메모리 할당


	for (int r = 0; r < row; ++r)
		for (int c = 0; c < col; ++c)
			matrix[r][c] = s2da[r][c];
	// s2da의 값을 matrix에 복사

	// print all elements //
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
			cout << matrix[r][c] << " ";
		cout << endl;
	}

	// delete //
	for (int r = 0; r < row; ++r)
		delete[] matrix[r];
	delete[] matrix;
	// 동적메모리 할당 해제, 메모리 누수 방지!
	
	*/
	

	/*
	matrix[c + col * r] 인 이유

	행 인덱스(r)에 col을 곱하는 이유:

	행 인덱스를 사용하여 각 행의 시작 위치를 계산합니다.
	행의 시작 위치는 해당 행의 인덱스에 열의 개수를 곱한 값입니다.
	이렇게 함으로써 각 행이 1차원 배열에서 어디에서 시작하는지를 나타냅니다.
	열 인덱스(c)를 더하는 이유:

	행의 시작 위치에 열 인덱스를 더하여 각 요소의 위치를 나타냅니다.
	각 행에서 열 인덱스만큼 이동하면서 해당 요소의 위치를 찾습니다.
	*/
		
	return 0;

} 