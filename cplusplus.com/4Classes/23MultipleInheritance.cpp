// Multiple inheritance
// --------------------------------------------------------------------------------
/*
A class may inherit from more than one class by simply specifying more base classes,
separated by commas, in the list of a class's base classes (i.e. after the colon).
*/

#include <iostream>
using namespace std;

class Polygon
{
protected:
	int width, height;
public:
	Polygon (int a, int b) : width (a), height (b) {}
};

class Output
{
public:
	static void print (int i);
};

void Output::print (int i)
{
	cout << i << endl;
}

class Rectangle: public Polygon, public Output
{
public:
	Rectangle (int a, int b) : Polygon (a, b) {}
	int area()
	{ return width * height; }
};

class Triangle: public Polygon, public Output
{
public:
	Triangle (int a, int b) : Polygon (a, b) {}
	int area()
	{ return width * height / 2; }
};

int main ()
{
	Rectangle rect (4, 5);
	Triangle trgl (4, 5);
	rect.print (rect.area());
	Triangle::print (trgl.area());

	return 0;
}
