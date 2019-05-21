// staic_cast
// --------------------------------------------------------------------------------

// static_cast can perform conversions between pointers to related classes,
// not only upcasts, but also downcasts.
// No checks are performed during runtime to guarantee that 
// the object being converted is in fact a full object of the destination type.
// Therefore, it is up to the programmer to ensure that the conversion is safe.
// On the other side, 
// it does not incur the overhead of the type-safety checks of dynamic_cast.

#include <iostream>
#include <exception>
using namespace std;

class Base 
{
	virtual void dummy () {}
};

class Derived : public Base
{
	int a;
public:
	void show()
	{ cout << a << endl; }
};

int main ()
{
	// This would be valid code:
	Base * pb = new Base;
	Derived * pd = static_cast<Derived*>(pb);
	// pd would point to an incomplete object of the class 
	// and could lead to runtime errors if dereferenced.
	pd->show();

// Therefore, static_cast is able to perform with pointers to classes 
// not only the conversions allowed implicitly,
// but also their opposite conversions.

	return 0;
}

/*
static_cast is also able to perform all conversions allowed implicitly (not only those 
with pointers to classes), and is also able to perform the opposite of these.
It can:
	# Convert from void* to any pointer.
	  In this case, it guarantees that if the void* value was obtained by converting from
	  that same pointer type, the resulting pointer value is the same.
	# Convert integers, floating-point values and enum types to enum types.
Additionally, static_cast can also perform the following:
	# Explicitly call a single-argument constructor or a conversion operator.
	# Convert to rvalue references.
	# Convert enum class values into integers or floating-point values.
	# Convert any type to void, evaluating and discarding the value.
*/
