// exception 위험성과 단점
// 빈번하게 호출되는 for문에 예외처리 하면 아주 느림
// 가급적 main안에 사용하면 퍼포먼스 괜찮음
// 모든 오류를 예외처리로 하려고 하지 말기
// 분산처리 병렬처리시 예측 불가능한 상황 논리적으로 가늠하기 힘든 상황에 사용
// if 기능으로 해결 가능 한 것은 그렇게 해결

#include <iostream>
#include <memory>

using namespace std;

class A
{
public:
	// 소멸자 안에서 throw 불가 런타임 에러 발생
	~A()
	{
		throw "error";
	}
};
int main()
{
	try
	{
		// 예외가 발생하면 throw로 넘어가 delete[] 실행 X 메모리 누수 발생
		// 스마트포인터 unique_ptr로 해결
		int* i = new int[1000000];
		unique_ptr<int> up_i(i);

		// doSomething with i
		throw "error";

		// delete[] i;
		// A a
	}

	catch (...)
	{
		cout << "catch" << endl;
	}

	return 0;
}