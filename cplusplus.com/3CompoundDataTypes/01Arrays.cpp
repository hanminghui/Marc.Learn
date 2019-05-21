// Arrays
// --------------------------------------------------------------------------------
// An array is a series of elements of the same type 
// placed in contiguous memory locations
// that can be individually referenced by adding an index to a unique identifier.

// In C++, the first element in an array is always numbered with a zero,
// no matter its length

// type is a valid type, name is a valid identifier,
// and the elements field, specifies the length of the array 
// in terms of the numbers of elements

// NOTE: elements must be a constant expression
// since arrays are blocks of static memory whose size must be determined at compile
// time, before the program runs.

#include <iostream>
using namespace std;

template <typename T, size_t size>
void print_array (const T (&array)[size])
{
	for (const auto& e : array)
		cout << e << " ";
	cout << endl;
}

int main ()
{
	// declare and initialize arrays
	// --------------------------------------------------
	// type name [elements];
	int foo [5] = {16, 2, 77, 40, 12071};
	print_array(foo);
	int bar [5] = {10, 20, 30};
	print_array(bar);
	int baz [5] = {};
	int foo1 [] = {16, 2, 77, 40, 12071};	// array foo1 would be 5 in long
	// uniform initialization, no longer need for the equal sign
	int foo2 [5] {16, 2, 77, 40, 12071};

	// accessing the values of an array
	// --------------------------------------------------
	// name [index]
	foo [2] = 75;
	print_array(foo);
	int x = foo[5];	// foo's last element is foo[4], this will exceed the array size
	// In C++, it is syntactically correct to exceed the valid range of an array.
	// This do not cause errors on compilation, but cause errors on runtime.
	// the reason for this being allowed will be seen
	// in a later chapter when pointers are introduced.
	cout << x << endl;

	// NOTE: the two uses that brackets [] have related to arrays
	// one is to specify the size of arrays when they are declared
	// second is to specify indices for concrete array elements then they are accessed

	foo [2] = 77;
	int result;
	for (int n = 0; n < 5; ++n)
	{
		result += foo[n];
	}
	cout << result << endl;
	return 0;
}
