#include <iostream>

class Foo
{
public:
	Foo(int i) {_i = i;}
	void f()
	{
		std::cout << "Foo::f()" << std::endl;
	}
	static void staticf()
	{
		std::cout << "static f()" << std::endl;
	}
	void g()
	{
		std::cout << _i << std::endl;
	}
private:
	int _i;
};

int main(int argc, char *argv[])
{
    Foo * a = nullptr;
	
	/* call from null pointer */
	a->f();

	/* pointer to member function */
	void (Foo::*ptof) (void) = &Foo::f;
	/* call the function by pointer, ptr to member select ->* */
	(a->*ptof)();
	/* call the function by member, ptr to member select .* */
	Foo b(1);
	(b.*ptof)();

	void (Foo::*ptog) (void) = &Foo::g;
	Foo c(2);
	(b.*ptog)();
	(c.*ptog)();
	a = &b;
	(a->*ptog)();
	a = &c;
	(a->*ptog)();

	/* static member function */
// 	void (Foo::*ptostaticf) (void) = &Foo::staticf; // error
	/* regular pointer */
	void (*ptostaticf)(void) = &Foo::staticf;
	/* call by regular function pointer call */
	ptostaticf();
	(*ptostaticf)();

    return 0;
}
