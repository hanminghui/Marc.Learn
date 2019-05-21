// Efficiency considerations and const references
#include <iostream>
#include <string>
using namespace std;

// Calling a function with parameters taken by value causes copies of the value to be made.
// This is a relatively inexpensive operation for fundamental types, 
// but for large compound type, it may result on certain overhead.
string concatenate1 (string a, string b)
{
	return a + " " + b;
}

// Arguments by reference do not require a copy.
// This version is more efficient.
//--------------------------------------------------
string concatenate2 (string& a, string& b)
{
	return a + " " + b;
}

// Functions with reference parameters are generally perceived as functions that modify the arguments passed.
// guarantee its reference parameters are not going to be modified, 
// This can be done by qualifying the parameters as constant:
//--------------------------------------------------
string concatenate3 (const string& a, const string& b)
{
	return a + " " + b;
}

// Preceding a function declaration with the inline specifier
// informs the compiler that inline expansion is preferred over the usual function call mechanism for a specific function.
//--------------------------------------------------
inline string concatenate4 (const string& a, const string& b)
{
	return a + " " + b;
}

// By qualifying them as const, the function is forbidden to modify the values,
// but can actually access their values as references, without having to make actual copies of the strings.

// const reference provide functionality similar to passing arguments by value, 
// but with an increased efficiency for parameters of large types.

// They are extremely populer in C++ for arguments of compound types.
// Not though, that for most fundamental types, there is no noticeable difference in efficiency,
// and in some cases, const references may even be less efficient.

int main ()
{
	string a, b;
	cout << "Please Enter two sentences below: " << endl;
	getline (cin, a);
	getline (cin, b);
	cout << "The concatenated sentence is: " << "\n" << concatenate1 (a, b) << endl;
	cout << "The concatenated sentence is: " << "\n" << concatenate2 (a, b) << endl;
	cout << "The concatenated sentence is: " << "\n" << concatenate3 (a, b) << endl;
	cout << "The concatenated sentence is: " << "\n" << concatenate4 (a, b) << endl;

	return 0;
}
