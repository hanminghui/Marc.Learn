#include <iostream>

typedef void(* Fun)(void);

class Base
{
	public:
		virtual void f() {std::cout << "Base::f" << std::endl;}
		virtual void g() {std::cout << "Base::g" << std::endl;}
		virtual void h() {std::cout << "Base::h" << std::endl;}
};

int main(int argc, char *argv[])
{
	Base b;
	Base c;
	Fun pFun = nullptr;

	void (Base::*ptof)(void) = &Base::f;
	void (Base::*ptog)(void) = &Base::g;
	void (Base::*ptoh)(void) = &Base::h;

	std::cout << "b address: " << (int*)(&b) << std::endl;
	std::cout << "c address: " << (int*)(&c) << std::endl;
	std::cout << "f() address: " << &ptof << std::endl;
	std::cout << "g() address: " << &ptog << std::endl;
	std::cout << "h() address: " << &ptoh << std::endl;

	(b.*ptof)();
    return 0;
}
