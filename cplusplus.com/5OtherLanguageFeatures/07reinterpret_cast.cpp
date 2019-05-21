// reinterpret_cast
// --------------------------------------------------------------------------------

/*
reinterpret_cast converts any pointer type to any other pointer type,
even of unrelated classes.
The operation result is a simple binary copy of the value from one pointer to the other.
All pointer conversions are allowed:
neither the content pointed nor the pointer type itself is checked.
*/

// It can also cast pointers to or from integer types.

class A
{
	int fuck;
};

class B
{
	double shit;
};

int main ()
{
/*
The conversions that can be performed by reinterpret_cast but not by static_cast
are low-level operations based on reinterpreting the binary representations of the types,
which on most cases results in code which is system-specific, and thus non-portable.
For example:
*/
	A * a = new A;

// 	B * b = a;	//error: cannot convert ‘A*’ to ‘B*’ in initialization

// 	B * b = static_cast<B*>(a);
	// error: invalid static_cast from type ‘A*’ to type ‘B*’

	B * b = reinterpret_cast<B*>(a);

// This code compiles, although it does not make much sense, 
// since now b points to an object of a totally unrelated and likely incompatible class.
// Dereferencing b is unsafe.

	return 0;
}
