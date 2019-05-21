// Library arrays
// --------------------------------------------------------------------------------
// C++ provides an alternative array type as a standard container.
// It is a type template (a class template, in fact) defined in header <array>

#include <iostream>
#include <array>	// for the library array
using namespace std;

int main ()
{
	// language built-in array
	// --------------------------------------------------
	// this kind of array are directly implemented as a language feature
	// they probably suffer from an excess of optimization
	// by restricting its copy and easily decay into pointers
	int defaultArray [] {1, 3, 5, 7, 9};

	for (int i = 0; i < 5; i++)
		++defaultArray[i];

	for (int elem : defaultArray)
		cout << elem << " ";
	cout << endl;

	// container library array
	// --------------------------------------------------
	// they operate in a similar way to built-in arrays
	// except that they allow being copied
	// (an actually expensive opration that copies the entire block of memory,
	//	and thus to use with care)
	// and decay into pointers only when explicitly told to do so 
	// (by means of its member data)
	array <int,5> libraryArray {1, 3, 5, 7, 9};

	for (int i = 0; i < libraryArray.size(); i++)
		++libraryArray[i];

	for (int elem : libraryArray)
		cout << elem << " ";
	cout << endl;

	// As you can see, both use the same syntax to access its elements: identifier[i]
	// Other than that, the main difference lay on the declaration
	// Notice:
	// the inclusion of an additional header for the library array
	// also how it is easy to access the size of the library array

	return 0;
}
