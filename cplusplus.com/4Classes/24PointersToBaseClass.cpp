// Pointers to base class
// --------------------------------------------------------------------------------

// One of the key features of class inheritance is that 
// a pointer to a derived class is type-compatible with a pointer to its base class.

// Polymorphism is the art of taking advantage of this simple 
// but powerful and versatile feature.

#include <iostream>
using namespace std;

class Polygon
{
protected:
	int width, height;
public:
	void set_values (int a, int b)
	{ width = a; height = b; }
};

class Rectangle : public Polygon
{
public:
	int area() 
	{ return width * height; }
};

class Triangle : public Polygon
{
public:
	int area() 
	{ return width * height / 2; }
};

int main ()
{
	Rectangle rect;
	Triangle trgl;
	// declares two pointers to Polygon (named ppoly1 and ppoly2)
	Polygon * ppoly1 = &rect;	// assigned the address of rect (objects of Rectangle)
	Polygon * ppoly2 = &trgl;	// assigned the address of trgl (objects of Triangle)
	// Such assignments are valid, 
	// since both Rectangle and Triangle are classes derived from Polygon.
	ppoly1->set_values (4, 5);	// equal to    rect.set_values (4, 5);
	ppoly2->set_values (4, 5);
	// But because the type of ppoly1 and ppoly2 is pointer to Polygon
	// (and not pointer to Rectangle nor pointer to Triangle)
	// Only the members inherited from Polygon can be accessed,
	// and not those of the derived classes Rectangle and Triangle.
	cout << rect.area() << endl;	// use rect, instead of the pointer
	cout << trgl.area() << endl;

	return 0;
}
