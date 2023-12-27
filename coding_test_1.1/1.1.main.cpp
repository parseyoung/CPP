/*
* 설명
N개의 문자열이 주어지면 N개의 문자열이 주어지면 이 문자열들의 최대 공통 접두사를 출력하는 프로그램을 작성하세요.
만약 문자열들이 {“long", "longtime", "longest"} 라면 세 단어의 최대 공통 접두사는 ”long"입니다.
* 입력
첫 번째 줄에 자연수 N(3<=N<=30)이 주어집니다.
두 번째 줄부터 N개의 단어가 입력됩니다. 각 단어의 길이는 100을 넘지 않는다.
* 출력
첫 번째 줄에 최대 공통 접두사를 출력하세요.
*/

// count() 컨테이너에서 특정란 값과 일치하는 원소의 개수 count시 사용
// 매개변수는 3개 count (start iterator, end iterator, value)

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int  main()
{
	ios_base::sync_with_stdio(false);
	
	int n, len=INT_MAX;
	string str;
	cin >> n;

	vector<string> words;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		words.push_back(str);
		len = min(len, int(str.size()));
	}
	string res;
	for (int i = 0; i < len; i++)
	{
		string tmp;
		// 빈 문자열로 초기화 string tmp=""; 같은 의미
		for (auto& s : words)
			tmp += s[i];
		int m = count(tmp.begin(), tmp.end(), tmp[0]);
		if (m == n) res+=tmp[0];
		else break;
	}

	//vector<string> words;
	//for (int i = 0; i < n; i++)
	//{
	//	cin >> str;
	//	words.push_back(str);
	//	len = min(len, int(str.size()));
	//}
	//string res;
	//for (int i = 0; i < len; i++)
	//{
	//	set<char> tmp;
	//	for (auto& s : words)
	//		tmp.insert(s[i]);
	//	if (tmp.size() == 1) res += words[0][i];
	//	else break;
	//}
	//cout << res << endl;
	//return 0;

	/*vector<string> words;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		words.push_back(str);
	}
	string res = words[0];
	for (int i = 0; i < res.size(); i++)
	{
		while (words[i].find(res) != 0)
		{
			res = res.substr(0, res.size() - 1);
		}
	}*/

	cout << res << endl;
	return 0;
}
