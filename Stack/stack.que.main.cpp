// stack : 입구와 출구 1개, LIFO
// Queue : 입구 출구 따로 있음, FIFO

#include<iostream>
#include <stack>
#include <queue>
using namespace std;

int main(void) {

	stack<int> s;
	s.push(7);
	s.push(5);
	s.push(4);
	s.pop();
	s.push(6);
	s.pop();
	while (!s.empty()) {
		cout << s.top() << ' '; // 5 7
		s.pop();
	}
	cout << endl;

	queue<int> q;
	q.push(7);
	q.push(5);
	q.push(4);
	q.pop();
	q.push(6);
	q.pop();
	while (!q.empty()) {
		cout << q.front() << ' '; // 4 6
		q.pop();
	}
	return 0;
}
