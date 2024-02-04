#include <iostream>
#include <thread>
#include <string>
// ref ����ϸ� ���縦 ���� ������ ���, ������ ���� ������ ���� �����ϸ� �浹 �Ͼ
// �ϰ��� ������ ���� & (ref) ����� ����ȭ�� ����Ͽ� ����ؾ� ��
// arf, ref, ret�� ���� �˾� ��

void fn(int a, std::string & s) {
	std::cout << a << s << std::endl;
}

void fn2(int& c) {
	std::cout << c << std::endl;
}

void threadcaller(std::thread & t) {
	int num = 42;
	t = std::thread(fn2, std::ref(num));
	// main���� join�ϸ� ������ �� ���
	// ���� ���������� join�� ���ִ� �� ����
	t.join();
}

int fn3(int& ret) {
	ret = 3;
	return 3;
}

int fn4()
{
	return 5;
}

int main() {
	//int num = 42;
	//std::string s = "nocope";
	//std::thread t1(fn, num, std::ref(s));
	//t1.join();

	//std::thread t2;
	//threadcaller(t2);

	//int num = 0;
	//std::thread t3(fn3, std::ref(num));
	//t3.join();
	//std::cout << "retVal" << num << std::endl;
	
	int num = 0;
	std::thread t4([&num](){
		num = fn4();
	});
	t4.join();
	std::cout << "retVal" << num << std::endl;

	return 0;
}