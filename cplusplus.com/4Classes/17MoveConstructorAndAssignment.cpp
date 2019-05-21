// Move constructor and assignment
// --------------------------------------------------------------------------------
// MyClass (MyClass&&);				// move-constructor
// MyClass& operator= (MyClass&&);	// move-assignment
// MyClass&& is an rvalue(Return Value) reference, 
// rvalue is specified by following the type with two ampersands(&&)
// As a parameter, an rvalue reference matches arguments of temperaries of this type.

#include <iostream>
#include <string>
using namespace std;

// Similar to copying, 
// moving also uses the value of an object to set the value to another object
// But, unlike copying,
// the content is actually transferred from the source to the destination:
// the source loses that content, which is taken over by the destination.

// This moving only happens when the source of the value is an unnamed object.

// Unnamed objects are objects that are temporary in nature,
// and thus haven't even been given a name.
// Typical examples of unnamed objects are return values of functions or type-casts.

// The move constructor is called when an object is initialized on construction
// using an unnamed temporary.
// Likewise, the move assignment is called when an object is assigned the value of an
// unnamed temporary.

/*
moving is most useful for objects that manage the storage they use,
such as objects that allocate storage with new and delete.
In such objects, copying and moving are really different operations:
Copying from A to B:
------------------------------
new memory is allocated to B, 
and then the entire content of A is copied to this new memory allocated for B.
Moving from A to B:
------------------------------
the memory already allocated to A is transferred to B without allocating any new storage.
It involves simply copying the pointer.
*/

class Example6
{
	string * ptr;
public:
	// constructor
	Example6 (const string& str) : ptr {new string(str)} {}
	// destructor
	~Example6 () {delete ptr;}
	// move constructor
	Example6 (Example6&& x) : ptr(x.ptr) { x.ptr = nullptr; }
	// move assignment
	Example6& operator= (Example6&& x)
	{
		delete ptr;
		ptr = x.ptr;
		x.ptr = nullptr;
		return *this;
	}
	// access content
	const string& content() const {return *ptr;}
	// addition
	Example6 operator+ (const Example6& rhs)
	{
		return Example6(content() + rhs.content());
	}
};

int main ()
{
	Example6 foo ("FUCK");
	Example6 bar = Example6("SHIT");	// move-constructor

	foo = foo + bar;					// move-assignment

	cout << "foo's content: " << foo.content() << endl;

	return 0;
}
