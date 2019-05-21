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
// using/using namespace have validity only in the same block in which they are started 
// or in the entire source code file if they are used directly in the global scope.
	{
		using namespace first;
		cout << "x " << x <<endl;
	}
// Existing namespaces can be aliased with new names:
// namespace new_name = current = current_name;
	{
		namespace s = second;
		using namespace s;
		cout << "x " << x <<endl;
	}
	return 0;
}
