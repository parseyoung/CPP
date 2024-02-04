// 자료형에게 가명 붙혀주기
// 유지보수, 고정너비정수에서 플랫폼에 독립적인 코딩하는데 사용 가능하다.
#include <iostream>
#include <vector>
#include <cstdint>


int main()
{
	using namespace std;

	typedef double distance_t; // double을 float로 수정하면 많은 자료형을 더 쉽게 변경 가능
	//pairlist_t로 정의해놨기 때문에 "pairlist_t pairrlist3;" 이런식으로 간단하게 사용 가능
	typedef vector<pair<string, int> > pairlist_t;
	

	double my_distance;
	distance_t homework;
	distance_t home2school;

	vector<pair<string, int> > pairlist1;
	vector<pair<string, int> > pairlist2;

	pairlist_t pairrlist3;



	return 0;
}