// Declaring Functions Prototypes
// Functions cannot be called before they are declared, same as the identifiers.
// The prototype of a function can be declared without actually defining the function completely,
// giving just enough details to allow the types involved in a function call to be known.
// The parameter list does not need to include the parameter names, but only their types.

#include <iostream>
using namespace std;

// declaration of function prototype
void odd (int x);
void even (int x);

int main ()
{
	int i;
	do
	{
		cout << "Please, enter number (0 to exit): ";
		cin >> i;
		odd (i);
	}while (i != 0);
	return 0;
}

void odd (int x)
{
	if ((x % 2) != 0)
		cout << "It is odd.\n";
	else
		even (x);
}

void even (int x)
{
	if ((x % 2) == 0)
		cout << "It is even.\n";
	else odd(x);
}
