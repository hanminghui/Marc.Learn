// void pointers
// --------------------------------------------------------------------------------
// The void type of pointer is a special type of pointer.
// In C++, void represents the absence of type.
// Therefore, void pointers point to a value that has no type,
// and thus also an undetermined length and undetermined dereferencing properties.

// This gives void pointer a great flexibility, by being able to point to any data type,
// from an integer value or a float to a string of characters.

// In exchange, they have a great limitation:
// the data pointed to by them cannot be directly dereferenced.
// for that reason,
// any address in a void pointer needs to be transformed into some other pointer type
// that points to a concrete data type before being dereferenced.

// increaser
#include <iostream>
using namespace std;

// One of its possible uses is to pass generic parameters to a function.
void increase (void * data, int psize)
{
	if (psize == sizeof(char))
	{
		char * pchar;
		pchar = (char*) data;	// void * transformed to char *
		++(*pchar);
	}
	else if (psize == sizeof(int))
	{
		int * pint;
		pint = (int*) data;		// void * transformed to int *
		++(*pint);
	}
}

int main ()
{
	char a = 'x';
	int b = 1602;
	increase (&a, sizeof(a));
	increase (&b, sizeof(b));

	cout << a << ", " << b << endl;

	return 0;
}
