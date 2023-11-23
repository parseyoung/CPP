//() parenthesis 괄호 연산자 오버로딩과 Function object(Funcor) 함수객체
// 함수 객체는 일반 함수와는 달리 상태를 가질 수 있어서 
// 함수 호출 간에 정보를 보존하거나 공유할 때 유용
#include <iostream>
using namespace std;

class Accmualtor
{
private:
	int m_counter = 0;
public:
	int operator()(int i) { return (m_counter += i); }
};

int main()
{
	Accmualtor acc;
	cout << acc(10) << endl;
	cout << acc(20) << endl;

	return 0;
}