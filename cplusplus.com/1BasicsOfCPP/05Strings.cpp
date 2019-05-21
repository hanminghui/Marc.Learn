// string class is an example of compound type

// my first string
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string mystring;
	mystring = "This is a string.\n";

	// As with fundamental types, all initialization formats are valid with strings
	string string1 = "This is string one.\n";
	string string2 ("This is string two.\n");
	string string3 {"This is string three.\n"};
	cout << mystring;
	cout << string1 << string2 << string3;

	// Strings can also perform all the other basic operations that fundamental data types can,
	// like being declared without an initial value and change its value during execution

	string fuck;
	fuck = "This is the initial string content.";
	cout << fuck << '\n';
	fuck = "This is a different string content.";
	cout << fuck << endl;
	// inserting the endl manipulator ends the line (printing a newline character and flushing the stream).

	return 0;
}
