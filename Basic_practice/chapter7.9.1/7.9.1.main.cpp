// �Լ������� ����Ͽ� Ȧ�� ¦�� ����

#include <iostream>
#include <array>
#include <functional>	

using namespace std;

bool isEven(const int& number)
{
	if (number % 2 == 0) return true;
	else return false;
}

bool is0dd(const int& number)
{
	if (number % 2 != 0) return true;
	else return false;
}

//typedef bool (*check_fcn_t)(const int&);
// �Լ������͸� typedef ���� ��Ÿ��
using check_fcn_t = bool (*)(const int&);
// using���ε� �ٿ��� ��� ����

void printNumbers(const array<int, 10> &my_arr, 
	std::function<bool(const int&)> check_fcn = isEven) // functional Ȱ��
	//check_fcn_t check_fcn = isEven) // �⺻�� ����, �� �ڵ� ���� ��� 
{
	for (auto element : my_arr)
	{
		if (check_fcn(element)== true) cout << element;
	}
	cout << endl;
}

int main()
{

	std::array<int, 10> my_arr{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//printNumbers(my_arr); // �⺻�� isEven 
	//printNumbers(my_arr, is0dd);

	std::function<bool(const int&)> fcnptr = isEven;
	printNumbers(my_arr, fcnptr);
	fcnptr = is0dd;
	printNumbers(my_arr, fcnptr);
	return 0;
}