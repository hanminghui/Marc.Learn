// Namespaces
// ---------------------------------------------------------------------------------
// Namespaces allow us to group named entities that otherwise would have global scope
// into a narrower scopes, giving them namespace scope.
// This allows organizing the elements of programs into different logical scopes referred
// to by names.

// Reason to introduce Namespace
// --------------------------------------------------------------------------------
// Only one entity can exist with a particular name in a particular scope.
// This is seldom a problem for local names, since blocks tend to be relatively short.
// But non-local names bring more possibilities for name collision,
// especially considering that libraries may delare many function, types and variables,
// neither of them local in nature, and some of them very generic.

// syntax to declare a namespace
// --------------------------------------------------------------------------------
/*
namespace identifier
{
	named_entities
}
*/
// named_entities is the set of variables, types and functions
// that are included within the namespace.

// scope operator ::
// --------------------------------------------------------------------------------
// access named_entities from outside the namespace

#include <iostream>
#include <string>
using namespace std;

// There are two functions with the same name: value

namespace marc
{
	int value () { return 5; }
}

namespace han
{
	const double pi = 3.14159;
	// pi is accessed in an unqualified manner
	double value () { return 2*pi; }
}

// Namespace can be split: Two segments of a code can be declared in the same namespace:
namespace marc
{
	string pi = "Π";
}

int main ()
{
	cout << marc::value() << endl;
	cout << han::value() << endl;
	cout << marc::pi << endl;
	// pi needs to be qualified
	cout << han::pi << endl;
	return 0;
}
