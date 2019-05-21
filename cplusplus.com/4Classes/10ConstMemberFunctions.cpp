// Const member functions
// --------------------------------------------------------------------------------

#include <iostream>
using namespace std;

class MyClass
{
public:
	int x;
	MyClass (int val) : x {val} {}
	int get0() {return x;}
	int get1() const {return x;}		// const member function
	// Member functions specified to be const cannot modify non-static data members
	// nor call other non-const member functions.
	// In essence, const members shall not modify the state of an object
	const int& get2() {return x;}		// member function returning a const&

	// Member functions can be overloaded on their constness:
	const int& get3() const {return x;} // const member function returning a const&
	int& get3() {return x;}
};

void print (const MyClass& arg)
{
// 	cout << arg.get2() << endl;	// error
	cout << arg.get3() << endl;
}

int main ()
{
	// When an object of a class is qualified as a const object:
	// The access to its data members from outside the class is restricted to read-only,
	// as if its data members were const for those accessing them from outside the class.
	// Note though, that constructor is still called and is allowed to 
	// initialize and modify these data members:

	const MyClass foo(10);
	MyClass bar (20);
// 	foo.x = 20;		// error: assignment of member 'MyClass::x' in read-only object
	cout << foo.x << endl;		// ok, data member x can be read
	// The member functions of a const object can only be called 
	// if they themselves specified as const members
// 	cout << foo.get0() << endl;		// error
	cout << foo.get1() << endl;
	cout << endl;

	print (foo);
	cout << endl;

// 	foo.get3() = 15;		// not valid: get3() returns const int&
	bar.get3() = 25;		// ok: get3() returns int&

	cout << foo.get3() << endl;
	cout << bar.get3() << endl;

	return 0;
}
