// Inheritance between classes
// --------------------------------------------------------------------------------

// classes in C++ can be extended, 
// creating new classes which retain characteristics of the base class.
// This process, known as inheritance,
// involves a base class and a derived class:
// the derived class inherits the members of the base class,
// on top of which it can add its own members.

#include <iostream>
using namespace std;

class Polygon	// the base class
{
protected:		// protected can be accessed by it's derived class, private can't
	int width, height;
public:			// public can be accessed from any where
	void set_values (int a, int b)
	{ width = a; height = b; }
};

// The objects of the classes Rectangle and Triangle 
// each contain members inherited from Polygon.
// These are: width, height and set_values

// Three keywords: 
// (set keyword as the less restrictive access level only for the members inherited)
// --------------------------------------------------
// public:
// the derived class will inherit all the members 
// with the same levels they had in the base class
// ------------------------------
// protected:
// all public members of the base class are inherited as protected in the derived class.
// ------------------------------
// private:
// all the base class members are inherited as private.
// ------------------------------

// If no access level is specified for the inheritance,
// the compiler assumes private for classes declared with keyword class
// and public for those declared with struct.

// Actually, most use cases of inheritance in C++ should use public inheritance.
// When other access levels are needed for base classes,
// they can usually be better represented as member variables instead.

class Rectangle: public Polygon		// the derived class
// keyword public denotes the most accessible level, all the members
{
public:
	int area ()
	{ return width * height; }
};

class Triangle: public Polygon		// another derived class
{
public:
	int area ()
	{ return width * height / 2; }
};

int main ()
{
	Rectangle rect;
	Triangle trgl;
	rect.set_values (4, 5);
	trgl.set_values (4, 5);
	cout << rect.area() << endl;
	cout << trgl.area() << endl;

	return 0;
}
