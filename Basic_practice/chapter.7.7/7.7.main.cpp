// 함수 오버로딩
// 명확하게 지도를 해야 함수 오버로딩의 구현이 쉬움
// 컴파일러가 구분을 정확히 못하면 에러가 발생함
// return type 만으로 구분이 되지 않음, 매개변수가 달라야함

void print(unsigned int value) {}
void print(float value) {}

int add(int x, int y)
{
	return x + y;
}

double add(double x, double y)
{
	return x + y;
}

int main()
{
	print((unsigned int)'a');
	print(0u);
	print(3.14F);
	return 0;
}