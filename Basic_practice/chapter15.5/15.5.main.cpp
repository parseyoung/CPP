// std::unique_ptr 소유권 한 개만 가능 
// copy 불가 move만 가능

#include <iostream>
#include <memory>
#include "Resource.h"

auto doSomething()
{
	/*auto res1 = std::make_uiepue<Resource>(5);
	return tes1;*/

	return std::unique_ptr<Resource>(new Resource(5));

	// return std::make_unique<Resource>(5);

}

// L-value &
// void doSomething2(std::unique_ptr<Resource>& res)
// L-value
//auto doSomething2(std::unique_ptr<Resource> res)

// Resource 타입 유니크포인터로 설계하는 경우,
void doSomething2(Resource * res)
{
	res->setAll(10);
	res->print();

	//return res;
}

int main()
{
	/*std::unique_ptr<Resource> res(new Resource(100000000));*/
	
	//{

		//std::unique_ptr<int> uqi(new int);

		/*동적할당 된 곳에 유니크 포인터 사용 가능
		auto* ptr = new Resource(5);
		std::unique_ptr<Resource> res1(ptr);*/

		// std::make_unique 사용해서 생성
		// auto 사용 안 하면, 아래처럼 해야 함 보통 auto 사용
		// std::make_unique<Resource> res1 = std::make_unique<Resource>(5);
		auto res1 = std::make_unique<Resource>(5);

		// doSomething() return 사용해서도 가능
		//auto res1 = doSomething();

		(*res1).setAll(5);
		res1->print();

		std::unique_ptr<Resource> res2;

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;
		std::cout << static_cast<bool>(res2) << std::endl;

	//	unique_ptr은 copy Semantics 사용 못함 주의 **
	//	res2 = res1;
	//	
	//	move semantics
	//	소유권을 넘겨 res1은 잃고 res2는얻음
	//	res2 = std::move(res1);

	//	std::cout << std::boolalpha;
	//	std::cout << static_cast<bool>(res1) << std::endl;
	//	std::cout << static_cast<bool>(res2) << std::endl;

	//	if (res1 != nullptr) res1->print();
	//	if (res2 != nullptr) (*res2).print();
	// }

	
	//	auto res1 = std::make_unique<Resource>(5);
	//	res1->setAll(1);
	//	res1->print();

	//	std::cout << std::boolalpha;
	//	std::cout << static_cast<bool>(res1) << std::endl;

	//	// move 하면 소유권 잃으므로 res1에 다시 넣어줌
	//	//res1 = doSomething2(std::move(res1));
	//	
	//	// 아래는 void doSomething2(Resource * res) 이때 사용
	//	doSomething2(res1.get());

	//	std::cout << std::boolalpha;
	//	std::cout << static_cast<bool>(res1) << std::endl;
	//	res1->print();

	//}
	
	// res를 유니크포인터로 2곳 소유권 X
	// delete로 지우려고 하면 안됌.
	/*{
		Resource* res = new Resource;
		std::unique_ptr<Resource> res1(res);
		std::unique_ptr<Resource> res2(res);

		delete res;
	}*/
	return 0;
}