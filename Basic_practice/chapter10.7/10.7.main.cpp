// contanier class vector
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class IntArray
{
private:
	std::vector<int> my_arr;

public:
	IntArray(int size)
		: my_arr(size)
	{
		for (int i = 0; i < size; ++i)
		{
			my_arr[i] = i * 2;
		}
	}

	int getSize() const
	{
		return static_cast<int>(my_arr.size());
	}

	int& operator[](int index)
	{
		if (index >= 0 && index < getSize())
			return my_arr[index];
		else
			throw std::out_of_range("Index out of range");
	}
	// 새로운 요소 추가
	void append(int value)
	{
		my_arr.push_back(value);
	}
	// 특정 요소 제거
	void remove(int index)
	{
		if (index >= 0 && index < getSize())
			my_arr.erase(my_arr.begin() + index);
		else
		{
			throw out_of_range("index out of range");
		}
	}

	friend std::ostream& operator << (std::ostream& out, const IntArray& arr)
	{
		out << "[";
		// int가 아닌 size_t를 사용한 이유?
		// size_t는 부호 없는 정수 타입으로, 특히 배열의 크기를 나타낼 때 부호가 필요하지 않으며,
		// 큰 양수 값을 나타내기에 적합합니다. int 는 부호 있는 정수 타입임
		for (int i = 0; i < arr.my_arr.size(); ++i)
		{
			out << arr.my_arr[i];
			if (i < arr.my_arr.size() - 1)
			{
				out << ", ";
			}
		}
		out << "]";
		return out;
	}

};

int main()
{
	IntArray arr(5);

	cout << "Original Array : " << arr << endl;

	arr.append(10);
	cout << "Array after Append : " << arr << endl;

	arr.remove(3);
	cout << "Array after Remove : " << arr << endl;

	return 0;
}