// Nesting structures
// --------------------------------------------------------------------------------

// Structures can also be nested in such a way that an element of a structure is itself another structure:

#include <iostream>
#include <string>
using namespace std;

#define MALE 0
#define FEMALE 1

struct movies_t
{
	string title;
	int year;
};

struct friends_t
{
	string name;
	bool sex;
	string email;
	movies_t favorite_movie;
} maria;

friends_t marc;

friends_t * pfriend = &maria;

void printfriend (friends_t afriend);

int main ()
{
	marc.name = "Marc";
	pfriend->name = "Maria";
	marc.sex = MALE;
	pfriend->sex = FEMALE;
	marc.email = "marc@gmail.com";
	pfriend->email = "maria@hotmail.com";
	marc.favorite_movie.title = "The Matrix";
	pfriend->favorite_movie.title = "Blade Runner";
	marc.favorite_movie.year = 1999;
	pfriend->favorite_movie.year = 1976;

	printfriend (marc);
	cout << endl;
	printfriend (*pfriend);

	return 0;
}

void printfriend (friends_t afriend)
{
	cout << afriend.name << " is one of my friends." << endl;
	if (afriend.sex) cout << "She's "; else cout << "He's ";
	cout << "favorite movie is ";
	cout << afriend.favorite_movie.title << " (" << afriend.favorite_movie.year << ")\n";
	cout << "Contact ";
	if (afriend.sex) cout << "her "; else cout << "him ";
	cout << "via EMAIL: " << afriend.email << endl;
}
