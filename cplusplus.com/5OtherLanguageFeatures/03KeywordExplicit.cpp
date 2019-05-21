// Keyword explicit
// --------------------------------------------------------------------------------

#include <iostream>
using namespace std;

// On a function call, C++ allows one implicit conversion to happen for each argument.
void print (int a)
{ cout << a << endl;}

// This may be somewhat problematic for classes, 
// because it is not always what is intended.
class A {};
class B
{
public:
// 	B (const A& x) {}
	explicit B (const A& x) {}
	B& operator= (const A& x) {return *this;}
	operator A() {return A();}
};

// this function takes an argument of type B,
// but it could as well be called with an object of type A as argument
void fn (B x) {}
// it can be prevented by marking the affected constructor with explicit keyword

int main ()
{
	double x = 3.14;
	print (x);

	A foo;
	B bar (foo);
	bar = foo;
	foo = bar;

// 	fn (foo);	// not allowed for explicit constructor
	fn (bar);

	// Additionally, constructors marked with explicit cannot be called 
	// with the assignment-like syntax
// 	B baz = foo;	// not allowed for explicit constructor

	// Type-cast member functions can also be specified as explicit.
	// This prevents implicit conversions in the same way as explicit-specified 
	// constructors do for the destination type.

	return 0;
}
