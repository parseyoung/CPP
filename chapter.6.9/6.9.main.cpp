#include <iostream>

using namespace std;

int main()

{

	char name[] = "Jack jack";
	const int n_name = sizeof(name) / sizeof(char);
	char* ptr = name;

	for (int i = 0; i < n_name; ++i)
	{
		cout << *(ptr + i) << endl;
	}
	/*
	int array[]{9, 7, 5, 3, 1};

	int * ptr = array;


	for (int i = 0; i < 5; ++i)
		//cout << array[i] << " " << (uintptr_t) & array[i] << endl;
		cout << *(ptr + i) << " " << (uintptr_t)(ptr + i) << endl;
	*/
	return 0;

}
