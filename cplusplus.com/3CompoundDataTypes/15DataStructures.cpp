// Example about structures
// --------------------------------------------------------------------------------

// A data structure is a group of data elements grouped together under one name.
// These data elements, known as members, can have different types and different lengths.

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// declaration of struct and their object
// ------------------------------------------------------------
struct movies_t	// type_name, is a name for the structure type
{
	// members
	string title;
	int year;
} mine;	// an object name, identifier for objects that have the type of this structure

movies_t yours;		// another object, movies_t is used to declare new objects

// movies_t is a new type, mine and yours is two objects (variables) of this type

// struct requires either a type_name or at least one name in object_name,
// but necessarily both
// ------------------------------------------------------------
// in this case, where objects are specified,
// the type_name becomes optional:
// ------------------------------
struct	// no type_name
{
	int weight;
	double price;
} apple;
// ------------------------------
struct fruit
{
	int weight;
	double price;
};		// no object_name, NOTE: REMEMBER the semicolon ( ; )

// It is important to clearly differentiate between the structure type name,
// and the object name of this type.
// Many objects can be declared from a single structure type.

void printmovie (movies_t movie);

int main ()
{
	apple.weight = 8;
	apple.price = 1.99;
	cout << "The price of the apple you buy is: " << endl;
	cout << apple.weight * apple.price << endl;
	fruit banana;
	banana.weight = 3;
	banana.price = 0.99;
	cout << "The price of the banana you buy is: " << endl;
	cout << banana.weight * banana.price << endl;

	string mystr;

	mine.title = "2001 A Space Odyssey";
	mine.year = 1968;

	cout << "Enter title of your favorite movie: ";
	getline (cin, yours.title);
	cout << "Enter year: ";
	getline (cin, mystr);
	stringstream(mystr) >> yours.year;

	cout << "My favorite movie is: \n";
	printmovie(mine);
	cout << "And yours is:\n";
	printmovie(yours);

	return 0;
}

void printmovie (movies_t movie)
{
	cout << movie.title;
	cout << " (" << movie.year << ")\n";
}
