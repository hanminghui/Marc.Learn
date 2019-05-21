// Exceptions
// ---------------------------------------------------------------------------------

// Exceptions provide a way to react to exceptional circumstances (like runtime errors)
// in programs by transferring control to special functions called handlers.

// exception inspection by try-block
// When an exceptional circumstances arises within that block,
// an exception is thrown that transfers the control to the exception handler.
// If no exception is thrown, the code continues normally and all handlers are ignored.

#include <iostream>
using namespace std;

int main ()
{
// basic try-catch
// ------------------------------------------------------------
	try
	{
		throw 20;	// an exception is thrown by using keyword throw
		// a throw expression accepts one parameter, 
		// which is passed as an argument to the exception handler.
	}
	catch (int e)	// exception handlers are declared with the keyword catch
// the type of the parameter of exception handler is very important,
// since the type of the argument passed by the throw expression is checked against it
// and only in case they match, the exception is caught by that handler.
	{
		cout << "An exception occurred. Exception Nr. " << e << endl;
	}

// chained handlers
// ------------------------------------------------------------
// Multiple handlers can be chained; each one with a different parameter type.
// Only the handler whose argument type matches the type of the exception specified in the thrown statement is executed.
	try
	{
		throw 3.14;
	}
	catch (int param) { cout << "int exception" << endl; }
	catch (char param) { cout << "char exception" << endl; }
	catch (...) { cout << "default exception" << endl; }
// if an ellipsis is used as the parameter of catch, 
// that handler will catch any exception no matter what the type of the exception thrown.
// This can be used as a default handler that catches all exceptions not caught by other handlers.

// nest try-catch blocks
// ------------------------------------------------------------
// It is also possible to nest try-catch blocks within more external try blocks.
	try
	{
		try
		{
			throw 1;
		}
		catch (int n)
		{
			// In these cases, we have the possibility that an internal catch block 
			// forwards the exception to its external level.
			throw;	// this is done with the expression throw, with no arguments.
		}
	}
	catch (...)
	{
		cout << "Exception occurred." << endl;
	}

	return 0;
}
