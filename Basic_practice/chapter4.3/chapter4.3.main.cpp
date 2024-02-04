//using문과 모호성

#include <iostream>

namespace a
{
	int my_val(10);
}

namespace b
{
	int my_val(20);
}

int main()
{
	using namespace std;
	/*
	using std::cout;
	using std::endl;
	...
	*/

	using namespace a;
	using namespace b;

	cout << "namespace a : " << a::my_val << endl;
	cout << "namespace b : " << b::my_val << endl;

	return 0;


}