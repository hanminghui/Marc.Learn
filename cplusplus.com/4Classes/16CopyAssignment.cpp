// Copy assignment
// --------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

// implicit version, also a shallow copy
// --------------------------------------------------
class MyClass
{
	int a, b;
	string c;
public:
	// constructors:
	MyClass () {}
	MyClass (int x, int y, const string& z) : a {x}, b {y}, c{z} {}
	// member functions:
	void print () { cout << a << "; " << b << "; " << c << endl; }
};

// explicit version
// --------------------------------------------------
class Example5
{
	string * ptr;
public:
	Example5 (const string& str) : ptr(new string(str)) {}
	~Example5 () {delete ptr;}
	Example5 (const Example5& x) : ptr(new string(x.content())) {}
	const string& content () const {return * ptr;}
	// copy assignment
	Example5& operator= (const Example5& x)
	{
		delete ptr;						// delete currently pointed string
		ptr = new string (x.content());	// allocate space for new string, and copy
		return *this;
	}
};

int main ()
{
	// implicit version, also a shallow copy
	// --------------------------------------------------
	// Objects are not only copied on construction, when they are initialized:
	// They can also be copied on any assignment operation.
	MyClass foo (3, 8, "DIE!!!");
	foo.print();
	MyClass bar (foo);	// object bar initialization, copy constructor called
	bar.print();
	MyClass baz;		// object baz initialization
	baz = foo;			// object baz already initialized, copy assignment called
	baz.print();

	// The copy assignment operator is an overload of operator=
	// MyClass& operator= (const MyClass&);
	// It's also defined implicitly if a class has no custom copy nor move assignments
	// (nor move constructor) defined.

	// explicit version
	// --------------------------------------------------
	Example5 A ("FUCK");
	cout << A.content() << endl;
	Example5 B ("SHIT");
	A = B;
	cout << A.content() << endl;

	return 0;
}
