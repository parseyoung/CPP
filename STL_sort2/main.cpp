// vector와 pair 사용하여 short coding

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
		return a.second.first > b.second.first; // 점수 같다면, 나이 많은 사람 출력
	}
}
int main(void) {

	vector<pair< string, pair<int, int> > > v;
	v.push_back(pair< string, pair<int, int> >("박한울", pair<int, int>(90, 19961222)));
	v.push_back(pair< string, pair<int, int> >("박세영", pair<int, int>(93, 19991209)));
	v.push_back(pair< string, pair<int, int> >("임주원", pair<int, int>(89, 19880718)));
	v.push_back(pair< string, pair<int, int> >("이민규", pair<int, int>(89, 19720512)));
	v.push_back(pair< string, pair<int, int> >("윤재현", pair<int, int>(100, 19990803)));


	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << " "; // second는 이름 의미
	}
	return 0;
}
