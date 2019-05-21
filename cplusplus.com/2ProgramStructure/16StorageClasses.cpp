// Storage classes
// static storage & automatic storage
// --------------------------------------------------------------------------------
// static storage
// --------------------------------------------------
// The storage for variables with global or namespace scope is allocated
// for the entire duration of the program. This is known as static storage.
// automatic storage
// --------------------------------------------------
// the storage for local variables (those are delared within a block)
// The storage for local variables is only available during the block
// in which they are declared; after that, that storage may be used for a local variable
// of some other function, or used otherwise.

// Another substantial difference between them:
// --------------------------------------------------------------------------------
// Variables with static storage (such as global variables)
// that are not explicitly initialized are automatically initialized to zeroes.
// Variables with automatic storage (such as local variables)
// that are not explicitly initialized are left uninitialized,
// and thus have an undetermined value.

// static storage vs automatic storage
#include <iostream>
using namespace std;

int x;

int main ()
{
	int y;
	cout << "not explicitly initialized variables" << endl;
	cout << "variables with static storage: " << x << endl;
	cout << "variables with automatic storage: " << y << endl;
	return 0;
}
