// Default constructor
// --------------------------------------------------------------------------------

// Default constructor is the constructor called when objects of class are declared,
// but are not initialized with any arguments.

// When any constructor is explicitly declared in a class, 
// no implicit default constructor is automatically provided.

#include <iostream>
#include <string>
using namespace std;

class Example	// a class definition has no constructors
{
public:
	int total;
	void accumulate (int x) { total += x; }
};

class Example2	// a class has some constructor taking any number of parameters
{
public:
	int total;
	// declare an explicitly constructor taking one argument:
	Example2 (int initial_value) : total(initial_value) {}
	void accumulate (int x) { total += x; }
};

class Example3	// a class has a default constructor
{
	string data;
public:
	Example3 () {}	// default constructor
	Example3 (const string& str) : data {str} {}
	const string& content() const {return data;}
};

int main ()
{
// Example
// the compiler assumes class Example to have an implicitly defined default constructor
// Therefore, objects of this class can be constructed by simply declaring them
// without any arguments:
	cout << "Example1:" << endl;
	Example ex;
	ex.total = 0;
	cout << ex.total << endl;
	ex.accumulate(8);
	cout << ex.total << endl;

// Example2
// the compiler no longer provides an implicit default constructor,
// and no longer allows the declaration of new objects of that class without arguments.
	cout << "Example2:" << endl;
// 	Example2 ex2;			// not valid: no default constructor
	Example2 ex2(100);		// ok: calls constructor
	cout << ex2.total << endl;
	ex2.accumulate(8);
	cout << ex2.total << endl;

// Example3
	cout << "Example3:" << endl;
	Example3 foo;	// construct without arguments
	Example3 bar ("FUCK");
	cout << "bar's content: " << bar.content() << endl;

	return 0;
}
