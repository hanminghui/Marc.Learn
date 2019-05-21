// Member initialization in constructors
// --------------------------------------------------------------------------------

#include <iostream>
using namespace std;

// When a constructor is used to initialize other members,
// these other members can be initialized directly,
// without resorting to statements in its body.

// This is done by inserting, before the constructor's body,
// a colon : and a list of initializations for class members.

/*
// EXAMPLE
class Rectangle
{
	int width, height;
public:
	Rectangle(int, int);
	int area() {return width * height;}
};
// defined as usual
Rectangle::Rectangle (int x, int y) { width = x, height = y; }
// defined using member initialization
Rectangle::Rectangle (int x, int y) : width(x) { height = y; }
Rectangle::Rectangle (int x, int y) : width(x), height(y) {}
// in last case, constructor does nothing else than initialize its members
*/

/*
For members of fundamental types, it makes no differences which of the ways above 
the constructor is defined, because they are not initialized by default,
but for member objects (class), if they are not initialized after the colon,
they are default-constructed.
Default-constructing all members of a class may or may not be convenient:
	in some cases, this is a waste
	in some other cases, default-construction is not even possible 
	(when the class does not have a default constructor, like the example below).
in these cases, members shall be initialized in the member initialization list.
*/

class Circle
{
	double radius;
public:
	Circle (double r) : radius(r) {}
	double area() {return radius*radius*3.14159265;}
};

class Cylinder
{
	Circle base;	// Cylinder has a member object whose type is another class
	double height;
public:
	// Because objects of class Circle can only be constructed with a parameter,
	// Cylinder's constructor needs to call base's constructor,
	// and the only way to do this is in the member initializer list
// 	Cylinder (double r, double h) : base(r), height(h) {}
	// initializations can also use uniform initializer syntax, {} instead of ()
	Cylinder (double r, double h) : base{r}, height{h} {}
	double volume () {return base.area() * height;}
};

int main ()
{
	Cylinder foo (10, 20);
	cout << "foo's volume: " << foo.volume() << '\n';
	return 0;
}
