// Task(�۾�)��� �񵿱� ���α׷��� (async, future, promise)
// thread�� join() �ؾ� ������, asynce�� join() X
// asynce()�� future ������ �� �ϸ� ���������� ���� ��
#include <iostream>
#include <future> // async, promise
#include <thread>
using namespace std;

int main()
{
	// multi-threading
	// thread ������ ����
	{
		int result;
		std::thread t([&] { result = 1 + 2; });
		t.join();
		cout << result << endl;
	}

	// task-based parallelism
	// thread ���� async�� �� ��ȣ ��
	// � task�� �� ���ΰ��� ����
	{
		// std::future<int> fut = ...
		auto fut = std::async([] {return 1 + 2; });
		cout << fut.get() << endl;
	}

	// future and promise
	// future�� thread���� ����Ϸ��� promise�� �ؾ� ��
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
