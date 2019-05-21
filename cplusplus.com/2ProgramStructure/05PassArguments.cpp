// Arguments passed by value and by reference

#include <iostream>
using namespace std;

int addition (int a, int b)
{
	return a + b;
}

// To gain access to its arguments, the function declares its parameters as references.
// In C++, references are indicated with an ampersand & following the parameter type
void duplicate (int& x, int& y, int& z)
{
	x *= 2;
	y *= 2;
	z *= 2;
}

int main ()
{
	int x = 5, y = 3, z;
	// passing parameters by value
	//--------------------------------------------------
	z = addition (x, y);
	cout << "The value of z is: " << z << endl;

	// In certain cases, it may be useful to access an external variable from within a function.

	// passing parameters by reference, instead of by value
	//--------------------------------------------------
	int a = 1, b = 2, c = 3;
	cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
	duplicate (a, b, c);
	cout << "after duplicate();" << endl;
	cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

	return 0;
}
