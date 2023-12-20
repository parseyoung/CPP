// std::thread�� multithreading(��Ƽ������)�� ����
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>
using namespace std;

mutex mtx; // mutual exclusion (��ȣ ����)

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
	//	e.join(); // ������ thread ������ ��ٸ�

	auto work_func = [](const string& name)
	{
		for (int i = 0; i < 5; ++i)
		{
			std::this_thread::sleep_for(std::chrono::microseconds(100));

			// mutex�� �ߺ� ���� �ذ�
			mtx.lock();
			cout << name << " " << std::this_thread::get_id() << "is working" << i << " " << endl;
			mtx.unlock();
		}
	};

	std::thread t1 = std::thread(work_func, "Jae Hyun");
	std::thread t2 = std::thread(work_func, "Se Young");

	// join() �Ͽ� main()�� ���� ������ �ʵ��� ��
	t1.join();
	t2.join();

	return 0;
}