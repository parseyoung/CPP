// std::vector

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// std::array<int, 5> array; std::array는 정적할당이기에 사이즈를 지정 해주어야 했음


	std::vector<int> arr { 1, 2, 3, 4, 5 };

	arr.resize(3);

	for (auto& element : arr)
		cout << element << " ";
	cout << endl;

	cout << arr.size() << endl;

	cout << arr[1] << endl;

	cout << arr.at(1) << endl;


	std::vector<int> array2 { 17, 46, 1, };
	cout << array2.size() << endl;


	return 0;

}
