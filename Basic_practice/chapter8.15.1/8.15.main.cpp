// 실행 시간 측정하기 (실시간 작용 코드 개발 시 자주 사용) 
// 실제 시간 측정 시 릴리즈 모드로 측정 하면 됌.
// 시간 측정 시 최소 3~4번 체크 해봐야 함.
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

class Timer
{
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;

	std::chrono::time_point<clock_t> start_time = clock_t::now();


public:
	void elapsed()
	{
		std::chrono::time_point<clock_t> end_time = clock_t::now();

		cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << endl;

	}
};

int main()
{
	random_device rnd_device;
	mt19937 mersenne_engine{ rnd_device() };

	vector<int> vec(10);
	for (unsigned int i = 0; i < vec.size(); ++i)
		vec[i] = i;

	std::shuffle(begin(vec), end(vec), mersenne_engine);

	for (auto& e : vec)
		cout << e << " ";
	cout << endl;

	Timer timer;

	std::sort(begin(vec), end(vec));

	timer.elapsed(); 

	for (auto& e : vec)
		cout << e << " ";
	cout << endl;


	return 0;
}

