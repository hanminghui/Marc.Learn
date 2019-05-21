// Recursivity
// Recursivity is the property that functions have to be called by themselves.

// factorial calculator
#include <iostream>
using namespace std;

long factorial (long);

int main ()
{
	long x;
	cout << "Please enter an integer: ";
	cin >> x;
	cout << "The factorial of " << x << " is " << factorial(x) << endl;
	return 0;
}

long factorial (long x)
{
	if (x > 0)
		x *= factorial (x - 1);
	else
		x = 1;
	return x;
}
