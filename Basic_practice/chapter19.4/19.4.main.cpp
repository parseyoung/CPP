// Race Condition(레이스 컨디션)
// std::atomic, std::scoped_lock
// std::atomic은 남용하면 효율성 떨어짐 주의
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>
using namespace std;

mutex mtx;

int main()
{
	// race condition을 atomic으로 해결
	//atomic<int> shared_memory(0);
	int shared_memory(0);

	auto count_func = [&]() {
		for (int i = 0; i < 1000; ++i)
		{
			this_thread::sleep_for(chrono::microseconds(1));
			
			// mutex로 race condition 해결
			//mtx.lock();

			// lock_guard()는 scope({ }) 내 unlock() 불가능한 경우 사용
			// 대부분의 경우 lock_guard() 사용 권장
			// C++ 17부터는 scoped_lock() 사용 권장
			//std::lock_guard lock(mtx);
			std::scoped_lock lock(mtx);
			shared_memory++;
			//shared_memory.fetch_add(1);
			//mtx.unlock();
		}
	};

	thread t1 = thread(count_func);
	thread t2 = thread(count_func);


	t1.join();
	t2.join();


	cout << "After" << endl;
	cout << shared_memory << endl;

	return 0;
}