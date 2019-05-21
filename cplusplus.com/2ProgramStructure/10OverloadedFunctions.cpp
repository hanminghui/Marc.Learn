// Overloaded functions
// In C++, two different functions can have the same name if their parameters are different;
// either because they have a different number of parameters,
// or because any of their parameters are of a different type.

#include <iostream>
using namespace std;

// there are two functions called operate

// one has two parameters of type int
int operate (int a, int b)
{
	return (a * b);
}

// while the other has them of type double
double operate (double a, double b)
{
	return (a / b);
}

// In this example, both functions have quite different behavious.
// This is generally not a good idea.
// Two functions with the same name are generally expected to have at least a similar behavior,
// but that is entirely possible for them not to.

int main ()
{
	int x = 5, y = 2;
	double n = 5.0, m = 2.0;

	// The compiler knows which one to call in each case by examining the types passed as arguments when the function is called.

	// it is called with two int arguments
	cout << operate (x, y) << endl;
	// it is called with two double arguments
	cout << operate (n, m) << endl;
	return 0;
}

// Note that a function cannot be overloaded only by its return type.
// At least one of its parameters must have a different type.
