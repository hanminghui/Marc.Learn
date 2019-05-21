// Template specialization.cpp
// --------------------------------------------------------------------------------
// syntax:
// template <> class class_name <special_type> {...};

// It is possible to define a different implementation for a template 
// when a specific type is passed as template argument.
// This is called a template specialization.

#include <iostream>
using namespace std;

// class template:
template <class T>
class mycontainer	// a simple class can store one element of any type
{
	T element;
public:
	mycontainer (T arg) {element = arg;}	// constructor
	T increase () {return ++element;}		// one member function increase
};

// When mycontainer stores an element of type char,

// declare a class template specialization for type char:
template <>	// precede the class name with template<>, including an empty parameter list
class mycontainer <char>// <char> specialization parameter after the class template name
{	// Because there is no "inheritance" of members from the generic template
	// When we declare specialization for a template class, 
	// we must also define all its members:
	char element;
public:
	mycontainer (char arg) {element = arg;}
	char uppercase ()		// a different function member uppercase
	{
		if ((element >= 'a') && (element <= 'z'))
			element += 'A'-'a';
		return element;
	}
};

int main ()
{
	mycontainer<int> myint (7);
	mycontainer<double> mydouble(3.14);
	mycontainer<char> mychar ('h');
	cout << myint.increase() << endl;
	cout << mydouble.increase() << endl;
	cout << mychar.uppercase() << endl;

	return 0;
}

// NOTE: the differences between the generic class template and the specialization

// generic class template:
// ------------------------------
// template <class T> 
// class class_name 
// {...};

// template specialization:
// ------------------------------
// template <>
// class class_name <special_type>
// {...};
