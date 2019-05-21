// Friend functions
// --------------------------------------------------------------------------------
// Friends are functions or classes declared with the keyword friend.

// In principle, private and protected members of a class cannot be accessed 
// from outside the same class in which they are declared.
// However, this rule does not apply to "friends".

#include <iostream>
using namespace std;

class Rectangle
{
	int width, height;
public:
	Rectangle () {}
	Rectangle (int x, int y) : width {x}, height {y} {}
	int area() {return width * height;}
// A non-member function can access the private and protected members of a class
// if it is declared a friend of that class.
// include a declaration of this external function within the class, with keyword friend
	friend Rectangle duplicate (const Rectangle&);
};

// The duplicate function is a friend of class Rectangle.
// Therefore, duplicate is able to access the members width and height (private)
Rectangle duplicate (const Rectangle& param)
{
	Rectangle res;
	res.width = param.width * 2;
	res.height = param.height * 2;
	return res;
}

// NOTE: neither in the declaration of duplicate nor in its later use in main,
// it is considered a member of class Rectangle.

int main ()
{
	Rectangle foo;
	Rectangle bar (2,3);
	foo = duplicate (bar);
	cout << foo.area() << endl;

	return 0;
}

// Typical use cases of friend functions are operations
// that are conducted between two different classes 
// accessing private or protected members of both.
