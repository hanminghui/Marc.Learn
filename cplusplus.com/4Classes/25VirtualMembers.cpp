// Virtual members
// --------------------------------------------------------------------------------

// A virtual member is a member function that can be defined in a derived class, 
// while preserving its calling properties through references.

// A class that declares or inherits a virtual function is called a polymorphic class

#include <iostream>
using namespace std;

class Polygon
{
protected:
	int width, height;
public:
	void set_values (int a, int b)
	{ width = a; height = b; }
	// The syntax for a function to become virtual is to precede its declaration
	// with the virtual keyword:
	virtual int area ()			// declared as virtual in base class
	{ return 0; }
};

class Rectangle : public Polygon
{
public:
	int area ()					// redefined
	{ return width * height; }
};

class Triangle : public Polygon
{
public:
	int area ()					// redefined again
	{ return width * height / 2; }
};

// In this example, all three classes (Polygon, Rectangle and Triangle)
// have the same members: width, height, and functions set_values and area.

// area() in base class (Polygon) is virtual, 
// and it's redefined in derived classes(Rectangle and Triangle)

// Non-virtual members can also be redefined in derived classes,
// but non-virtual members of derived classes cannot be accessed 
// through a reference of the base class

int main ()
{
	Rectangle rect;
	Triangle trgl;
	Polygon poly;
	Polygon * ppoly1 = &rect;
	Polygon * ppoly2 = &trgl;
	Polygon * ppoly3 = &poly;
	ppoly1->set_values (4, 5);
	ppoly2->set_values (4, 5);
	ppoly3->set_values (4, 5);
	cout << ppoly1->area() << endl;
	cout << ppoly2->area() << endl;
	cout << ppoly3->area() << endl;

	return 0;
}
