// Type Inference(자료형 추론) auto와 decltype
// auto : 컴파일러가 초기 값을 기반으로 자료형 추론, 남발하면 가독성 떨어짐
// decltype : 표현식이나 개체의 자료형 조회 시 사용, 자료형만을 반환
#include <iostream>
#include <vector>
#include <algorithm> // std::min
using namespace std;


class Examples
{
public:
	void ex1()
	{
		std::vector<int> vect;
		for (std::vector<int>::iterator itr = vect.begin(); itr != vect.end(); ++itr)
			cout << *itr;

		for (auto itr = vect.begin(); itr != vect.end(); itr++)
			cout << *itr;

		for (auto itr : vect) // for (const auto * itr : vect)
			cout << itr;
	}

	void ex2()
	{
		// auto는 추론 시 const, & 하지 않음
		// 가장 기본적인 type만 남김
		int x = int();

		auto auto_x = x;

		const int& crx = x;

		auto auto_crx1 = crx;
		
		// 명시해줘야 추론 가능 
		const auto& auto_crx2 = crx;

		volatile int vx = 1024;

		auto avx = vx;

		volatile auto vavx = vx;
	}

	/*template<class T>
	void func_ex3(T arg)
	{}*/

	template<class T>
	void func_ex3(const T& arg)
	{}

	void ex3()
	{
		const int& crx = 123;

		func_ex3(crx);
	}

	void ex4()
	{
		const int c = 0;
		auto& rc = c;
		// rc = 123; // error
	}

	void ex5() //amendment
	{
		int i = 42;
		auto&& ri_1 = i; // l-value
		auto&& ri_2 = 42; // r_value
	}

	void ex6()
	{
		int x = 42;
		const int* p1 = &x;
		auto p2 = p1;
		// *p2 = 45; // error
	}

	template<typename T, typename S>
	void func_ex7(T lhs, S rhs)
	{
		auto prod1 = lhs * rhs;

		// typedef typeof(lhs * rhs) product_type; // pre-c++11 'some' compilers
		typedef decltype(lhs* rhs) product_type;

		product_type prod2 = lhs * rhs;

		// decltype(lhs * rhs)를 자료형으로 사용 가능
		// decltype은 실제로 수행하지 X
		decltype(lhs * rhs) prod3 = lhs * rhs;
	}

	template<typename T, typename S>
	auto func_ex8(T lhs, S rhs) -> decltype(lhs* rhs)
	{
		return lhs * rhs;
	}

	void ex7_8()
	{
		func_ex7(1.0, 345);
		func_ex8(1.2, 345);
	}

	struct S
	{
		int m_x;

		S()
		{
			m_x = 42;
		}
	};

	void ex9()
	{
		int x;
		const int cx = 42;
		const int& crx = x;
		const S* p = new S();

		auto a = x;
		auto b = cx;
		auto c = crx;
		auto d = p;
		auto e = p->m_x;

		typedef decltype(x) x_type;
		typedef decltype(cx) cx_type;
		typedef decltype(crx) crx_type;
		typedef decltype(p->m_x) m_x_type; // 'declared' type

		typedef decltype((x)) x_with_parens_type; // add references to lvalues
		typedef decltype((cx)) cx_with_parens_type;
		typedef decltype((crx)) crx_with_parens_type;
		typedef decltype((p->m_x)) m_w_with_parens_type;
	}

	const S foo()
	{
		return S();
	}

	const int& foobar()
	{
		return 123;
	}

	void ex10()
	{
		std::vector<int> vect = { 42, 43 };

		auto a = foo();
		typedef decltype(foo()) foo_type;

		auto b = foobar();
		typedef decltype(foobar()) foobar_type;

		auto itr = vect.begin();
		typedef decltype(vect.begin()) iterator_type;

		// vector []은 int 반환
		auto first_element = vect[0];
		decltype(vect[1]) second_element = vect[1];
	}

	void ex11()
	{
		int x = 0;
		int y = 0;
		const int cx = 42;
		const int cy = 43;
		double d1 = 3.14;
		double d2 = 2.72;

		typedef decltype(x* y) prod_xy_type;
		auto a = x * y;

		typedef decltype(cx* cy) prod_cxcy_type; // result is prvlaue
		auto b = cx * cy;

		// 두 개의 data type 같으면 & 붙음
		typedef decltype(d1 < d2 ? d1 : d2) cond_type; // result is lvalue. & is added
		auto c = d1 < d2 ? d1 : d2;

		typedef decltype(x < d2 ? x : d2) cond_type_mixed; // promotion of x to double
		auto d = x < d2 ? x : d2;

		// auto d = std::min(x, dbl); // type different error
	}

	template<typename T, typename S>
	auto fpmin_wrong(T x, S y) -> decltype(x < y ? x : y)
	{
		return x < y ? x : y;
	}

	// 자료형 같아도 & 안 붙히는 func
	template<typename T, typename S>
	auto fpmin(T x, S y) ->
		typename std::remove_reference<decltype(x < y ? x : y)>::type
	{
		return x < y ? x : y;
	}

	void ex12()
	{
		int i = 42;
		double d = 45.1;
		//auto a = std::min(i, d); // error : 'std::min' no matching overloaded function found
		auto a = std::min(static_cast<double>(i), d);

		int& j = i;

		typedef decltype(fpmin_wrong(i, d)) fpmin_return_type2;
		typedef decltype(fpmin_wrong(j, d)) fpmin_return_type2;
		// 자료형 같아서 & return
		typedef decltype(fpmin_wrong(d, d)) fpmin_return_type1;
	}

	void ex13()
	{
		std::vector<int> vect; // vect is empty
		typedef decltype(vect[0]) integer;
	}

	template<typename R>
	class SomeFunctor
	{
	public:
		typedef R result_type;

		SomeFunctor()
		{}

		result_type operator() ()
		{
			return R();
		}
	};

	void ex14()
	{
		SomeFunctor<int> func;
		typedef decltype(func)::result_type integer; // nested type
	}

	void ex15()
	{
		auto lamda = []() { return 42; };
		decltype(lamda) lamda2(lamda);
		decltype((lamda)) lamda3(lamda);

		cout << "Lamda Functions" << endl;
		cout << &lamda << " " << &lamda2 << endl;
		cout << &lamda << " " << &lamda3 << endl;
	}

	void ex16()
	{
		//generic lamda
		auto lamda = [](auto x, auto y)
		{
			return x + y;
		};

		cout << lamda(1.1, 2) << " " << lamda(3, 4) << " " << lamda(4.5, 2.2) << endl;
	}
};

int main()
{
	Examples examples;

	examples.ex1();
	examples.ex2();
	examples.ex3();
	examples.ex4();
	examples.ex5();
	examples.ex6();
	examples.ex7_8();
	examples.ex9();
	examples.ex10();
	examples.ex11();
	examples.ex12();
	examples.ex13();
	examples.ex14();
	examples.ex15();
	examples.ex16();

	return 0;
}