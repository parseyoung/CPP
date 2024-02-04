// Race Condition(���̽� �����)
// std::atomic, std::scoped_lock
// std::atomic�� �����ϸ� ȿ���� ������ ����
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>
using namespace std;

mutex mtx;

int main()
{
	// race condition�� atomic���� �ذ�
	//atomic<int> shared_memory(0);
	int shared_memory(0);

	auto count_func = [&]() {
		for (int i = 0; i < 1000; ++i)
		{
			this_thread::sleep_for(chrono::microseconds(1));
			
			// mutex�� race condition �ذ�
			//mtx.lock();

			// lock_guard()�� scope({ }) �� unlock() �Ұ����� ��� ���
			// ��κ��� ��� lock_guard() ��� ����
			// C++ 17���ʹ� scoped_lock() ��� ����
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