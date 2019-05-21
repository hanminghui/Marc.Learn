// Arrays as Parameters
// --------------------------------------------------------------------------------
// At some point, we may need to pass an array to a function as a parameter.

#include <iostream>
using namespace std;

void printarray (int arg[], int length)
{
	for(int n = 0; n < length; ++n)
		cout << arg[n] << " ";
	cout << endl;
}

// In a way, passing an array as argument always loses a dimension.
// arrays cannot be directly copied, and thus what is really passed is a pointer

template <typename T, size_t size>
void printarray2 (T (&arg) [size])
{
	for (const auto e : arg)
		cout << e << " ";
	cout << endl;
}

int main ()
{
	int firstarray [] {5, 10, 15};
	int secondarray [] {2, 4, 6, 8, 10};
	double thirdarray [] {3.14, 8.88, 9.99, 6.66};
	char fourtharray [] {'f', 'u', 'c', 'k'};
	printarray (firstarray, 3);
	printarray (secondarray, 5);
	printarray2 (firstarray);
	printarray2 (thirdarray);
	printarray2 (fourtharray);
	return 0;
	return 0;
}
