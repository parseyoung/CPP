// circular dependency issues (순환 의존성 문제와)
// std::weak_ptr

#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Person
{
private:
	std::string m_name;
	// std::shared_ptr<Person> m_partner;
	std::weak_ptr<Person> m_partner;

public:
	Person(const std::string& name) : m_name(name)
	{
		std::cout << m_name << " created \n";
	}

	~Person()
	{
		std::cout << m_name << " destroyed \n";
	}

	friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
	{ 
		if (!p1 || !p2)
			return false;

		p1->m_partner = p2;
		(*p2).m_partner = p1;

		std::cout << p1->m_name << "is partnered with " << p2->m_name << "\n";

		return true;
	}

	// std::weak_ptr 사용 시 내부 내용 lock() 필수
	// 순환 의존성 깨기 위해 사용
	// 직접 사용 X shared_ptr로 return 받아 사용 하는 구조

	const std::shared_ptr<Person> getPartner() const
	{
		return m_partner.lock();
	}

	const std::string& getname() const
	{
		return m_name;
	}
};

	int main()
	{
		auto jh = std::make_shared<Person>("Jae Hyun");
		auto sy = std::make_shared<Person>("Se Young");

		partnerUp(jh, sy);

		cout << jh->getPartner()->getname() << endl;

		return 0;
	}
