// initialization of variables

// there are three ways to initialize variables
// they are equivalent and are reminiscent of the evolution of the language over the years

#include <iostream>

using namespace std;

int main()
{
	// 1. c-like initialization
	int a = 5;
	// 2. constructor initialization, introduced by the C++ language
	int b (3);
	// 3. uniform initialization, introduced by the revision of the C++ standard, in 2011
	int c {2};
	// initial value undetermined
	int result;

	a = a + b;
	result = a - c;
	cout << result << '\n';

	return 0;
}
