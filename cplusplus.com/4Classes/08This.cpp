// The keyword this
// --------------------------------------------------------------------------------

// The keyword this represents a pointer to the object 
// whose member function is being executed.
// It is used within a class's member function to refer to the object itself.

#include <iostream>
using namespace std;

class Dummy
{
public:
	bool isitme (Dummy& param);
};

// One of this's uses can be to check if a parameter passed to a member function
// is the object itself.
// ------------------------------------------------------------
bool Dummy::isitme (Dummy& param)
{
	if (&param == this) return true;
	else return false;
}

// It is also frequently used in operator= member functions 
// that return objects by reference.
// ------------------------------------------------------------
class CVector
{
public:
	int x, y;
	CVector () {};
	CVector (int a, int b) : x {a}, y {b} {}
	CVector& operator= (const CVector&);
	CVector& operator++ ();			// prefix
	CVector& operator-- (int i);	// postfix
};

// in fact, this is very similar to the code
// that the compiler generates implicitly for this class for operator=
CVector& CVector::operator= (const CVector& param)
{
	x = param.x;
	y = param.y;
	return *this;
}

CVector& CVector::operator++ ()
{
	x++;
	y++;
	return *this;
}
CVector& CVector::operator-- (int i)
{
	x--;
	y--;
	return *this;
}

int main ()
{
	Dummy a;
	Dummy * b = &a;
	if (b->isitme(a))
		cout << "yes, &a is b\n";

	CVector foo (3, 1);
	CVector bar;
	bar = foo;
	cout << bar.x << ',' << bar.y << endl;
	++foo;
	cout << foo.x << ',' << foo.y << endl;
	foo--;
	cout << foo.x << ',' << foo.y << endl;
	return 0;
}
