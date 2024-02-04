// thread�� ���� �� �Լ��� ���� ������� thread�� Ȱ��ȭ ��
// copy�Ұ� move�� ����
// mutex�� ����Ͽ� �ټ��� �����尣�� ����� ������ �ʵ��� ȣ��
// ��� ���ϸ� 
// fn fn
// // 
// fn   fn fn  �̷������� ��� ���� ������� ���� 
// ���� : �Լ� ȣ�� �� ���������� ���� ���� ������ ���� �޸� ����
// ������� ������ ������ �Ҵ�Ǿ� �������� �Լ� ȣ�� �� �������� ����
// ������ ������ ���� �� �������� �Ҵ� ��, ������ ���� �� �ڵ� ����
// ������� ���ÿ��� ���� ������ vector�� Ȱ�� �� ������ �Ҵ�� �޸𸮸� ���� ������ ���� ����

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
	//// copy constructor ��� X
	//// std::thread t2(t1);
	//
	//// join() ����ؼ� �ش� thread�� ������ ���� ��ٸ�
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