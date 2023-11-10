// For-each 반복문

#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>


using namespace std;

int main()
{
	//int fibonacci[]{ 0, 1, 2, 3, 200, 25, 100 };

	std::vector<int> fibonacci = { 0, 1, 2, 3, 200, 25, 100 };

	int max_number = std::numeric_limits<int>::lowest();
	for (const auto &n : fibonacci)
		max_number = std::max(max_number, n);

		cout << max_number << endl;


	return 0;
	/*change array values

	for (auto &number : fibonacci) //reference 해야 바뀜
		number *= 10;

	*/

	/* output

	for (const auto& number : fibonacci)
		cout << number << " ";
	cout << endl;

	return 0;

	*/
}