// Array of structures
// --------------------------------------------------------------------------------

// Because structures are types,
// they can also be used as the type of arrays to construct tables or database of them:

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct movies_t
{
	string title;
	int year;
} films [3];

void printmovie (movies_t movie);

int main ()
{
	string mystr;
	int n;

	for (n = 0; n < 3; n++)
	{
		cout << "Enter title: ";
		getline (cin, films[n].title);
		cout << "Enter year: ";
		getline (cin, mystr);
		stringstream(mystr) >> films[n].year;
	}

	cout << "\nYou have entered these movies:\n";
	for (n = 0; n < 3; n++)
	{
		printmovie (films[n]);
	}

	return 0;
}

void printmovie (movies_t movie)
{
	cout << movie.title << " (" << movie.year << ")\n";
}
