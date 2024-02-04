// STL Iterators (STL �ݺ���)
// vector�� ���� ���, ���ӵ� �޸𸮿� ������ ����
// �˻��� ������, �޸� ȿ���� ��� ���� ���� ���� �������� ����

// list�� ���߿��Ḯ��Ʈ ���, ������ ���� ���� ������ ������ ����
// ���� ������ ������, �˻� ����, �޸� ȿ���� ��� �����

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
