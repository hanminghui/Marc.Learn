// What is inherited from the base class
// --------------------------------------------------------------------------------
/*
In principle, a publicly derived class inherits access to every member of a class except:
	its consturctors and its destructor
	its assignment operator members (operator=)
	its friends
	its private members
*/

// Even though access to the constructors and destructor of the base class 
// is not inherited as such,
// they are automatically called by the constructors and destructor of the derived class.

#include <iostream>
using namespace std;

class Mother
{
public:
	Mother ()
	{ cout << "Mother: no parameters\n"; }
	Mother (int a)
	{ cout << "Mother: int parameter\n"; }
};

// Unless otherwise specified, 
// the constructors of a derived class calls the default constructor of its base classes
// (i.e. the constructor taking no arguments)
class Daughter : public Mother
{
public:
	Daughter (int a)	// nothing specified: call default constructor
	{ cout << "Daughter: int parameter\n\n"; }
};

// Calling a different constructor of a base class is possible,
// using the same syntax used to initialize member variables in the initialization list:
// derived_constructor_name (parameters) : base_constructor_name (parameters) {...}
class Son : public Mother
{
public:
	Son (int a) : Mother (a)	// constructor specified: call this specific constructor
	{ cout << "Son: int parameter\n\n"; }
};

int main ()
{
	Daughter kelly(0);
	Son bud(0);

	return 0;
}
