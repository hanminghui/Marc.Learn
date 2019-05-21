// Standard exceptions
// --------------------------------------------------------------------------------

// The C++ Standard library provides a base specifically designed to declare objects 
// to be thrown as exceptions.
// It is called std::exception and is defined in the <exception> header.
// This class has a virtual member called function called what 
// that returns a null-terminated character sequence (of type char*)
// and that can be overwritten in derived classes 
// to contain some sort of description of the exception.

#include <iostream>
#include <exception>
#include <cmath>
using namespace std;

long long Giga = pow (2, 30);

class myexception: public exception
{
	virtual const char* what () const throw()
	{
		return "My exception happend";
	}
} myex;

int main ()
{
	try
	{
		throw myex;
	}
	// we placed a handler that catches exception objects by reference ( & )
	// therefore this catches also classes derived from exception, like our myex
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

// All exceptions thrown by components of the C++ Standard library throw exceptions
// derived from this exception class.
/*
	bad_alloc		thrown by new		on allocation failure
	bad_cast		thrown by dynamic_cast		when it fails in a dynamic cast
	bad_exception	thrown by certain dynamic exception specifiers
	bad_typeid		thrown by typeid
	bad_function_call thrown by empty function objects
	bad_weak_ptr	thrown by shared_ptr		when passed a bad weak_ptr
Also deriving from exception, header <exception> defines two generic exception types 
that can be inherited by custom exceptions to report errors:
	logic_error		error related to the internal logic of the program
	runtime_error	error detected during runtime
*/

	// a typical example where standard exceptions need to be checked for is on memory allocation:
	try
	{
		int * myarray = new int[Giga];
	}
	catch (exception& e)
	{
		cout << "Standard exception: " << e.what() << endl;
	}

	return 0;
}
