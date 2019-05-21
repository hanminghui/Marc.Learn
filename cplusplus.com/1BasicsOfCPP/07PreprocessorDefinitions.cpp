// Another mechanism to name constant values is the use of preprocessor definitions.
// They have the following form:
// #define identifier repacement
// After this directive, any occurrence of identifier in the code is interpreted as replacement
// this happens before the program is compiled
// thus causing a sort of blind replacement: the validity of the types or syntax involved is not checked in any way

#include <iostream>
using namespace std;

#define PI 3.14159
#define NEWLINE '\n'

int main()
{
	double r = 5.0;		// radius
	double circle;

	circle = 2 * PI * r;
	cout << circle;
	cout << NEWLINE;
}
