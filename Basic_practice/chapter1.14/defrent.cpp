#include <iostream>


void doSomething()
{
//가급적 중괄호 안에 넣는게 좋음
using namespace std;

	//ifdef, endif는 전처리기
#ifdef LIKE_APPLE //정의가 되어있으면, 
	cout << "Apple" << endl;

#else LIKE_APPLE//정의가 되어있지 않으면,
	cout << "orange" << endl;

#endif
}
