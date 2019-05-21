// const_cast
// --------------------------------------------------------------------------------

// This type of casting manipulates the constness of the objects pointed by a pointer,
// either to be set or to be removed.

// For example, 
// in order to pass a const pointer to a function that expects a non-const argument:

#include <iostream>
using namespace std;

void print (char * str)
{
	cout << str << endl;
}

int main ()
{
	const char * c = "sample text";
// 	print (c);	// error: invalid conversion from ‘const char*’ to ‘char*’
	print (const_cast<char *>(c));

	return 0;
}

// The example above is guaranteed to work 
// because function print does not write to the pointed object.

// Note though,
// that removing the constness of a pointed object to actually write to it
// causes undefined behavior.
