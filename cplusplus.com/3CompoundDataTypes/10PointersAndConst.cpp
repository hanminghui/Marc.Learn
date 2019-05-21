// Pointers and const
// --------------------------------------------------------------------------------

#include <iostream>
using namespace std;

void increment_all (int * start, int * stop)
{
	int * current = start;
	while (current != stop)
	{
		++(*current);	// increment value pointed
		++current;		// increment pointer
	}
}

// Pointers point to constant elements
// ------------------------------------------------------------
// print_all uses pointers that point to constant elements.
// These pointers point to constant content they cannot modify,
// but they are not constant themsleves
// i.e. the pointers can still be incremented or assigned different addresses, 
// although they cannot modify the content they point to.
void print_all (const int * start, const int * stop)
{
	const int * current = start;
	while (current != stop)
	{
		cout << *current << endl;
		++current;		// increment pointer
	}
}

int main ()
{
	int numbers[] = {10, 20, 30, 40, 50};
	increment_all (numbers, numbers + 5);
	print_all (numbers, numbers + 5);

	// Pointers can also be themselves const.
	// ------------------------------------------------------------
	int x;
	      int *       p1 = &x;	// non-const pointer to non-const int
	const int *       p2 = &x;	// non-const pointer to const int
	      int * const p3 = &x;	// const pointer to non-const int
	const int * const p4 = &x;  // const pointer to const int

	// the const qualifier can either precede or follow the pointed type:
	const int * p2a = &x;	//      non-const pointer to const int
	int const * p2b = &x;	// also non-const pointer to const int

	return 0;
}
