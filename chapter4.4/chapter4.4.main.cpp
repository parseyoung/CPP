// Auto 키워드와 자료형 추론

#include <iostream>

auto add(int x, int y) //auto를 파라미터에는 사용불가
{
	return x + y;
}

int main()
{
	using namespace std;

	auto a = 123; // 단, 초기화 하지 않으면 auto키워드 사용불가
	auto d = 123.0;
	auto c = 1 + 2.0;
	auto result = add(1, 2);

	cout << result << endl;

	return 0;

}