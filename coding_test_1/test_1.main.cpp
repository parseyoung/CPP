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