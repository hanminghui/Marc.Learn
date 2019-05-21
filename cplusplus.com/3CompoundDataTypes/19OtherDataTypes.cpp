// Other data types
// --------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main ()
{
// (1)
// Type aliases ( typedef / using )
// --------------------------------------------------------------------------------
// A type alias is a different name by which a type can be identified.
// In C++, any valid type can be aliased, so that it can be referred to with a different identifier.
// There are two syntaxes for creating such type aliases:

	// typedef, inherited from the C language
	// --------------------------------------------------
	typedef char C;				// C		as		char
	typedef unsigned int WORD;	// WORD		as		unsigned int
	typedef char * pChar;		// pChar	as		char *
	typedef char field [50];	// field	as		char [50]
	C mychar, anotherchar, *ptc1;
	WORD myword;
	pChar ptc2;
	field name;
	// using, more recently, a second syntax to define type aliases introduced in C++
	// --------------------------------------------------
	using C = char;
	using WORD = unsigned int;
	using pChar = char *;
	using field = char [50];
	// only difference, typedef has certain limitations in the realm of the templates that using has not.
	// Therefore, using is more generic

	// NOTE: neither typedef nor using create new distinct data types.
	// They only create synonyms of existing types.

// (2)
// Unions
// ---------------------------------------------------------------------------------
// Unions allow one portion of memory to be accessed as different data types.
// It's declaration and uses is similar to structures, but function totally different
// all its member elements occupy the same physical space in memory.

	union mytypes_t		// a new union type, mytypes_t
	{	// the size of this type is one of the largest member element, float here
		char c;
		int i;
		float f;
	} mytypes;
	cout << "The size of mytypes_t is " << sizeof(mytypes_t) << " bytes" << endl;
	// declares an object (mytypes) with 3 members
	// Each of these members is of a different data type.
	// But since all of them are referring to the same location in memory, the modification of one of the members will affect the value of all of them.
	// It is not possible to store different values in them in a way that each is independent of the others.

	union mix_t
	{
		int l;
		struct
		{
			short hi;
			short lo;
		} s;
		char c[4];
	} mix;			// 4 bytes, mix.l, mix.s, mix.c
	// which we can use according to how we want to access these values


// (3)
// Anonymous unions
// --------------------------------------------------------------------------------
// When unions are members of a class (or structure), They can be decalred with no name.
// In this case, they become anonymous unions.

	// structure with regular union
	// --------------------------------------------------
	struct book1_t
	{
		char title[50];
		char author[50];
		union
		{
			float dollars;
			int yen;
		} price;			// member union has a name, price
	} book1;
	// structure with anonymous union
	// --------------------------------------------------
	struct book2_t
	{
		char title[50];
		char author[50];
		union
		{
			float dollars;
			int yen;
		};					// no name
	} book2;
	// difference
	book1.price.dollars;
	book1.price.yen;
	book2.dollars;
	book2.yen;
	// the members dollars and yen actually share the same memory location,
	// so they cannot be used to store two different values simultaneously.
	// The price can be set in dollars or in yen, but not in both simultaneously.

// (4)
// Enumerated types ( enum )
// --------------------------------------------------------------------------------
// Enumerated types are types that are defined with a set of custom identifiers,
// known as enumerators, as possible values.
// Objects of these enumerated types can take any of these enumerators as value.

	enum colors_t {black, blue, green, cyan, red, purple, yellow, white};
	// NOTE: this declaration includes no other type, neither fundamental nor compound
	// this creates a whole new data type from scratch 
	// without basing it on any other existing type.
	colors_t mycolor;
	mycolor = blue;
	if (mycolor == green) mycolor = red;

	// Values of enum are implicitly convertible to an integer type, and vice versa.
	// If it is not specified otherwise,
	// the integer value equivalent to the first possible value is 0,
	// then 1, 2, and so on
	cout << "balck: " << black << endl;

	enum months_t
	{	// if the constant value that follows it is itself not given its own value,
		// it is automatically assumed to be the same value plus one
		january = 1, february, march, april, may, june, july, august,
		september, october, november, december
	} birthmonth;
	birthmonth = september;
	cout << "birthmonth is september: " << birthmonth << endl;
	// The implicit conversion works both ways:
	// a value of type moths_t can be assigned a value of 5 (may)
	birthmonth = (months_t)5;
	cout << "birthmonth is chaged to may: " << birthmonth << endl;
	int nine = 9;
// 	birthmonth = nine;	// error, need conversion
	birthmonth = static_cast<months_t>(nine);
	cout << "birthmonth is chaged again: " << birthmonth << endl;
	// or an integer variable can be assigned a value of may (5)
	int fifthmonth = may;
	cout << "May is the " << fifthmonth << "th month." << endl;

// (5)
// Enumerated types with enum class
// --------------------------------------------------------------------------------
// In C++, create real enum types that are neither implicitly convertible to int
// and that neither have enumerator values of type int
// but of the enum type itself, thus preserving type safety.
	enum class Colors
	{
		black, blue, green, cyan, red, purple, yellow, white
	};

	Colors color;
	// Each of the enumerator values of an enum class type
	// need to be scoped into its type
	// (this is actullay also possible with enum types, but it is only optional.)
	color = Colors::blue;
	if (color == Colors::green) color = Colors::red;

	// Enumerated types declared with enum class also
	// have more control over their underlying type;
	// it may be any integral data type, such as char, short, or unsigned int,
	// which essentially serves to determine the size of the type.
	// This is specified by a colon and the underlying type following the enumerated type
	enum class EyeColor : char {blue, green, brown};
	// Here, EyeColor is a distinct type with the same size of a char (1 byte)
	cout << "sizeof colors_t: " << sizeof(colors_t) << endl;   
	cout << "sizeof Colors: " << sizeof(Colors) << endl;   
	cout << "sizeof EyeColor: " << sizeof(EyeColor) << endl;   

	return 0;
}
