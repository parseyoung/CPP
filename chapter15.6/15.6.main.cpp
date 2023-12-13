// std::shared_ptr 소유권 여러개 가능
// 내부적으로 마지막 shared 포인터가 소멸시 delete된다.

#include <iostream>
#include "Resource.h"

// 파라미터로 넣을 경우
void doSomething(std::unique_ptr<Resource> res)
{

}

int main()
{	
	/*권장하지 않음
	doSomething(std::unique_ptr<Resource>(new Resource(100000)));
	권장 (shared도 마찬가지임)
	doSomething(std::make_unique<Resource>(1000000));*/

	/*Resource* res = new Resource(3);
	res->setAll(1);
	std::shared_ptr<Resource> ptr1(res);*/
	{
		auto ptr1 = std::make_shared<Resource>(3);
		ptr1->setAll(1);

		ptr1->print();

		{
			//std::shared_ptr<Resource> ptr2(ptr1);
			auto ptr2 = ptr1;

			(*ptr2).setAll(3);
			(*ptr2).print();

			std::cout << "Going out of the block" << std::endl;
		}

		ptr1->print();
		std::cout << "Going out of the block" << std::endl;

	}
}
