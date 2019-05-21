// Static members
// --------------------------------------------------------------------------------

// A class can contain static members, either data or functions.

// A static data member of a class is also known as a "class variable",
// because there is only one common variable for all the objects of that same class,
// sharing the same value:
// i.e. its value is not different from one object of this class to another.

#include <iostream>
using namespace std;

class Dummy
{
public:
	static int n;		// n contain a counter with the nubmer of objects of class Dummy
	Dummy () { n++; }
};

// In fact, static members have the same properties as non-member variables
// but they enjoy class scope.
// they cannot be initialized directly in the class, but somewhere outside it.
int Dummy::n = 0;

int main ()
{
	Dummy a;
	Dummy b[5];
// it can be referred to as a member of any object of that class
	cout << a.n << endl;
	Dummy * c = new Dummy;
// or even directly by the class name, of course this is only valid for static members
	cout << Dummy::n << endl;
// These two calls above are referring to the same variable: 
// the static variable n within class Dummy shared by all objects of this class.
	delete c;

	return 0;
}

// Classes can also have static member functions.

// These represent the same:
// members of a class that are common to all object of that class,
// acting exactly as non-member functions but being accessed like members of the class.

// Because they are like non-member functions, 
// they cannot access non-static members of the class 
// (neither member variables nor member functions).
// They neither can use the keyword this.
