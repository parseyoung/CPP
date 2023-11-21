//  정적 멤버 변수(Static Member Variables) :
//	클래스 내부에서 선언된 static 멤버 변수는 해당 클래스의 모든 객체가 공유하는 변수입니다.
//	객체가 여러 개 생성되더라도 이 변수는 하나의 메모리 공간만 차지하며 모든 객체가 공유합니다.
//	클래스의 정적 멤버 변수는 클래스의 하나의 복사본만 유지되며, 모든 객체가 이를 참조할 수 있습니다.

#include <iostream>
using namespace std;

class Something
{
public:
	static int s_value;
	static const int cs_value = 5;
	static constexpr int cse_value = 1;
	//싱글톤 패턴에서 자주 사용
	// 정적 변수는 여기서 초기화 불가, const일 경우는 여기서 반드시 초기화
};

int Something::s_value = 1; // define in cpp, no header file

int main()
{
	cout << &Something::s_value << " " << Something::s_value << endl;
	// static은 정의 되기 전에도 주소 찍어볼 수 있음 

	Something st1;
	Something st2;

	st1.s_value = 2;

	cout << &st1.s_value << " " << st1.s_value << endl;
	cout << &st2.s_value << " " << st2.s_value << endl;
	// st1.s_value와 st2.s_value는 같은 주소 사용 함.
	return 0;
}

