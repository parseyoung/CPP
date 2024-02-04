// circular dependency issues (��ȯ ������ ������)
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

	// std::weak_ptr ��� �� ���� ���� lock() �ʼ�
	// ��ȯ ������ ���� ���� ���
	// ���� ��� X shared_ptr�� return �޾� ��� �ϴ� ����

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
