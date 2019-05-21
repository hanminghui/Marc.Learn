// Scopes
// --------------------------------------------------------------------------------
// Named entities, such as variables, functions, and compound types
// need to be declared before being used in C++.
// The point in the program where this declaration happens influences its visibility.

// An entity declared outside any block has global scope
// global variables
// While an entity declared within a block, has block scope
// local variables

#include <iostream>
using namespace std;

int main()
{
	// global variable
	int x = 10;
	int y = 20;
	{
		// local variable
		int x;		// OK, inner scope
		x = 50;		// sets value to inner x
		y = 50;		// sets value to (outer) y
		cout << "inner block:" << endl;
		cout << "x: " << x << endl;
		cout << "y: " << y << endl;
	}
	cout << "outer block:" << endl;
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;

	return 0;
}
