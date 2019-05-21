// Basic Input/Output
// streams, are a source/destination of characters
// and these characters are provided/accepted sequentially.
// stream		description
// cin			standard input stream
// cout			standard output stream
// cerr			standard error (output) stream
// clog			standard logging (output) stream

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	// Standard output ( cout )
	//--------------------------------------------------
	// cout is used together with the insertion operator <<
	cout << "Output sentence";
	cout << 120;
	int x {888};
	cout << x;
	// these two sentences have very different results:
	float Hello {0.9999};
	cout << "Hello";
	cout << Hello << endl;
	// Multiple insertion operations ( << ) may be chained in a single statement:
	cout << "This " << "is a " << "single C++ statement.\n";
	// Chaining insertions is especially useful to mix literals and variables in a single statement:
	int age {25};
	string zipcode {"010001"};
	cout << "I am " << age << " years old and my zipcode is " << zipcode << ".\n";
	// To insert a line break. \n
	cout << "First sentence.\n";
	cout << "Second sentence.\nThird sentence.\n";
	// the endl manipulator
	// it also has an additional behavior:
	// the stream's buffer (if any) is flushed
	cout << "Fourth sentence." << endl;
	cout << "Fifth sentence." << endl;

	// Standard input ( cin )
	//--------------------------------------------------
	// cin is used together with the extraction operator >>
	int i;
	cout << "\nPlease enter an integer value: ";
	cin >> i;
	cout << "The value you entered is " << i;
	cout << " and its double is " << i * 2 << ".\n";
	// cin can be chained
	cout << "Please input two interger value: ";
	int a, b;
	cin >> a >> b;
	// same with
	// cin >> a;
	// cin >> b;
	cout << "The two numbers you input is " << a << " and " << b << ".\n";
	// stringstreams can be used to have better control over user input.

	// cin and strings
	//--------------------------------------------------
	// cin extraction always considers spaces (whitespaces, tabs, new-line...)
	// as terminating the value being extracted, thus extracting a string means
	// to always a single word, not a phrase or an entire sentence.
	// getline
	cin.ignore();
	string name;
	cout << "Please enter you full name: ";
	getline (cin, name);
	cout << "Hello, " << name << "!" << endl;

	// stringstream <sstream>
	//--------------------------------------------------
	// The standard header <sstream> defines a type called stringstream that allows
	// to be treated as a stream
	string str;
	float price {0};
	int quantity {0};

	cout << "Enter price: ";
	getline (cin, str);
	stringstream(str) >> price;
	cout << "Enter quantity: ";
	getline (cin, str);
	stringstream(str) >> quantity;
	cout << "Total price: " << price * quantity << endl;

	return 0;
}
