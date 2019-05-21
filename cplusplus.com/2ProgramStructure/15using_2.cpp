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
	// using can also be used as a directive to introduce an entire namespace:
	using namespace first;
	cout << "x " << x << endl;
	cout << "y " << y << endl;
	cout << "x " << second::x << endl;
	cout << "y " << second::y << endl;

	return 0;
}
