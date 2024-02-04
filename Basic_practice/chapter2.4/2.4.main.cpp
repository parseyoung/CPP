#include <iostream>

//()괄호 안 void 생략 가능, 원칙주의 코딩 하는 분들이 자주 함.
//()괄호 내부 : 파라미터 자리, 파라미터가 없으면 (void)
//return이 없을 경우에도 맨 앞에 void 넣어야 함.
void my_function(void)

{

}

int main()
{
	//void my_void; void는 메모리를 차지 하지 않기 때문에 이렇게 선언 불가능
	//data type이 다르고 data size가 다르더라도, data의 주소를 표현하는 data양 동일 ***
	int i = 123;
	float f = 123.456f;

	void* my_void; 
	
	//&는 주소, i(정수형)의 주소
	my_void = (void*)&i;
	my_void = (void*)&f;

	return 0;
}