// constructors
// --------------------------------------------------------------------------------

// in the previous example, if we called the member function area before set_values,
// an undetermined result will happen,
// since the members width and height had never been assigned a value.

// In order to avoid that, we use constructor, a special function included in a class

#include <iostream>
using namespace std;

class Rectangle
{
	int width, height;
public:
	// constructor function, is declared just like a regular member function,
	// but with a name that matches the class name and without any return type;
	// not even void.
	Rectangle (int, int);
	int area () {return (width*height); }
};

Rectangle::Rectangle (int a, int b)
{
	width = a;
	height = b;
}

// Notice how neither the constructor prototype declaration (within the class)
// nor the latter constructor difinition, have return values; not even void:
// Constructors never return values, they simply initialize the object.

int main ()
{
// constructor will automatically called whenever a new object of this class is created,
// allowing the class to initialize member variables or allocate storage.
	Rectangle rect (3, 4);
	Rectangle rectb (5, 6);
	// Constructors cannot be called explicitly as if they were regular member functions.
	// They are only executed once, when a new object of that class is created.
	cout << "rect area: " << rect.area() << endl;
	cout << "rectb area: " << rectb.area() << endl;
	return 0;
}
