// Overloading class constructors
// --------------------------------------------------------------------------------

// like any other function, a constructor can also be overloaded with different versions:
// with different number of parameters and/or parameters of different types.
// The compiler will automatically call the one whose parameters match the arguments

#include <iostream>
using namespace std;

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
	Rectangle rect (3, 4);
	Rectangle rectb;		// call the default constructor
	cout << "rect area: " << rect.area() << endl;
	cout << "rectb area: " << rectb.area() << endl;

	// NOTE: there is no parentheses when calling the default constructor.
	// rectc is a function declaration instead of an object declaration:
	// It would be a funcction that takes no arguments and returns Rectangle.
	Rectangle rectc();

	return 0;
}
