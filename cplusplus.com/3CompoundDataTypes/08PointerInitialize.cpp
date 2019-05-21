// Pointer initialization
// --------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main ()
{
	// Pointer initialization
	// ------------------------------------------------------------
	// Pointers can be initialized to point to specific locations when they are defined.
	{
		int myvar;
		int * myptr = &myvar;
	}
	// The resuting state variables after this code is same as after
	{
		int myvar;
		int * myptr;
		myptr = &myvar;
	}
	// When pointers are initialized, what initialized is the address they point to,
	// (i.e. myptr), never the value being pointed (i.e. *myptr).
	// Therefore, the code bellow would not make much sense, and is not valid code
	{/* WRONG
		int myvar;
		int * myptr;
		*myptr = &myvar;
	*/}
	// Pointers can be initialized either to the address of a variable
	// such as in the case above, or to the value of another pointer (or array)
	{
		int myvar, myarray[5];
		int * foo = &myvar;		// the address of a variable
		int * bar = foo;		// the value of another pointer
		int * ptr = myarray;	// array
	}
	return 0;
}
