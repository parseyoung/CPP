// mutex : 상호 배제, 레이스 컨디션 방지 
// Race Condition(레이스 컨디션) : 여러 스레드가 공유된 데이터를 동시에 접근하고 수정하려고 할 때 발생하는 문제
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std::mutex myMutex;
int sharedData = 0;

void shardFun() {

	// mutex lock
	lock_guard<std::mutex> lock(myMutex);

	// shard data modify
	sharedData++;

	// mutex unlock
	// (std::lock_guard의 소멸자가 자동으로 호출)

}
int main() {
	thread t1(shardFun);
	thread t2(shardFun);

	t1.join();
	t2.join();

	std::cout << "Final value of sharedData: " << sharedData << std::endl;

	return 0;
}