/*
정적 할당은 컴파일 전에 미리 설정 되있어야 함 (const로 고정) const int leg = 5;
동적 할당은 런타임때 배열의 사이즈 결정하고 os로부터 메모리 그때 그떄 받아옴
*/

#include <iostream>

using namespace std;

int main()
{
	int length;
	cin >> length;

	int* array = new int[length] {}; //{} 안에 안 넣으면 array[2]부터 0으로 채움

	array[0] = 1;
	array[1] = 2;

	for (int i = 0; i < length; ++i)
	{
		cout << (uintptr_t)&array[i] << endl;
		cout << array[i] << endl;

	}

	delete [] array; //new를 사용했기에 delete를 습관적으로 해주는 것이 좋음
	return 0;


}
