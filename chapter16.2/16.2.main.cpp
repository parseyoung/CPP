// STL Iterators (STL 반복자)
// vector는 동적 기반, 연속된 메모리에 순차적 저장
// 검색이 빠르며, 메모리 효율적 사용 가능 삽입 삭제 끝에서만 빠름

// list는 이중연결리스트 기반, 이전과 다음 원소 포인터 가지고 있음
// 삽입 삭제가 빠르며, 검색 느림, 메모리 효율적 사용 어려움

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;

int main()
{
	//vector<int> container;
	//for (int i = 0; i < 10; ++i)
	//	container.push_back(i);

	//list<int> container;
	//for (int i = 0; i < 10; ++i)
	//	container.push_back(i);

	//set<int> container;
	//for (int i = 0; i < 10; ++i)
	//	container.insert(i);

	map<int, char> container;
	for (int i = 0; i < 10; ++i)
		container.insert(make_pair(i, char(i+65)));

	 //ver3.
	for (auto itr = container.begin(); itr != container.end(); ++itr)
		//cout << *itr << " ";
		cout << itr->first << " " << itr->second << endl;

	// ver1.
	//vector<int>::const_iterator itr;
	//itr = container.begin();
	//while (itr != container.end())
	//{
	//	cout << *itr << " ";

	//	++itr;
	//}
	//cout << endl;

	// ver2.
	//for (auto& e : container)
	//	cout << e << " ";
	//cout << endl;

	


	return 0;
}
