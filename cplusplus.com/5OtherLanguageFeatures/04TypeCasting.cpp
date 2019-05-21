// Type casting
// --------------------------------------------------------------------------------

// C++ is a strong-typed language.
// Many conversions, specially those that imply a different interpretation of the value,
// require an explicit conversion, known as C++ as type-casting.

#include <iostream>
using namespace std;

class Dummy
{
	double i, j;
public:
	Dummy () {}
	Dummy (double a, double b) { i = a; j = b; }
	void fuck ()
	{ cout << "fuck" << endl; }
};

class Addition
{
	int x, y;
public:
	Addition (int a, int b) { x = a; y = b; }
	int result() { return x + y; }
};

int main ()
{
	// There exist two main syntaxes for generic type-casting: functional and c-like
	double x = 10.3;
	int y;
	y = int (x);	// functional notation
	y = (int) x;	// c-like cast notation

	// The functionality of these generic forms of type-casting is enough
	// for most needs with fundamental data types.
	// However, these operators can be applied indescriminately on classes
	// and pointers to classes,
	// which can lead to code that -while being syntactically correct-
	// can cause runtime errors.

	// For example, the following code compiles without errors:
	Dummy d;
	Addition * padd;	// declares a pointer to Addition
	// but then it assigns to a reference to an object of another unrelated type
	// using explicit type-casting:
	padd = (Addition*) &d;

// Unrestricted explicit type-casting allows to convert any pointer into any other type, 
// independently of the types they point to.

// The subsequent call to member result will produce either a run-time error
// or some other unexpected results.
	cout << padd->result() << endl;

	return 0;
}

/*
In order to control these types of conversions between classes,
we have four specific casting operators:
	dynamic_cast <new_type> (expression)
	reinterpret_cast <new_type> (expression)
	static_cast <new_type> (expression)
	const_cast <new_type> (expression)
The traditional type-casting equivalents to these expressions would be:
	(new_type) expression
	new_type (expression)
*/
