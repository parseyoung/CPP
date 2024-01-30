// vector�� pair ����Ͽ� short coding

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair< string, pair<int, int> > a,
			pair< string, pair<int, int> > b)
{
	if (a.second.first == b.second.first) {
		return a.second.second < b.second.second;
	}
	else {
		return a.second.first > b.second.first; // ���� ���ٸ�, ���� ���� ��� ���
	}
}
int main(void) {

	vector<pair< string, pair<int, int> > > v;
	v.push_back(pair< string, pair<int, int> >("���ѿ�", pair<int, int>(90, 19961222)));
	v.push_back(pair< string, pair<int, int> >("�ڼ���", pair<int, int>(93, 19991209)));
	v.push_back(pair< string, pair<int, int> >("���ֿ�", pair<int, int>(89, 19880718)));
	v.push_back(pair< string, pair<int, int> >("�̹α�", pair<int, int>(89, 19720512)));
	v.push_back(pair< string, pair<int, int> >("������", pair<int, int>(100, 19990803)));


	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << " "; // second�� �̸� �ǹ�
	}
	return 0;
}
