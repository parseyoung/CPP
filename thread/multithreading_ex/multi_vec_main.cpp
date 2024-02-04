// 멀티스레딩 예제 <inner_product, 벡터 내적 계산>
#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <utility>
#include <vector>
#include <atomic>
#include <numeric> // std::inner_product
#include <execution> // parallel execution
#include <future>

using namespace std;

mutex mtx;

void dotProductNaive(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end, unsigned long long& sum) {

	for (unsigned long long i = i_start; i < i_end; ++i) {
		sum += v0[i] * v1[i];
	}
}

// lock 걸린 부분이 적은 수록 퍼포먼스 올라감
void dotProductLock(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end, unsigned long long& sum) {
	cout << "thread start" << endl;
	for (unsigned i = i_start; i < i_end; ++i) {
		std::lock_guard<std::mutex> lock(mtx);
		//std::scoped_lock(mtx); // c++17
		sum += v0[i] * v1[i];
	}
}

void dotProductAtomic(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end, atomic<unsigned long long>& sum) {

	for (unsigned i = i_start; i < i_end; ++i) {
		sum += v0[i] * v1[i];
	}
}

auto dotProductFuture(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end)
{
	unsigned long long sum = 0;
	for (unsigned i = i_start; i < i_end; ++i) {
		sum += v0[i] * v1[i];
	}
	return sum;
}

void dotProductThreaded(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end, promise<unsigned long long>&& p)
{
	unsigned long long sum = 0;
	for (unsigned i = i_start; i < i_end; ++i) {
		sum += v0[i] * v1[i];
	}
	p.set_value(sum);
}

int main() {

	/*
	v0 = {1, 2, 3};
	v1 = {4, 5, 6};
	v0_dot_v1 = 1*4 + 2*5 + 3*6;
	*/

	const long long n_data = 100'000;
	const unsigned n_threads = 7;

	// initialize vec
	// reserve() : 동적 할당과 복사의 비용을 줄이기 위해 미리 특정 크기의 메모리를 할당
	std::vector<int> v0, v1;
	v0.reserve(n_data);
	v1.reserve(n_data);

	// 난수 생성
	random_device seed;
	mt19937 engine(seed());

	// 1부터 10 사이의 정수를 생성하는 균일 분포 객체를 생성
	uniform_int_distribution<> uniformDist(1, 10);

	for (long long i = 0; i < n_data; ++i) {
		v0.push_back(uniformDist(engine));
		v1.push_back(uniformDist(engine));
	}
	
	// 정답
	cout << "std::inner_product" << endl; {
		const auto sta = chrono::steady_clock::now();

		const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	// 가장 순진한 방법 - 레이스 컨디션 발생
	cout << "Naive" << endl; {
		const auto sta = chrono::steady_clock::now();
		unsigned long long sum = 0;

		vector<thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads;
		for (unsigned t = 0; t < n_threads; ++t)
			threads[t] = std::thread(dotProductNaive, std::ref(v0), std::ref(v1),
				t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));

		for (unsigned t = 0; t < n_threads; ++t)
			threads[t].join();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;

	}
	//// roxk guard (race condition 해결)
	//// but, 속도 느림
	//cout << "Lockguard" << endl; {

	//	const auto sta = chrono::steady_clock::now();
	//	unsigned long long sum = 0;

	//	vector<thread> threads;
	//	threads.resize(n_threads);

	//	const unsigned n_per_thread = n_data / n_threads;
	//	for (unsigned t = 0; t < n_threads; ++t)
	//		threads[t] = std::thread(dotProductLock, std::ref(v0), std::ref(v1),
	//			t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));

	//	for (unsigned t = 0; t < n_threads; ++t)
	//		threads[t].join();

	//	const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

	//	cout << dur.count() << endl;
	// cout << endl;
	//	cout << sum << endl;
	//}

	// atomic 정답은 정확하지만, 역시나 속도 느림
	cout << "Atomic" << endl; {
		const auto sta = chrono::steady_clock::now();
		atomic<unsigned long long> sum = 0;

		vector<thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads;
		for (unsigned t = 0; t < n_threads; ++t)
			threads[t] = std::thread(dotProductAtomic, std::ref(v0), std::ref(v1),
				t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));

		for (unsigned t = 0; t < n_threads; ++t)
			threads[t].join();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}
	// future는 다른것 처럼 글로벌 변수에 여러 스레드가 접근하여 값을 더해나가는 방식이 아님!
	// async(비동기)가 작동할때 dotProductFuture() 함수를 통해 각 local sum을 return 받고
	// 그걸 futures가 받아서 sum 함
	// future은 값 return 가능
	cout << "future" << endl; {
		const auto sta = chrono::steady_clock::now();

		unsigned long long sum = 0;
		vector<std::future<unsigned long long>> futures;
		futures.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads;
		for (unsigned t = 0; t < n_threads; ++t)
			futures[t] = std::async(dotProductFuture, std::ref(v0), std::ref(v1),
				t * n_per_thread, (t + 1) * n_per_thread);

		for (unsigned t = 0; t < n_threads; ++t)
			sum += futures[t].get();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	cout << "std::transform_reduce" << endl; {
		const auto sta = chrono::steady_clock::now();
		// const auto sum = std::transform_reduce(std::execution::seq, v0.begin(), v0.end(), v1.begin(), 0ull);
		const auto sum = std::transform_reduce(std::execution::par, v0.begin(), v0.end(), v1.begin(), 0ull);

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	// std::promise 및 std::future를 사용하여 벡터 내적을 계산하는 방법
	cout << "Promise and Future" << endl; {
		const auto sta = chrono::steady_clock::now();
		vector<future<unsigned long long>> futures;
		futures.reserve(n_threads);

		const unsigned n_per_thread = n_data / n_threads;
		vector<promise<unsigned long long>> promises(n_threads);

		for (unsigned t = 0; t < n_threads; ++t) {
			futures.emplace_back(promises[t].get_future());
			thread(dotProductThreaded, cref(v0), cref(v1), t * n_per_thread, (t + 1) * n_per_thread, move(promises[t])).detach();
		}

		unsigned long long sum = 0;
		for (unsigned t = 0; t < n_threads; ++t)
			sum += futures[t].get();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}
	return 0;
}