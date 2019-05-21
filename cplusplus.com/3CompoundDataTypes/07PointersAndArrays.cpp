// Pointers and arrays
// --------------------------------------------------------------------------------
// arrays work very much like pointers to their first elements
// actually an array can always be implicitly converted to the pointer of the proper type

#include <iostream>
using namespace std;

int main ()
{
	int myarray [] {1, 3, 5, 7, 9};
	int * mypointer;
	mypointer = myarray;
	// myarray and mypointer would be equivalent and would have very similar propertise.
	// The main difference is that mypointer can be assigned a different address,
	// whereas myarray can never be assigned anything,
	// and will always represent the same block of 20 elements of type int.
	// 	myarray = mypointer;	// this assignment would not be valid
	cout << myarray << endl;
	cout << mypointer << endl;
	cout << endl;

	// an example that mixes arrays and pointers
	// pointers and arrays suport the same set of operations,
	// with the same meaning for both.
	// The main difference is that pointers can be assinged new addresses,
	// while arrays cannot
	int numbers[5];
	int * p;

	p = numbers;
	*p = 10;

	p++;
	*p = 20;

	p = &numbers[2];
	*p = 30;

	p = numbers + 3;
	*p = 40;

	p = numbers;
	*(p+4) = 50;

	for (int i = 0; i < 5; i++)
		cout << numbers[i] << ", ";
	cout << endl;
	for (int i = 0; i < 5; i++)
		cout << *(p+i) << ", ";
	cout << endl;
	cout << endl;

	// in fact, brackets [], are dereferencing operator known as offset operator
	// They dereference the variable they follow just as * does,
	// but they also add the number between brackets to the address being dereferenced.
	numbers[1] = 0;
	*(numbers + 2) = 0;
	p[3] = 0;
	*(p + 4) = 0;
	// These expressions are equivalent and valid, both pointer and array
	// NOTE: an array's name can be used just like a pointer to its first element.

	for (int i = 0; i < 5; i++)
		cout << numbers[i] << ", ";
	cout << endl;

	return 0;
}
