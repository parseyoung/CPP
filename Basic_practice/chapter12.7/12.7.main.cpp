// pure virtuual function (순수 가상 함수)
// body가 없어 자식클래스에서 반드시 오버라이딩 해야 함
// 
// abstract basic class (추상 기본 클래스)
// 순수가상함수가 포함된 클래스를 추상기본클래스라 함
// 
// interface class (인터페이스 클래스)
// 모든 멤버 함수가 순수가상함수인 클래스를 인터페이스클래스라 함
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

// 인터페이스는 할 줄 아는게 없음, 상속 받은 하위 클래스가 
// reportError를 할 줄 안다만 가지고 있음
class IErrorLog  // 인터페이스는 I를 붙히는게 관습
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

	// IErrorLog 클래스를 상속 받았기에 함수 사용 가능
	doSomething(file_log);
	doSomething(console_log);
	return 0;
}


