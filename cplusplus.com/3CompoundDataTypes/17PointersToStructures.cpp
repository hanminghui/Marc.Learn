// Pointers to structures
// --------------------------------------------------------------------------------

// Like any other type, structures can be pointed to by its own type of pointers.

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct movies_t
{
	string title;
	int year;
};

int main ()
{
	string mystr;

	movies_t amovie;		// amovie is an object of structure type movies_t
	movies_t * pmovie;	// pmovie is a pointer to point to objects of movies_t
	pmovie = &amovie;	// the value of pmovie would be assigned the address of amovie

	cout << "Enter title: ";
	// the arrow operator ->
	// ------------------------------------------------------------
	// it's a dereference operator that is used exclusively with
	// pointers that have members.
	// This operator serves to access the member of an object directly from its address
	getline (cin, pmovie->title);
	// pmovie->title  is equivalent to  (*pmovie).title
	cout << "Enter year: ";
	getline (cin, mystr);
	(stringstream) mystr >> pmovie->year;

	cout << "\nYou have entered:\n";
	cout << pmovie->title;
	cout << " (" << pmovie->year << ")\n";

	return 0;
}

// NOTE:
// (1) pmovie->title  and  (*pmovie).title
// (1) access the member title of the data structure pointed by a pointer called pmovie.
// It is definitely something different than:
// (2) *pmovie.title, which is rather equivalent to *(pmovie.title)
// (2) would access the value pointed by a hypothetical pointer member called title
// of the structure object pmovie.
