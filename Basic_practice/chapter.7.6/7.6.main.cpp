// inline 함수
// 컴파일러에게 인라인 방식으로 해달라고 요청을 하는 것임
// 인라인 키워드를 명시 했어도 컴파일러 판단으로 진행 안 할수도 있음

#include <iostream>

using namespace std;

inline int min(int x, int y)
{
	return x > y ? y : x;
}

int main()
{
	cout << min(2, 7) << endl;
	cout << min(3, 1) << endl;

	cout << (2 > 7 ? 2 : 5) << endl;
	// inline사용 시 이런식으로 작동 되어서, 함수가 호출 되는
	// 일련의 과정이 생략되어 속도가 빨라질 순 있으나.
	// 정확한 근거는 크게 없는 듯함.
	// 차라리 속도를 높히고 싶다면, 하드웨어 가속, GPU 가속, 병령처리가 나을듯함

	return 0;
}