// Type deduction : auto and decltype
/* auto specifier
   specifier that the type of the variable */
/* decltype specifier
   inspects the declared type of an entity or the type and value category of an expression */

// more on cppreference.com

#include <iostream>

using namespace std;

int main()
{
	int foo = 10;
	auto bar = foo;		// the same as: int bar = foo;

	int fuck = 2;
	decltype(fuck) you;	// the same as: int you;
	you = 3;

	cout << bar % you << '\n';

	return 0;
}
/* auto and decltype are powerful features recently added to the language.
But the type deduction features they introduce are meant to be used either
when the type cannot be obtained by other means or when using it improves
code readability. The two examples above were likely neither of these use
cases. In fact they probably decreased readability, since, when reading the 
code, one has to search for the type of foo to actually know the type of bar.
*/
