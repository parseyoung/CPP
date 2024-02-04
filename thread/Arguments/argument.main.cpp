#include <iostream>
#include <thread>
#include <string>
// ref 사용하면 복사를 피해 성능은 향상, 하지만 여러 스레드 동시 접근하면 충돌 일어남
// 일관성 유지를 위해 & (ref) 사용은 동기화를 고려하여 사용해야 함
// arf, ref, ret의 대해 알아 봄

void fn(int a, std::string & s) {
	std::cout << a << s << std::endl;
}

void fn2(int& c) {
	std::cout << c << std::endl;
}

void threadcaller(std::thread & t) {
	int num = 42;
	t = std::thread(fn2, std::ref(num));
	// main에서 join하면 쓰레기 값 출력
	// 같은 스코프에서 join을 해주는 게 좋음
	t.join();
}

int fn3(int& ret) {
	ret = 3;
	return 3;
}

int fn4()
{
	return 5;
}

int main() {
	//int num = 42;
	//std::string s = "nocope";
	//std::thread t1(fn, num, std::ref(s));
	//t1.join();

	//std::thread t2;
	//threadcaller(t2);

	//int num = 0;
	//std::thread t3(fn3, std::ref(num));
	//t3.join();
	//std::cout << "retVal" << num << std::endl;
	
	int num = 0;
	std::thread t4([&num](){
		num = fn4();
	});
	t4.join();
	std::cout << "retVal" << num << std::endl;

	return 0;
}