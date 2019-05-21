// Classes
// --------------------------------------------------------------------------------

// Classes allow programming using object-oriented paradigms

// Classes are expanded concept of data structures:
// like data structures, they can contain data members,
// but they can also contain functions as members.
// and have access specifier

/*
class class_name				// class_name is a valid identifier for the class
{
	access_specifier_1:			// optionally access specifiers
		member1;				// members can either be data or function declarations
	access_specifier_2:
		member2;
	...
} object_names;					// optional list of names for objects of this class
*/

// An object is an instantiation of a class.

// access_specifiers: private, public or protected
// These specifiers modify the access rights for the members that follow them:

// private members, all members of a class is private access automatically
// ------------------------------
// private members are accessible only from within other members of the same class
// or from their friends
// private is the default access level

// protected members
// ------------------------------
// protected members are accessible from other members of the same class,
// or from their friends, but also from members of their derived classes.

// public members
// ------------------------------
// public members are accessible from anywhere where the object is visible.

#include <iostream>
using namespace std;

class Rectangle					// a class called Rectangle
{								// contains 4 members: 2 int, 2 member functions
	int width, height;			// 2 int with private access, default
public:							// 2 member functions with public access
	// two functions' declaration, without their definition
	void set_values (int, int);		// prototype
	int area () {return width * height;}	// definition
};							// an object of class Rectangle

// reintroduce the scope operator ::
// here is used in definition of function set_values, outside difinition
// to define a member of a class outside the class itself.
void Rectangle::set_values (int x, int y)
{
	width = x;
	height = y;
}

// The only difference between defining a member function within the class definition
// or to just include its declaration and define it later outside the class,
// is that the first case the function is automatically considered
// an inline member function by the compiler, while the second is a normal function
// This causes no differences in behavior, but only on possible compiler optimizations

int main ()
{
	Rectangle rect, rectb;
	// rect.width = 10;
	// error: ‘int Rectangle::width’ is private within this context: rect.width = 10;
	// width and height have private access and they can only be referred to
	// from within other members of that same class.
	// like function set_values and area
	rect.set_values (3,4);
	cout << "rect area: " << rect.area() << endl;
	rectb.set_values (5,6);
	cout << "rectb area: " << rectb.area() << endl;

	return 0;
}
