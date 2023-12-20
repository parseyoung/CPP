// std::thread와 multithreading(멀티쓰레딩)의 기초
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>
using namespace std;

mutex mtx; // mutual exclusion (상호 배제)

int main()
{
	//const int num_pro = std::thread::hardware_concurrency();

	//cout << std::this_thread::get_id() << endl;

	//vector<std::thread> my_threads;
	//my_threads.resize(num_pro);

	//for (auto & e : my_threads)
	//	e = std::thread([]() {  
	//				cout << std::this_thread::get_id() << endl;
	//				while (true) {}});
	//for (auto& e : my_threads)
	//	e.join(); // 여러개 thread 끝나기 기다림

	auto work_func = [](const string& name)
	{
		for (int i = 0; i < 5; ++i)
		{
			std::this_thread::sleep_for(std::chrono::microseconds(100));

			// mutex로 중복 문제 해결
			mtx.lock();
			cout << name << " " << std::this_thread::get_id() << "is working" << i << " " << endl;
			mtx.unlock();
		}
	};

	std::thread t1 = std::thread(work_func, "Jae Hyun");
	std::thread t2 = std::thread(work_func, "Se Young");

	// join() 하여 main()이 먼저 끝나지 않도록 함
	t1.join();
	t2.join();

	return 0;
}