// Abstract base classes
// -------------------------------------------------------------------------------- 

// Abstract base classes are classes that can only be used as base classes,
// and thus are allowed to have virtual member functions without definition
// (known as pure virtual functions)
// The syntax is to replace their definition by =0 (an equal sign and a zero)

/*
Virtual members and abstract classes grant C++ polymorphic characteristics,
most useful for object-oriented projects.
*/

// these examples are very simple use cases,
// but these features can be applied to 
// arrays of objects or dynamically allocated objects.
// see 27DynamicAllocationAndPolymorphism.cpp

#include <iostream>
using namespace std;

// Classes that contain at least one pure virtual function 
// are known as abstract base classes.
class Polygon	// abstract base Polygon class
{
protected:
	int width, height;
public:
	void set_values (int a, int b)
	{ width = a; height = b; }

	// a pure virtual function
	virtual int area (void) = 0;	// area() has no definition; been replaced by =0

// Is is possible to use the special pointer this to access the proper virtual members,
// even though Polygon itself has no implementation for this function:
	void printarea()
	// pure virtual member called by abstract base class
	{ cout << this->area() << endl; }	
};

class Rectangle : public Polygon
{
public:
	int area (void)
	{ return width * height; }
};

class Triangle : public Polygon
{
public:
	int area (void)
	{ return width * height / 2; }
};

int main ()
{
	Rectangle rect;
	Triangle trgl;
	// Abstract base classes cannot be used to instantiate objects.
	// But it can be used to create pointers to it,
	// and take advantage of all its polymorphic abilities.
	Polygon * ppoly1 = &rect;
	Polygon * ppoly2 = &trgl;
	ppoly1->set_values (4, 5);
	ppoly2->set_values (4, 5);
	cout << ppoly1->area() << endl;
	cout << ppoly2->area() << endl;
	cout << endl;
	ppoly1->printarea();
	ppoly2->printarea();

	return 0;
}
