// Class templates
// --------------------------------------------------------------------------------
// Just like we can create function templates, we can also create class templates,
// allowing classes to have members that use template parameters as types.

#include <iostream>
using namespace std;

template <typename T>
class mypair0
{
	T values [2];	// a class store two elements of any valid type
public:
	mypair0 (T first, T second)	// constructor with T defined inline, within the class
	{
		values[0] = first; values[1] = second;
	}
	void print ()
	{
		cout << values[0] << " ; " << values[1] << endl;
	}
};

template <class T>
class mypair
{
	T a, b;
public:
	mypair (T first, T second)	// function (constructor) defined inline
	{
		a = first; b = second;
	}
	T getmax ();
};

template <class T>	// function defined outside the definition of the class template
T mypair<T>::getmax()
{
	T retval;
	retval = a > b ? a : b;
	return retval;
}

// NOTE: in the definition of getmax() above,
// first T: is the template parameter.
// second T: refers to the type returned by the function.
// third T (the one between angle brackets): 
// specifies that this function's template parameter is also the class template parameter

int main ()
{
	mypair0 <int> mypair0_int (24, 88);		// object of class mypair0 to store 2 int
	mypair0 <double> mypair0_double (3.14, 8.17);	// 2 double
	mypair0_int.print();
	mypair0_double.print();

	cout << endl;

	mypair <int> mypair_obj (100, 75);
	cout << mypair_obj.getmax() << endl;

	return 0;
}
