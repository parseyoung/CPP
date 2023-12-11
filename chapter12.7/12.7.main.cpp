// pure virtuual function (���� ���� �Լ�)
// body�� ���� �ڽ�Ŭ�������� �ݵ�� �������̵� �ؾ� ��
// 
// abstract basic class (�߻� �⺻ Ŭ����)
// ���������Լ��� ���Ե� Ŭ������ �߻�⺻Ŭ������ ��
// 
// interface class (�������̽� Ŭ����)
// ��� ��� �Լ��� ���������Լ��� Ŭ������ �������̽�Ŭ������ ��
#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
	string m_name;

public:
	Animal(string name)
		: m_name(name)
	{}

public:
	string getName() { return m_name; }

	virtual void speak() const = 0; //pure virtual func

};

void Animal::speak() const
{
	cout << m_name << "???" << endl;
}

class Cow : public Animal
{
public:
	Cow(string name)
		: Animal(name)
	{}

	virtual void speak() const
	{
		cout << m_name << "Moooo" << endl;
	}
};

class Cat : public Animal
{
public:
	Cat(string name)
		: Animal(name)
	{}

	virtual void speak() const
	{
		cout << "name : " << m_name << " Mewooo " << endl;
	}
};

// �������̽��� �� �� �ƴ°� ����, ��� ���� ���� Ŭ������ 
// reportError�� �� �� �ȴٸ� ������ ����
class IErrorLog  // �������̽��� I�� �����°� ����
{
public:
	virtual bool reportError(const char* errorMessage) = 0;
	virtual ~IErrorLog() {}
};

class FileErrorLog : public IErrorLog
{
public:
	virtual bool reportError(const char* errorMessage) override
	{
		cout << "Writing error to a file" << endl;
		return true;
	}
};

class ConsolErrorLog : public IErrorLog
{
public:
	virtual bool reportError(const char* errorMessage) override
	{
		cout << "Priting error to a console" << endl;
		return true;
	}
};

void doSomething(IErrorLog& log)
{
	log.reportError("Runtime error!");
}

int main()
{
	Cow cow("Jae Hyun");
	cow.speak();

	FileErrorLog file_log;
	ConsolErrorLog console_log;

	// IErrorLog Ŭ������ ��� �޾ұ⿡ �Լ� ��� ����
	doSomething(file_log);
	doSomething(console_log);
	return 0;
}


