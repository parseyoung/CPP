// move constructors(이동 생성자)와 move assignment(이동 대입)
#include "Timer.h"
#include "AutoPtr.h"
#include "Resource.h"

AutoPtr<Resource> generateReource()
{
	AutoPtr<Resource> res(new Resource(1000000));

	return res;
}

int main()
{
	using namespace std;
	streambuf* orig_buf = cout.rdbuf();
	//cout.rdbuf(NULL); // disconnecnt cout from buffer
	
	Timer timer;

	{
		AutoPtr<Resource> main_res;
		main_res = generateReource();
	}

	cout.rdbuf(orig_buf);
	cout << timer.elapsed() << endl;

	return 0;

}