// Copy constructor
// --------------------------------------------------------------------------------

// When an object is passed a named object of its own type as argument,
// its copy constructor is invoked in order to construct a copy

// a copy constructor is a constructor whose first parameter is of type reference to 
// the class itself (possibly const qualified) and which can be invoked with a single 
// argument of this type.

#include <iostream>
#include <string>
using namespace std;

// If a class has no custom copy nor move constructors (or assignments) defined, 
// an implicit copy constructor is provided.
class MyClass	// an implicit copy constructor is automatically defined.
{
public:
	int a, b;
	string c;
	MyClass () {}
	MyClass (int x, int y, const string& z) : a {x}, b {y}, c{z} {}
	void print ()
	{
		cout << a << "; " << b << "; " << c << endl;
	}
};

// implicit copy constructor sometimes is not enough
// pinters in classes like Example4, when is copied, not the content itself
// this means boths objects, the copy and the original, share a single string object
class Example5
{
	string * ptr;
public:
	Example5 (const string& str) : ptr(new string(str)) {}
	~Example5 () {delete ptr;}
	// copy constructor, performs a deep copy
	// allocates storage for a new string, initialized to contain a copy of the original
	// In this way, both objects, the copy and the original, 
	// have distinct copies of the content stored in different locations.
	Example5 (const Example5& x) : ptr(new string(x.content())) {}
	const string& content () const {return * ptr;}
};

int main ()
{
	MyClass A (3, 5, "Hahaha!");
	A.print();
	MyClass B (A);	// implicit copy constructor, performs a shallow copy
	B.print();

	// Example5
	cout << "Example5:" << endl;

	Example5 foo ("Example");
	cout << "foo's content: " << foo.content() << endl;

	Example5 bar = foo;
// 	Example5 bar (foo);		// same
// 	Example5 bar {foo};		// same

	cout << "bar's content: " << bar.content() << endl;

	return 0;
}
