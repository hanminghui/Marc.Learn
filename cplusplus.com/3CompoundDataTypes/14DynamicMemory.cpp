// Dynamic memory
// --------------------------------------------------------------------------------
// the dynamic memory requested by program is allocated by system from the memory heap

// There may be cases where the memory needs can only be determined during runtime.
// e.g. when the memory needed depends on user input.
// On these cases, programs need to dynamically allocate memory,
// for which the C++ language integrates the operators new and delete.

#include <iostream>
#include <new>	// for nothrow
using namespace std;

int main ()
{
	// Operators new and new[]
	// --------------------------------------------------------------------------------
	// Dynamic memory is allocated using operator new.
	// pointer = new type
	// pointer = new type [number_of_elements]

	int * foo, * bar;
	foo = new int;			// to allocate memory to contain one single element of int
	bar = new int [5];		// to allocate a block (an array) of elements of type int

	// There is a substantial difference between declaring a normal array
	// and allocating dynamic memory for a block of memory using new.
	// The most important difference is that
	// the size of a regular array needs to be a constant expression,
	// whereas the dynamic memory allocation performed by new
	// allows to assign memory during runtime using any variable value as size.

	// C++ provides two standard mechanisms to check if the allocation was successful:
	// ------------------------------------------------------------
	// One is by handling exceptions.
	// ------------------------------
	// new used this method by default
	foo = new int [5]; // if allocation fails, an exception is thrown (bad_alloc)
	// The other method is known as nothrow
	// ------------------------------
	// instead of throwing a bad_alloc exception or terminating the program,
	// the pointer returned by new is a null pointer,
	// and the program continues its execution normally.
	foo = new (nothrow) int [5];
	if (foo == nullptr)	// the allocation fail can be detected by checking if foo is 0
	{
		// error assigning memory. Take measures.
	}

	// the exception mechanism is generally prefered

	// Operators delete and delete[]
	// --------------------------------------------------------------------------------
	// delete pointer
	// delete [] pointer

	// the value passed as argument to delete shall be
	// either a pointer to a memory block previously allocated with new,
	// or a null pointer (in case of a null pointer, delete produces no effect)

	// EXAMPLE
	// rememb-o-matic

	int i, n;
	int * p;
	cout << "How many numbers would you like to type? ";
	cin >> i;
	p = new (nothrow) int [i];
	if (p == nullptr)
		cout << "Error: memory could not be allocated" << endl;
	else
	{
		for (n = 0; n < i; n++)
		{
			cout << "Enter number: ";
			cin >> p[n];
		}
		cout << "You have entered: ";
		for (n = 0; n < i; n++)
		{
			if (n == i - 1) cout << p[n] << endl;
			else cout << p[n] << ", ";
		}
		delete[] p;
	}

	// Dynamic memory in C
	// --------------------------------------------------------------------------------
	// new and delete are not available in C
	// instead, it used a library solution, with the functions
	// malloc, calloc, realloc adn free
	// defined in <cstdlib> (<stdlib.h> in C)
	// can also be used in C++

	// NOTE: don't mixed new/delete and dynamic memory in C
	// each one should be handled with its own set of functions or operators.

	return 0;
}
