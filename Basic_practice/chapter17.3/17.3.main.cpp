//std::string의 길이와 용량
// c-style은 문자열 마지막에 null char 숨어있지만
// C++는 추가 되지 않음 C++에서 string은 class임
// 0 = false 
// 효율성을 높히기 위해 미리 용량을 알고, 
// reserve로 잡고 시작하면 효율적임

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string my_str("01234567");
	my_str.reserve(1000); // capacity 최소 1000 잡아달라

	cout << std::boolalpha;
	cout << my_str.empty() << endl;
	cout << my_str.size() << endl;
	cout << my_str.length() << endl;
	cout << my_str.capacity() << endl;
	cout << my_str.max_size() << endl;

	return 0;
}