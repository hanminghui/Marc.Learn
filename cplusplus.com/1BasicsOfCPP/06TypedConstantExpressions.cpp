// some times, it is just convenient to give a name to a constant value
// and we can then use these names instead of the literals they were defined to:

#include <iostream>

using namespace std;

const double pi = 3.14159;
const char newline = '\n';

int main ()
{
	double r = 5.0;		// radius
	double circle;

	string s1 {"string with \\, \""};
	string s2 {R"(string with \ ")"};
	string s3 {R"fuck( \ ")fuck"};

	circle = 2 * pi * r;
	cout << circle;
	cout << newline;

	cout << s1 << newline;
	cout << s2 << newline;
	cout << s3 << newline;
}
