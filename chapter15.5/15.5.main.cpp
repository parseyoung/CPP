// std::unique_ptr ������ �� ���� ���� 
// copy �Ұ� move�� ����

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

// Resource Ÿ�� ����ũ�����ͷ� �����ϴ� ���,
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

		/*�����Ҵ� �� ���� ����ũ ������ ��� ����
		auto* ptr = new Resource(5);
		std::unique_ptr<Resource> res1(ptr);*/

		// std::make_unique ����ؼ� ����
		// auto ��� �� �ϸ�, �Ʒ�ó�� �ؾ� �� ���� auto ���
		// std::make_unique<Resource> res1 = std::make_unique<Resource>(5);
		auto res1 = std::make_unique<Resource>(5);

		// doSomething() return ����ؼ��� ����
		//auto res1 = doSomething();

		(*res1).setAll(5);
		res1->print();

		std::unique_ptr<Resource> res2;

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;
		std::cout << static_cast<bool>(res2) << std::endl;

	//	unique_ptr�� copy Semantics ��� ���� ���� **
	//	res2 = res1;
	//	
	//	move semantics
	//	�������� �Ѱ� res1�� �Ұ� res2�¾���
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

	//	// move �ϸ� ������ �����Ƿ� res1�� �ٽ� �־���
	//	//res1 = doSomething2(std::move(res1));
	//	
	//	// �Ʒ��� void doSomething2(Resource * res) �̶� ���
	//	doSomething2(res1.get());

	//	std::cout << std::boolalpha;
	//	std::cout << static_cast<bool>(res1) << std::endl;
	//	res1->print();

	//}
	
	// res�� ����ũ�����ͷ� 2�� ������ X
	// delete�� ������� �ϸ� �ȉ�.
	/*{
		Resource* res = new Resource;
		std::unique_ptr<Resource> res1(res);
		std::unique_ptr<Resource> res2(res);

		delete res;
	}*/
	return 0;
}