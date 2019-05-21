// Dynamic allocation and polymorphism
// --------------------------------------------------------------------------------

// this example combines some of the features in the latest chapters,
// such as dynamic memory, constructor initializers and polymorphism

#include <iostream>
using namespace std;

class Polygon
{
protected:
	int width, height;
public:
	Polygon (int a, int b) : width {a}, height {b} {}
	virtual int area (void) = 0;
	void printarea()
	{ cout << this->area() << endl; }
};

class Rectangle: public Polygon
{
public:
	Rectangle (int a, int b) : Polygon (a, b) {}
	int area ()
	{ return width * height; }
};

class Triangle : public Polygon
{
public:
	Triangle (int a, int b) : Polygon (a, b) {}
	int area ()
	{ return width * height / 2; }
};

int main ()
{
// ppoly pointers are declared being of type "pointer to Polygon",
// but the objects allocated have been declared having the derived class type directly
// (Rectangle and Triangle)
	Polygon * ppoly1 = new Rectangle (4, 5);
	Polygon * ppoly2 = new Triangle (4, 5);
	ppoly1->printarea();
	ppoly2->printarea();
	delete ppoly1;
	delete ppoly2;

	return 0;
}
