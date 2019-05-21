// Invalid Pointers and null pointers
// --------------------------------------------------------------------------------

// In principle, pointers are meant to point to valid addresses.
// ------------------------------------------------------------

#include <iostream>
using namespace std;

int main ()
{
	// invalid pointers
	// ------------------------------------------------------------
	// But pointers can actually point to any address
	// typical example of this are:

	// uninitialized pointers
	// ------------------------------
	int * p;	// uninitialized pointer (local variable)

	// pointers to nonexistent elements of an array
	// ------------------------------
	int myarray [10];
	int * q = myarray + 20;	//element out of bounds

	// Neither p or q point to address known to contain a value,
	// but none of the above statements causes an error.

	// What can cause an error is to dereference such a pointer
	// i.e. actually accessing the value they point to

	// Accessing such a pointer causes undefined behavior,
	// ranging from an error during runtime to accessing some random value.

	// the null pointer value
	// ------------------------------------------------------------
	// But, sometimes, a pointer really needs to explicitly point to nowhere,
	// and not just an invalid address.

	// this value can be expressed in C++ in two ways:
	int * ptr1 = 0;				// with an integer value of zero
	int * ptr2 = nullptr;		// with the nullptr keyword
	// here both ptr1 and ptr2 are null pointers
	// meaning that they explicitly point to nowhere
	int * ptr3 = NULL;	// It's quite usual to see this in older code
	// NULL is defined in several headers of the standart library
	// and is defined as an alias of some null pointer constant value
	// (such as 0 or nullptr)

	// all null pointers compare equal to other null pointers

	// NOTE: Do not confuse null pointers with void pointers!
	// null means nowhere
	// void means notype

	return 0;
}
