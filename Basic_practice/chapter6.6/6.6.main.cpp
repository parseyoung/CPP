#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char source[] = "Copy this!";
	char dest[50];
	strcpy_s(dest, 50, source);
	//strcpy(dest, source)
	//strcat(dest, source) 는 동일 내용 뒤에 한번 더 붙혀줌
	/*
	strcmp(source, dest)는 같으면 0, 다르면 - 1 출력
	아래처럼 골격을 짜야 함
	if (strcmp(source, dest) == 0)
	{

	}
	*/
	cout << source << endl;
	cout << dest << endl;

	return 0;
}