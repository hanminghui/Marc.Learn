// Implicit conversions with classes
// --------------------------------------------------------------------------------

// In the world of classes, 
// implicit converions can be controlled by means of three members functions:

// Single-argument constructors:
// allow implicit conversion from a particular type to initialize an object.

// Assignment operator:
// allow implicit conversion from a particular type on assignments.

// Type-cast operator:
// allow implicit conversion to a particular type.

#include <iostream>
using namespace std;

class A {};

class B
{
public:
	// conversion from A (constructor)
	B (const A& x) {}
	// conversion from A (assignment)
	B& operator= (const A& x) {return *this;}
	// converstion to A (type-cast operator)
	operator A() {return A();}
	// Notice that the return type is the destination type 
	// and thus is not specified before the operator keyword.
};

int main ()
{
	A foo;
	B bar = foo;	// calls constructor
	bar = foo;		// calls assignment
	foo = bar;		// calls type-cast operator
	foo = A(bar);	// calls type-cast operator explicitly

	return 0;
}
