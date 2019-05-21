// Uniform initialization
// --------------------------------------------------------------------------------

// The way of calling constructors by enclosing their arguments in parentheses,
// as shown above, is known as functional form.
// class_name object_name (value, value, value, ...)

// But constructors can also be called with other syntaxes.

// constructors with a single parameter
// class_name object_name = initialization_value;

// uniform initialization
// class_name object_name {value, value, value, ... }
// an equal sign = is optional

#include <iostream>
using namespace std;

class Circle
{
	double radius;
public:
	Circle (double r) { radius = r; }
	double circum () { return 2 * radius * 3.14159265;}
};

class Rectangle
{
	int width, height;
public:
	Rectangle ();			// the default constructor
	Rectangle (int, int);
	int area () {return (width*height); }
};

Rectangle::Rectangle ()
{
	width = 5;
	height = 5;
}

Rectangle::Rectangle (int a, int b)
{
	width = a;
	height = b;
}

int main ()
{
// four ways to construct objects of a class whose constructor takes a single parameter
	Circle a (10.0);		// functional form
	Circle b  = 20.0;		// assignment init
	Circle c {30.0};		// uniform init
	Circle d = {40.0};		// POD-like

	cout << "a's circumference: " << a.circum() << endl;
	cout << "b's circumference: " << b.circum() << endl;
	cout << "c's circumference: " << c.circum() << endl;
	cout << "d's circumference: " << d.circum() << endl;

// an advantage of uniform initialization is that, unlike parentheses,
// braces cannot be confused with function declarations,
// and thus can be used to explicitly call default constructors.
	Rectangle recta;	// default constructor called
	Rectangle rectb ();	// function declaration (default constructor NOT called)
	Rectangle rectc {};	// default constructor called

	return 0;
}
