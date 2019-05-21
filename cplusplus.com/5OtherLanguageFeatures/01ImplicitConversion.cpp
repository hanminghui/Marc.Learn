// Implivit conversion
// --------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main ()
{
	// Implicit conversions are automatically performed 
	// when a value is copied to a compatible type, for example:
	short a = 2000;
	int b;
	b = a;	// the value of a is promoted from short to int without any explicit operator
	// This is known as a standard conversion.

	// Standard conversion affect fundamental data types,
	// and allow the conversion between numerical types, 
	// to or from bool, and some pointer conversions.

	// promotion: converting from smaller type, 
	// guarenteed to produce the exact same value in the destination type.

	// Other conversions between arithmetic types may not always be the same:
	{// 2's complement bitwise representation
	int x = -1;
	cout << "int: " << x << endl;
	unsigned int y = x;
	cout << "unsigned int: " << y << endl;;
	cout << endl;
	}
	{
	char x = -1;
	cout << "char: " << (int)x << endl;
	unsigned char y = x;
	cout << "unsigned char: " << (int)y << endl;;
	cout << endl;
	}
	{
	float x = 4.1;
	cout << "float: " << x << endl;
	int y = x;
	cout << "int: " << y << endl;;
	cout << endl;
	}
	{
	double x = 4.9;
	cout << "double: " << x << endl;
	int y = x;
	cout << "int: " << y << endl;;
	cout << endl;
	}

	// For non-fundamental types,
	// arrays and functions implicitly convert to pointers,
	// and pointers in general allow the following conversions:
	// # Null pointers can be converted to pointers of any type.
	// # Pointers to any type can be converted to void pointers.
	// # Pointer upcast: 
	// pointers to a derived class can be conerted to 
	// a pointer of an accessible and unambiguous base class,
	// without modifying its const or valatile qualification.

	return 0;
}
