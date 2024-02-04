#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
	vector<int> a = { 1, 3, 2, 4, 3, 2, 1, 1, 2, 3 };

	// set : 중복제거 및 정렬
	set<int> s;
	for (int i=0; i< a.size(); ++i)
	{
		s.insert(a[i]);
	}
	cout << s.size() << endl;
	for (auto it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}

	cout << endl;

	for (auto x : s) cout << x << " ";
	cout << endl;

	if (s.find(5) == s.end())
	{
		cout << "false";
		cout << *s.end() << endl;
	}
	else cout << "true";
	
	return 0;
}


//#include <iostream>
//using namespace std;
//
//int main()
//{
//	string a = "Jae Hyun Merry Christ mas!", res;
//	//string a = "aa bbb cccc ddddd eeeeee", res;
//
//	int pos, max = INT_MIN;
//	while ((pos = a.find(' '))!=string::npos)
//	{
//		string temp = a.substr(0, pos);
//		int len = temp.size();
//		if (len > max)
//		{
//			max = len;
//			res = temp;
//		}
//		a = a.substr(pos + 1);
//		//cout << a << endl;
//	}
//
//	if (a.size() > max) res = a;
//	cout << res << endl;
//
//	return 0;
//}