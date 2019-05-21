// using
// --------------------------------------------------------------------------------
// The key word using introduces a name into the current delarative region,
// such as a block, thus avoiding the need to qualify the name.

#include <iostream>
using namespace std;

namespace first
{
	int x = 5;
	int y = 10;
}

namespace second
{
	double x = 3.14159;
	double y = 2.7183;
}

int main ()
{
	// in main, the variable x refers to first::x, whereas y refers to second::y
	using first::x;
	using second::y;
	cout << "x " << x << endl;
	cout << "y " << y << endl;
	// the variables first::y and second::x can still be accessed,
	// but require fully qualified names
	cout << "x " << second::x << endl;
	cout << "y " << first::y << endl;

	return 0;
}
