// std::exception class ��ӹ޾� ����ϱ� (���Ĵٵ���̺귯��)
// exception�� �θ�Ŭ������ �ڽ� Ŭ������ �ſ� ���� ���ǵǾ� ����

#include <iostream>
#include <exception>
#include <string>

class CustomException : public std::exception
{
public:
	// noexcept? �ش� ���� �ȿ����� ���ܸ� �߻���Ű�� �ʰڴ�.
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
		
		// ���� �� exception ���
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