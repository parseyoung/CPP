/*
* ����
N���� ���ڿ��� �־����� N���� ���ڿ��� �־����� �� ���ڿ����� �ִ� ���� ���λ縦 ����ϴ� ���α׷��� �ۼ��ϼ���.
���� ���ڿ����� {��long", "longtime", "longest"} ��� �� �ܾ��� �ִ� ���� ���λ�� ��long"�Դϴ�.
* �Է�
ù ��° �ٿ� �ڿ��� N(3<=N<=30)�� �־����ϴ�.
�� ��° �ٺ��� N���� �ܾ �Էµ˴ϴ�. �� �ܾ��� ���̴� 100�� ���� �ʴ´�.
* ���
ù ��° �ٿ� �ִ� ���� ���λ縦 ����ϼ���.
*/

// count() �����̳ʿ��� Ư���� ���� ��ġ�ϴ� ������ ���� count�� ���
// �Ű������� 3�� count (start iterator, end iterator, value)

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
		// �� ���ڿ��� �ʱ�ȭ string tmp=""; ���� �ǹ�
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
