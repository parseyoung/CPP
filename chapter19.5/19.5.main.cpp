// Task(작업)기반 비동기 프로그래밍 (async, future, promise)
// thread는 join() 해야 하지만, asynce는 join() X
// asynce()와 future 연결을 안 하면 순차적으로 실행 됨
#include <iostream>
#include <future> // async, promise
#include <thread>
using namespace std;

int main()
{
	// multi-threading
	// thread 생성에 집중
	{
		int result;
		std::thread t([&] { result = 1 + 2; });
		t.join();
		cout << result << endl;
	}

	// task-based parallelism
	// thread 보다 async를 더 선호 함
	// 어떤 task를 할 것인가에 집중
	{
		// std::future<int> fut = ...
		auto fut = std::async([] {return 1 + 2; });
		cout << fut.get() << endl;
	}

	// future and promise
	// future을 thread에서 사용하려면 promise를 해야 함
	{
		std::promise<int> prom;
		auto fut = prom.get_future();

		auto t = std::thread([](std::promise<int>&& prom)
		{
			prom.set_value(1 + 2);
		}, std::move(prom)); // r-value & 

		cout << fut.get() << endl;
		t.join();
	}

	{
		auto f1 = std::async([] {
			cout << "async1 start" << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "async1 end" << endl;
			});

		auto f2 = std::async([] {
			cout << "async2 start" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "async2 end" << endl;
			});

		std::cout << "Main Function" << endl;
	}

	return 0;
}
