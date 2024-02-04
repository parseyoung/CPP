// STL(표준템플릿라이브러리)와 Containers(컨테이너)
#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
using namespace std;

void sequnence_containers()
{
	// vector : 뒤에만 데이터 추가 가능
	{
		std::vector<int> vec;
		for (int i = 0; i < 10; ++i)
			vec.push_back(i);

		for (auto e : vec)
			cout << e << " ";
		cout << endl;
	}

	// deque : 앞 뒤 데이터 추가 가능

	{
		std::deque<int> deq;
		for (int d = 0; d < 10; ++d)
		{
			deq.push_back(d);
			deq.push_front(d);
		}

		for (auto& e : deq)
			cout << e << " ";
		cout << endl;	
	}
}

void associative_containers()
{
	//set
	{
		std::set<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");

		// 2 출력, 중복 요소 무시
		cout << str_set.size() << endl;

		for (auto& e : str_set)
			cout << e << " ";
		cout << endl;
	}

	// multoset : duplication is allowed
	{
		std::multiset<string> str_mset;

		str_mset.insert("Hello");
		str_mset.insert("World");
		str_mset.insert("Hello");

		// 3 출력, 중복 요소 허용
		// but 정렬된 순서로 출력
		// Hello Hello World
		cout << str_mset.size() << endl;

		for (auto& e : str_mset)
			cout << e << " ";
		cout << endl;
	}

	// map : key/value (pair)
	// key는 유일해야 하며, key 기반 정렬 상태 유지
	{
		std::map<char, int> map;

		map['c'] = 50;
		map['a'] = 10;
		map['b'] = 20;


		cout << map['a'] << endl;

		map['a'] = 100;

		cout << map['a'] << endl;

		// first : key, second : value
		// 정렬된 a, b, c 순서로 출력
		for (auto& e : map)
			cout << e.first << " " << e.second << " ";
		cout << endl;
	}

	// multimap : duplicated keys
	// key base sorting
	{
		std::multimap<char, int> m_map;
		// before C++ 14, pair<char, int>('a', 10)
		m_map.insert(std::pair('a', 10));
		m_map.insert(std::pair('b', 10));
		m_map.insert(std::pair('c', 10));
		m_map.insert(std::pair('a', 100));

		cout << m_map.count('a') << endl; // 2

		for (auto& e : m_map)
			cout << e.first << " " << e.second << " ";
		cout << endl;
	}
}

void container_adapters()
{
		// stack : LIFO
	{
		cout << "Stack" << endl;

		std::stack<int> stack;
		stack.push(1); // push adds a copy
		stack.emplace(2); // constructurs a new object
		stack.emplace(3);
		cout << stack.top() << endl; // 3
		stack.pop(); // 3 delete
		cout << stack.top() << endl; // 2
	}

	// queue : FIFO
	{
		cout << "Queue" << endl;

		std::queue<int> queue;
		queue.push(1);
		queue.push(2);
		queue.push(3);
		cout << queue.front() << " " << queue.back() << endl; // 1 3
		queue.pop();
		cout << queue.front() << " " << queue.back() << endl; // 2 3
	}

	// Priority queue : sorting 
	{
		cout << "Priority queue" << endl;

		std::priority_queue<int> queue;

		for (const int n : {1, 8, 3, 5, 6, 0, 9, 2, 7})
			queue.push(n);

		for (int i = 0; i < 10; ++i)
		{
			cout << queue.top() << endl;
			queue.pop();
		}
	}
}

int main()
{
	sequnence_containers();
	associative_containers();
	container_adapters();
	return 0;
}
