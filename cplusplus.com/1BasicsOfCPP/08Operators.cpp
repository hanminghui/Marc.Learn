// Once introduced to variables and constants, 
// we can begin to operate with them by using operators.

#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
	// Assignment operator =
	//--------------------------------------------------
	// the assignment operator assigns a value to a variable
	// assignment operation always takes place from right to left

	int a, b;	// a:?   b:?
	a = 10;		// a:10  b:?
	b = 4;		// a:10  b:4
	a = b;		// a:4   b:4
	b = 7;		// a:4   b:7

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	int x, y, z;
	y = 2 + (x = 5);

	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	cout << "z: " << z << endl;

	x = y = z = 8;

	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	cout << "z: " << z << endl;

	// Arithmetic operators + - * / %
	//--------------------------------------------------
	// addition, subtraction, multiplication, division, modulo
	x = 11 % 3;
	cout << "x = 11 % 3, the result is x: " << x << endl;

	// Compound assignment += -= *= /= %= >>= <<= &= ^= |=
	//--------------------------------------------------
	// compound assignment operators modify the current value of a variable by performing an operation on it.
	// They are equivalent to assigning the result of an operation to the first oprand.
	x = y = 8;
	y += x;
	cout << "y: " << y << endl;
	x -= 3;
	cout << "x: " << x << endl;
	y /= x;
	cout << "y: " << y << endl;
	int price = 10;
	int units {9};
	price *= units + 1;
	cout << "price: " << price << endl;

	// Increment and decrement ++ --
	//--------------------------------------------------
	// They are equivalent to += 1 and to -= 1
	// it can be used both as a prefix and as a suffix
	cout << "x = 3" << endl;
	x = 3;
	y = ++x;
	cout << "y = ++x : " << y << endl;
	// x contains 4, y contains 4
	x = 3;
	y = x++;
	cout << "y = x++ : " << y << endl;
	// x contains 4, y contains 3

	// Relational and comparison operators == != > < >= <=
	//--------------------------------------------------
	// The result of such an operation is either true or false (i.e. a Boolean value)
	cout << "(7 == 5) : " << (7 == 5) << endl;
	cout << "(5 > 4) : " << (5 > 4) << endl;
	cout << "(3 != 2) : " << (3 != 2) << endl;
	cout << "(6 >= 6) : " << (6 >= 6) << endl;
	cout << "(5 < 5) : " << (5 < 5) << endl;
	a = 2;
	b = 3;
	int c {6};
	cout << "a = 2, b = 3, c = 6." << endl;
	cout << "(a == 5) : " << (a == 5) << endl;
	cout << "(a * b >= c) : " << (a * b >= c) << endl;
	cout << "(b + 4 > a * c) : " << (b + 4 > a * c) << endl;
	cout << "((b = 2) == a) : " << ((b = 2) == a) << endl;

	// Logical operators ! && ||
	//--------------------------------------------------
	// ! NOT
	cout << "!(5 == 5) : " << !(5 == 5) << endl;
	cout << "!(6 <= 4) : " << !(6 <= 4) << endl;
	cout << "!true : " << !true << endl;
	cout << "!false : " << !false << endl;
	// && AND , || OR
	cout << "((5==5) && (3>6)) : " << ((5==5) && (3>6)) << endl;
	cout << "((5==5) || (3>6)) : " << ((5==5) || (3>6)) << endl;
	// pay attention to short-circuit

	// Conditional ternary operator ?
	//--------------------------------------------------
	// condition ? result1 ? result2
	a = 2;
	b = 7;
	c = (a > b) ? a : b;	// evaluates to whichever is greater, a or b.
	cout << "a = 2, b = 7, c = (a > b) ? a : b" << endl;
	cout << "c : " << c << endl;
	
	// Comma operator ,
	//--------------------------------------------------
	// comma operator is used to seperate two or more expressions that are included
	// where only one expression is expected. When the set of expressions has to be
	// evaluated for a value, only the right-most expression is considered.
	a = (b = 3, b + 2);
	cout << "a = (b = 3, b + 2) : " << a << endl;

	// Bitwise operator & | ^ ~ << >>
	//--------------------------------------------------
	// Bitwise operators modify variables considering the bit patterns that represent the values they store
	// operator		asm equivalent		description
	// &			AND					bitwise AND
	// |			OR					bitwise inclusive OR
	// ^			XOR					bitwise exclusive OR
	// ~			NOT					unary complement(bit inversion)
	// <<			SHL					shift bits left
	// >>			SHR					shift bits right

	// Explicit type casting operator
	//--------------------------------------------------
	// Type casting operators allow to convert a value of a given type to another type.
	int p;
	float q = 3.14;
	// inherited from the C language
	p = (int) q;
	cout << "type of q : " << typeid(q).name() << endl;
	cout << "type of p : " << typeid(p).name() << endl;
	cout << "value of p : " << p << endl;

	// sizeof
	//--------------------------------------------------
	// accept one parameter which can be either a type or a variable
	// and returns the size in bytes of that type or object
	cout << "size of q : " << sizeof(q) << endl;
	cout << "size of p : " << sizeof(p) << endl;

	// Other operators
	//--------------------------------------------------
	// Later in these tutorials, we will see a few more operators, 
	// like the ones referring to pointers or the specifics for object-oriented programming.

	// Precedence of operators
	//--------------------------------------------------
	x = 5 + 7 % 2;
	cout << "x = 5 + 7 % 2 : " << x << endl;
	x = 5 + (7 % 2);
	cout << "x = 5 + (7 % 2) : " << x << endl;
	x = (5 + 7) % 2;
	cout << "x = (5 + 7) % 2 : " << x << endl;

	// Enclosing all sub-statements in parentheses improves code readability.

	return 0;
}
