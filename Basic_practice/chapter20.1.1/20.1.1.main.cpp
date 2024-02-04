// Release mode 프로파일링
#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <utility>
#include <vector>
#include <atomic>
#include <future>
#include <numeric> // std::inner_product
#include <execution> // parallel execution
using namespace std;

mutex mtx;

void dotProductNaive(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end, unsigned long long& sum)
{
	for (unsigned i = i_start; i < i_end; ++i)
		sum += v0[i] * v1[i];
}

void dotProductLock(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end, unsigned long long& sum)
{
	//cout << "Thread start" << endl;

	for (unsigned i = i_start; i < i_end; ++i)
	{
		std::scoped_lock lock(mtx); //c++ 17
		// lock() 범위가 적을 수록 퍼포먼스 유리
		// 이처럼 반복이 잦은 곳에 사용하면 속도 느림

		sum += v0[i] * v1[i];
	}

	//cout << "Thread end" << endl;
}

void dotProductAtomic(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end, atomic<unsigned long long>& sum)
{
	for (unsigned i = i_start; i < i_end; ++i)
	{
		sum += v0[i] * v1[i];
	}
}

auto dotProductFuture(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end) {
	int sum = 0; // local sum
	for (unsigned i = i_start; i < i_end; ++i) {
		sum += v0[i] * v1[i];
	}
	return sum;
}

int main()
{

	const long long n_data = 100'000;
	const unsigned n_threads = 2;

	// initialize vectors
	std::vector<int> v0, v1;
	v0.reserve(n_data); // capacity 할당
	v1.reserve(n_data);

	random_device seed;
	mt19937 engine(seed());

	uniform_int_distribution<> uniformDist(1, 10);

	for (long long i = 0; i < n_data; ++i)
	{
		v0.push_back(uniformDist(engine));
		v1.push_back(uniformDist(engine));
	}

	cout << "std::inner_product" << endl;
	{
		const auto sta = chrono::steady_clock::now();
		const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);
		// 두 번째 부터는 begin()만 있어도 됨, 두 개가 갯수 같다고 가정
		// 0ull : unsigned long long , 0이면 int임
		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	cout << "Atomic" << endl;
	{
		const auto sta = chrono::steady_clock::now();
		atomic<unsigned long long> sum = 0;

		vector<thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads; // assumrs remainder = 0
		for (unsigned t = 0; t < n_threads; ++t)
			threads[t] = std::thread(dotProductAtomic, std::ref(v0), std::ref(v1),
				t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));
		for (unsigned t = 0; t < n_threads; ++t)
			threads[t].join();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum.load() << endl;  // load 함수를 통해 값을 가져옴
		cout << endl;
	}

	cout << "future" << endl;
	{
		const auto sta = chrono::steady_clock::now();
		atomic<unsigned long long> sum = 0;

		vector<std::future<int>> futures;
		futures.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads;
		for (unsigned t = 0; t < n_threads; ++t)
			futures[t] = std::async(std::launch::async, dotProductFuture, std::ref(v0), std::ref(v1),
				t * n_per_thread, (t + 1) * n_per_thread);

		for (unsigned t = 0; t < n_threads; ++t)
			sum += futures[t].get();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	return 0;
}
