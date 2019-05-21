// Character sequences
// --------------------------------------------------------------------------------

// string class

// plain arrays of elements of a character type
// the null character \0 indicate the end of character sequences

#include <iostream>
#include <string>
using namespace std;

int main ()
{
	// initialization of null-terminated character sequences
	// ------------------------------------------------------------

	// initialize just like any other array,
	// ----------------------------------------
	// with the characters that form the word plus a null character \0 and the end
	char myword1 [] = {'F', 'U', 'C', 'K', '\0'};
	// using string literals directly
	// ----------------------------------------
	// Sequences of characters enclosed in double-quotes " are literal constants.
	// And their type is, in fact, a null-terminated array of characters.
	// This means that string literals always have a null character \0 automatically
	// appended at the end.
	char myword2 [] = "FUCK";
	cout << myword1 << endl;
	cout << myword2 << endl;

	// assign value to an array of characters
	// ------------------------------------------------------------
	// once they have already declared, because string literals are regular arrays,
	// they have the same restrictions as these, and cannot be assigned values.
	/* the follows would not be valid:
	myword1 = "GOOD";
	myword1 [] = "GOOD";
	myword1 = {'G', 'O', 'O', 'D', '\0'};
	*/
	// this would be correct:
	myword1 [0] = 'G';
	myword1 [1] = 'O';
	myword1 [2] = 'O';
	myword1 [3] = 'D';
	myword1 [4] = '\0';
	cout << myword1 << endl;

	// Strings and null-terminated character sequences (NTCS)
	// ------------------------------------------------------------
	// in this example, both arrays of characters using null-terminated sequences
	// and strings are used.
	// They are quite interchangeable in their use together with cin and cout
	// but there is a notable difference in their declaration
	char question1[] = "What's your name? ";
	string question2 = "Where do you live? ";

	// answer1 has a size of 80 characters
	char answer1 [80];
	// strings are simply strings, no size is specified.
	string answer2;
	// This is due to the fact that strings have a dynamic size determined during runtime
	// while the size of arrays is determined on compilation, before the program runs.

	cout << question1;
	cin >> answer1;

	cout << question2;
	cin >> answer2;

	cout << "Hello, " << answer1;
	cout << " from " << answer2 << "!" << endl;

	// null-terminated character sequences and strings are easily transformed
	// from one to another
	// ------------------------------------------------------------
	// Null-terminated character sequences can be transformed into strings implicitly
	char myntcs[] = "some text";
	string mystring = myntcs;	// convert c-string to string
	cout << mystring << endl;	// printed as a library string
	// strings can be transformed into null-terminated character sequence by using
	// either of string's member functions c_str or data:
	cout << mystring.c_str() << endl;	// printed as a c-string

	return 0;
}
