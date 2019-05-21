// Friend classes
// --------------------------------------------------------------------------------
// similar to friend functions, a friend class is a class
// whose members have access to the private or protected members of another class:

#include <iostream>
using namespace std;

// an empty declaration of class Square
// It's neccesary bacause class Rectangle uses Square (as a parameter in member convert),
// and Square uses Rectangle (declaring it a friend).
class Square;

class Rectangle	// Rectangle is a friend of Square
{
	int width, height;
public:
	int area()
	{
		return width * height;
	}
	void convert (Square a);	// Rectangle's member function convert()
};

class Square
{
friend class Rectangle;
private:
	int side;	// describes the side of the square
public:
	Square (int a) : side(a) {}
};

// convert is able to access private and protected members of Square
void Rectangle::convert (Square a)
{
	width = a.side;
	height = a.side;
}

// Friendships are never corresponded unless specified.
// Rectangle is a friend of Square, Square is not considered a friend by Rectangle.

// Another property of friendships is that they are not transitive:
// The friend of a friend is not considered a friend unless explicitly specified.

int main ()
{
	Rectangle rect;
	Square sqr (4);
	rect.convert(sqr);
	cout << rect.area() << endl;

	return 0;
}
