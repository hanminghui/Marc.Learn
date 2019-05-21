// dynamic_cast
// --------------------------------------------------------------------------------

// dynamic_cast can only be used with pointers and references to classes (or with void*).
// Its purpose is to ensure that the result of the type conversion 
// points to a valid complete object of the destination pointer type.

// This natually includes pointer upcast 
// (converting from pointer-to-derived to pointer-to-base)
// in the same way as allowed as an implicit conversion.

// But dynamic_cast can also downcast polymorphic classes (those with virtual members)
// if -and only if- the pointed object is a valid complete object of the target type.

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
};

int main ()
{
	try
	{
		// Even though both are pointers of type Base*
		// pba actually points to an object of type Derived,
		Base * pba = new Derived;
		// while pbb points to an object of type Base.
		Base * pbb = new Base;
		Derived * pd;

// two dynamic_cast from pointer objects of type Base* (pba and pbb)
// to a pointer object of type Derived*,
// but only the first one is successful.

// pba points to a full object of class Derived
		pd = dynamic_cast <Derived*> (pba);
		if (pd == 0)
			cout << "Null pointer on first type-cast." << endl;
// pbb points to an object of class base, which is an incomplete object of class Derived
		pd = dynamic_cast <Derived*> (pbb);
// When dynamic_cast cannot cast a pointer 
// because it is not a complete object of the required class 
// it returns a null pointer to indicate the failure.
		if (pd == 0)
			cout << "Null pointer on second type-cast." << endl;
	}catch (exception& e) { cout << "Exception: " << e.what(); }
// If dynamic_cast is used to convert to a reference type 
// and the conversion is not possible,
// an exception of type bad_cast is thrown instead.

	return 0;
}

/*
dynamic_cast can also perform the other implicit casts allowed on pointers:
casting null pointers between pointers types (even between unrelated classes),
and casting any pointer of any type to a void* pointer.
*/
