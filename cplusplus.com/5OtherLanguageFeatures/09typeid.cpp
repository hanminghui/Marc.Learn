// typeid
// --------------------------------------------------------------------------------

// typeid allows to check the type of an expression:
// typeid (expression)

// This operator returns a reference to a constant object of type type_info
// that is defined in the standard header <typeinfo>.

// A value returned by typeid can be compared with another value returned by typedid
// using operators == and != or can serve to obtain a null-terminated character sequence 
// representing the data type or class name by using its name() member.

#include <iostream>
#include <typeinfo>
#include <exception>
using namespace std;

class Base { virtual void f() {} };
class Derived : public Base {};

int main ()
{
	int * a, b;
	a = 0; b = 0;
	if ( typeid(a) != typeid(b))
	{
		cout << "a and b are of different types:" << endl;
		cout << "a is: " << typeid(a).name() << endl;
		cout << "b is: " << typeid(b).name() << endl;
	}

	cout << "typeid, polymorphic class" << endl;

	try
	{
		Base* x = new Base;
		Base* y = new Derived;
		cout << "x is: " << typeid(x).name() << endl;
		cout << "y is: " << typeid(y).name() << endl;
		cout << "*x is: " << typeid(*x).name() << endl;
		cout << "*y is: " << typeid(*y).name() << endl;
	}
	catch (exception& e)
	{ cout << "Exception: " << e.what() << endl; }
// Exception thrown on typreid of null pointer
// Type of the exception thrown by typeid
// when applied on a pointer to a polymorphic type which has a null pointer value.
	try
	{
		Base * z = 0;
		cout << "*z is: " << typeid(*z).name() << endl;
	}
	catch (exception& e)
// Its member what returns a null-terminated character sequence identifying the exception
	{ cout << "Exception: " << e.what() << endl; }


	return 0;
}
