// lamda func(���� �Լ�=anonymous)�� std::function
// ���α׷��� �������� ������

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for each
#include <functional>
using namespace std;

void goodbye(const string& s)
{
	cout << "Good bye" << s << endl;
}

class Object
{
public:
	void hello(const string& s)
	{
		cout << "Hello " << s << endl;
	}
};

int main()
{
	// lamda-introducer
	// lamda-paramter-declaration
	// lamda-return-type-clause	
	// compuond-statement

	/*auto func = [](const int& i) -> void { cout << "Hello, World!" << endl; };
	func(123);*/

	[](const int& i) -> void { cout << "Hello, World!" << endl; } (1234);

	{
		string name = "JackJack";
		[&]() {std::cout << name << endl; } (); // name�� &������
		//[=]() {std::cout << name << endl; } (); // = : copy
		//[this]() {std::cout << name << endl; } (); // this : class ���
	}

	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	auto func2 = [](int val) {cout << val << endl; };
	for_each(v.begin(), v.end(), func2);
	// for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });


	cout << []() -> int { return 1; }() << endl;

	std::function<void(int)> func3 = func2;
	func3(123);

	// Ư�� paramter �ܿ��� �ް���� ��� bind() ���
	std::function<void()> func4 = std::bind(func3, 456);
	func4();

	//
	{
		Object instance;
		auto f = std::bind(&Object::hello, &instance, std::placeholders::_1);

		f(string("World"));
		// f("World");

		auto f2 = std::bind(&goodbye, std::placeholders::_1);

		f2(string("World"));
	}


	return 0;
}