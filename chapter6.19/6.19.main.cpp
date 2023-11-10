// ���������Ϳ� ���� ������ �迭
//new�� �������� ��������� delete �� �������
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
	���������� �����Ҵ� 2���� �迭 �����

	int **matrix = new int *[row];
	// ���������� matrix �����ϰ� �� ������ŭ ���� �޸� �Ҵ�
	// matrix�� ������ �迭��, �� �����ʹ� ���� ���� �迭�� ����Ŵ

	for (int r = 0; r < row; ++r)
		matrix[r] = new int[col]; 
	// �ݺ����� ���� �� �࿡ ���� �޸� �Ҵ�


	for (int r = 0; r < row; ++r)
		for (int c = 0; c < col; ++c)
			matrix[r][c] = s2da[r][c];
	// s2da�� ���� matrix�� ����

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
	// �����޸� �Ҵ� ����, �޸� ���� ����!
	
	*/
	

	/*
	matrix[c + col * r] �� ����

	�� �ε���(r)�� col�� ���ϴ� ����:

	�� �ε����� ����Ͽ� �� ���� ���� ��ġ�� ����մϴ�.
	���� ���� ��ġ�� �ش� ���� �ε����� ���� ������ ���� ���Դϴ�.
	�̷��� �����ν� �� ���� 1���� �迭���� ��𿡼� �����ϴ����� ��Ÿ���ϴ�.
	�� �ε���(c)�� ���ϴ� ����:

	���� ���� ��ġ�� �� �ε����� ���Ͽ� �� ����� ��ġ�� ��Ÿ���ϴ�.
	�� �࿡�� �� �ε�����ŭ �̵��ϸ鼭 �ش� ����� ��ġ�� ã���ϴ�.
	*/
		
	return 0;

} 