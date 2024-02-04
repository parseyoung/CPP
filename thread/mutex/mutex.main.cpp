// mutex : ��ȣ ����, ���̽� ����� ���� 
// Race Condition(���̽� �����) : ���� �����尡 ������ �����͸� ���ÿ� �����ϰ� �����Ϸ��� �� �� �߻��ϴ� ����
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
	// (std::lock_guard�� �Ҹ��ڰ� �ڵ����� ȣ��)

}
int main() {
	thread t1(shardFun);
	thread t2(shardFun);

	t1.join();
	t2.join();

	std::cout << "Final value of sharedData: " << sharedData << std::endl;

	return 0;
}