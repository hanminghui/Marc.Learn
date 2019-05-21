// Implicit members
// --------------------------------------------------------------------------------

// the six members functions described above 
// will be implicitly declared under certain circumstances:
/*
1 Default constructor:
	if no other constructors.
	Default definition: does nothing
2 Destructor:
	if no destructor.
	Default definition: does nothing
3 Copy constructor:
	if no move constructor and no move assignment
	Default definition: copies all members
4 Copy assignment:
	if no move constructor and no move assignment
	Default definition: copies all members
5 Move constructor:
	if no destructor, no copy constructor and no copy nor move assignment
	Default definition: moves all members
6 Move assignment:
	if no destructor, no copy constructor and no copy nor move assignment
	Default definition: moves all members
*/

// Each class can select explicitly 
// which of these members exist with their default definition
// or which are deleted by using the keywords default and delete, respectively.
// function_declaration = default;
// function_declaration = delete;

// EXAMPLE
// default and delete implicit members
#include <iostream>
using namespace std;

class Rectangle
{
	int width, height;
public:
	// Rectangle can be constructed either with two in arguments
	Rectangle (int x, int y) : width(x), height(y) {}
	// or be default-constructed (with no arguments)
	Rectangle () = default;
	// It cannot however be copy-constructed from another Rectangle object
	Rectangle (const Rectangle& other) = delete;
	int area () { return width * height; }
};

class Rectangle1
{
	int width, height;
public:
	Rectangle1 (int x, int y) : width(x), height(y) {}
	Rectangle1 () = default;
/*
the keyword default does not define a member function equal to the default constructor 
(i.e. where default constructor means constructor with no parameters),
but equal to the constructor that would be implicitly defined if not deleted.
*/
	Rectangle1 (const Rectangle1& other) = default;
	// is essentially equivalent to:
// 	Rectangle1 (const Rectangle1& other) : width(other.width), height(other.height) {}

	int area () { return width * height; }
};

int main ()
{
	Rectangle foo;
	Rectangle bar (10, 20);
// 	Rectangle baz { foo };	// error: copy constructor has been deleted
	cout << "bar's area: " << bar.area() << endl;

	Rectangle1 A (10, 20);
	Rectangle1 B { A };
	cout << "B's area: " << B.area() << endl;

	return 0;
}

/*
In general, and for future compatibility,
classes that explicitly define one copy/move constructor or one copy/move assignment
but not both,
are encouraged to specify either delete or default on the other special member functions
they don't explicitly define.
*/
