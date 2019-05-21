// Function with no type. The use of void
// What if the function does not need to return a value?
// In this case, the type to be used is void, which is a special type to represent the absence of value.

#include <iostream>
using namespace std;

void printmessage()
{
	cout << "I'm a function!" << endl;
}

int main ()
{
	printmessage();
	return 0;
}
