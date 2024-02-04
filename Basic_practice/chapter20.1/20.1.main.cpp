// 프로파일러를 통해 최적화가 필요한 부분 찾기 가능
// 최적화가 가장 필요한 곳을 80% 최적화 하는 것 목표
// 정밀한 프로그램 프로파일링 할 경우, 메모리와 CPU를 따로 함 
// 일반적인 프로그램은 같이 해도 큰 문제는 없지만, 위험성이 있을 수 있음
// 최적화 시 프로그래밍 스킬이 아닌(한계가 있음), 알고리즘 설계를 최적화하는 것이 효율적임
// Debug mode 진단도구 활용 프로파일링
// 디버그모드는 디버깅 정보를 모아 코드를 자세하게 볼 수는 있으나, 
// 퍼포먼스는 실제 릴리즈모드와 차이 발생
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <numeric> // std::inner_product
using namespace std;

void func1()
{
	long long sum = 0;
	for (unsigned i = 0; i < 100'000; ++i)
		sum += i;

	cout << sum << endl;
}

void func2()
{
	long long sum = 0;
	for (unsigned i = 0; i < 1000'000'000; ++i)
		sum += i;

	cout << sum << endl;
}

void run()
{
	func1();
	func2();
}
int main()
{

	//run();

	int* d = new int[10000];
	float* f = new float[100];

	delete[] d;
	delete[] f;

	return 0;

}