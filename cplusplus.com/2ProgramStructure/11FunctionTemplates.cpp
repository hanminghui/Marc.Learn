// Function templates

#include <iostream>
using namespace std;

// Here, sum is overloaded with different parameter types, but with the exact same body.

int sum (int a, int b)
{
	return a + b;
}

double sum (double a, double b)
{
	return a + b;
}

// C++ has the ability to define functions with generic types, known as function templates.
// template parameters can be generic template types by specifying either the class or typename keywork followed by an identifier
// this identifier can then be used in the function declaration as if it was a regular type.

// template <template-parameters> function-declaration
template <class T>
T sum_template (T a, T b)
{
	// T is used to declare a local variable
	T result;
	result = a + b;
	return result;
}

// Templates are a powerful and versatile feature.
// They can have multiple template parameters,
// and the function can still use regular non-templated types.
template <class T, typename U>	// here uses class and typename
bool are_equal (T a, U b)
{
	return (a == b);
}

int main ()
{
	cout << sum (10, 20) << endl;
	cout << sum (1.0, 1.5) << endl;

	int i = 5, j = 6, k;
	double f = 2.0, g = 0.5, h;
	float n = 3.0, m = 5.0;

	// Instantiating a template
	// name <template-arguments> (function-arguments);
	k = sum_template <int> (i, j);
	h = sum_template <double> (f, g);
	cout << k << endl;
	cout << h << endl;
	// the compiler is even able to deduce the data type automatically 
	// without having to explicitly specify it within angle brackets
	// the type shall be unambiguous
	cout << sum_template (n, m) << endl;

	if (are_equal (10, 10.0))
		cout << "x and y are equal" << endl;
	else
		cout << "x and y are not equal" << endl;

	return 0;
}
