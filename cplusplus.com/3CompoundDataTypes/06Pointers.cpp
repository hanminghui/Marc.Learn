// Pointers
// --------------------------------------------------------------------------------
// The variable that stores the address of another variable is what in C++ is called a
// pointer.
// Pointers are a very powerful feature of the language that has many uses in lower
// level programming.

#include <iostream>
using namespace std;

int main ()
{
	// Address-of operator & (ampersand sign) (the address of)
	// --------------------------------------------------
	// the address of a variable can be obtained by preceding the name of a variable
	// with an ampersand sign &, known as address-of operator
	int myvar = 25;
	cout << "The address of myvar is: " << &myvar << endl;
	cout << "The value of myvar is: " << myvar << endl;
	myvar = 10;
	cout << "After assign 10 to myvar:" << endl;
	cout << "The address of myvar is: " << &myvar << endl;
	cout << "The value of myvar is: " << myvar << endl;
	cout << endl;

	// Dereference operator * (asterisk sign) (the value pointed to by)
	// --------------------------------------------------
	// pointers can be used to access the variable they point to directly.
	// This is done by preceding the pointer name with the dereference operator *
	// The operator itself can be read as "value pointed to by"

	// Declaring pointers
	// --------------------------------------------------
	// a pointer has different properties when it points to a char than
	// when it points to an int or a float.
	// Once dereferenced, the type needs to be known.
	// And for that, the declaration of a pointer needs to include the type
	// the pointer is going to point to.
	// type * name;
	// where type is the data type pointed to by the poiner.
	// This type is not the type of the pointer itself, 
	// but the type of the data the pointer points to.
	int * number;
	char * character;
	double * decimals;
	// all the three pointers occupy the same amount space in memory
	// the size in memory of a pointer depends on the platform where the program runs

	// NOTE: the asterisk * used when declaring a pointer only means it is a pointer
	// it is part of its type compound specifier
	// and should not be confused with the dereference operator
	// They are simply two different things represented with the same sign.

	// my first pointer
	// --------------------------------------------------
	int firstvalue, secondvalue;
	int * mypointer;
	// the two value will not be directly assigned
	// but end up with a value set indirectly through the use of mypointer
	mypointer = &firstvalue;
	*mypointer = 10;
	// a pointer may point to different variables during its lifetime in a program
	mypointer = &secondvalue;
	*mypointer = 20;
	cout << "first value is " << firstvalue << endl;
	cout << "second value is " << secondvalue << endl;
	cout << endl;

	// more pointers
	int value1 = 5, value2 = 15;
	// there is an asterisk * for each pointer
	int * p1, * p2;

	p1 = &value1;	// p1 = address of value1
	p2 = &value2;	// p2 = address of value2
	*p1 = 10;		// value pointed to by p1 = 10
	*p2 = *p1;		// value pointed to by p2 = value pointed to by p1
	p1 = p2;		// p1 = p2 (value of pointer is copied, p1 points to value2)
	*p1 = 20;		// value pointed to by p1 = 20;

	cout << "value1 is " << value1 << endl;
	cout << "value2 is " << value2 << endl;

	return 0;
}
