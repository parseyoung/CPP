// std::exception class 상속받아 사용하기 (스탠다드라이브러리)
// exception은 부모클래스임 자식 클래스가 매우 많이 정의되어 있음

#include <iostream>
#include <exception>
#include <string>

class CustomException : public std::exception
{
public:
	// noexcept? 해당 구문 안에서는 예외를 발생시키지 않겠다.
	const char* what() const noexcept override
	{
		std::cout << "custom()" << std::endl;
		return "Custom exception";
	}
};

int main()
{
	try
	{
		//std::string s;
		//s.resize(-1);
		
		// 정의 된 exception 사용
		// throw std::runtime_error("Bad thihng happend");

		throw CustomException();
	}

	catch (std::exception& exception)
	{
		std::cout << typeid(exception).name() << std::endl;
		// class std::length_error 

		std::cerr << exception.what() << std::endl;
		std::cout << "what()" << std::endl;
	}
	return 0;
}