// Destructor
// --------------------------------------------------------------------------------
/*
Destructor fulfill the opposite functionality of constructors:
They are responsible for the necessary cleanup needed by a class when its lifetime ends.
The classes we have defined in previous chapters did not allocate any resource and thus
did not really require any clean up.
*/

#include <iostream>
#include <string>
using namespace std;

class Example4
{
	string * ptr;
public:
	// constructors:
	Example4() : ptr(new string) {}
	Example4 (const string& str) : ptr(new string(str)) {}
	// destructor:
	~Example4 () {delete ptr;}
	// access content:
	const string& content() const {return *ptr;}
};

int main ()
{
	Example4 foo;
	Example4 bar ("FUCK");

	cout << "bar's content: " << bar.content() << endl;

	return 0;
}
