// Default values in parameters
// In C++, functions can also have optional parameters

#include <iostream>
using namespace std;

// this function include a default value for its last parameter
int divide (int a, int b = 2)
{
	int r;
	r = a / b;
	return (r);
}

int main ()
{
	// two calls to function divide
	cout << divide (12) << '\n';
	cout << divide (20, 4) << '\n';
	return 0;
}
