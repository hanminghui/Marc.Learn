// Pointer arithmetics
// --------------------------------------------------------------------------------
// To conduct arithmetical operations on pointers is a little difference than
// to conduct them on regular integer types.

// Only addition and subtraction operations are allowed.
// And both addition and subtraction have a slightly different behavior with pointers, 
// according to the size of the data type to which they point.

#include <iostream>
using namespace std;

int main ()
{
	// basic arithmetics: addition and subtraction
	// ------------------------------------------------------------
	char mychar = 'A';
	short myshort = 8;
	int myint = 5;
	long mylong = 9;

	char * mychar_ptr = &mychar;
	short * myshort_ptr = &myshort;
	int * myint_ptr = &myint;
	long * mylong_ptr = &mylong;

	cout << "mychar_ptr : " << (void*)mychar_ptr << endl;
	cout << "myshort_ptr: " << myshort_ptr << endl;
	cout << "myint_ptr  : " << myint_ptr << endl;
	cout << "mylong_ptr : " << mylong_ptr << endl;
	cout << endl;

	++mychar_ptr;
	++myshort_ptr;
	++myint_ptr;
	++mylong_ptr;

	cout << "mychar_ptr : " << (void*)mychar_ptr << endl;
	cout << "myshort_ptr: " << myshort_ptr << endl;
	cout << "myint_ptr  : " << myint_ptr << endl;
	cout << "mylong_ptr : " << mylong_ptr << endl;
	cout << endl;

	// combinations of the dereference operator with 
	// both the prefix and suffix version of the increment operator
	{
		int a = 10, b = 20;
		int * p = &a;
		cout << "a:" << a << " ; b:" << b << endl;
		cout << "&a:" << &a << " ; &b:" << &b << " ; pointer p:" << p << endl;
		// *p++, same as *(p++)
		// ------------------------------
		// increment pointer, and dereference unincremented address
		cout << "*p++      : " << *p++ << endl;
		cout << "pointer p:" << p << " ; *p:" << *p << endl;
		cout << endl;
	}
	{
		int a = 10, b = 20;
		int * p = &a;
		cout << "a:" << a << " ; b:" << b << endl;
		cout << "&a:" << &a << " ; &b:" << &b << " ; pointer p:" << p << endl;
		// *++p, same as *(++p)
		// ------------------------------
		// increment pointer, and dereference incremented address
		cout << "*++p      : " << *++p << endl;
		cout << "pointer p:" << p << " ; *p:" << *p << endl;
		cout << endl;
	}
	{
		int a = 10, b = 20;
		int * p = &a;
		cout << "a:" << a << " ; b:" << b << endl;
		cout << "&a:" << &a << " ; &b:" << &b << " ; pointer p:" << p << endl;
		// ++*p, same as ++(*p)
		// ------------------------------
		// dereference pointer, and increment the value it points to
		cout << "++*p      : " << ++*p << endl;
		cout << "pointer p:" << p << " ; *p:" << *p << endl;
		cout << endl;
	}
	{
		int a = 10, b = 20;
		int * p = &a;
		cout << "a:" << a << " ; b:" << b << endl;
		cout << "&a:" << &a << " ; &b:" << &b << " ; pointer p:" << p << endl;
		// (*p)++
		// ------------------------------
		// dereference pointer, and post-increment the value it points to
		cout << "(*p)++    : " << (*p)++ << endl;
		cout << "pointer p:" << p << " ; *p:" << *p << endl;
		cout << endl;
	}

	// Like always, parentheses reduce confusion by adding legibility to expressions.

	return 0; 
}
