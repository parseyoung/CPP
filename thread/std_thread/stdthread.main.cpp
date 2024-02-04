// thread는 생성 시 함수를 같이 던져줘야 thread가 활성화 됨
// copy불가 move만 가능
// mutex를 사용하여 다수의 스레드간의 출력이 섞이지 않도록 호출
// 사용 안하면 
// fn fn
// // 
// fn   fn fn  이런식으로 출력 순서 보장되지 않음 
// 스택 : 함수 호출 및 지역변수와 같은 지역 데이터 저장 메모리 영역
// 스레드는 독립된 스택이 할당되어 스레드의 함수 호출 및 지역변수 관리
// 스텍은 스레드 생성 시 동적으로 할당 됨, 스레드 종료 시 자동 해제
// 스레드는 스택에서 실행 되지만 vector를 활용 해 힙에서 할당된 메모리를 통해 데이터 공유 가능

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex cout_mutex;

void fn() {
	std::lock_guard<std::mutex> lock(cout_mutex);
	std::cout << "fn" << std::endl;
}

int main() {
	//std::thread t1(fn);
	//std::thread t2{ std::move(t1) };
	//// copy constructor 사용 X
	//// std::thread t2(t1);
	//
	//// join() 사용해서 해당 thread가 끝날때 까지 기다림
	//t2.join();

	std::vector<std::thread> threads;
	for (int i = 0; i < 5; i++) {
		threads.emplace_back(std::thread(fn));
	}

	for (auto& thread : threads) {
		thread.join();
	}
	return 0;
}