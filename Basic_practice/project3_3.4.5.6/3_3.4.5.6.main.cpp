#include <iostream>

int main() {

	using namespace std;

	//sizeof(float); sizeof는 데이터의 크기를 알고싶을 경우 사용 데이터 타입을 넣어도 되고 변수를 넣어도 됨
	//sizeof는 함수 아니고 오퍼레이트임 표준으로 정의 해놈, 이로인해 변수명일 경우 괄호 없어도 작동함

	//comma operator

	int x = 3;
	int y = 10;

	int z = (++x, ++y);
	//위 코드를 풀어쓰면 밑 3줄임 
	//++x;
	//++y;
	//int z = y;

	cout << x << " " << y << " " << z << endl;

	// conditional opertator
	bool oneSale = true;

	const int price = (oneSale == true) ? 10 : 100;

	cout << price << endl;

	int d = 5;
	
	cout << ((d % 2 == 0) ? 0 : "odd") << endl;

	return 0;

}