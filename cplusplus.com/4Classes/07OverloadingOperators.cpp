// Overloading operators
// --------------------------------------------------------------------------------
// C++ allows most operators to be overloaded so that their behavior can be
// defined for just about any type, including classes.
/*
list of all the operators that can be overloaded:
+	-	*	/	=	<	>	+=	-=	*=	/=	<<	>>
<<=	>>=	==	!=	<=	>=	++	--	%	&	^	!	|
~	&=	^=	|=	&&	||	%=	[]	()	,	->*	->
new		delete		new[]		delete[]
*/

// Operators are overloaded by means of operator functions
// type operator sign (parameters) { /*...body...*/ }

// To all binary operators, 
// parameter is naturally the operand to the right hand side of the operator.
// like the example bellow

// EXAMPLE
#include <iostream>
using namespace std;

// cartesian vectors
class CVector
{
public:
	int x, y;
	CVector () {};
	CVector (int a, int b) : x {a}, y {b} {}	// CVector is function name (constructor)
	CVector operator + (const CVector&);		// CVector is type
};

// Member function
// ------------------------------------------------------------
// function operator+ of class CVector overloads the addition operator + for that type
CVector CVector::operator + (const CVector& param)
{
	CVector temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
	return temp;
}

// Non-Member function, some operators may be overloaded in two forms
// ------------------------------------------------------------
CVector operator* (const int i, const CVector& param)
{
	CVector temp;
	temp.x = i * param.x;
	temp.y = i * param.y;
	return temp;
}

CVector operator* (const CVector& param, const int i)
{
	CVector temp;
	temp.x = i * param.x;
	temp.y = i * param.y;
	return temp;
}

int main ()
{
	CVector foo (3, 1);
	CVector bar (1, 2);
	CVector baz (4, 6);
	CVector result;
	// function operator+ is called implicitly using the operator:
	result = foo + bar;
	cout << result.x << ',' << result.y << endl;
	// or explicitly using its functional name:
	result = bar.operator+ (baz);
	cout << result.x << ',' << result.y << endl;

	int i = 2, j = 3;
	result = i * foo;
	cout << result.x << ',' << result.y << endl;
	result = foo * j;
	cout << result.x << ',' << result.y << endl;
	return 0;
}

// NOTE: It's recommended that overload bears a relation to the
// mathematical or usual meaning of the operator.
